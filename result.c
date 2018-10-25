#include <string.h>
#include "result.h"

result shopping(shop* shop, customer* cust) {
    for (product* c = cust->products; c->name != NULL; c++) {
        for (product* s = shop->products; s->name != NULL; s++) {
            if (strcmp(c->name, s->name)) {
                continue;
            }
            if (s->quantity < c->quantity) {
                return not_enough_products;
            }
            if (cust->money < s->price * c->quantity) {
                return not_enough_money;
            }
            cust->money -= s->price * c->quantity;
            s->quantity -= c->quantity;
        }
    }
    return ok;
}

void print_result(result res) {
    if (res == ok) {
        printf("Я все купил!\n");
    } else if (res == not_enough_money) {
        printf("Денег не хватило.\n");
    } else if (res == not_enough_products) {
        printf("Что хотел, того не было.\n");
    }
}
