// Singly Circular Liked List

#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};
template <class T>
class SinglyCL
{
private:
    struct node<T> *first;
    struct node<T> *last;
    int Count;

public:
    SinglyCL();
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
SinglyCL<T>::SinglyCL()
{

    first = NULL;
    last = NULL;
    Count = 0;
}
template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    Count++;
}
template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    struct node<T> *Temp = first;
    if (first == NULL) // if(Count == 0)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    Count++;
}
template <class T>
void SinglyCL<T>::Display()
{
    int i;
    struct node<T> *Temp = first;
    if ((first == NULL) && (last == NULL))
    {
        do
        {
            cout << "|" << first->data << "|->";
            first = first->next;
        } while (first != last->next);
    }
}
template <class T>
int SinglyCL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
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
        delete last->next;
        last->next = first;
    }
    Count--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
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
        struct node<T> *Temp = first;
        while (Temp->next != last)
        {
            Temp = Temp->next;
        }
        delete Temp;
        last = Temp;
        last->next = first;
    }
    Count--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    if (iPos < 1 && iPos > Count + 1)
    {
        printf("Invalid position");
    }
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == Count + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        struct node<T> *Temp = first;
        int i = 0;
        for (i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
        Count++;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 && iPos > Count + 1)
    {
        printf("Invalid position");
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == Count + 1)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *Temp = first;
        int i = 0;
        for (i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->next;
        }
        struct node<T> *Targetednode = Temp->next;
        Temp->next = Temp->next->next;
        delete Targetednode;

        Count--;
    }
}

int main()
{
    SinglyCL<int> iobj;
    SinglyCL<float> fobj;
    SinglyCL<double> dobj;
    SinglyCL<char> cobj;

    return 0;
}