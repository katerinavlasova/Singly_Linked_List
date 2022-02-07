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
};


int main()
{
    LinkedList<int> listik(5);
    std::cout << "Hello World!\n";
}
