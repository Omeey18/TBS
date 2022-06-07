#ifndef HEADER_H
#define HEADER_H

/***************************************
* MACROS
****************************************/
#define C_SIZE 30
/*function declaration.*/
void printList();
void insertFirst(char *movie_name, char *theater_name, int time_slots, int total_seats, int avail_seat, int booked_seats);
void theaterList(char *movie_theater);
void line();

#endif //HEADER_H