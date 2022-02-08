#include <iostream>

namespace List
{
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
        LinkedList(const TypeValue& value);
        ~LinkedList();

        TypeValue pushBack(const TypeValue& value);
        TypeValue pushFront(const TypeValue& value);
        TypeValue popFront();
        TypeValue popBack();
        TypeValue insertAfter(TypeValue value, int index);
        TypeValue eraseAfter(int index);
        void clear();
        void printList();
        TypeValue front();
        bool isEmpty();
        unsigned int getSize();
        };
}
