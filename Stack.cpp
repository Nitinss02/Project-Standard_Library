// Stack

#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};
template <class T>
class Stack
{
private:
    struct node<T> *first;
    int Count;

public:
    Stack();
    void Push(T no);
    void Display();
    int CountNode();
    void Pop();
};

template <class T>
Stack<T>::Stack()
{

    first = NULL;
    Count = 0;
}
template <class T>
void Stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    struct node<T> *Temp = first;
    if (first == NULL) // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
    Count++;
}

template <class T>
void Stack<T>::Display()
{
    int i;
    struct node<T> *Temp = first;
    while (Temp != NULL)
    {
        cout << "|" << Temp->data << "|->";
        Temp = Temp->next;
    }
    cout << "NULL\n";
}
template <class T>
int Stack<T>::CountNode()
{
    return Count;
}

template <class T>
void Stack<T>::Pop()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete (first);
        first = NULL;
    }
    else
    {
        struct node<T> *Temp = first;
        first = first->next;
        delete Temp;
    }
    Count--;
}

int main()
{
    Stack<int> iobj;
    Stack<float> fobj;
    Stack<double> dobj;
    Stack<char> cobj;

    return 0;
}