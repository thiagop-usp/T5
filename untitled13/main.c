#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

enum priority{
    minutes = 0, hours, days, months
};

int main(){
    vector* v = create_vector();
    int exit = 0;
    int op;
    while(exit == 0){
        scanf("%d", &op);
        if(op == 1){
                tab* t = malloc(sizeof(tab));
                scanf("%*[\r\n]");
                scanf("%31[^\n]", (t->title));
                scanf("%*[\r\n]");
                scanf("%1024[^\n]", (t->url));
                scanf("%*[\r\n]");
                scanf("%d %d", &(t->d_day), &(t->d_month));
                scanf("%d %d", &(t->d_hour), &(t->d_minutes));
                push_back(v, t);
        } else if(op == 2){
            char name[30];
            int position;
            scanf("%*[\r\n]");
            scanf("%[^\n]", name);
            scanf("%*[\r\n]");
            scanf("%d", &position);
            new_position(v, name, position);
        } else if(op == 3){
            sort(v, minutes);
            sort(v, hours);
            sort(v, days);
            sort(v, months);
        } else if(op == 4){
            show(v);
        } else {
            destroy_vector(v);
            exit = 1;
        }
    }
    return 0;
}
