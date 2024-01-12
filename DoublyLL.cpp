// Doubly Linear

#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};
template <class T>

class DoublyLL
{
private:
    struct node<T> *first;
    int Count;

public:
    DoublyLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T no, int iPos);
    void DeleteAtPos(int iPos);
};

/*
Return_value class_Name :: Function_Name()
{

}
*/
template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    Count = 0;
}
template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> newn;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL))
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    Count++;
}
template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> newn;
    newn = new struct node<T>;
    struct node<T> Temp = first;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
    }
    Temp->next = newn;
    newn->prev = Temp;
    Count++;
}
template <class T>
void DoublyLL<T>::Display()
{
    cout << "NULL<=>";
    while (first != NULL)
    {
        cout << "|" << first->data << "<=>";
        first = first->next;
    }
    cout << "NULL\n";
}
template <class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}
template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if ((first == NULL))
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
        first = first->next;
        delete (last->prev);
        first->prev = NULL;
    }
    Count--;
}
template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct node<T> *Temp = first;
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if ((first->next == NULL) && (first->prev == NULL))
    {
        delete (first);
        first = NULL;
    }
    else
    {
        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete Temp->next;
        Temp->next = NULL;
    }
    Count--;
}
template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    int size = CountNode();
    int i = 0;
    struct node<T> newn = NULL;
    struct node<T> Temp = NULL;
    Temp = first;
    if (iPos < 1 || iPos > size + 1)
    {
        cout << "Invalid Position\n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        for (i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        Temp->next = newn;
        newn->prev = Temp;
    }
    Count++;
}
template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int size = CountNode();
    int i = 0;
    struct node<T> Temp = first;
    if (iPos < 1 || iPos > size)
    {
        cout << "Invalid Position\n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == size + 1)
    {
        DeleteLast();
    }
    else
    {
        for (i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete (Temp->next->prev);
        Temp->next->prev = Temp;
    }
    Count--;
}

int main()
{

    DoublyLL<int> iobj;
    DoublyLL<float> fobj;
    DoublyLL<double> dobj;
    DoublyLL<char> cobj;
    return 0;
}