#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>

using std::string;
using std::unique_ptr;

class Context
{
    std::unordered_map<string, bool> values_;

public:
    void set(string name, bool value) { values_[name] = value; }
    bool get(const string& name) const { return values_.at(name); }
};

class IExpression
{
public:
    IExpression() = default;
    virtual ~IExpression() {};
    virtual bool interpret(const Context& ctx) = 0;
};

class Variable : public IExpression
{
private:
    string name_;

public:
    Variable() = delete;
    Variable(string name) : name_(name) {};
    bool interpret(const Context& ctx) override
    {
        return ctx.get(name_);
    }
};

class AndExpression : public IExpression
{
private:
    unique_ptr<IExpression> left_;
    unique_ptr<IExpression> right_;

public:
    AndExpression(unique_ptr<IExpression> l, unique_ptr<IExpression> r)
        : left_(std::move(l)), right_(std::move(r)) {}
    bool interpret(const Context &ctx) override
    {
        return left_->interpret(ctx) && right_->interpret(ctx);
    }
};

class OrExpression : public IExpression
{
private:
    unique_ptr<IExpression> left_;
    unique_ptr<IExpression> right_;

public:
    OrExpression(unique_ptr<IExpression> l, unique_ptr<IExpression> r)
        : left_(std::move(l)), right_(std::move(r)) {}
    bool interpret(const Context &ctx) override
    {
        return left_->interpret(ctx) || right_->interpret(ctx);
    }
};

class NotExpression : public IExpression
{
private:
    unique_ptr<IExpression> val_;
public:
    NotExpression(unique_ptr<IExpression> val)
        : val_(std::move(val)) {}
    bool interpret(const Context &ctx) override
    {
        return !val_->interpret(ctx);
    }
};