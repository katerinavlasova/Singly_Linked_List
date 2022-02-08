#include <iostream>

using namespace std;
#include <iterator>
#include <cstddef>


template <typename TypeValue>
class LinkedList {

private:
    template <typename TypeValue>
    struct Node {
        TypeValue value = NULL;
        Node* nextNode = nullptr;
        Node<TypeValue>(TypeValue val = TypeValue(), Node* node = nullptr) : value(val), nextNode(node)
        {
        };
    };
    Node<TypeValue>* head = nullptr;
    unsigned int size = 0;

public:

    LinkedList(const TypeValue& value)
    {
        Node<TypeValue>* node;
        node = new Node<TypeValue>(value);
        if (!node)
            return;
        ++size;
        head = node;
    }

    TypeValue pushBack(const TypeValue& value)
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

    TypeValue pushFront(const TypeValue& value)
    {
        Node<TypeValue>* node = new Node<TypeValue>(value);
        if (!node)
            return NULL;
        ++size;
        node->nextNode = head;
        head = node;
        return value;
    }

    TypeValue popFront()
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

    TypeValue popBack()
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

    TypeValue insertAfter(TypeValue value, int index)
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

    TypeValue eraseAfter(int index)
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

    void clear()
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

    void printList()
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

    TypeValue front()
    {
        if (head == nullptr)
            return NULL;
        return head->value;
    }

    bool isEmpty()
    {
        if (head == nullptr)
            return true;
        return false;
    }

    unsigned int getSize()
    {
        return size;
    }
};


int main()
{
    LinkedList<int> listik(5);
    std::cout << "Hello World!\n";
}
