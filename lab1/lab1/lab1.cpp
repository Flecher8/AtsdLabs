#include <iostream>

using namespace std;

template <typename T>
struct Node
{
public:
    T data;
    Node* next;
    // constructors
    Node();
    Node(T d, Node* link = NULL);
};
template <typename T>
Node<T>::Node()
{
    next = NULL;
}
template <typename T>
Node<T>::Node(T item, Node* link)
{
    data = item;
    next = link;
}
template <typename T>
class SortedLinkedList
{
public:
    SortedLinkedList(); // default constructor
    ~SortedLinkedList();// destructor
    bool isEmpty();
private:
    int count;
    Node<T>* first;
};

template <typename T>
SortedLinkedList<T>::SortedLinkedList()
{
    count = 0;
    first = NULL;
}
template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
    count = 0;
    Node<T>* temp;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}
template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
    return (count == 0);
}
int main()
{
    return 0;
}

