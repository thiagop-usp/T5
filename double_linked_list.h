#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

// ================================== Structures =========================================== //
typedef struct TAB tab; // a tab, which contains all the info about that website
typedef struct NODE node; // a node cointains the pointers that connect the list
typedef struct VECTOR vector; // a doubly linked list with many functions

struct TAB{
    char title[30];
    char url[1024];
    int d_day, d_month, d_hour, d_minutes;
};

struct NODE{
    tab* t;
    node* next;
    node* previous;
};

struct VECTOR{
    node* first;
    node* last;
    int size;
};

// ================================== Vector functions ======================================= //
vector* create_vector();
int is_empty(vector* v); // shows whether the vector is empty OR doesn't exist
void show(vector* v); // prints out a vector's information regarding its tabs
void sort(vector* v, int type); // sorts the vector tabs based on each time-stamp
void new_position(vector* v, char* name, int position); // moves a tab to wherever desired
void push_back(vector* v, tab* t); // inserts a new tab at the back
tab* pop_front(vector* v); // removes the first element in the vector and retrieves it
void destroy_vector(vector* v); //deallocates all memory

#endif //DOUBLE_LINKED_LIST_H
