#include <iostream>
#include <functional>
using namespace std;

template <typename T>
class My_Custom_Allocator {
    using value = T;

    template <typename U>
    struct rebind {
        using other = My_Custom_Allocator<U>;
    };

public:
    T* allocate(int n) {
        cout << "you called allocator" << endl;
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p) {
        cout << "you called deallocator";
        ::operator delete(p);
    }

    template <typename U, typename... Args>
    void construct(U* point, Args&&... args) {
        ::new ((void*)point) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destruct(U* p) {
        p->~U();
    }
};

template <typename T, typename U>
bool operator==(My_Custom_Allocator<T>&, My_Custom_Allocator<U>&) {
    return true;
}

template <typename T, typename U>
bool operator!=(My_Custom_Allocator<T>&, My_Custom_Allocator<U>&) {
    return false;
}

template <typename Keys, typename Values, typename Alloc = My_Custom_Allocator<Values>>
class Unordered_map {
    struct Node {
        Keys key;
        Values value;
        Node* next;

        Node(const Keys& k, const Values& v)
            : key{k}, value{v}, next{nullptr} {}
    };

    int m_size = 13;
    Node** table;
    int count = 0;
    static constexpr double max_load_factor = 1.0;

    int hash_function(Keys value, int size) {
        std::hash<Keys> hasher;
        return hasher(value) % size;
    }

public:
    using NodeAlloc = typename Alloc::template rebind<Node>::other;

    Unordered_map() {
        table = new Node*[m_size];
        for (int i = 0; i < m_size; ++i) {
            table[i] = nullptr;
        }
        count = 0;
    }

    void insert(Keys keys, Values values) {
        if (load_factor() >= max_load_factor) {
            rehash();
        }

        int index = hash_function(keys, m_size);
        if (table[index] == nullptr) {
            table[index] = new Node(keys, values);
            ++count;
            return;
        }

        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == keys) {
                temp->value = values;
                return;
            }
            temp = temp->next;
        }

        Node* new_node = new Node(keys, values);
        new_node->next = table[index];
        table[index] = new_node;
        ++count;
    }

    bool erase(const Keys& keys) {
        int index = hash_function(keys, m_size);
        if (table[index] == nullptr) {
            return false;
        }

        Node* curr = table[index];
        if (curr->key == keys) {
            table[index] = curr->next;
            delete curr;
            --count;
            return true;
        }

        Node* prev = nullptr;
        while (curr != nullptr && curr->key != keys) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            return false;
        }

        prev->next = curr->next;
        delete curr;
        --count;
        return true;
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    void clear() {
        for (int i = 0; i < m_size; ++i) {
            Node* cur = table[i];
            while (cur) {
                Node* nxt = cur->next;
                delete cur;
                cur = nxt;
            }
            table[i] = nullptr;
        }
        count = 0;
    }

    Node* find(Keys keys) {
        int index = hash_function(keys, m_size);
        Node* temp = table[index];

        while (temp != nullptr) {
            if (temp->key == keys) {
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }

    bool contains(Keys keys) {
        int index = hash_function(keys, m_size);
        Node* ptr = table[index];

        while (ptr != nullptr) {
            if (ptr->key == keys) {
                return true;
            }
            ptr = ptr->next;
        }

        return false;
    }

    float load_factor() const {
        return static_cast<float>(count) / m_size;
    }

    void rehash() {
        cout << "called rehash" << endl;
        int new_size = m_size * 2;
        Node** new_table = new Node*[new_size];

        for (int i = 0; i < new_size; ++i) {
            new_table[i] = nullptr;
        }

        for (int i = 0; i < m_size; ++i) {
            Node* t = table[i];
            while (t) {
                int index = hash_function(t->key, new_size);
                Node* new_node = new Node(t->key, t->value);
                new_node->next = new_table[index];
                new_table[index] = new_node;
                t = t->next;
            }
        }

        for (int i = 0; i < m_size; ++i) {
            Node* curr = table[i];
            while (curr) {
                Node* nxt = curr->next;
                delete curr;
                curr = nxt;
            }
        }

        delete[] table;
        table = new_table;
        m_size = new_size;
    }

    ~Unordered_map() {
        clear();
        delete[] table;
    }
};

