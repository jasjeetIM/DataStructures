/* This is the implementation of a balanced Binary Tree */

#include <iostream>
using namespace std;

/* #ifndef NODE_H
 * #define NODE_H
*/

template <class T, class K>
class Node
{
private:
    T key;
    K data;
    Node * l_ptr;
    Node * r_ptr;

public:
    Node(); // Default constructor
    Node(T key, K data); // parametrized constructor with both values
    Node (T key); // parametrized constructor with one value
    Node(const Node & nod); // copy constructor
    ~Node(); // destructor
    void setKey(T key);
    void setData(K data);
    void setLeft(Node* left){ l_ptr = left; }
    void setRight(Node * right) {r_ptr = right; }
    void getLeft() { return l_ptr; }
    void getRight() {return r_ptr; }
    T getKey();
    K getData();
    Node& operator=(const Node& nod); // assignment operator
};

//#endif

// #include "Node.h"
// Node.cpp
template <class T, class K>
Node<T,K>::Node()
{
    key = NULL;
    data = NULL;
    l_ptr = r_ptr = NULL;
}

template <class T, class K>
Node<T,K>:: Node(T ke, K dat)
{
    key = ke;
    data = dat;
    l_ptr = r_ptr = NULL;
}

template <class T, class K>
Node <T,K> :: Node (T ke)
{
    key = ke;
    data = NULL;
    l_ptr = r_ptr = NULL;
}

template <class T, class K>
Node<T,K>::Node(const Node& nod)
{
    key = nod.key;
    data = nod.data;
    l_ptr = nod.l_ptr;
    r_ptr = nod.r_ptr;
}

template <class T, class K>
Node<T,K>::~Node()
{
    delete l_ptr;
    delete r_ptr;
}

template <class T, class K>
void Node<T,K>::setKey(T ke)
{
    key = ke;
}

template <class T, class K>
void Node<T,K>::setData(K dat)
{
    data = dat;
}

template <class T, class K>
T Node<T,K>:: getKey()
{
    return key;
}

template <class T, class K>
K Node<T,K>:: getData()
{
    return data;
}

template <class T, class K>
Node<T,K>& Node<T,K>::operator=(const Node<T,K> &nod)
{
    if (this == &nod) return *this;
    else
    {
        key = nod.key;
        l_ptr = nod.l_ptr;
        r_ptr = nod.r_ptr;
        data = nod.data;
        return *this;
    }
}


/* Binary Tree Class */

/* #ifndef BINARY_TREE_H
 * #define BINARY_TREE_H
*/

// #include "Node.h"

template <class T, class K>
class BinaryTree
{
private:
    Node<T,K> * root;

public:
    BinaryTree(); // default constructor
    BinaryTree(T * arr, int size); // construct a binary tree from an array of keys
    ~BinaryTree();
    bool insertNode(Node<T,K>* node);
    bool insertNode (T key, K data);
    void deleteNode (T key);
    void clearTree(Node<T,K> * node);
    Node<T,K> * findNode(T key);
    void printData (Node<T,K>* node);
    void printSubTree(Node<T,K>*node);
    void printTree();

private:
    void clearTree();
};

template <class T, class K>
BinaryTree<T,K>:: BinaryTree()
{
    root = NULL;
}

template<class T, class K>
BinaryTree<T,K>:: BinaryTree(T *arr, int size)
{
    Node<T,K> ** nodes = new Node<T,K> *[size];
    root = new Node<T,K>(arr[0]);
    nodes[0] = root;

    for (int i =1; i < size; i++)
    {
        Node<T,K> * parent = nodes[(i+1)/2 - 1];
        Node <T,K> * child = new Node<T,K>(arr[i]);

        if (i%2 == 0) parent->setRight(child);
        else parent->setLeft(child);

        nodes[i] = child;

    }
    delete [] nodes;
}

template <class T, class K>
BinaryTree<T,K>::~BinaryTree()
{
    clearTree(root);
}

template <class T, class K>
void BinaryTree<T,K>:: clearTree(Node<T,K>* node)
{
    if (node == NULL) return;
     if (node->getLeft() != NULL) clearTree(node->getLeft());
     if (node->getRight() != NULL) clearTree(node->getRight());
     delete node;
}

template <class T, class K>
bool BinaryTree<T,K>:: insertNode(Node<T,K> * node)
{
    Node<T,K> * temp, * backNode;
    temp = root;

    while (temp!=NULL)
    {
        backNode = temp;
        if (node->getKey()<= temp->getKey())
            temp = temp->getLeft();
        else if (node->getKey() >= temp->getKey() )
            temp = temp->getRight();
    }

    if (backNode == NULL)
    {
        root = node;
        return true;

    }
    else
    {
        if (node->getKey() <= backNode->getKey())
            backNode->setLeft(node);
        else if (node->getKey() > backNode->getKey())
            backNode->setRight(node);
            return true;
    }

}

template <class T, class K>
bool BinaryTree<T,K>:: insertNode(T ke, K dat)
{
    Node<T,K> * tempNode = new Node<T,K>(ke, dat);
  return(insertNode(tempNode));

}

template <class T, class K>
void BinaryTree<T,K>:: deleteNode(T ke)
{
    Node<T,K> * temp, *backNode, *delNode, *delParent;

    temp = root;

    while (temp!= NULL && temp->getKey() != ke)
    {
        backNode = temp;
        if (ke > temp.getKey()) temp = temp->getRight();
        else if (ke <= temp.getKey() ) temp = temp->getLeft();
    }

    if (temp == NULL)
    {
        cout << "did not find the node to be deleted" << endl;
        return;
    }

    else
    {
        if (temp == root)
        {
            delNode = root;
            delParent = NULL;
        }

        else
        {
            delNode = temp;
            delParent = backNode;
        }
    }

    // Case 1: 0 or Right Child only
    if (delNode->getLeft() == NULL)
    {
            if (delParent == NULL)
            {
                root = delNode->getRight();
                delete delNode;
                return;
            }
            else
            {
                if (delParent->getLeft() == delNode)
                    delParent->setLeft(delNode->getRight());
                else
                    delParent->setRight(delNode->getRight());

                delete delNode;
                return;
            }
    }

    //  Case 2: 0 or Left Child only
    if (delNode->getRight() == NULL)
    {
        if (delParent == NULL)
        {
            root = delNode->getLeft();
            delete delNode;
            return;
        }

        else
        {
            if (delParent->getLeft() == delNode)
                delParent->setLeft(delNode->getLeft());
            else
                delParent->setRight(delNode->getRight());
            delete delNode;
            return;


        }


    }


    // Case 3: 2 Children
    else
    {
        temp = delNode->getLeft();
        backNode = delNode;

        while (temp->getRight() != NULL)
        {

            backNode = temp;
            temp = temp->getRight();

        }

        // temp node is the replacement node, so we must copy the values into the delNode

        delNode->setKey(temp->getKey());
        delNode->setData(temp->getData());

        if (backNode == delNode)
            backNode->setLeft(temp->getLeft());
        else
            backNode->setRight(temp->getRight());

        delete delNode;
        return;
    }

}

template <class T, class K>
Node<T,K> * BinaryTree<T,K>::findNode(T ke)
{
    Node<T,K> * temp;
    temp = root;

    while (temp!=NULL && temp->getKey() != ke)
    {
        if (ke <temp->getKey()) temp = temp->getLeft();
        else temp = temp->getRight();
    }

    if (temp == NULL) {
            cout << " couldnt find node in the tree" << endl;
            return NULL;
    }

    else return temp;

}

template <class T, class K>
void BinaryTree<T,K>:: printData(Node<T,K> * nod)
{
    cout << "Key = " << nod->getKey() << ", Data = " << nod->getData() << endl;
}

template <class T, class K>
void BinaryTree<T,K>:: printSubTree(Node<T,K> * node)
{
    if (node != NULL)
    {
        printTree(node->getLeft());
        printData(node);
        printTree(node->getRight());

    }

}

template <class T, class K>
void BinaryTree<T,K>:: printTree()
{
    printSubTree(root);
}
