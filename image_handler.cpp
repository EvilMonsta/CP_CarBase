#include "image_handler.h"

#include <QFileInfo>

ImageHandler::ImageHandler(QObject *parent) : QObject(parent),
    m_selectImageButton(nullptr), m_imageLabelName(nullptr),
    m_addObjectConfirmed(nullptr), m_cancelImageButton(nullptr)
{
}

void ImageHandler::setWidgets(QPushButton *selectImageButton, QLabel *imageLabelName, QPushButton *addObjectConfirmed, QPushButton *cancelImageButton)
{
    m_selectImageButton = selectImageButton;
    m_imageLabelName = imageLabelName;
    m_addObjectConfirmed = addObjectConfirmed;
    m_cancelImageButton = cancelImageButton;
}

void ImageHandler::onSelectImageButtonClicked()
{
    QString imagePath = QFileDialog::getOpenFileName(nullptr, "Выберите изображение", "", "Images (*.png *.jpg *.jpeg)");

    if (!imagePath.isEmpty()) {
        QString targetFolder = "C:/course/CourseProject/resources/images";
        QDir().mkpath(targetFolder);

        QString fileName = QFileInfo(imagePath).fileName();
        QString targetPath = targetFolder + "/" + fileName;

        if (QFile::exists(targetFolder + "/" + fileName)) {
            QFile::remove(targetFolder + "/" + fileName);
        }

        if (QFile::copy(imagePath, targetPath)) {

            QPixmap pixmap(targetPath);
            QIcon icon(pixmap);
            m_selectImageButton->setIcon(icon);
            m_selectImageButton->setIconSize(m_selectImageButton->size());
            m_selectImageButton->setText("");
            m_imageLabelName->setText(fileName);
            m_imageLabelName->setAlignment(Qt::AlignCenter);

            m_addObjectConfirmed->setEnabled(true);
            m_cancelImageButton->setEnabled(true);
        }
    }
}

void ImageHandler::onCancelImageButtonClicked()
{
    QString fileName = m_imageLabelName->text();
    if (!fileName.isEmpty()) {
        QString targetFolder = "C:/course/CourseProject/resources/images";
        QString targetPath = targetFolder + "/" + fileName;

        if (QFile::exists(targetPath)) {
            QFile::remove(targetPath);
        }

        fileName.clear();
        m_selectImageButton->setIcon(QIcon());
        m_selectImageButton->setText("+img");
        m_imageLabelName->setText("Файл не выбран");
        m_imageLabelName->setAlignment(Qt::AlignCenter);

        m_addObjectConfirmed->setEnabled(false);
        m_cancelImageButton->setEnabled(false);
    }
}
