#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "shop.h"

void test_fill_shop() {  
    FILE* f = fopen("data/test_shop", "r");

    shop* got = fill_shop(f);
    fclose(f);

    shop want = {
        (product[3]){
            {"butter", 70, 20},
            {"cheese", 100, 15},
            {"milk", 40, 17},
        },
    };

    for (int i = 0; i < 3; i++) {
        assert(!strcmp(got->products[i].name, want.products[i].name));
        assert(got->products[i].price == want.products[i].price);
        assert(got->products[i].quantity == want.products[i].quantity);
    }
    free_shop(got);

    printf("Все тесты прошли успешно!\n");
}

int main() {
    test_fill_shop();
    return 0;
}
