#include<iostream>
using namespace std;

template <typename T>
class Stack {
    T *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    void push(T element) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = element;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }

    void change(int index, T val) {
        int actualindex = top - index + 1;
        if (actualindex <= top && actualindex >= 0) {
            arr[actualindex] = val;
        } else {
            cout << "Invalid index_no" << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack is:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack<int> st(10);
    int code, val, index_no;

    while (1) {
        cout << "Enter 1 for push, 2 for pop, 3 for change, 4 for display:" << endl;
        cin >> code;

        switch (code) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                st.push(val);
                break;

            case 2:
                st.pop();
                break;

            case 3:
                cout << "Enter index_no from top and value to change respectively: ";
                cin >> index_no >> val;
                st.change(index_no, val);
                break;

            case 4:
                st.display();
                break;

            default:
                cout << "Invalid code" << endl;
                break;
        }
    }

    return 0;
}
