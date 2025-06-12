#include "vector_impl.h"
using namespace std;

template<typename T>
template<typename Iterator>
typename Vector<T>::template reverse_iterator<Iterator>::pointer Vector<T>::reverse_iterator<Iterator>::operator->() {
    Iterator tmp = current;
    --tmp;
    return tmp.operator->();
}

template<typename T>
template<typename Iterator>
typename Vector<T>::template reverse_iterator<Iterator>::reference Vector<T>::reverse_iterator<Iterator>::operator*() {
    Iterator tmp = current;
    --tmp;
    return *tmp;
}

template<typename T>
template<typename Iterator>
typename Vector<T>::template reverse_iterator<Iterator>& Vector<T>::reverse_iterator<Iterator>::operator++() {
    --current;
    return *this;
}

template<typename T>
template<typename Iterator>
typename Vector<T>::template reverse_iterator<Iterator> Vector<T>::reverse_iterator<Iterator>::operator++(int) {
    reverse_iterator temp = *this;
    --current;
    return temp;
}

template<typename T>
template<typename Iterator>
typename Vector<T>::template reverse_iterator<Iterator>& Vector<T>::reverse_iterator<Iterator>::operator--() {
    ++current;
    return *this;
}

template<typename T>
template<typename Iterator>
typename Vector<T>::template reverse_iterator<Iterator> Vector<T>::reverse_iterator<Iterator>::operator--(int) {
    reverse_iterator temp = *this;
    ++current;
    return temp;
}
