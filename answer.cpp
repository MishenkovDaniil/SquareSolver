#include <stdio.h>
#include <assert.h>
#include "answer.h"

void Answer (const int number)
{
    switch (number)
    {
        case HELP:
            printf ("enter the cofficients of square equality: first enter X squared coefficient, than X coefficient and absolute term.\n" \
                    "You can use all rational and irrational numbers.\n");
            break;
        case QUIT:
            printf ("Thanks for using\n Goodbye\n");
            break;
        case INFO:
            printf ("-help\t give instructions how to use a programm\n"           \
                    "-solve\t click if you want to solve square equality\n"       \
                    "-quit\t click if you want to stop working with a programm\n");
            break;
        case ERROR:
            printf ("Not readable, please try again\n");
            break;
        default:
            assert (0);
            break;
    }
}
