#include <stdlib.h>
#include "shop.h"

// Fills struct "shop" from corresponding file.
shop* fill_shop(FILE* f) {
    char buf[20];
    int size = 1;
    shop* shop = malloc(sizeof(shop));
    shop->products = malloc(size * sizeof(product));     
    
    for (int i = 0; fgets(buf, sizeof(buf), f) != NULL; i++) {
        shop->products[i].name = malloc(sizeof(char) * 10);
        sscanf(buf, "%s %d %d", shop->products[i].name, &shop->products[i].price, &shop->products[i].quantity);
        if (size == i+1) {
            size <<= 1; 
            shop->products = realloc(shop->products, size*sizeof(product));
            set_defaults(&shop->products[i+1]);
        }
    }
    return shop;
}

void print_shop(shop* s) {
    printf("Список магазина:\n");
    printf("  Наименование Цена Кол-во\n");
    for (product* p = s->products; p->name != NULL; p++) {
        printf("  %-12s %4d %6d\n", p->name, p->price, p->quantity);
    }
}

void free_shop(shop* s) {
    for (product* p = s->products; p->name != NULL; p++) {
        free(p->name);
    }
    free(s->products);
    free(s);
}
