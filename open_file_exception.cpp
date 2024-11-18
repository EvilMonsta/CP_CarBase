#include "open_file_exception.h"
#include <QMessageBox>


OpenFileException::OpenFileException(const string& message) : errorMessage(message) {}

const char* OpenFileException::what() const noexcept{
    return errorMessage.c_str();
}

void OpenFileException::showErrorDialog(const QString& message) {
    QMessageBox::critical(nullptr, "Error", message);
}
