#include "open_file_exception.h"
#include <QMessageBox>


OpenFileException::OpenFileException(const string& msg) : errorMessage(msg) {}

const char* OpenFileException::what() const noexcept{
    return errorMessage.c_str();
}

void OpenFileException::showErrorDialog(const QString& msg) {
    QMessageBox::critical(nullptr, "Error", msg);
}
