#include <iostream>
#include <memory>
#include <vector>

// Receiver
class Receiver
{
public:
    void action(const std::string& message)
    {
        std::cout << "Receiver: " << message << std::endl;
    }
};

// Command Interface
class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Concrete Command
class ConcreteCommand : public Command
{
private:
    std::shared_ptr<Receiver> receiver;
    std::string message;

public:
    ConcreteCommand(std::shared_ptr<Receiver> receiver, const std::string& message)
        : receiver(receiver), message(message) {}
    
    void execute() override
    {
        receiver->action(message);
    }
};

// Invoker
class Invoker
{
private:
    std::vector<std::shared_ptr<Command>> commands;

public:
    void addCommand(std::shared_ptr<Command> command)
    {
        commands.push_back(command);
    }

    void executeCommands()
    {
        for (const auto& command : commands)
        {
            command->execute();
        }
    }
};

int main()
{
    auto receiver = std::make_shared<Receiver>();
    auto command1 = std::make_shared<ConcreteCommand>(receiver, "Command 1");
    auto command2 = std::make_shared<ConcreteCommand>(receiver, "Command 2");

    Invoker invoker;
    invoker.addCommand(command1);
    invoker.addCommand(command2);

    invoker.executeCommands();

    return 0;
}