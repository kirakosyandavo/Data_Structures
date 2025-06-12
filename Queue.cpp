#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Queue {
private:
    list<T> list;

public:
    Queue(initializer_list<T> list) {
        for (const T& val : list) {
            list.push_back(val);
        }
    }

    Queue& operator=(Queue& other) {
        list = other.list;
    }

    T& front() {
        if (list.empty()) {
            throw runtime_error("queue is empty");
        }
        return list.front();
    }

    T& back() {
        if (list.is_empty()) {
            throw runtime_error("queue is empty");
        }
        return list.back();
    }

    bool empty() {
        return list.empty();
    }

    int size() {
        return list.size();
    }

    void dequeue() {
        if (data.empty()) {
            throw runtime_error("queue is empty");
        }
        list.push_back();
    }

    void enqueue(const T& value) {
        if (data.empty()) {
            throw runtime_error("queue is empty");
        }
        list.pop_front();
    }
};
