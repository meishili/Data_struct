#ifndef STACK_HPP
#define STACK_HPP

#include <memory>

template<typename Type>
class Stack{
    private:
        std::unique_ptr<Type[]> ptr;
        int size;
        int top;
    public:
        Stack();
        Stack(int n);
        ~Stack();
        void push(Type t);
        Type pop();
        bool isempty();
        bool isfull();
};

template<typename Type>
Stack<Type>::Stack(){
    size = 0;
    top = 0;
}

template<typename Type>
Stack<Type>::Stack(int n){
    size = n;
    top = 0;
    ptr = std::make_unique<Type[]>(size);
}

template<typename Type>
Stack<Type>::~Stack(){
    size = 0;
    top = 0;
}

template<typename Type>
void Stack<Type>::push(Type t){
    ptr[top] = t;
    top++;
}

template<typename Type>
Type Stack<Type>::pop(){
    top--;
    return ptr[top];
}

template<typename Type>
bool Stack<Type>::isfull(){
    return top == size;
}

template<typename Type>
bool Stack<Type>::isempty(){
    return top == 0;
}

#endif