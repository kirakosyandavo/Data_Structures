#include "list_impl.h"
using namespace std;

template <typename T>
typename List<T>::const_iterator::reference List<T>::const_iterator::operator*() {
    return current->data;
}

template <typename T>
typename List<T>::const_iterator::pointer List<T>::const_iterator::operator->() {
    return &(current->data);
}

template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++() {
    if (current == nullptr) {
        return *this;
    }
    current = current->next;
    return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int) {
    if (current == nullptr) {
        return *this;
    }
    const_iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator--() {
    if (current == nullptr) {
        return *this;
    }
    current = current->prev;
    return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int) {
    if (current == nullptr) {
        return *this;
    }
    const_iterator temp = *this;
    --(*this);
    return temp;
}

template <typename T>
bool List<T>::const_iterator::operator!=(const const_iterator& other) const {
    return current != other.current;
}

template <typename T>
bool List<T>::const_iterator::operator==(const const_iterator& other) const {
    return current == other.current;
}

template <typename T>
typename List<T>::const_iterator List<T>::cbegin() {
    return const_iterator(head);
}

template <typename T>
typename List<T>::const_iterator List<T>::cend() {
    return const_iterator(nullptr);
}
