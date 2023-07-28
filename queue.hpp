#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <memory>

template<typename Type>
class Queue{
    private:
        int size;
        int start;
        int end;
        std::unique_ptr<Type[]> ptr;
    public:
        Queue();
        Queue(int n);
        ~Queue();
        void push(Type t);
        Type pop();
        bool isfull();
        bool isempty();
};

template<typename Type>
Queue<Type>::Queue(){
    size = 0;
    start = 0;
    end = 0;
}

template<typename Type>
Queue<Type>::Queue(int n){
    size = n + 1;
    start = 0;
    end = 0;
    ptr = std::make_unique<Type[]>(size);
}

template<typename Type>
Queue<Type>::~Queue(){
    size = 0;
    start = 0;
    end = 0;
}

template<typename Type>
void Queue<Type>::push(Type t){
    ptr[end] = t;
    end = (end + 1) % size;
}

template<typename Type>
Type Queue<Type>::pop(){
    int temp = start;
    start = (start + 1) % size;
    return ptr[temp];
}

template<typename Type>
bool Queue<Type>::isempty(){
    return start == end;
}

template<typename Type>
bool Queue<Type>::isfull(){
    return (end + 1) % size == start;
}
#endif