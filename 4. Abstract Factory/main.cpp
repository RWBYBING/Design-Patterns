#include <iostream>
#include <memory>

// Abstract products
class AbstractProductA
{
public:
    virtual void operationA() const = 0;
    virtual ~AbstractProductA() = default;
};

class AbstractProductB
{
public:
    virtual void operationB() const = 0;
    virtual ~AbstractProductB() = default;
};

// Concrete products
class ConcreteProductA1 : public AbstractProductA
{
public:
    void operationA() const override
    {
        std::cout << "ConcreteProductA1 operation" << std::endl;
    }
};

class ConcreteProductA2 : public AbstractProductA
{
public:
    void operationA() const override
    {
        std::cout << "ConcreteProductA2 operation" << std::endl;
    }
};

class ConcreteProductB1 : public AbstractProductB
{
public:
    void operationB() const override
    {
        std::cout << "ConcreteProductB1 operation" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB
{
public:
    void operationB() const override
    {
        std::cout << "ConcreteProductB2 operation" << std::endl;
    }
};

// Abstract factory
class AbstractFactory
{
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
    virtual ~AbstractFactory() = default;
};

// Concrete factories
class ConcreteFactory1 : public AbstractFactory
{
public:
    std::unique_ptr<AbstractProductA> createProductA() const override
    {
        return std::make_unique<ConcreteProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override
    {
        return std::make_unique<ConcreteProductB1>();
    }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    std::unique_ptr<AbstractProductA> createProductA() const override
    {
        return std::make_unique<ConcreteProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override
    {
        return std::make_unique<ConcreteProductB2>();
    }
};

int main()
{
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractProductA> productA1 = factory1->createProductA();
    productA1->operationA();
    std::unique_ptr<AbstractProductB> productB1 = factory1->createProductB();
    productB1->operationB();

    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
    std::unique_ptr<AbstractProductA> productA2 = factory2->createProductA();
    productA2->operationA();
    std::unique_ptr<AbstractProductB> productB2 = factory2->createProductB();
    productB2->operationB();
}