#pragma once

#include <iostream>
#include <memory>

using std::cout, std::endl;

class IModulePhone
{
public:
    IModulePhone() = default;
    virtual ~IModulePhone() = default;
    virtual void ICan() = 0;
};

class BasicPhone : public IModulePhone
{
public:
    void ICan() override
    {
        cout << "Make calls and send messages" << endl;
    }
};

class AudioModule : public IModulePhone
{
    std::unique_ptr<IModulePhone> phone_;

public:
    AudioModule(std::unique_ptr<IModulePhone> phone)
        : phone_(std::move(phone)) {}

    ~AudioModule() = default;

    void ICan() override
    {
        phone_->ICan();
        cout << "+ Best audio system in the world" << endl;
    }
};

class CameraModule : public IModulePhone
{
    std::unique_ptr<IModulePhone> phone_;

public:
    CameraModule(std::unique_ptr<IModulePhone> phone)
        : phone_(std::move(phone)) {}

    ~CameraModule() = default;

    void ICan() override
    {
        phone_->ICan();
        cout << "+ Best camera in the world" << endl;
    }
};

class BatteryModule : public IModulePhone
{
    std::unique_ptr<IModulePhone> phone_;

public:
    BatteryModule(std::unique_ptr<IModulePhone> phone) : phone_(std::move(phone)) {}

    ~BatteryModule() = default;

    void ICan() override
    {
        phone_->ICan();
        cout << "+ Live after first charging forever" << endl;
    }
};