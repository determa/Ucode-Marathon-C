#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    t_list *buff, *pbuff = *list;

    if ((buff = (*list)->next)) {
        while (buff->next) {
            if (cmp(buff->data, del_data)) {
                pbuff->next = buff->next;
                buff = pbuff->next;
            }
            else {
                pbuff = pbuff->next;
                buff = buff->next;
            }
        }
        if (cmp(buff->data, del_data))
            pbuff->next = NULL;
        buff = *list;
        if (cmp(buff->data, del_data))
            (*list) = (*list)->next;
    }
    else
        if (cmp(pbuff->data, del_data))
    free(buff);
}

