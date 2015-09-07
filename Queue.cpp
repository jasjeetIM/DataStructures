#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    int max_size;
    T * arr;
    int q_size, tail_index, head_index;
public:
    Queue(int size);
    ~Queue();
    void enQueue(T item);
    void deQueue();
    T head();
    int size() {return q_size; }
    bool isEmpty();
    int capacity();

};

template <class T>
Queue<T>::Queue(int mSize)
{
    max_size = mSize;
    q_size = 0;
    arr = new T[max_size];
    head_index = 0;
    tail_index = -1;
}


template <class T>
Queue<T>::~Queue()
{
    delete [] arr;
}

template <class T>
void Queue<T>::enQueue(T item)
{
    if (q_size == max_size)
    {
        cout << "Cannot add any more items" << endl;
    }

    else
    {
        arr[(tail_index + 1) %  max_size] = item;
        q_size++;
        tail_index++;
    }
}

template <class T>
void Queue<T>:: deQueue()
{
    if (q_size == 0) return;
    else if (q_size == 1) q_size--;
    else {
         head_index = (head_index + 1 ) %max_size;
         q_size--;
    }
}

template <class T>
bool Queue<T>:: isEmpty()
{
    if (q_size == 0) return true;
    return false;

}

template <class T>
T Queue<T>:: head()
{
    return arr[head_index];
}

template <class T>
int Queue<T>:: capacity()
{
    return max_size;
}



int main ()
{

    Queue<int> myQ(10);
    cout << myQ.capacity() << endl;
    for (int i = 0; i < myQ.capacity(); i++) myQ.enQueue(i);

    for (int m = 0; m <10; m++)
    {
        cout << myQ.head() << endl;
        myQ.deQueue();
    }

    return 0;


}
