#include <stdio.h>
#include "../include/checkout.h"
#include "../include/rooms.h"

void checkout_room() {
    int rno;
    printf("\nEnter room number to checkout: ");
    if (scanf("%d", &rno) != 1) { while(getchar()!='\n'); return; }

    int idx = find_room_index_by_number(rno);
    if (idx == -1) { printf("Room %d not found\n", rno); return; }
    if (!rooms[idx][1]) { printf("Room %d is already available\n", rno); return; }

    rooms[idx][1] = 0;
    customer[idx][0] = '\0';
    printf("Checked out room %d. It is now available\nCOME AGAIN!!", rno);
}