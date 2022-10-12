#include <stdio.h>

#define container_of(ptr, type, member) ({			\
        const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
        (type *)( (char *)__mptr - offsetof(type,member) ); })

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

struct llist {
    struct llist *next;
};

static inline void INIT_LIST_HEAD(struct llist *list) {
    list->next = NULL;
}
static void list_head_plugin(struct llist *list, struct llist *node) {
    if (list == node) {
        return;
    }
    if (list == NULL) {
        list = node;
        return;
    }
    node->next = list->next;
    list->next = node;
}
static void list_remove(struct llist *list, struct llist *node) {
}
static void llist_forEach(struct llist *list, void (*callback)(struct llist *)) {
    struct llist *p = list;
    while (p) {
        callback(p);
        p = p->next;
    }
}