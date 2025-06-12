#include "list_impl.tpp"

template <typename T>
template <typename Iter>
typename List<T>::template reverse_iterator<Iter>::pointer
List<T>::reverse_iterator<Iter>::operator->() {
    return iterat.operator->();
}

template <typename T>
template <typename Iter>
typename List<T>::template reverse_iterator<Iter>::reference
List<T>::reverse_iterator<Iter>::operator*() {
    return *iterat;
}

template <typename T>
template <typename Iter>
typename List<T>::template reverse_iterator<Iter>&
List<T>::reverse_iterator<Iter>::operator=(const reverse_iterator& other) {
    iterat = other.iterat;
    return *this;
}

template <typename T>
template <typename Iter>
typename List<T>::template reverse_iterator<Iter>&
List<T>::reverse_iterator<Iter>::operator++() {
    --iterat;
    return *this;
}

template <typename T>
template <typename Iter>
typename List<T>::template reverse_iterator<Iter>
List<T>::reverse_iterator<Iter>::operator++(int) {
    reverse_iterator temp = *this;
    --iterat;
    return temp;
}

template <typename T>
template <typename Iter>
typename List<T>::template reverse_iterator<Iter>&
List<T>::reverse_iterator<Iter>::operator--() {
    ++iterat;
    return *this;
}

template <typename T>
template <typename Iter>
typename List<T>::template reverse_iterator<Iter>
List<T>::reverse_iterator<Iter>::operator--(int) {
    reverse_iterator temp = *this;
    ++iterat;
    return temp;
}
