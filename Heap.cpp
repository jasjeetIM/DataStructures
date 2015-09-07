/* Minimum Binary Heap */

#include <iostream>
using namespace std;

/* #ifndef HEAPITEM_H
   #define HEAPITEM_H

*/

template <class T, class K>
class HeapItem
{
private:
    T key;
    K data;

public:
    HeapItem();
    HeapItem(T key, K data);
    ~HeapItem();
    void setKey (T ke);
    void setData (K data);
    T getKey();
    K getData();
    HeapItem<T,K>& operator=(const HeapItem<T,K> &item);
};

// #endif


// HeapItem.cpp

template <class T, class K>
HeapItem<T,K>:: HeapItem()
{
    T key = NULL;
    K Data = NULL;
}
template <class T, class K>
HeapItem<T,K>:: HeapItem(T ke, K dat)
{
    key = key;
    data = data;
}

template <class T, class K>
HeapItem<T,K>:: ~HeapItem()
{
  // No memory assigned on the heap therefore nothing needs to be deleted
}

template <class T, class K>
void HeapItem<T,K>::setKey(T ke)
{
    key = ke;
}

template <class T, class K>
void HeapItem<T,K>:: setData(K dat)
{
    data = dat;
}

template <class T, class K>
T HeapItem<T,K>:: getKey()
{
        return key;
}

template <class T, class K>
K HeapItem<T,K>::getData()
{
    return data;
}

template <class T, class K>
HeapItem<T,K>& HeapItem<T,K>::operator=(const HeapItem<T,K> &item)
{
    // check for self assignment
    if (this = &item) return *this;

    else
    {
        key = item.key;
        data = item.data;

        return *this;
    }

}

/* ifndef# Heap_H
   define# Heap_H

   // #include "HeapItem.h"

*/
template <class T, class K>
class Heap
{
private:
    HeapItem<T,K> * arr;    // array of heap items allocated dynamically in heap memory
    int num_elements;       // total number of elements in the heap
    int heap_size;          // maximum capacity of the heap

public:
    Heap(int size); //  constructor based on the size of the array
    Heap(HeapItem<T,K> * arr); // constructor that will build a minimum heap
    void heapUp(int root, int bottom); // Heapify after adding an item
    void heapDown(int root, int bottom); // Heapify after removing an item
    bool addItem(HeapItem<T,K> * item); // Add item to the heap
    bool addItem(T key, K data); // Construct a heapItem and then add it to the heap
    HeapItem<T,K> * getMinItem(); // get the minimum item in the heap
    int num_element();
    void printAll(); // print all the items in the heap
};

// #endif


// Heap.cpp
// #include "Heap.h"

template <class T, class K>
Heap<T,K>:: Heap(int size)
{
    heap_size = size;
    arr = new HeapItem<T,K>[heap_size];
    num_elements = 0;
}

template <class T, class K>
Heap<T,K>:: Heap(HeapItem<T,K> * arr)
{
    // to be implemented later
}

template <class T, class K>
Heap<T,K>:: ~Heap()
{
    delete [] arr;
}

template <class T, class K>
void Heap<T,K>:: heapDown(int root, int bottom)
{

    // Since we remove items at the root, we only need to heapDown

    int min_child, l_child, r_child;
    HeapItem<T,K> temp;

    l_child = (root*2)+1;
    r_child = (root*2)+2;

    //Base Case -- check to see if left child is the last element in the heap

    if (l_child <=bottom)
    {


    if (l_child = botttom) min_child = l_child; // the root node does not have any right child;

    else
    {
        if (arr[l_child].getKey() <= arr[r_child].getKey()) min_child = l_child;

        else if (arr[r_child].getKey() < arr[l_child].getKey()) min_child = r_child;


    }

     if (arr[root].getKey() > arr[min_child].getKey())
        {
            temp = arr[root];
            arr[root] = arr[min_child];
            arr[min_child] = temp;
            heapDown(min_child, bottm);

        }

    }


}

template <class T, class K>
void Heap<T,K> ::heapUp (int root, int bottom)
{
    HeapItem<T,K> temp;
    int parent;

    if (bottom > root ) // This is the base case since an index equal to or lower than the root will not need to be swapped
    {
        parent = (bottom -1)/2;

        if (arr[parent].getKey() > arr[bottom].getKey())
        {
            temp = arr[parent];
            arr[parent] = arr[bottom];
            arr[bottom] = temp;
            heapUp(root, parent);
        }

    }

}

template<class T, class K>
bool Heap<T,K>:: addItem(HeapItem<T,K> * item)
{
    if (num_elements < heap_size)
    {

        arr[num_elements] = *item;
        heapUp(0, num_elements);
        num_elements++;
        return true;

    }

    else return false;

}


template <class T, class K>
bool Heap<T,K>:: addItem(T ke, K dat)
{
    if (num_elements < arr_size)
    {
            HeapItem<T,K> * item;
            item = new HeapItem<T,K>(ke,dat);

            arr[num_elements] = *item;
            heapUp(0, num_elements);
            num_elements++;
            delete item;
            return true;
    }

    else return false;

}

template <class T, class K>
HeapItem<T,K> * Heap<T,K>::getMinItem()
{

        if (num_elements == 0)
        {
            return NULL;
        }
        else
        {
            HeapItem<T,K> * item = new HeapItem<T,K>(arr[0].getKey(), arr[0].getData());
            num_elements--;
            arr[0] = arr[num_elements];
            heapDown(0, num_elements -1);
            return item;
        }
}

template <class T, class K>
int Heap<T,K>::num_element()
{
    return num_elements;
}

template <class T, class K>
void Heap<T,K>::printAll()
{
    for (int i = 0; i < num_elements; i++)
    {
        cout << "Heap Element " << i << ": Key = " << arr[i].getKey() << "; Data = " << arr[i].getData() << endl;
    }

}

// #include "Heap.h"
// #include "HeapItem.h"

int main ()
{

    Heap<int, string> * myHeap = new Heap(10);

    myHeap->addItem(1, "Test1");
    myHeap->addItem(2, "Test2");
    myHeap->addItem(3,"Test3");
    myHeap->addItem(4, "Test4");
    myHeap->addItem(5, "Test5");
    myHeap->addItem(6, "Test6");
    myHeap->addItem(7, "Test7");
    myHeap->addItem(8,"Test8");
    myHeap->addItem(9, "Test9");
    myHeap->addItem(10, "Test10");

    myHeap->printAll();

    return 0;

}
