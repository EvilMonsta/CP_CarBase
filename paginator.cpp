#include "paginator.h"

Paginator::Paginator(int itemsPerPage, QObject *parent)
    : QObject(parent), itemsPerPage(itemsPerPage), currentPage(1) {}

void Paginator::setIds(const vector<int> &ids) {
    this->ids = ids ;
    currentPage = 1;
    emit pageChanged(getCurrentPageIds());
    emit pageInfoUpdated(currentPage, totalPages());
}
vector<int> Paginator::getCurrentPageIds() const {
    int startIndex = (currentPage - 1) * itemsPerPage;
    int endIndex = std::min(startIndex + itemsPerPage, (int)ids.size());
    return vector<int>(ids.begin() + startIndex, ids.begin() + endIndex);
}

int Paginator::totalPages() const {
    return (ids.size() + itemsPerPage - 1) / itemsPerPage;
}

int Paginator::getCurrentPage() const {
    return currentPage;
}

void Paginator::nextPage() {
    if (currentPage < totalPages()) {
        ++currentPage;
        emit pageChanged(getCurrentPageIds());
        emit pageInfoUpdated(currentPage, totalPages());
    }
}

void Paginator::prevPage() {
    if (currentPage > 1) {
        --currentPage;
        emit pageChanged(getCurrentPageIds());
        emit pageInfoUpdated(currentPage, totalPages());
    }
}
