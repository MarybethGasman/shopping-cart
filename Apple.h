#include "AbstractGoods.h"

struct Apple {
    struct AbstractGoodsOps abGoods;
    int num;
};
void Apple_increaseNum(struct AbstractGoodsOps *abGoods) {
    struct Apple *Apple = container_of(abGoods, struct Apple, abGoods);
    Apple->num++;
}
void Apple_decreaseNum(struct AbstractGoodsOps *abGoods) {
    struct Apple *Apple = container_of(abGoods, struct Apple, abGoods);

    Apple->num--;
}
int Apple_getPrice(struct AbstractGoodsOps *abGoods) {
    return 50;
}
int Apple_getNum(struct AbstractGoodsOps *abGoods) {
    struct Apple *Apple = container_of(abGoods, struct Apple, abGoods);
    return Apple->num;
}
struct AbstractGoodsOps AppleOps = {
    .getPrice = (int (*)(void *))Apple_getPrice,
    .getNum = (int (*)(void *))Apple_getNum,
    .increaseNum = (void (*)(void *))Apple_increaseNum,
    .decreaseNum = (void (*)(void *))Apple_decreaseNum,
};
struct Apple *Apple() {
    struct Apple *Apple = (struct Apple *)malloc(sizeof(*Apple));
    Apple->abGoods = (AppleOps);
    Apple->abGoods.list.next = NULL;
    Apple->num = 0;
    return Apple;
}