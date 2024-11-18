#ifndef DUPLICATE_MARK_EXCEPTION_H
#define DUPLICATE_MARK_EXCEPTION_H
#include <exception>
#include <QString>

using namespace std;

class DuplicateMarkException : public exception
{

public:

    explicit DuplicateMarkException(const string& msg);

    const char* what() const noexcept override;

    string getMessage() const;

private:

    string message;

};

#endif // DUPLICATE_MARK_EXCEPTION_H
