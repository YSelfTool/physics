#pragma once
#include <string>

class Exception {
    public:
    virtual std::string reason() const = 0;
};
