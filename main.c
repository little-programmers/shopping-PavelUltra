#include "shop.h"
#include "customer.h"
#include "product.h"
#include "result.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Недостаточно аргументов для выполнения\n`Имя программы shop файл cust файл`\n");
        return -1;
    }
    
    FILE* shop_file = fopen(argv[1], "r");   // для примера введем несуществующий файл
    if (!shop_file) {
        perror("fopen failed");
        return -1;
    }
    
    shop* shop = fill_shop(shop_file);
    fclose(shop_file);
 
    FILE* cust_file = fopen(argv[2], "r");
    if (!cust_file) {
        perror("fopen failed");
        return -1;
    }

    customer* cust = fill_customer(cust_file);
    fclose(cust_file);

    print_result(shopping(shop, cust));

    print_shop(shop);
    print_customer(cust);

    free_shop(shop);
    free_customer(cust);
    return 0;
}
