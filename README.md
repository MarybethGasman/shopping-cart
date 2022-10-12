### Introduction

A simple shopping cart implemented in c using OOP.

### Prerequisite

-   GNU gcc

### Usage

```c
#include "AbstractCart.h"

```

You can create new goods by implementing AbstractGoodsOps in AbstractGoods.h.
Examples are in Apple.h or Orange.h.

### API

```c

struct AbstractCartOps {
    //add a goods to the cart
    void (*add)(struct AbstractCart*, struct AbstractGoodsOps*);

    //remove a goods
    void (*remove)(struct AbstractCart*, struct AbstractGoodsOps*);

    //get total cost
    int (*getTotalCost)(struct AbstractCart*);
};

struct AbstractGoodsOps {
    //increase purchase num
    void (*increaseNum)(void*);

    //decrease purchase num
    void (*decreaseNum)(void*);

    //get the price of a particular goods
    int (*getPrice)(void*);

    //get purchase num
    int (*getNum)(void*);

    //used for linkedlist, you don't need to care about it.
    struct llist list;
};

```

### Example

see test.c

```c
#include <assert.h>

#include "AbstractCart.h"
#include "Apple.h"
#include "Orange.h"
int main() {
    struct AbstractCart *cart = cartInit();
    struct Orange *goods1 = Orange();
    goods1->abGoods.increaseNum(&goods1->abGoods);
    goods1->abGoods.increaseNum(&goods1->abGoods);
    struct Apple *goods2 = Apple();
    goods2->abGoods.increaseNum(&goods2->abGoods);
    goods2->abGoods.increaseNum(&goods2->abGoods);

    cart->cartOps->add(cart, &goods1->abGoods);
    cart->cartOps->add(cart, &goods2->abGoods);

    int total = cart->cartOps->getTotalCost(cart);
    assert(total == 120);

    return 0;
}
```

### Acknowledgements

-   Linux Kernel Hackers for the marco ' container_of '
