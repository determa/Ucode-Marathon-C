#include "../inc/list.h"

void mx_push_index(t_list **list, void *data, int index) {
    if (index <= 0) {
        mx_push_front(list, data);
        return;
    }
    t_list *t = * list;
    t_list *t2 = * list;
    int i;
    for (i = 0; t->next != NULL; i++) {
        if (i + 1 == index) {
            t2 = t;
        }
        if (i == index) {
            t_list *temp = mx_create_node(data);
            t2->next = temp;
            temp->next = t;
        } else {
            t = t->next;
        }
    }
    if (index > i) mx_push_back(list, data);
}

