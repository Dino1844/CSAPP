/**
 * @author Dino1844 <fangjiacheng2021@gmail.com>
 */

#include <stdbool.h>
#include <stddef.h>

/************** Data structure declarations ****************/

typedef struct list_ele {
    char *value;
    struct list_ele *next;
} list_ele_t;

typedef struct {
    list_ele_t *head;
    unsigned long q_size; 
    list_ele_t *q_insert_tail;
} queue_t;

/************** Operations on queue ************************/

queue_t *queue_new(void);

void queue_free(queue_t *q);

bool queue_insert_head(queue_t *q, const char *s);

bool queue_insert_tail(queue_t *q, const char *s);

bool queue_remove_head(queue_t *q, char *sp, size_t bufsize);

size_t queue_size(queue_t *q);

void queue_reverse(queue_t *q);
