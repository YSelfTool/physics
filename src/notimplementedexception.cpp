#include "notimplementedexception.hpp"

NotImplementedException::NotImplementedException() : _message("") {
    
}

NotImplementedException::NotImplementedException(const std::string& message) 
    : _message(message) {
    
}

std::string NotImplementedException::reason() const {
    return "Not Implemented Yet" 
        + (this->_message != "" ? ": " + this->_message : "");
}
