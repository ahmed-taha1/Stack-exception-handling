#include <iostream>
#include "Stack.cpp"
using namespace std;

template<typename T>
void manageStack(){
    int size = 0, choose = -1;
    T x = T();
    while (size <= 0){
        cout << "please enter the stack size which is greater than zero\n";
        cout << ">> ";
        cin >> size;
    }
    system("cls");
    Stack<T> stack1(size);
    while (choose != 6){
        cout <<"\n\t\tplease choose operation\n";
        cout <<"1- push\n";
        cout <<"2- pop\n";
        cout <<"3- top\n";
        cout <<"4- is empty\n";
        cout <<"5- size\n";
        cout <<"6- exit\n";
        cout <<">> ";
        cin >> choose;

        switch (choose) {
            case 1:
                try {
                    cout << "please enter the value : ";
                    cin >> x;
                    stack1.push(x);
                }
                catch (StackOverflowException ex){
                    cout << ex.what();
                }
                break;

            case 2:
                try{
                    stack1.pop();
                }
                catch (StackEmptyException ex){
                    cout << ex.what();
                }
                break;

            case 3:
                cout << stack1.top() << '\n';
                break;

            case 4:
                cout <<stack1.empty() << '\n';
                break;

            case 5:
                cout << stack1.size() << '\n';
                break;

            default:
                cout << "wrong choice please try again\n";
                break;
        }
    }
}

int main() {
    int choose = -1;
    while (choose <= 0 || choose > 3){
        cout << "please choose stack type:\n";
        cout << "1- int\n";
        cout << "2- string\n";
        cout << "3- float\n";
        cout << "4- char\n";
        cout << ">> ";
        cin >> choose;
    }
    switch (choose) {
        case 1:
            manageStack<int>();
            break;
        case 2:
            manageStack<string>();
            break;
        case 3:
            manageStack<float>();
            break;
        case 4:
            manageStack<char>();
            break;
        default:
            cout << "wrong choose\n";
            break;
    }
}