#ifndef PAGINATOR_H
#define PAGINATOR_H

#include <QObject>
#include <vector>
#include <QString>

class Paginator : public QObject {
    Q_OBJECT

public:
    explicit Paginator(int itemsPerPage = 9, QObject *parent = nullptr);

    void setData(const std::vector<QString> &data);

    std::vector<QString> getCurrentPageData() const;
    int totalPages() const;
    int getCurrentPage() const;

signals:
    void pageChanged(const std::vector<QString> &pageData);
    void pageInfoUpdated(int currentPage, int totalPages);

public slots:
    void nextPage();
    void prevPage();

private:
    std::vector<QString> data;
    int itemsPerPage;
    int currentPage;
};
#endif // PAGINATOR_H
