#include <stdio.h>
#include "../include/rooms.h"
#include "../include/booking.h"
#include "../include/checkout.h"

int main() {
    init_rooms();
    int choice;
    do {
        printf("\n=== Hotel Management ===\n");
        printf("1. Show rooms\n");
        printf("2. Book room\n");
        printf("3. Checkout room\n");
        printf("4. Exit\n");
        printf("Choose: ");
        if (scanf("%d", &choice) != 1) { while(getchar()!='\n'); choice = -1; }
        switch (choice) {
            case 1: show_rooms(); break;
            case 2: book_room(); break;
            case 3: checkout_room(); break;
            case 4: printf("Exiting\n"); break;
            default: printf("Invalid option\n");
        }
    } while (choice != 4);

    return 0;
}