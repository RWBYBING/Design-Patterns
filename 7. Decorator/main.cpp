#include <iostream>
#include <memory>

// Component Interface
class Component
{
public:
    virtual void operation() = 0;
    virtual ~Component() = default;
};

// Concrete Component
class ConcreteComponent : public Component
{
public:
    void operation() override
    {
        std::cout << "Concrete component operation" << std::endl;
    }
};

// Abstract Decorator
class Decorator : public Component
{
protected:
    std::unique_ptr<Component> component;

public:
    Decorator(std::unique_ptr<Component> component) : component(std::move(component)) {}

    void operation() override
    {
        component->operation();             // Base Operation
    }
};

// Concrete Decorators
class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(std::unique_ptr<Component> component) : Decorator(std::move(component)) {}

    void operation() override
    {
        Decorator::operation();             // Call the base operation
        std::cout << "Concrete decoratorA operation" << std::endl;
    }
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(std::unique_ptr<Component> component) : Decorator(std::move(component)) {}

    void operation() override
    {
        std::cout << "Concrete decoratorB pre-operation" << std::endl;
        Decorator::operation();             // Call the base operation
        std::cout << "Concrete decoratorB post-operation" << std::endl;
    }
};

int main()
{
    std::unique_ptr<Component> component = std::make_unique<ConcreteComponent>();
    std::unique_ptr<Component> decoratorA = std::make_unique<ConcreteDecoratorA>(std::move(component));
    std::unique_ptr<Component> decoratorB = std::make_unique<ConcreteDecoratorB>(std::move(decoratorA));

    decoratorB->operation();

    return 0;
}