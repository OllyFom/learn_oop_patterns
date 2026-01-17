#pragma once

#include <iostream>
#include <vector>
#include <memory>

using std::cout, std::endl, std::string, std::unique_ptr, std::vector;

class IFileSysObject
{
public:
    virtual int size() = 0;
    virtual ~IFileSysObject() = default;
};

class File : public IFileSysObject
{
    int size_ = 1024;
    string name_;

public:
    int size() override
    {
        cout << "Size of File " << name_ << " is:" << size << endl;
        return size_;
    }
    File(string name, int size) : name_(std::move(name)), size_(size) {};
    File(string name) : name_(std::move(name)) {};
};

class Directory : public IFileSysObject
{
    vector<
        unique_ptr<IFileSysObject>>
        consist_;
    string name_;
    int size_ = 0;

public:
    Directory(string name, vector<unique_ptr<IFileSysObject>> consist) : name_(std::move(name)), consist_(std::move(consist)) {};
    int size() override
    {
        int size = 0;
        for (auto obj = consist_.begin(); obj <= consist_.end(); obj++)
        {
            size += (obj)->get()->size();
        }
        cout << "Size of Directory " << name_ << " is:" << size << endl;
        return size;
    }
};