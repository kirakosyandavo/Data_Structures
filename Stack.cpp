#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack {
private:
    vector<T> vec;

public:
    Stack(const initializer_list<T>& list) {
        for (T& val : list) {
            vec.push_back(val);
        }
    }

    Stack& operator=(Stack& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    bool empty() {
        return vec.size() == 0;
    }

    int size() {
        return vec.size();
    }

    T& top() {
        if (vec.empty()) {
            throw runtime_error("Stack is empty");
        }
        return vec[vec.size() - 1];
    }

    void push(T& obj) {
        vec.push_back(obj);
    }

    void pop() {
        vec.pop_back();
    }

    void swap(Stack& other) {
        swap(vec, other.vec);
    }

    ~Stack() {
        vec.clear();
    }
};
