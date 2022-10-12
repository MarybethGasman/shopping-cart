#include "AbstractGoods.h"

struct Orange {
    struct AbstractGoodsOps abGoods;
    int num;
};
void orange_increaseNum(struct AbstractGoodsOps *abGoods) {
    struct Orange *orange = container_of(abGoods, struct Orange, abGoods);
    orange->num++;
}
void orange_decreaseNum(struct AbstractGoodsOps *abGoods) {
    struct Orange *orange = container_of(abGoods, struct Orange, abGoods);

    orange->num--;
}
int orange_getPrice(struct AbstractGoodsOps *abGoods) {
    return 10;
}
int orange_getNum(struct AbstractGoodsOps *abGoods) {
    struct Orange *orange = container_of(abGoods, struct Orange, abGoods);
    return orange->num;
}
struct AbstractGoodsOps orangeOps = {
    .getPrice = (int (*)(void *))orange_getPrice,
    .getNum = (int (*)(void *))orange_getNum,
    .increaseNum = (void (*)(void *))orange_increaseNum,
    .decreaseNum = (void (*)(void *))orange_decreaseNum,
};
struct Orange *Orange() {
    struct Orange *orange = (struct Orange *)malloc(sizeof(*orange));
    orange->abGoods = (orangeOps);
    orange->abGoods.list.next = NULL;
    orange->num = 0;
    return orange;
}