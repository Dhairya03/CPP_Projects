#include <SDL2/SDL.h>
int main(int argc, char* argv[]) {
    // Initialize SDL Audio subsystem
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Load music file
    const char* musicFile = "/home/dhairyagupta/Downloads/song.wav"; // Change this to your music file path
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8* wavBuffer;
    if (SDL_LoadWAV(musicFile, &wavSpec, &wavBuffer, &wavLength) == NULL) {
        SDL_Log("Could not load music: %s", SDL_GetError());
        return 1;
    }

    // Open audio device
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if (deviceId == 0) {
        SDL_Log("Failed to open audio: %s", SDL_GetError());
        SDL_FreeWAV(wavBuffer);
        return 1;
    }

    // Play music
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0); // Unpause audio device

    // Wait until music finishes playing
    SDL_Delay(50000); // Adjust this to the duration of your music

    // Clean up
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();

    return 0;
}
