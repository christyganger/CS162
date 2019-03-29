#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

class List
{
private:

   typedef struct node // can Do this style instead of one thats commended out below
   {
       int data;
       node* next;
   }* nodePtr;

   /* // other method of writing it all out
    struct node
    {
        int data;
        node* next;
    };

    typedef struct node* nodePtr;
    */

    //example
   // node* head; // instead of this
   nodePtr head; // can do this
   nodePtr curr;
   nodePtr temp;


public: // this is where functions go
    List();
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList();

};

#endif // LIST_H_INCLUDED
