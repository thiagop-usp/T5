#include "double_linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int size(int a){
    if(a == 0) return 61; // minutes
    if(a == 1) return 25; // hours
    if(a == 2) return 32; // days
    if(a == 3) return 13; // months
}

int evaluate(int type, tab* t){
    if(type == 0) return t->d_minutes;
    if(type == 1) return t->d_hour;
    if(type == 2) return t->d_day;
    if(type == 3) return t->d_month;
}

vector* create_vector(){
    vector* v;
    v = malloc(sizeof(vector));
    v->size = 0;
    v->first = NULL;
    v->last = NULL;
    return v;
}

int is_empty(vector* v){
    return (v == NULL || v->size == 0);
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

tab* pop_front(vector* v){
    tab* t = NULL;
    if(v->size == 1){
        t = v->first->t;
        if(v->first != NULL) free(v->first);
    } else {
        node* aux = v->first;
        t = v->first->t;
        v->first->next->previous = NULL;
        v->first = v->first->next;
        free(aux);
    }
    v->size--;
    return t;
}

void show(vector* v){
    node* current = v->first;
    while(current != NULL){
        if(current->t->d_day != 0)
            printf("%s %s %02d/%02d %02d:%02d\n",
                current->t->title,
                current->t->url,
                current->t->d_day,
                current->t->d_month,
                current->t->d_hour,
                current->t->d_minutes);
        current = current->next;
    }
    printf("\n");
}

void destroy_vector(vector* v){
    while(!is_empty(v)){
        tab* t = pop_front(v);
		free(t);
    }
    free(v);
}

    void sort(vector* v, int type){
    vector* bucket[size(type)+1];
    node* current = v->first;
    memset(bucket, 0, sizeof(bucket));

    while(current != NULL){
        int value = evaluate(type, current->t);
        if(bucket[value] == NULL) bucket[value] = create_vector();
        push_back(bucket[value], current->t);
        current = current->next;
    }

    current = v->first;
    for(int i = 0, j = 0; i < v->size; j++){
        while(!is_empty(bucket[j])){
            current->t = pop_front(bucket[j]);
            current = current->next;
            i++;
        }
        if(bucket[j] != NULL) destroy_vector(bucket[j]);
    }
}

void new_position(vector* v, char* name, int position){
    node* target = NULL;
    node* new_position = NULL;
    node* current = v->first;
    while(current != NULL && strcmp(current->t->title, name) != 0){
        current = current->next;
    }
    if(current == NULL) return;
    else target = current;

    if(position > v->size){
        new_position = v->last;
    } else if (position == 1){
        new_position = v->first;
    } else {
        current = v->first;
        for(int i = 1; i <= position; i++){
            if(i == position || current == v->last) break;
            current = current->next;
        }
        new_position = current;
    }

    if(new_position == target) return;
    node* aux = target;

    if(target != v->first && target != v->last){
        target->previous->next = target->next;
        target->next->previous = target->previous;
    } else if (target == v->first){
        target->next->previous = NULL;
        v->first = target->next;
    } else if (target == v->last){
        target->previous->next = NULL;
        v->last = target->previous;
    }

    if(position >= v->size){
        aux->previous = v->last;
        aux->next = NULL;
    } else {
        aux->previous = new_position->previous;
        aux->next = new_position;
    }

    if(new_position != v->first && new_position != v->last){
        aux->previous->next = aux;
        aux->next->previous = aux;
    } else if (new_position == v->first){
        v->first = aux;
        aux->next->previous = aux;
    } else if (position >= v->size){
        v->last = aux;
        aux->previous->next = aux;
    }
}
