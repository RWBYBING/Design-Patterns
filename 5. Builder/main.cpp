#include <iostream>
#include <string>
#include <memory>

// Product (Complex object)
class Pizza
{
public:
    std::string dough;
    std::string sauce;
    std::string topping;

    void display() const 
    {
        std::cout << "Pizza:" << std::endl;
        std::cout << "  Dough: " << dough << std::endl;
        std::cout << "  Sauce: " << sauce << std::endl;
        std::cout << "  Topping: " << topping << std::endl;
    }
};

// Abstract Builder
class PizzaBuilder
{
public:
    virtual ~PizzaBuilder() = default;
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual std::unique_ptr<Pizza> getPizza() = 0;
};

// Concrete Builders
class HawaiianPizzaBuilder : public PizzaBuilder
{
private:
    std::unique_ptr<Pizza> pizza = std::make_unique<Pizza>();

public:
    void buildDough() override { pizza->dough = "Thin crust"; }
    void buildSauce() override { pizza->sauce = "Tomato"; }
    void buildTopping() override { pizza->topping = "Ham and pineapple"; }
    std::unique_ptr<Pizza> getPizza() override { return std::move(pizza); }
};

class SpicyPizzaBuilder : public PizzaBuilder
{
private:
    std::unique_ptr<Pizza> pizza = std::make_unique<Pizza>();

public:
    void buildDough() override { pizza->dough = "Thick crust"; }
    void buildSauce() override { pizza->sauce = "Spicy tomato"; }
    void buildTopping() override { pizza->topping = "Pepperoni and jalapenos"; }
    std::unique_ptr<Pizza> getPizza() override { return std::move(pizza); }
};

// Director
class Cook
{
public:
    void makePizza(PizzaBuilder& builder)
    {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};

int main()
{
    Cook cook;

    HawaiianPizzaBuilder hawaiian_builder;
    cook.makePizza(hawaiian_builder);
    std::unique_ptr<Pizza> hawaiian_pizza = hawaiian_builder.getPizza();
    hawaiian_pizza->display();

    SpicyPizzaBuilder spicy_builder;
    cook.makePizza(spicy_builder);
    std::unique_ptr<Pizza> spicy_pizza = spicy_builder.getPizza();
    spicy_pizza->display();

    return 0;
}