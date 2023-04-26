#include "check.h"
#include "tree.h"

void checkValue(int* value)
{
    while (scanf("%d", value) == 0 || *value < 0 || *value > 1 || getchar() != '\n')
    {
        printf("Error: wrong input! Try again\n>");
        rewind(stdin);
    }
}