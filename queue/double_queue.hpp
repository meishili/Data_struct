#ifndef DOUBLE_QUEUE_HPP
#define DOUBLE_QUEUE_HPP

#include <iostream>
#include <memory>

template<typename Type>
class Double_queue{
    private:
        std::unique_ptr<Type[]> ptr;
        int end;
        int begin;
        int size;
    public:
        Double_queue();
        Double_queue(const int s);
        bool head_push(const Type t);
        bool tail_push(const Type t);
        Type head_dequeue();
        Type tail_dequeue();
        bool isfull();
        bool isempty();
};

template<typename Type>
Double_queue<Type>::Double_queue(){
    end = 0;
    begin = 0;
    size = 0;
}

template<typename Type>
Double_queue<Type>::Double_queue(const int s){
    begin = 0;
    end = 0;
    size = s;
    ptr = std::make_unique<Type[]>(size);
}

template<typename Type>
bool Double_queue<Type>::head_push(const Type t){
    if(this->isfull()){
        return false;
    }
    begin = (begin - 1 + size) % size;
    ptr[begin] = t;
    return true;
}

template<typename Type>
bool Double_queue<Type>::tail_push(const Type t){
    if(this->isfull()){
        return false;
    }
    ptr[end] = t;
    end = (end + 1) % size;
    return true;
}

template<typename Type>
Type Double_queue<Type>::head_dequeue(){
    Type t;
    t = ptr[begin];
    begin = (begin + 1) % size;
    return t;
}

template<typename Type>
Type Double_queue<Type>::tail_dequeue(){
    end = (end - 1 + size) % size;
    return ptr[end];
}

template<typename Type>
bool Double_queue<Type>::isempty(){
    return begin == end;
}

template<typename Type>
bool Double_queue<Type>::isfull(){
    return (end + 1) % size == begin;
}

#endif