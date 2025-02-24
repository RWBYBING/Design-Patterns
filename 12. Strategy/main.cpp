#include <iostream>
#include <memory>

// Strategy Interface
class Strategy
{
public:
    virtual int execute(int a, int b) = 0;
    virtual ~Strategy() = default;
};

// Concrete Strategies
class ConcreteStrategyAdd : public Strategy
{
public:
    int execute(int a, int b) override
    {
        return a + b;
    }   
};

class ConcreteStrategySubstract : public Strategy
{
public:
    int execute(int a, int b) override
    {
        return a - b;
    }
};

class ConcreteStrategyMultiply : public Strategy
{
public:
    int execute(int a, int b) override
    {
        return a * b;
    }
};

// Context
class Context
{
private:
    std::unique_ptr<Strategy> strategy;

public:
    Context(std::unique_ptr<Strategy> strategy) : strategy(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<Strategy> strategy)
    {
        this->strategy = std::move(strategy);
    }

    int executeStrategy(int a, int b)
    {
        return strategy->execute(a, b);
    }
};

int main()
{
    std::unique_ptr<Strategy> addStrategy = std::make_unique<ConcreteStrategyAdd>();
    Context context(std::move(addStrategy));

    std::cout << "10 + 5 = " << context.executeStrategy(10, 5) << std::endl;

    std::unique_ptr<Strategy> substractStrategy = std::make_unique<ConcreteStrategySubstract>();
    context.setStrategy(std::move(substractStrategy));

    std::cout << "10 - 5 = " << context.executeStrategy(10, 5) << std::endl;

    std::unique_ptr<Strategy> multiplyStrategy = std::make_unique<ConcreteStrategyMultiply>();
    context.setStrategy(std::move(multiplyStrategy));
    
    std::cout << "10 * 5 = " << context.executeStrategy(10, 5) << std::endl;

    return 0;
}