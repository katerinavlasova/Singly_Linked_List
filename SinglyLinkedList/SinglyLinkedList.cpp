#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;
using namespace List;

template <typename TypeValue>
LinkedList<TypeValue>::LinkedList(const TypeValue& value)
{
    Node<TypeValue>* node;
    node = new Node<TypeValue>(value);
    if (!node)
        return;
    ++size;
    head = node;
}

template <typename TypeValue>
LinkedList<TypeValue>::~LinkedList()
{
    if (head == nullptr)
        return;
    Node<TypeValue>* tmp = head;
    Node<TypeValue>* previous = head;
    while (tmp != nullptr)
    {
        previous = tmp;
        tmp = tmp->nextNode;
        delete previous;
    }
}

template <typename TypeValue>
TypeValue LinkedList<TypeValue>::pushBack(const TypeValue& value)
{
    Node<TypeValue>* node = new Node<TypeValue>(value);
    if (!node)
        return NULL;
    ++size;
    if (head == nullptr)
    {
        head = node;
        return value;
    }
    Node<TypeValue>* tmp = head;
    while (tmp->nextNode != nullptr)
        tmp = tmp->nextNode;
    tmp->nextNode = node;
    return value;
}

template <typename TypeValue>
TypeValue LinkedList<TypeValue>::pushFront(const TypeValue& value)
{
    Node<TypeValue>* node = new Node<TypeValue>(value);
    if (!node)
        return NULL;
    ++size;
    node->nextNode = head;
    head = node;
    return value;
}

template <typename TypeValue>
TypeValue LinkedList<TypeValue>::popFront()
{
    if (head == nullptr)
        return NULL;
    --size;
    Node<TypeValue>* tmp = head->nextNode;
    TypeValue value = head->value;
    delete head;
    head = tmp;
    return value;
}

template <typename TypeValue>
TypeValue LinkedList<TypeValue>::popBack()
{
    if (head == nullptr)
        return NULL;
    --size;
    Node<TypeValue>* tmp, * last;
    tmp = head;
    last = head;
    while (tmp->nextNode != nullptr)
    {
        last = tmp;
        tmp = tmp->nextNode;
    }
    TypeValue value = tmp->value;
    if (last == tmp)
    {
        delete head;
        head = nullptr;
        return value;
    }
    delete last->nextNode;
    last->nextNode = nullptr;
    return value;
}

template <typename TypeValue>
TypeValue LinkedList<TypeValue>::insertAfter(TypeValue value, int index)
{
    int count = 0;
    ++size;
    Node<TypeValue> *element = new Node<TypeValue>(value);
    if (!element)
        return NULL;
    if (head == nullptr)
    {
        head = element;
        return value;
    }
    Node<TypeValue> *tmp = head;
    Node<TypeValue> *last = tmp;
    while (count <= index && tmp != nullptr)
    {
        ++count;
        last = tmp;
        tmp = tmp->nextNode;
    }
    if (tmp != head)
        element->nextNode = tmp;
    last->nextNode = element;
}

template <typename TypeValue>
TypeValue LinkedList<TypeValue>::eraseAfter(int index)
{
    int count = 0;
    TypeValue value;
    if (head == nullptr)
        return NULL;
     Node<TypeValue> *tmp = head;
     Node<TypeValue> *previous = tmp;
     while (count <= index && tmp != nullptr)
     {
         ++count;
         previous = tmp;
         tmp = tmp->nextNode;
     }
        
     if (tmp)
     {
         value = tmp->value;
         previous->nextNode = tmp->nextNode;
         delete tmp;
         return value;
     }
     
     return NULL;
}

template <typename TypeValue>
void LinkedList<TypeValue>::clear()
{
    if (head == nullptr)
        return;
    Node<TypeValue>* tmp = head;
    Node<TypeValue>* last = head;
    while (tmp->nextNode != nullptr)
    {
        last = tmp;
        tmp = tmp->nextNode;
        delete last;
    }
    delete tmp;
    head = nullptr;
    size = 0;
    cout << head << endl;
}

template <typename TypeValue>
void LinkedList<TypeValue>::printList()
{
    if (head == nullptr)
    {
        cout << "No elements!" << endl;
        return;
    }
    Node<TypeValue>* tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->nextNode;
    }
    cout << endl;
}

template <typename TypeValue>
TypeValue LinkedList<TypeValue>::front()
{
    if (head == nullptr)
        return NULL;
    return head->value;
}

template <typename TypeValue>
bool LinkedList<TypeValue>::isEmpty()
{
    if (head == nullptr)
        return true;
    return false;
}

template <typename TypeValue>
unsigned int LinkedList<TypeValue>::getSize()
{
    return size;
}


int main()
{
    LinkedList<int> listik(5);
    std::cout << "Hello World!\n";
}
