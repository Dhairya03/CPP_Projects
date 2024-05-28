#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Layer
{
public:
    Layer(std::string name) : name(std::move(name)) {}
    std::string getName() const { return name; }

private:
    std::string name;
};

class Image
{
public:
    Image(std::string title) : title(std::move(title)) {}

    Image(Image &&other) noexcept : title(std::move(other.title)), layers(std::move(other.layers))
    {
        std::cout << "Image " << title << " moved.\n";
    }

    void addLayer(const Layer &layer)
    {
        layers.push_back(layer);
    }

    void showLayers() const
    {
        std::cout << "Image " << title << " has layers:\n";
        for (const auto &layer : layers)
        {
            std::cout << "- " << layer.getName() << "\n";
        }
    }

private:
    std::string title;
    std::vector<Layer> layers;
};

int main()
{
    Image originalImage("Original Image");
    originalImage.addLayer(Layer("Background"));
    originalImage.addLayer(Layer("Foreground"));
    originalImage.showLayers();

    Image movedImage = std::move(originalImage);
    movedImage.showLayers();

    originalImage.showLayers();
    return 0;
}
