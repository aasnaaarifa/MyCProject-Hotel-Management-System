#include <stdio.h>
#include <string.h>
#include "../include/booking.h"
#include "../include/rooms.h"

void book_room() {
    int rno, nights, foodOption = 0;
    char name[NAME_LEN];
    char foodType[10];
    int foodCost = 0;

    printf("\nEnter room number to book: ");
    if (scanf("%d", &rno) != 1) { while(getchar()!='\n'); return; }

    int idx = find_room_index_by_number(rno);
    if (idx == -1) { printf("Room %d not found\n", rno); return; }
    if (rooms[idx][1]) { printf("Room %d already occupied\n", rno); return; }

    while (getchar() != '\n'); 
    printf("Guest name: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Number of nights: ");
    if (scanf("%d", &nights) != 1) { while(getchar()!='\n'); return; }

    printf("Do you want food included? (1=Yes, 0=No): ");
    if (scanf("%d", &foodOption) != 1) { while(getchar()!='\n'); foodOption = 0; }

    if (foodOption) {
        printf("Food prices per night:\n1. Veg = 500\n2. Non-Veg = 700\nChoose (1=Veg, 2=Non-Veg): ");
        int choice;
        if (scanf("%d", &choice) != 1) { while(getchar()!='\n'); choice = 1; }
        if (choice == 1) {
            foodCost = 500;
            strcpy(foodType, "Veg");
        } else {
            foodCost = 700;
            strcpy(foodType, "Non-Veg");
        }
    }

    rooms[idx][1] = 1;
    strncpy(customer[idx], name, NAME_LEN-1);
    customer[idx][NAME_LEN-1] = '\0';

    int bill = (rooms[idx][2] + foodCost) * nights;
    totalRevenue += bill;

    if (foodOption)
        printf("Room %d booked for %s for %d night(s) with %s food. Bill = %d\n", 
               rno, customer[idx], nights, foodType, bill);
    else
        printf("Room %d booked for %s for %d night(s). Bill = %d\n", rno, customer[idx], nights, bill);
}