#include <iostream>

// Abstract Class (Template Class)
class AbstractClass
{
public:
    // Template Method
    void templateMethod()
    {
        primitiveOperation1();
        primitiveOperation2();
        hook();
        primitiveOperation3();
    }

    virtual ~AbstractClass() = default;

protected:
    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;
    virtual void primitiveOperation3() = 0;
    virtual void hook() {} // Hook Method (optional override)
};

// Concrete Class
class ConcreteClassA : public AbstractClass
{
protected:
    void primitiveOperation1() override
    {
        std::cout << "ConcreteClassA: Operation 1" << std::endl;
    }

    void primitiveOperation2() override
    {
        std::cout << "ConcreteClassA: Operation 2" << std::endl;
    }

    void primitiveOperation3() override
    {
        std::cout << "ConcreteClassA: Operation 3" << std::endl;
    }
};

class ConcreteClassB : public AbstractClass
{
protected:
    void primitiveOperation1() override
    {
        std::cout << "ConcreteClassB: Operation 1" << std::endl;
    }

    void primitiveOperation2() override
    {
        std::cout << "ConcreteClassB: Operation 2" << std::endl;
    }

    void primitiveOperation3() override
    {
        std::cout << "ConcreteClassB: Operation 3" << std::endl;
    }

    void hook() override
    {
        std::cout << "ConcreteClassB: Hook overridden" << std::endl;
    }
};

int main()
{
    AbstractClass* classA = new ConcreteClassA();
    classA->templateMethod();

    std::cout << std::endl;

    AbstractClass* classB = new ConcreteClassB();
    classB->templateMethod();

    delete classA;
    delete classB;

    return 0;
}