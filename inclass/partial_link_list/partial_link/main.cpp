#include <iostream>
#include <iomanip>

using namespace std;

struct t_link {
    int value;
    t_link * next;
};

// create a new link and add at head of list
t_link * addHead(t_link * head, int value)
{
    t_link * temp = new t_link;
    temp->value = value;
    temp->next = head;
    head = temp;
    return head;
}

// display the list iteratively
void display(t_link * head)
{
    t_link *ptr = head;
    while ( ptr != nullptr )
    {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// display the list recursively
void rec_display(t_link *ptr)
{
    if ( ptr == nullptr )
    {
        cout << endl;
        return;
    }

    cout << ptr->value << " ";
    rec_display(ptr->next);
}

// iterative deletion of all links
void cleanUp(t_link * head)
{
    t_link * ptr = head;
    while ( ptr != nullptr )
    {
        t_link * temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

// recursive deletion of all links
void rec_cleanUp(t_link * ptr)
{
    if ( ptr == nullptr )
        return;
    rec_cleanUp(ptr->next);
    delete ptr;
}

// return true if value is in list
bool findItem(t_link *head, int value);


// recursively return true if value is in list
bool rec_findItem(t_link *ptr, int value);


// return the value at head
int getHead(t_link * head);

// delete the first link
// ignore empty list
t_link * removeHead(t_link * head);

// delete link containing value
// if not there, do nothing
t_link * removeValue(t_link *head, int value);



int main()
{
    t_link * head = nullptr;
    const int SIZE = 10;
    int numbers[SIZE] = {1, 3, 5, 7, 12, 33, 45, 87, 22, -5 };

        // load list with above values
    for(int i = 0; i < SIZE; i++)
    {
        head = addHead(head, numbers[i]);
    }

    display(head);


    cleanUp(head);

    return 0;
}

