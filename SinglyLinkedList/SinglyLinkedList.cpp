#include <iostream>

using namespace std;

template <typename TypeValue>
struct Node {
    TypeValue value = NULL;
    Node* nextNode = nullptr;
    Node<TypeValue>(TypeValue val = TypeValue(), Node* node = nullptr) : value(val), nextNode(node)
    {
    };
};

template <typename TypeValue>
class LinkedList {

private:
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
};


int main()
{
    LinkedList<int> listik(5);
    std::cout << "Hello World!\n";
}
