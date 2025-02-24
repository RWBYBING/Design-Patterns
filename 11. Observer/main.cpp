#include <iostream>
#include <vector>
#include <memory>

// Observer Interface
class Observer
{
public:
    virtual void update(int state) = 0;
    virtual ~Observer() = default;
};

// Subject Interface
class Subject
{
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
    virtual void setState(int state) = 0;
    virtual int getState() const = 0;
    virtual ~Subject() = default;
};

// Concrete Subject
class ConcreteSubject : public Subject
{
private:
    std::vector<Observer*> observers;
    int state;

public:
    void attach(Observer* observer) override
    {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override
    {
        for (auto it = observers.begin(); it != observers.end(); ++ it)
        {
            if (*it == observer)
            {
                observers.erase(it);
                return;
            }
        }
    }

    void notify() override
    {
        for (Observer* observer : observers)
        {
            observer->update(state);
        }
    }

    void setState(int state) override
    {
        this->state = state;
        notify();
    }

    int getState() const override
    {
        return state;
    }
};

// Concrete Observer
class ConcreteObserver : public Observer
{
private:
    int observerState;
    Subject* subject;

public:
    ConcreteObserver(Subject* subject) : subject(subject)
    {
        subject->attach(this);
    }

    void update(int state) override
    {
        observerState = state;
        std::cout << "Observer received update: " << observerState << std::endl;
    }

    ~ConcreteObserver()
    {
        subject->detach(this);
    }
};

int main()
{
    ConcreteSubject subject;
    ConcreteObserver observer1(&subject);
    ConcreteObserver observer2(&subject);

    subject.setState(10);
    subject.setState(20);

    return 0;
}