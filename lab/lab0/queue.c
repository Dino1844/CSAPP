/*
 * @author Dino1844 <fangjiacheng2021@gmail.com>
 */

#include "queue.h"

#include <stdlib.h>
#include <string.h>

queue_t *queue_new(void) {
    queue_t *q;
    q = malloc(sizeof(queue_t));
    if (!q) {
        return NULL;
    }
    q->head = NULL;
    q->q_size = 0;
    q->q_insert_tail = q->head;
    return q;
}

void queue_free(queue_t *q) {
    if (!q)
        return;
    list_ele_t *tmp = q->head;
    while (tmp) {
        q->head = tmp->next;
        if (tmp->value)
            free(tmp->value);
        free(tmp);
        tmp = q->head;
    }
    free(q);
}

bool queue_insert_head(queue_t *q, const char *s) {
    if (q == NULL) {
        return false;
    }
    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if (newh == NULL)
        return false;

    char *w = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    if (w == NULL) {
        free(newh);
        return false;
    }
    strcpy(w, s);
    newh->value = w;

    newh->next = q->head;
    q->head = newh;
    if (q->q_insert_tail == NULL) {
        q->q_insert_tail = q->head;
    }
    q->q_size++;
    return true;
}

bool queue_insert_tail(queue_t *q, const char *s) {
    if (!q) {
        return false;
    }

    list_ele_t *newh = (list_ele_t *)malloc(sizeof(list_ele_t));
    if (!newh) {
        return false;
    }

    if (!s) {
        newh->value = NULL;
    } else {
        char *test = malloc(sizeof(char) * (strlen(s) + 1));
        if (!test) {
            free(newh);
            return false;
        }
        strcpy(test, s);
        newh->value = test;
    }

    newh->next = NULL;

    if (q->head == NULL) {
        q->head = newh;
        q->q_insert_tail = newh;
    } else {
        q->q_insert_tail->next = newh;
    }
    q->q_insert_tail = newh;

    q->q_size++;
    return true;
}

bool queue_remove_head(queue_t *q, char *buf, size_t bufsize) {
    if (!q || !q->head)
        return false;

    list_ele_t *tmp = q->head;
    q->head = q->head->next;
    if (buf != NULL) {
        strncpy(buf, tmp->value, bufsize - 1);
        buf[bufsize - 1] = '\0';
    }
    if (tmp->value != NULL)
        free(tmp->value);
    free(tmp);
    q->q_size--;
    return true;
}

size_t queue_size(queue_t *q) {
    if (!q)
        return 0;
    return q->q_size;
}

void queue_reverse(queue_t *q) {
    if (!q || q->head == NULL || q->head->next == NULL) {
        return;
    }

    list_ele_t *s;
    list_ele_t *tmp;

    s = q->head;
    tmp = s->next;

    while (tmp) {
        s->next = tmp->next;
        tmp->next = q->head;
        q->head = tmp;
        tmp = s->next;
    }
    q->q_insert_tail = s;
}
