#include "list.h"

void mx_pop_front(t_list **list) {
    if (*list == NULL) return;
    t_list *temp = *list;
    temp = temp->next;
    *list = temp;
    free(temp);
    temp = NULL;
}

