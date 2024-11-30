#ifndef PAGINATOR_H
#define PAGINATOR_H

#include <QObject>
#include <vector>
#include <QString>
using namespace std;
class Paginator : public QObject {
    Q_OBJECT

public:
    explicit Paginator(int itemsPerPage = 9, QObject *parent = nullptr);

    void setIds(const vector<int> &ids);
    vector<int> getCurrentPageIds() const;
    int totalPages() const;
    int getCurrentPage() const;

signals:
    void pageChanged(const vector<int> &pageIds);
    void pageInfoUpdated(int currentPage, int totalPages);

public slots:
    void nextPage();
    void prevPage();

private:
    vector<int> ids;
    int itemsPerPage;
    int currentPage;
};
#endif // PAGINATOR_H
