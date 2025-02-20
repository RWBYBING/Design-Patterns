#include <iostream>
#include <memory>

// Subject Interface
class Image
{
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

// Real Subject
class RealImage : public Image
{
private:
    std::string filename;

public:
    RealImage(const std::string& filename) : filename(filename)
    {
        std::cout << "RealImage: Loading " << filename << std::endl; // Expensive operation
    }

    void display() override
    {
        std::cout << "RealImage: Display" << filename << std::endl;
    }
};

// Proxy
class ImageProxy : public Image
{
private:
    std::unique_ptr<RealImage> realImage;
    std::string filename;

public:
    ImageProxy(const std::string& filename) : filename(filename) {}

    void display() override
    {
        if (realImage == nullptr)
        {
            realImage = std::make_unique<RealImage>(filename);  // Lazy loading
        }
        realImage->display();
    }
};

int main()
{
    std::unique_ptr<Image> image = std::make_unique<ImageProxy>("large_image.jpg");

    std::cout << "Image not loaded yet..." << std::endl;

    image->display();       // RealImage created and display

    std::cout << "Image already loaded..." << std::endl;
    image->display();       // No new RealImage creation

    return 0;
}