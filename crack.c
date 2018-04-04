#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    string pw_entered;
    string check;
    char salt[2];
    //char guess_two[2];
    string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (argc == 2)
    {
        pw_entered = argv[1];
        salt[0] = pw_entered[0];
        salt[1] = pw_entered[1];
        //eprintf("%s", salt);
        string guess = NULL;
        //eprintf("%s", guess);
        char guess_one[1];
        //guess_two[2];
    while (strcmp(pw_entered, check) != 0)
    {
        for (int i = 0; i<strlen(alpha); i++)
        {
            guess_one[0] = alpha[i]; //alphi[i] is placeholder, write code to iterate through alphabet (upper and lower) to check for single char password match
            //guess = guess_one;
            check = crypt(guess_one, salt);
            //guess = guess_one;
            //eprintf("%d", i);
            //eprintf("%s\n", guess_one);
        }
        for (int k = 0; k<strlen(alpha); k++)
        {
            //guess_one[0] = alpha[i]; //alphi[i] is placeholder, write code to iterate through alphabet (upper and lower) to check for single char password match
            //check = crypt(guess_one, salt);
            char guess_two[2];
            guess_two[0] = alpha[k];

            for (int j = 0; j<strlen(alpha); j++)
            {
            //guess_two[0] = alpha[i];
            guess_two[1] = alpha[j];
            //guess_two =
            check = crypt(guess_two, salt);
            //guess = guess_two;
            //eprintf("%d", i);
            //eprintf("%d", j);
            //eprintf("%c%c\n", guess_two[0], guess_two[1]);
            eprintf("%s\n", guess_two);
            }
        }
        printf("Password not found\n");
        return 0;

    }
    //printf("%c\n", guess_one[0]);
    printf("%s\n", guess);
    return 0;
    }
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

}