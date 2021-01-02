#include "sort.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    int test1[] = {1, 4, 2, 5, 8};
    sort_alg_shell_int(test1, 5);
    for (int i=0; i<5; i++)
    {
        printf("%d ", test1[i]);
    }
    printf("\n");
    return 0;
}
