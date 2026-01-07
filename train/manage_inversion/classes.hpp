#pragma once
#include <memory>
#include <iostream>

#define CAR "car"
#define AIRPLANE "airplane"

class ITransport
{
public:
    ITransport() = default;
    virtual ~ITransport() = default;
    virtual void Go() {
        std::cout << "Walk, this is usefull" << std::endl;
    };
};
class Car : public ITransport
{
    public:
    Car()
    {
        std::cout << "Your post will be delevered by Car" << std::endl;
    }
    ~Car()
    {
        std::cout << "Post were delevered by Car" << std::endl;
    }
    void Go()
    {
        std::cout << "Go Car" << std::endl;
    }
};

class Airplane : public ITransport
{
    public:
    Airplane()
    {
        std::cout << "Your post will be delevered by Airplane" << std::endl;
    }
    ~Airplane()
    {
        std::cout << "Post were delevered by Airplane" << std::endl;
    }
    void Go()
    {
        std::cout << "Go Airplane" << std::endl;
    }
};

class DeleverySrc
{
private:
    std::unique_ptr<ITransport> transport_;

public:
    DeleverySrc(std::unique_ptr<ITransport> transport): transport_(std::move(transport)) {};

    void StartTransfer()
    {
        std::cout << "Start Transfer" << std::endl;

        //                Delegate to transport (airplane, car or another)
        transport_->Go();
    }
};