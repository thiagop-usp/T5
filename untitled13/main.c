#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

int main(){
    vector* v = create_vector();
    int exit = 0;
    while(exit == 0){
        int op;
        scanf("%d", &op);
        if(op == 1){
                tab* t;
                scanf("%s", (t->title));
                scanf("%s", (t->url));
                scanf("%d %d", &(t->d_day), &(t->d_month));
                scanf("%d %d", &(t->d_hour), &(t->d_minutes));
                push_back(v, t);
        } else if(op == 2){ ;
            char name[30];
            int position;
            scanf("%s", name);
            scanf("%d", &position);
        } else if(op == 3){

        } else if(op == 4){
            show(v);
        } else {
            exit = 1;
        }
    }
    return 0;
}