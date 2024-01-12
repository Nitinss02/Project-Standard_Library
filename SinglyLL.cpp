// Singly Linear Liked List

#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};
template <class T>
class SinglyLL
{
private:
    struct node<T> *first;
    int Count;

public:
    SinglyLL();
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
SinglyLL<T>::SinglyLL()
{

    first = NULL;
    Count = 0;
}
template <class T>
void SinglyLL<T>::InsertFirst(T no)
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
void SinglyLL<T>::InsertLast(T no)
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
void SinglyLL<T>::Display()
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
int SinglyLL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
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

template <class T>
void SinglyLL<T>::DeleteLast()
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
void SinglyLL<T>::InsertAtPos(T no, int iPos)
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
void SinglyLL<T>::DeleteAtPos(int iPos)
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
    SinglyLL<int> iobj;
    SinglyLL<float> fobj;
    SinglyLL<double> dobj;
    SinglyLL<char> cobj;

    return 0;
}