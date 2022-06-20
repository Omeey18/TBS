#ifndef HEADER_H
#define HEADER_H
#include <stdbool.h>

/***************************************
* MACROS
****************************************/
#define C_SIZE 30
#define READERSIZE 5024

/***************************************
* FUNCTION DECLARATION
****************************************/
/*function declaration.*/
void insertFirst(char *movie_name, int screen, int total_seats, int seats_index[],int n_booked);
void printList();
void storeData();
void readData();
char *printMovies();
void printScreen(char *choosed_movie);
int display_seats(char *choosed_movie, int screen_no);
void removeDuplicate();
int adminWork();
int resetAllSeats();
int resetSeats();
int getData();
struct node* deleteFirst();
bool isEmpty();

void line();
void setBlueColor();
void setDefaultColor();
void setRedColor();
void setGreenColor();

int init();

#endif //HEADER_H