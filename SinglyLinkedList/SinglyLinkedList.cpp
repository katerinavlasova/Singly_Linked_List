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
};


int main()
{
    LinkedList<int> listik(5);
    std::cout << "Hello World!\n";
}
