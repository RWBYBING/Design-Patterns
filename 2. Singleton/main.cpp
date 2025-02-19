#include <iostream>
#include <memory>
#include <mutex>

class Singleton
{
private:
    static std::unique_ptr<Singleton> instance;
    static std::once_flag _once_flag;

    Singleton()
    {
        std::cout << "Singleton instance created" << std::endl;
    }

public:
    static Singleton* getIntance()
    {
        std::call_once(_once_flag, [](){
            instance.reset(new Singleton());
        });
        return instance.get();
    }

    void doSomething()
    {
        std::cout << "Singleton is doing something." << std::endl;
    }

    Singleton(Singleton const&) = delete;
    void operator=(Singleton const&) = delete;

    ~Singleton()
    {
        std::cout << "Singleton instance destroyed." << std::endl;
    }
};

std::unique_ptr<Singleton> Singleton::instance;
std::once_flag Singleton::_once_flag;

int main()
{
    Singleton* s1 = Singleton::getIntance();
    Singleton* s2 = Singleton::getIntance();

    s1->doSomething();

    if (s1 == s2) {
        std::cout << "Both instances are the same." << std::endl;
    }

    return 0;
}
