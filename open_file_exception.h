#ifndef OPEN_FILE_EXCEPTION_H
#define OPEN_FILE_EXCEPTION_H
#include <exception>
#include <string>
#include <QString>
using namespace std;

class OpenFileException : public exception {
public:
    explicit OpenFileException(const string& message);

    const char* what() const noexcept override;

    static void showErrorDialog(const QString& message);
private:
    string errorMessage;
};

#endif // OPEN_FILE_EXCEPTION_H
