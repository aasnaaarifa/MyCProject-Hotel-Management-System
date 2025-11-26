#ifndef ROOMS_H
#define ROOMS_H

#define NUM_ROOMS 10
#define NAME_LEN 50

extern int rooms[NUM_ROOMS][3];
extern char customer[NUM_ROOMS][NAME_LEN];
extern char roomType[NUM_ROOMS][10];
extern int totalRevenue;

void init_rooms();
void show_rooms();
int find_room_index_by_number(int rno);

#endif