#include "text_validation_exception.h"
#include <QMessageBox>
#include <QRegularExpression>

TextValidationException::TextValidationException(const QString& message): errorMessage(message) {}

const char* TextValidationException::what() const noexcept {
    return errorMessage.toStdString().c_str();
}

void TextValidationException::validate(const QString& input, QWidget* parent) {
    QRegularExpression regex("^[a-zA-Zа-яА-Я0-9-ё\\s]+$");

    if (!regex.match(input).hasMatch()) {
        TextValidationException ex("Не оставляйте поле пустым и используйте только русский или английский язык.");
        showError(ex, parent);
        throw ex;
    }
}

void TextValidationException::showError(const TextValidationException& ex, QWidget* parent) {
    QMessageBox::critical(parent, "Input Error", ex.what());
}
