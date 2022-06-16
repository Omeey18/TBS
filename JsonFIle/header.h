#ifndef HEADER_H
#define HEADER_H

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
int printMovies();
void printScreen(char *choosed_movie);
int display_seats(char *choosed_movie, int screen_no);
void removeDuplicate();

void line();
void setBlueColor();
void setDefaultColor();
void setRedColor();
void setGreenColor();


#endif //HEADER_H