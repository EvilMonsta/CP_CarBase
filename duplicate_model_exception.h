#ifndef DUPLICATE_MODEL_EXCEPTION_H
#define DUPLICATE_MODEL_EXCEPTION_H
#include <exception>
#include <QString>

using namespace std;

class DuplicateModelException : public exception
{
public:

    explicit DuplicateModelException(const string& msg);

    const char* what() const noexcept override;

    string getMessage() const;

private:

    string message;

};

#endif // DUPLICATE_MODEL_EXCEPTION_H
