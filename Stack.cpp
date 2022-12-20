//
// Created by bjabo on 12/20/2022.
//

#include "Stack.h"

template<typename T>
Stack<T>::Stack(int si) {
    Size = si;
    index = 0;
    ptr = new T [Size];
    for(int i = 0; i < Size; i++)
        ptr[i] = T();
}

template<typename T>
Stack<T>::Stack(const Stack &another) {
    this->index = another.index;
    this->Size = another.Size;
    this->ptr = new T [this->Size];
    for(int i = 0; i < this->Size; i++)
        this->ptr[i] = another.ptr[i];
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> &another){
    this->index = another.index;
    this->Size = another.Size;
    delete[] this->ptr;
    this->ptr = new T [this->Size];
    for(int i = 0; i < this->Size; i++)
        this->ptr[i] = another.ptr[i];
    return *this;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] ptr;
}

template<typename T>
T Stack<T>::top() {
    if(index <= 0)
        return T();
    return ptr[index - 1];
}

template<typename T>
void Stack<T>::pop() {
    if(index < 1) {
        throw StackEmptyException{"you cannot pop stack is empty"};
        return;
    }
    ptr[index] = T();
    index--;
}

template<typename T>
void Stack<T>::push(T value) {
    if(index >= Size){
        throw StackOverflowException{"stack cannot be expand it reached max elements"};
        return;
    }
    ptr[index] = value;
    index++;
}

template<typename T>
int Stack<T>::size() {
    return Size;
}

template<typename T>
bool Stack<T>::empty() {
    return (index <= 0);
}