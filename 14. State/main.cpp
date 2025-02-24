#include <iostream>
#include <memory>

// State Interface
class State
{
public:
    virtual void handle(class Context* context) = 0;
    virtual ~State() = default;
};

// Concrete States
class ConcreteStateA : public State
{
public:
    void handle(class Context* context) override;    
};

class ConcreteStateB : public State
{
public:
    void handle(class Context* context) override;
};

// Context
class Context
{
private:
    std::unique_ptr<State> state;

public:
    Context(std::unique_ptr<State> state) : state(std::move(state)) {}

    void setState(std::unique_ptr<State> state)
    {
        this->state = std::move(state);
    }

    void request()
    {
        state->handle(this);
    }
};

void ConcreteStateA::handle(Context* context)
{
    std::cout << "ConcreteStateA handles request. Changing state to ConcreteStateB ..." << std::endl;
    context->setState(std::make_unique<ConcreteStateB>());
}

void ConcreteStateB::handle(Context* context)
{
    std::cout << "ConcreteStateB handles request. Changing state to ConcreteStateA ..." << std::endl;
    context->setState(std::make_unique<ConcreteStateA>());
}

int main()
{
    Context context(std::make_unique<ConcreteStateA>());
    context.request();
    context.request();
    context.request();

    return 0;
}