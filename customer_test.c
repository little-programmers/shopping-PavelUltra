#include <assert.h>
#include <string.h>
#include "customer.h"

void test_fill_customer() {  
    FILE* f = fopen("data/cust1", "r");

    customer* got = fill_customer(f);
    fclose(f);

    customer want = {
        100,
        (product[2]){
            {"milk", 0, 1},
            {"bread", 0, 1},
        },
    };

    assert(got->money == want.money);
    for (int i = 0; i < 2; i++) {
        assert(!strcmp(got->products[i].name, want.products[i].name));
        assert(got->products[i].quantity == want.products[i].quantity);
    }
    free_customer(got);

    f = fopen("data/cust3", "r");

    got = fill_customer(f);
    fclose(f);

    want = (customer){
        1200,
        (product[1]){
            {"sugar", 0, 25},
        },
    };

    assert(got->money == want.money);
    for (int i = 0; i < 1; i++) {
        assert(!strcmp(got->products[i].name, want.products[i].name));
        assert(got->products[i].quantity == want.products[i].quantity);
    }
    free_customer(got);

    printf("Все тесты прошли успешно!\n");
}

int main() {
    test_fill_customer();
    return 0;
}
