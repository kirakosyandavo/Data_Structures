#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Queue {
private:
    list<T> _data;

public:
    Queue(std::initializer_list<T> init)
  : _data(init.begin(), init.end())
    {}

   Queue& operator=(const Queue& other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}
    T& front() {
    if (_data.empty()) throw runtime_error("queue is empty");
    return _data.front();
}
const T& front() const {
    if (_data.empty()) throw runtime_error("queue is empty");
    return _data.front();
}

T& back() {
    if (_data.empty()) throw runtime_error("queue is empty");
    return _data.back();
}
const T& back() const {
    if (_data.empty()) throw runtime_error("queue is empty");
    return _data.back();
}

    bool empty()const noexcept {
        return _data.empty();
    }

    int size()const noexcept {
        return _data.size();
    }

void enqueue(const T& value) {
    _data.push_back(value);
}

void dequeue() {
    if (_data.empty())
        throw runtime_error("queue is empty");
    _data.pop_front();
}
};
