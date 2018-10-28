#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct TAB tab;
typedef struct NODE node;
typedef struct VECTOR vector;

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

vector* create_vector();
void sort(vector* v);
void push_back(vector* v, tab* t);
void new_position(vector* v, char* name, int position);
void show(vector* v);
void destroy_vector(node* n);

#endif //DOUBLE_LINKED_LIST_H
