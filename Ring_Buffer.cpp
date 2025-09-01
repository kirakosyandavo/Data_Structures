#include<iostream>
#include<memory>
#include<stdexcept>

template<typename T>
class Ring_Buffer{
size_t head;
size_t tail;
size_t capacity;
size_t count;
std::unique_ptr<T[]>data;
public:
explicit Ring_Buffer(size_t m_capacity):capacity{m_capacity},count{0},head{0},tail{0},data{std::make_unique<T[]>(m_capacity)}{}

Ring_Buffer(Ring_Buffer&& other) noexcept{
    data = std::move(other.data);
    head = other.head;
    tail = other.tail;
    count = other.count;
    capacity = other.capacity;

}

Ring_Buffer& operator=(Ring_Buffer&& other) noexcept{
       if(this == &other) {
        return *this;
       }
    data = std::move(other.data);
    head = other.head;
    tail = other.tail;
    capacity = other.capacity;
    count = other.count;
    return *this;     
}

bool is_full() const noexcept{
    return capacity == count;
}

bool empty() const noexcept{
    return count == 0;
} 

size_t size() const noexcept{
    return count;
}

size_t m_capacity()const {
    return capacity;
}

void push_back(const T& value) {
   if(is_full()) {
     throw std::overflow_error("your ring is full");
   }
   count++;
   data[head] = value;
   head = (head+1)%capacity;
} 

void push_back(T&& value) {
     if(is_full()) {
     throw std::overflow_error("your ring is full");
   }
   count++;
   data[head] = std::move(value);
   head = (head+1) % capacity;
} 

void pop_front() {
    if(empty()){
        throw std::underflow_error ("you not have element");
    }
    tail = (tail+1)%capacity;
    count--;
}

T& front() {
    return data[tail];
}
 
const T& front() const {
   return data[tail];

}
 
T& back() {
    return data[(head+capacity-1)%capacity]; 
}

const T& back() const {
 return data[(head+capacity-1)%capacity];
}

T& operator[](size_t index) {
    return data[(tail+index) % capacity];
}

const T& operator[](size_t index) const {
    return data[(tail+index) % capacity];
}
void print(){
    for(int i = 0; i<count ;i++){
        std::cout<<data[(tail+i)%capacity]<<std::endl;
    }
}
void clear()noexcept {
    tail = head = 0;
    count = 0;
}
};