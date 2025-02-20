#include <iostream>
#include <memory>

// Target Interfaces
class Target
{
public:
    virtual void request() = 0;
    virtual ~Target() = default;
};

// Adaptee (Incompatible Interface)
class Adaptee
{
public:
    void specificRequest()
    {
        std::cout << "Adaptee's specific request" << std::endl;
    }
};

// Adapter
class Adapter : public Target
{
private:
    std::unique_ptr<Adaptee> adaptee;

public:
    Adapter(std::unique_ptr<Adaptee> adaptee) : adaptee(std::move(adaptee)) {}

    void request() override
    {
        adaptee->specificRequest();
    }
};

int main()
{
    std::unique_ptr<Adaptee> adaptee = std::make_unique<Adaptee>();
    std::unique_ptr<Target> adapter = std::make_unique<Adapter>(std::move(adaptee));

    adapter->request();

    return 0;
}