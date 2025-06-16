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
void min_heapify(vector<T>& vec, int index) {
    int smallest = index;
    int l = left(index);
    int r = right(index);
    int n = vec.size();

    if (l < n && vec[l] < vec[index]) {
        smallest = l;
    }
    if (r < n && vec[r] < vec[smallest]) {
        smallest = r;
    }
    if (index != smallest) {
        swap(vec[index], vec[smallest]);
        min_heapify(vec, smallest);
    }
}

template <typename T>
void heapify_down(vector<T>& vec, int index) {
    while (index > 0) {
        int par = parent(index);
        if (vec[index] < vec[par]) {
            swap(vec[index], vec[par]);
            heapify_down(vec, par);
        } else {
            break;
        }
    }
}

template <typename T>
class Min_heap {
private:
    vector<T> vec;

public:
    Min_heap(vector<T>& vee) {
        vec = vee;
        build_heap();
    }

    void push(T value) {
        vec.push_back(value);
        heapify_down(vec, vec.size() - 1);
    }

    T extract_min() {
        T value = vec[0];
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        min_heapify(vec, 0);
        return value;
    }

    T& peek() {
        return vec[0];
    }

    void build_heap() {
        int n = vec.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            min_heapify(vec, i);
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
    Min_heap<int> heap(vec);

    cout << heap.is_empty() << endl;
    cout << heap.peek() << endl;

    heap.extract_min();
    cout << heap.peek() << endl;
}
