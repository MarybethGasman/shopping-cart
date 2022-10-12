#pragma once
#include <stdlib.h>

#include "llist.h"

// struct Abstractgoods {
//     struct llist list;
//     struct AbstractGoodsOps* goodsOps;
// };

struct AbstractGoodsOps {
    void (*increaseNum)(void*);
    void (*decreaseNum)(void*);
    int (*getPrice)(void*);
    int (*getNum)(void*);
    struct llist list;
};

// void* goods_init(struct AbstractGoodsOps* ops) {
//     struct Abstractgoods* goods = (struct Abstractgoods*)malloc(sizeof(*goods));
//     goods->goodsOps = ops;
//     goods->list.next = NULL;
//     return goods;
// }