#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

enum priority{
    // priority designed for the radix sort
    minutes = 0, hours, days, months
};

int main(){
    vector* v = create_vector();
    int exit = 0;
    int op;
    while(exit == 0){
        scanf("%d", &op);
        if(op == 1){ // read new tab
                // these scanfs are to deal with the input so that the strings don't get wrongly stored
                tab* t = malloc(sizeof(tab));
                scanf("%*[\r\n]");
                scanf("%31[^\n]", (t->title));
                scanf("%*[\r\n]");
                scanf("%1024[^\n]", (t->url));
                scanf("%*[\r\n]");
                scanf("%d %d", &(t->d_day), &(t->d_month));
                scanf("%d %d", &(t->d_hour), &(t->d_minutes));
                push_back(v, t);
        } else if(op == 2){ // move tab
            char name[30];
            int position;
            scanf("%*[\r\n]");
            scanf("%[^\n]", name);
            scanf("%*[\r\n]");
            scanf("%d", &position);
            new_position(v, name, position);
        } else if(op == 3){ // sort using a radix sort (bucket sort as subroutine)
            sort(v, minutes);
            sort(v, hours);
            sort(v, days);
            sort(v, months);
        } else if(op == 4){ // print each tab's information
            show(v);
        } else { // deallocate all memory
            destroy_vector(v);
            exit = 1;
        }
    }
    return 0;
}
