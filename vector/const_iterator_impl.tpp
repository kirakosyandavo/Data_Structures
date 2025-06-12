#include "vector_impl.h"
using namespace std;

template <typename T>
typename Vector<T>::const_iterator::reference Vector<T>::const_iterator::operator*() {
    return *ptr;
}

template <typename T>
typename Vector<T>::const_iterator::pointer Vector<T>::const_iterator::operator->() {
    return ptr;
}

template <typename T>
typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator++() {
    ++ptr;
    return *this;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::const_iterator::operator++(int) {
    const_iterator obj(this->ptr);
    ++(*this);
    return obj;
}

template <typename T>
typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator--() {
    --ptr;
    return *this;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::const_iterator::operator--(int) {
    const_iterator obj(this->ptr);
    --ptr;
    return obj;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::const_iterator::operator+(difference_type value) {
    return const_iterator(ptr + value);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::const_iterator::operator-(difference_type value) {
    return const_iterator(ptr - value);
}

template <typename T>
typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator+=(difference_type value) {
    ptr += value;
    return *this;
}

template <typename T>
typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator-=(difference_type value) {
    ptr -= value;
    return *this;
}

template <typename T>
typename Vector<T>::const_iterator::reference Vector<T>::const_iterator::operator[](difference_type value) {
    return ptr[value];
}

template <typename T>
bool Vector<T>::const_iterator::operator==(const const_iterator& other) const noexcept {
    return ptr == other.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator!=(const const_iterator& other) const noexcept {
    return ptr != other.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator<(const const_iterator& other) const noexcept {
    return ptr < other.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator<=(const const_iterator& other) const noexcept {
    return ptr <= other.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator>=(const const_iterator& other) const noexcept {
    return ptr >= other.ptr;
}

template <typename T>
typename Vector<T>::const_iterator::difference_type Vector<T>::const_iterator::operator-(const const_iterator& other) {
    return ptr - other.ptr;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() {
    return const_iterator(this->m_data);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() {
    return const_iterator(this->m_data + this->m_size);
}


