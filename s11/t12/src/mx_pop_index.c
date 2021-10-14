#include "../inc/list.h"

void mx_pop_index(t_list **list, int index) {
    if (!*list) return;
    if (index <= 0) {
        mx_pop_front(list);
        return;
    }
    t_list *t = *list, *temp = NULL;
    for (int i = 0; i < index; i++) {
        if (t->next == NULL)
            break;
        temp = t;
        t = t->next;
    }
    temp->next = t->next;
    free(temp);
    temp = NULL;
}

