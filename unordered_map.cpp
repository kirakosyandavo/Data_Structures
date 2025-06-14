#include <iostream>
#include <functional>
using namespace std;
template<typename T>
class My_Custom_Allocator{
using value = T;
template<typename U>
struct rebind{
    using other=My_Custom_Allocator<U>;
};
T* allocate(int n){
    cout<<"you called allocator"<<endl;
    return static_cast<T*>(::operator new(n*sizeof(T)));
}
void deallocate(T* p){
    cout<<"you called deallocator";
    ::operator delete(p);
}
template<typename U,typename... Args>
void construct(U* point,Args&&... args){
    ::new((void*)point)U(std::forward<Args>(args)...);
}
template<typename U>
void destruct(U* p){
    p->~U();
}  
};
template<typename T,typename U>
bool operator == (My_Custom_Allocator<T>& a,My_Custom_Allocator<U>& b){
       return true;
 }
 template<typename T,typename U>
 bool operator != (My_Custom_Allocator<T>& a,My_Custom_Allocator<U>& b){
    return false;
 }





template<typename Keys, typename Values,typename Alloc = My_Custom_Allocator<Values>>
class Unordered_map {
    struct Node {
        Keys key;
        Values value;
        Node* next;
        Node(const Keys& k, const Values& v) : key{k}, value{v}, next{nullptr} {}
    };

    int m_size = 13;
    Node** table;
    int count = 0;
    static constexpr double max_load_factor=1.0;

    int hash_function(Keys value,int size) {
        std::hash<Keys> hashs;
        int temp = hashs(value);
        temp = temp % size;
        return temp;
    }

public:
using NodeAlloc = typename Alloc::template rebind<Node>::other;
    Unordered_map() {
        table = new Node*[m_size];
        for (int i = 0; i < m_size; i++) {
            table[i] = nullptr;
        }
        count = 0;
    }

    void insert(Keys keys, Values values) {
        if (load_factor() >= max_load_factor) {
              rehash();
        }
        int index = hash_function(keys,m_size);
        if (table[index] == nullptr) {
            table[index] = new Node(keys, values);
            count++;
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
        Node* t = new Node(keys, values);
        t->next = table[index];
        table[index] = t;
        count++;
        return;
    }

    bool erase(const Keys& keys) {
        int index = hash_function(keys,m_size);
        if (table[index] == nullptr) {
            return false;
        }
        Node* tmp = table[index];
        Node* temp = table[index];
        if (temp->key == keys) {
            table[index] = temp->next;
            delete temp;
            count--;
            return true;
        }
        while (temp != nullptr && temp->key != keys) {
            tmp = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            return false;
        } else {
            tmp->next = temp->next;
            delete temp;
            count--;
            return true;
        }
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    void clear() {
        for (int i = 0; i < m_size; i++) {
            if (table[i] != nullptr) {
                Node* tmp = table[i];
                Node* temp = table[i];
                while (temp != nullptr) {
                    tmp = temp;
                    temp = temp->next;
                    delete tmp;
                }
                table[i] = nullptr;
            }
        }
        count = 0;
    }

    Node* find(Keys keys) {
        int index = hash_function(keys,m_size);
        if (table[index] == nullptr) {
            return nullptr;
        }
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == keys) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
 bool contains(Keys keys){
    int index=hash_function(keys,m_size);
    if (table[index] == nullptr) {
         return false;
    }
    Node* ptr = table[index];
    while (ptr != nullptr){
        if (ptr->key == keys) {
            return true;
        }
        ptr=ptr->next;
    }
    return false;

 }   
  float load_factor()const {
    return (double)count/m_size;
  }    
  void rehash(){
    cout << "called rehash"<<endl;
    int new_size = m_size * 2;
     Node** temp = new Node* [new_size];
     for (int i = 0;i < new_size;i++) {
        temp[i] = nullptr;  
     }
        for (int i = 0; i < m_size; ++i) {
        Node* t = table[i];
        while (t) {
            int index = hash_function(t->key,new_size);
            Node* new_node = new Node(t->key, t->value);
            new_node->next = temp[index];
            temp[index] = new_node;

            t = t->next;
        }
    }  
        for(int i = 0;i < m_size;i++){
        if (table[i] != nullptr ){
            Node* temp1 = table[i];
            Node* temp2 = temp1->next;
            while( temp2 != nullptr ){
                delete temp1;
                temp1 = temp2;
                temp2 = temp2->next;
            }
            delete temp1;
            
         }
        }
         delete []table;
     
     table = temp;
     m_size = new_size;
  } 
};
int main(){
 
}










