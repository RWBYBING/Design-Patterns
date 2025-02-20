#include <iostream>
#include <memory>

// Implementor Interface
class DrawingAPI
{
public:
    virtual void drawCircle(int x, int y, int radius) = 0;
    virtual void drawRectangle(int x1, int y1, int x2, int y2) = 0;
    virtual ~DrawingAPI() = default;
};

// Concrete Implementors
class OpenGLDrawing : public DrawingAPI
{
public:
    void drawCircle(int x, int y, int radius) override {
        std::cout << "OpenGL: Drawing circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
    void drawRectangle(int x1, int y1, int x2, int y2) override {
        std::cout << "OpenGL: Drawing rectangle from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;
    }
};

class SVGRendering : public DrawingAPI
{
public:
    void drawCircle(int x, int y, int radius) override {
        std::cout << "SVG: Drawing circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }
    void drawRectangle(int x1, int y1, int x2, int y2) override {
        std::cout << "SVG: Drawing rectangle from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;
    }
};

// Abstraction
class Shape 
{
protected:
    std::unique_ptr<DrawingAPI> drawingAPI;

public:
    Shape(std::unique_ptr<DrawingAPI> drawingAPI) : drawingAPI(std::move(drawingAPI)) {}
    virtual ~Shape() = default;
    virtual void draw() = 0;
    virtual void resize(int factor) = 0;
};

// Refined Abstractions
class Circle : public Shape
{
private:
    int x, y, radius;

public:
    Circle(int x, int y, int radius, std::unique_ptr<DrawingAPI> drawingAPI) : x(x), y(y), radius(radius), Shape(std::move(drawingAPI)) {}

    void draw() override
    {
        drawingAPI->drawCircle(x, y, radius);
    }

    void resize(int factor) override
    {
        radius *= factor;
    }
};

class Rectangle : public Shape
{
private:
    int x1, y1, x2, y2;

public:
    Rectangle(int x1, int y1, int x2, int y2, std::unique_ptr<DrawingAPI> drawingAPI) : x1(x1), y1(y1), x2(x2), y2(y2), Shape(std::move(drawingAPI)) {}

    void draw() override {
        drawingAPI->drawRectangle(x1, y1, x2, y2);
    }

    void resize(int factor) override {
        x2 *= factor;
        y2 *= factor;
    }
};

int main()
{
    std::unique_ptr<DrawingAPI> openGL = std::make_unique<OpenGLDrawing>();
    std::unique_ptr<Shape> circle = std::make_unique<Circle>(100, 100, 50, std::move(openGL));
    circle->draw();
    circle->resize(2);
    circle->draw();

    std::unique_ptr<DrawingAPI> svg = std::make_unique<SVGRendering>();
    std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>(50, 50, 200, 100, std::move(svg));
    rectangle->draw();

    return 0;
}