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

private:
    int count;
    Node<T>* first;
};
int main()
{
    return 0;
}

