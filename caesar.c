#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string k = argv[1];
        int key;
        key = atoi(k);
        printf("%i", key);
    }
    else
    {
        printf("ERROR: Too many args provided\n");
        return 1;
    }
}