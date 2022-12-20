#ifndef TASK_8_STACK_H
#define TASK_8_STACK_H
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
private:
    int Size{};
    int index{};
    T* ptr;

public:
    explicit Stack(int Size = 0);
    Stack(Stack const &another);
    Stack& operator=(const Stack<T> &another);
    ~Stack();
    T top();
    void pop();
    void push(T value);
    int size();
    bool empty();
};


class StackEmptyException{
private:
    string messege;
public:
    StackEmptyException(string s):messege(s){}
    string what(){
        return messege;
    }
};


class StackOverflowException{
private:
    string messege;
public:
    StackOverflowException(string s):messege(s){}
    string what(){
        return messege;
    }
};

#endif //TASK_8_STACK_H
