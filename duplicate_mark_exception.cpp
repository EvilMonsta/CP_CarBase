#include "duplicate_mark_exception.h"

DuplicateMarkException::DuplicateMarkException(const string& msg) : message(msg) {}

const char* DuplicateMarkException::what() const noexcept  {
    return message.c_str();
}
string DuplicateMarkException::getMessage() const {
    return message;
}
