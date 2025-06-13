#include <iostream>
#include <functional>
using namespace std;

template<typename Keys, typename Values>
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

    int hash_function(Keys value) {
        std::hash<Keys> hashs;
        int temp = hashs(value);
        temp = temp % m_size;
        return temp;
    }

public:
    Unordered_map() {
        table = new Node*[m_size];
        for (int i = 0; i < m_size; i++) {
            table[i] = nullptr;
        }
        count = 0;
    }

    void insert(Keys keys, Values values) {
        int index = hash_function(keys);
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
        int index = hash_function(keys);
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
        int index = hash_function(keys);
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
    int index=hash_function(keys);
    if (table[index] == nullptr) {
         return false;
    }
    Node* ptr = table[index];
    while (ptr != nullptr){
        if (ptr->key == keys) {
            return true;
        }
    }
    return false;

 }   
  float load_factor()const {
    return (double)count/m_size;
  }    
  void rehash(){
     Node** temp = new Node* [m_size*2];
     for(int i=0;i<m_size;i++){
        
     }   


  } 
};
int main(){
 Unordered_map<int,string> maps;
 maps.insert(12,"hello");
 maps.insert(14,"help");
 maps.erase(15);
 cout<<maps.contains(12)<<endl;
}










