#include "portaudio.h"
// #include "pa.h"
#include "math.h"
#define TWO_PI 6.2831853

double phase = 0, step = TWO_PI*440/44100.0;

void paFunc(const float* in, float* out, long frames, void* data){    
    // play a 440Hz sine tone
    for(int i = 0; i < frames; i++ ){
         *out++ = sin(phase)*0.5;
         phase += step;
     }
}

int main() {
    // use default parameters, not passing any data
    Pa a(paFunc, NULL);
    // start stream
    a.start(Pa::waitForKey);
    return 0;
}