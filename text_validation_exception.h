#ifndef TEXT_VALIDATION_EXCEPTION_H
#define TEXT_VALIDATION_EXCEPTION_H
#include <exception>
#include <QString>
#include <QWidget>
using namespace std;
class TextValidationException : public exception
{
public:
    explicit TextValidationException(const QString& message);
    const char* what() const noexcept override;

    static void validate(const QString& input, QWidget* parent = nullptr);

private:
    QString errorMessage;

    static void showError(const TextValidationException& ex, QWidget* parent);
};

#endif // TEXT_VALIDATION_EXCEPTION_H
