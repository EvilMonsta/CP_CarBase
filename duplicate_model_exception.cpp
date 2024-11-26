#include "duplicate_model_exception.h"

DuplicateModelException::DuplicateModelException(const string& msg) : message(msg) {}

const char* DuplicateModelException::what() const noexcept  {
    return message.c_str();
}
string DuplicateModelException::getMessage() const {
    return message;
}
