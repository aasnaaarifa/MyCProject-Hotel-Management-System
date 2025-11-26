#include <stdio.h>
#include <string.h>
#include "../include/rooms.h"

int rooms[NUM_ROOMS][3];
char customer[NUM_ROOMS][NAME_LEN]; 
char roomType[NUM_ROOMS][10] = {"AC", "Non-AC", "AC", "Non-AC", "AC", 
                                "Non-AC", "Non-AC", "AC", "Non-AC", "AC"};
int totalRevenue = 0;

void init_rooms() {
    for (int i = 0; i < NUM_ROOMS; ++i) {
        rooms[i][0] = 101 + i;        
        rooms[i][1] = 0;            
        rooms[i][2] = 2000 + (i * 250); 
        customer[i][0] = '\0';
    }
}

void show_rooms() {
    printf("\nRoom\tType\tStatus\t\tPrice\tGuest\n");
    printf("----\t----\t------\t\t-----\t-----\n");
    for (int i = 0; i < NUM_ROOMS; ++i) {
        printf("%d\t%s\t%s\t%d\t%s\n",
               rooms[i][0],
               roomType[i],
               rooms[i][1] ? "Occupied" : "Available",
               rooms[i][2],
               rooms[i][1] ? customer[i] : "-");
    }
}

int find_room_index_by_number(int rno) {
    for (int i = 0; i < NUM_ROOMS; ++i)
        if (rooms[i][0] == rno) return i;
    return -1;
}