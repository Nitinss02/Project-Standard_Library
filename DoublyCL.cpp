// Doubly Circular

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

class DoublyCL
{
private:
    struct node<T> *first;
    struct node<T> *last;
    int Count;

public:
    DoublyCL();
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
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}
template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    struct node<T> newn;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    Count++;
}
template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    struct node<T> newn;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    Count++;
}
template <class T>
void DoublyCL<T>::Display()
{
    if (first != NULL && last != NULL)
    {
        do
        {
            cout << "|" << first->data << "|<=>";
            first = first->next;
        } while (first != last->next);
    }
    cout << "\n";
}
template <class T>
int DoublyCL<T>::CountNode()
{
    return Count;
}
template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete (first);
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete (last->next);
        first->prev = last;
        last->next = first;
    }
    Count--;
}
template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete (first);
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete (last->next);
        first->prev = last;
        last->next = first;
    }
    Count--;
}
template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
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
void DoublyCL<T>::DeleteAtPos(int iPos)
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

    DoublyCL<int> iobj;
    DoublyCL<float> fobj;
    DoublyCL<double> dobj;
    DoublyCL<char> cobj;
    return 0;
}