#pragma once

#include <memory>
#include "msg_classes.hpp"

//                                         INTERFACES
class INotify {
    public:
    virtual ~INotify() = default;
    virtual std::unique_ptr<IEmail> create_email() = 0;
    virtual std::unique_ptr<ISms> create_sms() = 0;
};

//                                          FACTORY
class FormalNotify: public INotify {
    public:
    virtual std::unique_ptr<IEmail> create_email() {
        return std::make_unique<FormalEmail>();
    }
    virtual std::unique_ptr<ISms> create_sms() {
        return std::make_unique<FormalSms>();
    }
};

class CasualNotify: public INotify {
    public:
    virtual std::unique_ptr<IEmail> create_email() {
        return std::make_unique<CasualEmail>();
    }
    virtual std::unique_ptr<ISms> create_sms() {
        return std::make_unique<CasualSms>();
    }
};

