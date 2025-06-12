#include "vector_impl.h"
#include <stdexcept>
using namespace std;

template<typename T>
void Vector<T>::reallocate(int new_capacity){
    T* tmp = new T[new_capacity];
    for (int i = 0; i < m_size; i++) {
        tmp[i] = m_data[i];
    }
    delete[] m_data;
    m_data = tmp;
}

template<typename T>
T Vector<T>::at(int index) const {
    if (index >= m_size || index < 0) {
        throw std::out_of_range("out");
    }
    return m_data[index];
}

template<typename T>
T Vector<T>::at(int index) {
    if (index >= m_size || index < 0) {
        throw std::out_of_range("out");
    return m_data[index];
}
}

template <typename T>
void Vector<T>::push_back(T index){
    if (m_capacity == 0) {
        m_capacity = 2;
        reallocate(m_capacity);
    }
    if (m_size == m_capacity) {
        m_capacity *= 2;
        reallocate(m_capacity);
    }
    m_data[m_size++] = index;
}

template<typename T>
void Vector<T>::pop_back(){
    if (m_size > 0) {
        m_size--;
    }
}

template<typename T>
int Vector<T>::getSize() const noexcept {
    return m_size;
} 

template<typename T>
int Vector<T>::getCap() const noexcept {
    return m_capacity;
}

template<typename T>
void Vector<T>::resize(int n){
    if (n > m_capacity) {
        reserve(n);
    }
    if (n > m_size) {
        std::fill(m_data + m_size, m_data + n, T{});
    }
    m_size = n;
}

template<typename T>
void Vector<T>::reserve(int new_cap){
    reallocate(new_cap);
    m_capacity = new_cap;
    if (new_cap < m_size) {
        m_size = new_cap;
    }
}

template<typename T>
T Vector<T>::front() const {
    if (m_size == 0) {
        throw std::out_of_range("out");
    }
    return m_data[0];
}

template<typename T>
T Vector<T>::back() const {
    if (m_size == 0) {
        throw std::out_of_range("out");
    }
    return m_data[m_size - 1];  
}

template<typename T>
bool Vector<T>::isEmpty() const {
    return m_size == 0;
}

template<typename T>
void Vector<T>::shrink_to_fit() {
    m_capacity = m_size;
    reallocate(m_size);
}

template<typename T>
void Vector<T>::insert(int index, T value){
    if (index < 0 || index > m_size) {
        throw std::out_of_range("out");
    }

    if (m_size == m_capacity) {
        m_capacity *= 2;
        reallocate(m_capacity);
    }
    for (int i = m_size; i > index; --i) {
        m_data[i] = m_data[i - 1];
    }
    m_data[index] = value;
    ++m_size;
}

template<typename T> 
void Vector<T>::erase(int index){
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("out");
    }
    for (int i = index; i < m_size - 1; i++) {
        m_data[i] = m_data[i + 1];
    }
    --m_size;
}

template<typename T>
void Vector<T>::clear(){
    m_size = 0;
    m_capacity = 0;
    delete[] m_data;
    m_data = nullptr;
}

template<typename T>
void Vector<T>::print(){
    for (int i = 0; i < m_size; i++) {
        cout << m_data[i] << "\t";
    }
}
