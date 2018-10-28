#include "double_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

vector* create_vector(){
    vector* v;
    v = malloc(sizeof(vector));
    v->size = 0;
    v->first = NULL;
    v->last = NULL;
    return v;
}

void push_back(vector* v, tab* t){
    if(v->size == 0){
        node* n;
        n = malloc(sizeof(node));
        n->t = t;
        v->first = n;
        v->last = n;
        n->next = NULL;
        n->previous = NULL;
    } else {
        node* n;
        n = malloc(sizeof(node));
        n->t = t;
        n->next = NULL;
        n->previous = v->last;
        v->last->next = n;
        v->last = n;
    }
    v->size++;
}

void show(vector* v){
    node* current = v->first;
    while(current != NULL){
        printf("%s %s %d/%d %d:%d\n",
                current->t->title,
                current->t->url,
                current->t->d_day,
                current->t->d_month,
                current->t->d_hour,
                current->t->d_minutes);
        current = current->next;
    }
}

void destroy_vector(node* n){
    if(n->next == NULL){
        free(n->next);
        free(n->previous);
        free(n);
    } else {
        free(n->previous);
        destroy_vector(n->next);
        free(n->next);
        free(n);
    }
}
