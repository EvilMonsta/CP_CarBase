#include "paginator.h"

Paginator::Paginator(int itemsPerPage, QObject *parent)
    : QObject(parent), itemsPerPage(itemsPerPage), currentPage(1) {}

void Paginator::setData(const std::vector<QString> &data) {
    this->data = data;
    currentPage = 1;
    emit pageChanged(getCurrentPageData());
    emit pageInfoUpdated(currentPage, totalPages());
}

std::vector<QString> Paginator::getCurrentPageData() const {
    int startIndex = (currentPage - 1) * itemsPerPage;
    int endIndex = std::min(startIndex + itemsPerPage, (int)data.size());
    return std::vector<QString>(data.begin() + startIndex, data.begin() + endIndex);
}

int Paginator::totalPages() const {
    return (data.size() + itemsPerPage - 1) / itemsPerPage;
}

int Paginator::getCurrentPage() const {
    return currentPage;
}

void Paginator::nextPage() {
    if (currentPage < totalPages()) {
        ++currentPage;
        emit pageChanged(getCurrentPageData());
        emit pageInfoUpdated(currentPage, totalPages());
    }
}

void Paginator::prevPage() {
    if (currentPage > 1) {
        --currentPage;
        emit pageChanged(getCurrentPageData());
        emit pageInfoUpdated(currentPage, totalPages());
    }
}
