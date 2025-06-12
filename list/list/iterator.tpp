#pragma once
#include "list_impl.h"
using namespace std;

template <typename T>
typename List<T>::iterator::reference List<T>::iterator::operator*() {
    return current->data;
}

template <typename T>
typename List<T>::iterator::pointer List<T>::iterator::operator->() {
    return &(current->data);
}

template <typename T>
typename List<T>::iterator& List<T>::iterator::operator++() {
    if (current == nullptr) {
        return *this;
    }
    current = current->next;
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
    if (current == nullptr) {
        return *this;
    }
    iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
typename List<T>::iterator& List<T>::iterator::operator--() {
    if (current == nullptr) {
        return *this;
    }
    current = current->prev;
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int) {
    if (current == nullptr) {
        return *this;
    }
    iterator temp = *this;
    --(*this);
    return temp;
}

template <typename T>
bool List<T>::iterator::operator!=(const iterator& other) const {
    return current != other.current;
}

template <typename T>
bool List<T>::iterator::operator==(const iterator& other) const {
    return current == other.current;
}

template <typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator(head);
}

template <typename T>
typename List<T>::iterator List<T>::end() {
    return iterator(nullptr);
}