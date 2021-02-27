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

int main()
{
    return 0;
}

