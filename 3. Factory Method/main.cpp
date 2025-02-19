#include <iostream>
#include <memory>

// Product interface
class Product
{
public:
    virtual void operation() const = 0;
    virtual ~Product() = default;
};

// Concrete products
class ConcreteProductA : public Product
{
public:
    void operation() const override
    {
        std::cout << "ConcreteProductA operation" << std::endl;
    }
};

class ConcreteProductB : public Product
{
public:
    void operation() const override
    {
        std::cout << "ConcreteProductB operation" << std::endl;
    }
};

// Creator class
class Creator
{
public:
    virtual std::unique_ptr<Product> createProduct() const = 0;
    virtual ~Creator() = default;
};

// Concrete creators
class ConcreteCreatorA : public Creator
{
public:
    std::unique_ptr<Product> createProduct() const override
    {
        return std::make_unique<ConcreteProductA>();
    }
};

class ConcreteCreatorB : public Creator
{
public:
    std::unique_ptr<Product> createProduct() const override
    {
        return std::make_unique<ConcreteProductB>();
    }
};

int main()
{
    std::unique_ptr<Creator> createA = std::make_unique<ConcreteCreatorA>();
    createA->createProduct()->operation();

    std::unique_ptr<Creator> createB = std::make_unique<ConcreteCreatorB>();
    createB->createProduct()->operation();
}