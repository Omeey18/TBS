#include <stdio.h>
#include "header.h"

void line()
{
    printf("-----------------------------------------------------------------\n");
}

/**
 * @brief Set the Blue Color object
 *
 */
void setBlueColor()
{
    printf("\033[1;34m"); // switching color to blue
}
/**
 * @brief Set the Default Color object
 *
 */
void setDefaultColor()
{
    printf("\033[0m"); // switching color to default
}
/**
 * @brief Set the Red Color object
 * 
 */
void setRedColor()
{
    printf("\033[1;31m"); // switching color to red
}
void setGreenColor()
{
    printf("\033[1;32m"); // switching color to red
}