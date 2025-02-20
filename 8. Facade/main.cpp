#include <iostream>
#include <string>

// Subsystem classes （complex and potentially numerous)
class CPU
{
public:
    void start() { std::cout << "CPU starting" << std::endl; }
    void execute() { std::cout << "CPU executing" << std::endl; }
    void shutdown() { std::cout << "CPU shutting down" << std::endl; }
};

class Memory
{
public:
    void load(const std::string& data)
    {
        std::cout << "Memory loading: " << data << std::endl;
    }
};

class HardDrive
{
public:
    std::string read(int sector)
    {
        return "Data from sector" + std::to_string(sector);
    }
};

// Facade
class Computer
{
private:
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;

public:
    void start()
    {
        cpu.start();
        std::string data = hardDrive.read(1024);
        memory.load(data);
        cpu.execute();
    }

    void shutdown()
    {
        cpu.shutdown();
    }
};

int main()
{
    Computer computer;                      // Client only interacts with the Facade

    computer.start();
    std::cout << "Computer is running" << std::endl;
    computer.shutdown();

    return 0;
}