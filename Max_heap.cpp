#include <iostream>
#include <vector>
using namespace std;

int parent(int index) {
    return (index - 1) / 2;
}

int left(int index) {
    return 2 * index + 1;
}

int right(int index) {
    return 2 * index + 2;
}

template <typename T>
void max_heapify(vector<T>& vec, int index) {
    int largest = index;
    int l = left(index);
    int r = right(index);
    int n = vec.size();

    if (l < n && vec[l] > vec[index]) {
        largest = l;
    }
    if (r < n && vec[r] > vec[largest]) {
        largest = r;
    }
    if (index != largest) {
        swap(vec[index], vec[largest]);
        max_heapify(vec, largest);
    }
}

template <typename T>
void heapify_up(vector<T>& vec, int index) {
    while (index > 0) {
        int par = parent(index);
        if (vec[index] > vec[par]) {
            swap(vec[index], vec[par]);
            heapify_up(vec, par);
        } else {
            break;
        }
    }
}

template <typename T>
class Max_heap {
private:
    vector<T> vec;

public:
    Max_heap(vector<T>& vee) {
        vec = vee;
        build_heap();
    }

    void push(T value) {
        vec.push_back(value);
        heapify_up(vec, vec.size() - 1);
    }

    T extract_max() {
        T value = vec[0];
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        max_heapify(vec, 0);
        return value;
    }

    T& peek() {
        return vec[0];
    }

    void build_heap() {
        int n = vec.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            max_heapify(vec, i);
        }
    }

    int size() {
        return vec.size();
    }

    bool is_empty() {
        return size() == 0;
    }
};

int main() {
    vector<int> vec {15, 85, 69, 2, 4};
    Max_heap<int> heap(vec);

    cout << heap.is_empty() << endl;
    cout << heap.peek() << endl;

    heap.extract_max();
    cout << heap.peek() << endl;
}
