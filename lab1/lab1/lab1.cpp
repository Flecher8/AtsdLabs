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
    bool search(T item);
    SortedLinkedList copyDuplicate(SortedLinkedList& L2);
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
template <typename T>
bool SortedLinkedList<T>::search(T item)
{
    Node<T>* following = first;
    while (following != NULL)
    {
        if (following->data == item)
            return true;
        else if (following->data > item)
            return false;

        following = following->next;
    }
    return false;
}
template <typename T>
SortedLinkedList<T> SortedLinkedList<T>::copyDuplicate(SortedLinkedList<T>& L2)
{
    SortedLinkedList<T> L1;
    if (isEmpty())
        return L1;
    if (listSize() == 1)
    {
        L1.addItem(first->data);
        L1.addItem(first->data);
        L2.addItem(first->data);
        return L1;
    }
    Node<T>* following = first;
    while (following->next != NULL)
    {
        L1.addItem(following->data);
        following = following->next;
    }
    L1.addItem(following->data);

    Node<T>* previous = L1.first;
    following = L1.first->next;
    T item = L1.first->data;
    int repite = 0;
    while (previous->next != NULL)
    {
        if (following->next == NULL && previous->data != following->data)
        {
            following->next = new Node<T>(following->data, NULL);
            L2.addItem(following->data);
        }
        if (item == following->data)
        {
            repite++;
            previous = following;
            following = following->next;
            item = previous->data;
        }
        else
        {
            if (repite == 0)
            {
                previous->next = new Node<T>(previous->data, following);
                repite++;
                L2.addItem(previous->data);
            }
            else
            {
                repite = 0;
                previous = following;
                following = following->next;
                item = previous->data;
            }

        }

    }

    return L1;
}
int main()
{
    return 0;
}

