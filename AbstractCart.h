#include <stdlib.h>

#include "AbstractGoods.h"
struct AbstractCartOps;
struct AbstractGoodsOps;
struct AbstractCart {
    struct llist* aGoodsHead;
    struct AbstractCartOps* cartOps;
};

struct AbstractCartOps {
    void (*add)(struct AbstractCart*, struct AbstractGoodsOps*);

    void (*remove)(struct AbstractCart*, struct AbstractGoodsOps*);

    int (*getTotalCost)(struct AbstractCart*);
};

void add(struct AbstractCart* aCart, struct AbstractGoodsOps* aGoods) {
    if (aCart->aGoodsHead == NULL) {
        aCart->aGoodsHead = &(aGoods->list);
        return;
    }
    struct llist* head = aCart->aGoodsHead;
    list_head_plugin(head, &(aGoods->list));
}

void cartRemove(struct AbstractCart* aCart, struct AbstractGoodsOps* aGoods) {
    struct llist* head = aCart->aGoodsHead;
    struct llist* node = &(aGoods->list);

    if (head == node) {
        head == NULL;
        return;
    }
    list_remove(head, node);
}
int getTotalCost(struct AbstractCart* aCart) {
    struct llist* head = aCart->aGoodsHead;
    struct llist* p = head;
    struct AbstractGoodsOps* tmp;
    int sum = 0;
    while (p) {
        tmp = container_of(p, struct AbstractGoodsOps, list);
        sum += tmp->getPrice(tmp) * tmp->getNum(tmp);
        p = p->next;
    }
    return sum;
}
struct AbstractCart* cartInit() {
    struct AbstractCart* cart = (struct AbstractCart*)malloc(sizeof(*cart));
    cart->cartOps = (struct AbstractCartOps*)malloc(sizeof(*(cart->cartOps)));
    cart->cartOps->add = add;
    cart->cartOps->getTotalCost = getTotalCost;
    cart->cartOps->remove = cartRemove;

    return cart;
}