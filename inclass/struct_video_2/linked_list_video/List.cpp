#include <cstdlib>
#include <iostream>
#include "list.h"

using namespace std;

List::List()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::AddNode(int addData)
{
        nodePtr n = new node;
        n->next = NULL;
        n->data = addData;

        if(head != NULL) // go to last node
        {
            curr = head;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = n; // point to new
        }
        else
        {
            head = n; // then new one points to new
        }
}

void List::DeleteNode(int delData)
{
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while (curr != NULL && curr->data != delData)
    {
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL)
    {
        cout << delData << " Not found." << "\n";
        delete delPtr;
    }
    else
    {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if(delPtr == head)
        {
            head = head->next;
            temp = NULL;
        }
        delete delPtr;
        cout << "The value " << delData << " was deleted" << "\n";
    }

}

void List::PrintList()
{
    curr = head;
    while(curr != NULL)
    {
        cout << curr->data << "\n";
        curr = curr->next;
    }
}
