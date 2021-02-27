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
    int ListSize();
    void addItem(T item);
    void printList();
    T deleteItem(T item);
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
template <typename T>
int SortedLinkedList<T>::ListSize()
{
    return count;
}
template <typename T>
void SortedLinkedList<T>::addItem(T item)
{
    Node<T>* previous = NULL,  *following = first;
    while (following != NULL && following->data < item)
    {
        previous = following;
        following = following->next;
    }
    if (previous == NULL)
        first = new Node<T>(item, first);
    else
        previous->next = new Node<T>(item, following);
    count++;
}
template <typename T>
void SortedLinkedList<T>::printList()
{
    cout << "List content:\n";
    if (isEmpty())
        cout << "List is empty.\n";
    Node<T>* following = first;
    while (following != NULL)
    {
        cout << following->data << " ";
        following = following->next;
    }
    cout << endl;
}
template <typename T>
T SortedLinkedList<T>::deleteItem(T item)
{
    T result;
    if (isEmpty())
    {
        cout << "List underflow" << endl;
        return result;
    }
    Node<T>* previous = NULL;
    Node<T>* following = first;
    while (following != NULL && following->data != item)
    {
        if (following->data > item)
        {
            cout << "Item was not found and not deleted" << endl;
            return result;
        }
        previous = following;
        following = following->next;
    }

    if (previous == NULL && following != NULL && following->data == item)
    {
        result = following->data;
        first = first->next;
        delete following;
        count--;
        return result;
    }
    else if (previous != NULL && following != NULL && following->data == item)
    {
        result = following->data;
        previous->next = following->next;
        delete following;
        count--;
        return result;
    }
    else
    {
        cout << "Item was not found and not deleted" << endl;
        return result;
    }
}
int main()
{
    return 0;
}

