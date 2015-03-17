#pragma once
#include "exception.hpp"

class NotImplementedException : public Exception {
    private:
    std::string _message;
    
    public:
    NotImplementedException();
    NotImplementedException(const std::string& message);
    
    std::string reason() const;
};
