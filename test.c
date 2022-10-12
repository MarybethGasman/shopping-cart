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