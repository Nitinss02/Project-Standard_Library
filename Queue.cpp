// Queue
#include <iostream>
#include <string.h>

using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};
template <class T>
class Queue
{
private:
    struct node<T> *first;
    int Count;

public:
    Queue();
    void Enqueue(T no);
    void Display();
    void Dequeue();
};

template <class T>
Queue<T>::Queue()
{

    first = NULL;
    Count = 0;
}
template <class T>
void Queue<T>::Enqueue(T no)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Count++;
}

template <class T>
void Queue<T>::Display()
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
void Queue<T>::Dequeue()
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
    Queue<int> iobj;
    Queue<float> fobj;
    Queue<double> dobj;
    Queue<char> cobj;
    Queue<string> sobj;

    return 0;
}