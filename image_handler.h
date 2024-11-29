#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H

#include <QObject>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QLabel>

class ImageHandler : public QObject
{
    Q_OBJECT

public:
    explicit ImageHandler(QObject *parent = nullptr);

    void setWidgets(QPushButton *selectImageButton, QLabel *imageLabelName, QPushButton *addObjectConfirmed, QPushButton *cancelImageButton);

public slots:
    void onSelectImageButtonClicked();
    void onCancelImageButtonClicked();

private:
    QPushButton *m_selectImageButton;
    QLabel *m_imageLabelName;
    QPushButton *m_addObjectConfirmed;
    QPushButton *m_cancelImageButton;
};

#endif // IMAGE_HANDLER_H
