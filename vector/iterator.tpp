#include "vector_impl.h"
using namespace std;

template <typename T>
typename Vector<T>::iterator::reference Vector<T>::iterator::operator*() {
    return *ptr;
}

template <typename T>
typename Vector<T>::iterator::pointer Vector<T>::iterator::operator->() {
    return ptr;
}

template <typename T>
typename Vector<T>::iterator& Vector<T>::iterator::operator++() {
    ++ptr;
    return *this;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator++(int) {
    iterator obj(this->ptr);
    ++(*this);
    return obj;
}

template <typename T>
typename Vector<T>::iterator& Vector<T>::iterator::operator--() {
    --ptr;
    return *this;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator--(int) {
    iterator obj(this->ptr);
    --ptr;
    return obj;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator+(typename Vector<T>::iterator::difference_type value) {
    return iterator(ptr + value);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::iterator::operator-(typename Vector<T>::iterator::difference_type value) {
    return iterator(ptr - value);
}

template <typename T>
typename Vector<T>::iterator& Vector<T>::iterator::operator+=(typename Vector<T>::iterator::difference_type value) {
    ptr += value;
    return *this;
}

template <typename T>
typename Vector<T>::iterator& Vector<T>::iterator::operator-=(typename Vector<T>::iterator::difference_type value) {
    ptr -= value;
    return *this;
}

template <typename T>
typename Vector<T>::iterator::reference Vector<T>::iterator::operator[](typename Vector<T>::iterator::difference_type value) {
    return ptr[value];
}

template <typename T>
bool Vector<T>::iterator::operator==(const Vector<T>::iterator& other) const {
    return ptr == other.ptr;
}

template <typename T>
bool Vector<T>::iterator::operator!=(const Vector<T>::iterator& other) const {
    return ptr != other.ptr;
}

template <typename T>
bool Vector<T>::iterator::operator<(const Vector<T>::iterator& other) const {
    return ptr < other.ptr;
}

template <typename T>
bool Vector<T>::iterator::operator<=( const Vector<T>::iterator& other) const {
    return ptr <= other.ptr;
}

template <typename T>
bool Vector<T>::iterator::operator>=(const Vector<T>::iterator& other) const {
    return ptr >= other.ptr;
}

template <typename T>
typename Vector<T>::iterator::difference_type Vector<T>::iterator::operator-(const Vector<T>::iterator& other) {
    return ptr - other.ptr;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return typename Vector<T>::iterator(this->m_data);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return iterator(this->m_data + this->m_size);
}
