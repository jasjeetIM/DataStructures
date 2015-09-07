#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack
{
private:
     vector <T> arr;


public:
    Stack();
    T top ();
    void pop ();
    void push (T const&a);
    bool isEmpty();
    int size();
};

template <class T>
Stack<T>:: Stack()
{
    vector<T> arr;
}

template <class T>
T Stack<T>::top ()
{
    if (arr.back())
    return arr.back();
}

template <class T>
void Stack<T>:: pop()
{
    arr.pop_back();
}


template <class T>
void Stack<T>:: push(T const&a)
{
    arr.push_back(a);
}

template <class T>
bool Stack<T>:: isEmpty()
{
    return arr.empty();
}

template <class T>
int Stack<T>::size()
{
    return arr.size();
}

int main ()
{
    Stack <int> myStack;
    myStack.push(10);
    myStack.push(9);
    myStack.push(8);
    myStack.push(7);
    myStack.push(6);
    myStack.push(5);
    myStack.push(4);
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);

    int j = myStack.size();

    for (int i=0; i < j ; i++)
    {
        cout << myStack.top() << "Hello" << endl;
        myStack.pop();
    }


    return 0;
}











