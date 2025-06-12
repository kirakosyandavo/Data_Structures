#pragma once
#include "list_impl.h"
using namespace std;

template <typename T>
void List<T>::push_back(const T& value) {
    if (head == nullptr) {
        head = tail = new Node(value);
        size++;
    } else {
        tail->next = new Node(value);
        tail->next->prev = tail;
        tail = tail->next;
        size++;
    }
}

template <typename T>
void List<T>::push_front(const T& value) {
    if (!head) {
        head = tail = new Node(value);
    } else {
        head->prev = new Node(value);
        head->prev->next = head;
        head = head->prev;
    }
    size++;
}

template <typename T>
void List<T>::pop_back() {
    if (!tail) {
        return;
    }

    if (head == tail) {
        Node* temp = head;
        head = tail = nullptr;
        --size;
        delete temp;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        --size;
        delete temp;
    }
}

template <typename T>
void List<T>::pop_front() {
    if (!tail) {
        return;
    }
    if (tail == head) {
        delete head;
        head = tail = nullptr;
        size--;
    } else {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        size--;
    }
}

template <typename T>
void List<T>::clear() noexcept {
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = tail = nullptr;
    size = 0;
}

template <typename T>
bool List<T>::empty() const noexcept {
    return size == 0;
}

template <typename T>
void List<T>::print_forward() {
    Node* current = head;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

template <typename T>
void List<T>::print_backward() {
    Node* current = tail;
    while (current) {
        cout << current->data;
        current = current->prev;
    }
}

template <typename T>
int List<T>::get_size() {
    return size;
}
