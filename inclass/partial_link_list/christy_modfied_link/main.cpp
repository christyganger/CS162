#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct mysuper_t {
    string name_of_movie;
    int date_of_movie;
    mysuper_t * next;
};

// create a new link and add at head of list
mysuper_t * addHead(mysuper_t * head, int date_of_movie, string name_of_movie)
{
    mysuper_t * temp = new mysuper_t;
    temp->name_of_movie = name_of_movie;
    temp->date_of_movie = date_of_movie;
    temp->next = head;
    head = temp;
    return head;
}

// display the list iteratively
void display(mysuper_t * head)
{
    mysuper_t *ptr = head;
    while ( ptr != nullptr )
    {
        cout << ptr->name_of_movie << " ";
        cout << "(" << ptr->date_of_movie << ")" << " ";

        cout << "\n\nMoving on to next record \n\n";
        ptr = ptr->next;
    }
    cout << "\n";
}

// display the list recursively
void rec_display(mysuper_t *ptr)
{
    if ( ptr == nullptr )
    {
        cout << endl;
        return;
    }

    cout << ptr->name_of_movie << " ";
    cout << "(" << ptr->date_of_movie << ")" << " ";
    cout << "\n\nMoving on to next record \n\n";
    rec_display(ptr->next);
}

// iterative deletion of all links
void cleanUp(mysuper_t * head)
{
    mysuper_t * ptr = head;
    while ( ptr != nullptr )
    {
        mysuper_t * temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

// recursive deletion of all links
void rec_cleanUp(mysuper_t * ptr)
{
    if ( ptr == nullptr )
        return;
    rec_cleanUp(ptr->next);
    delete ptr;
}

// return true if value is in list
bool findItem(mysuper_t *head, int date_of_movie, string name_of_movie);


// recursively return true if value is in list
bool rec_findItem(mysuper_t *ptr, int date_of_movie, string name_of_movie);


// return the value at head
int getHead(mysuper_t * head);

// delete the first link
// ignore empty list
mysuper_t * removeHead(mysuper_t * head);

// delete link containing value
// if not there, do nothing
mysuper_t * removeValue(mysuper_t *head, int date_of_movie, string name_of_movie);

mysuper_t * enter_data(mysuper_t * head)
{
    const int size_max = 10;
    int size_current = 0;
    string mystring;
    int mydate;
    while(size_current < size_max){
           cout << "Please enter name of movie: ";
           getline(std::cin,mystring);
            cout << "please enter date of movie: ";
            cin >> mydate;
          head = addHead(head,mydate, mystring);
          cout << "\n";
          cin.clear();
          cin.ignore(1000,'\n');
          size_current++;
    }
    return head;
}


int main()
{
   cout << "This program is designed to use something called link lists";
   cout << "\n You will enter up to 10 movies and dates";
   cout << "\nThen it will print them back.";
   cout << "\n\n\n";
   mysuper_t * head = nullptr;
    head = enter_data(head);
    display(head);
    //rec_display(head);
    cleanUp(head);
    //rec_cleanUp(head);


    cout << "press any key to close this window.";
    cin.get();
    return 0;

}
