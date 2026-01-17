#pragma once

#include <iostream>
#include <memory>

using std::cout, std::endl;

class IPhone
{
public:
    virtual ~IPhone() = default;
    virtual void call() = 0;
};

class RealPhone : public IPhone
{
public:
    void call() override
    {

        //                         Предположим, что тут страшная процедура звонка с кучей вызовов и тд

        cout << "Calling procedure" << endl;
    }
};

class ProxyPhone : public IPhone
{
    mutable std::unique_ptr<RealPhone> phone_;

public:
    ProxyPhone() {
        phone_ = std::make_unique<RealPhone>();
        cout << "Proxy phone constructor" << endl;
    };
    void call() override
    {
        // Проверяем что-то дополнительно. Например, есть ли деньги на счету, модем ли мы позвонить по номеру и тд.
        cout << "Accessory function before calling someone" << endl;
        phone_->call();
    }
};
