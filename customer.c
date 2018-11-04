#include "customer.h"

// Fills struct "customer" from corresponding file.
customer* fill_customer(FILE* f) {
    int size = 1;
    customer* cust = malloc(sizeof(customer)); 
    cust->money = 0;
    cust->products = malloc(size * sizeof(product));
    
    char buf[20];        
    fgets(buf, sizeof(buf), f);
    sscanf(buf, "%d", &cust->money);
    
    for (int i = 0; fgets(buf, sizeof(buf), f) != NULL; i++) {
        cust->products[i].name = malloc(sizeof(char) * 10);
        sscanf(buf, "%s %d", cust->products[i].name, &cust->products[i].quantity);
        if (size == i+1) {
            size <<= 1;
            cust->products = realloc(cust->products, size*sizeof(product));
            for (int j = i+1; j < size; j++) {
                set_defaults(&cust->products[j]);
            }
        }
    }   
    return cust;
}

void print_customer(customer* c) {
    printf("Список покупателя:\n");
    printf("  Кол-во денег: %d\n", c->money);
    printf("  Наименование Кол-во\n");
    for (product* p = c->products; p->name != NULL; p++) {
        printf("  %-12s %6d\n", p->name, p->quantity);
    }
}

void free_customer(customer* c) {
    for (product* p = c->products; p->name != NULL; p++) {
        free(p->name);
    }
    free(c->products);
    free(c);
}
