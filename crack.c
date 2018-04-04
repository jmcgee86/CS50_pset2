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
    string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (argc == 2)
    {
        pw_entered = argv[1];
        salt[0] = pw_entered[0];
        salt[1] = pw_entered[1];
        char guess_one[2];

    //first guess - 1 letter
        for (int i = 0; i<strlen(alpha); i++)
        {
            guess_one[0] = alpha[i];
            guess_one[1] = '\0';
            check = crypt(guess_one, salt);
            if (strcmp(pw_entered, check) == 0)
            {
                printf("%s\n", guess_one);
                return 0;
           }
        }

    //second guess - 2 letters
        for (int k = 0; k<strlen(alpha); k++)
        {
            char guess_two[3];
            guess_two[0] = alpha[k];

            for (int j = 0; j<strlen(alpha); j++)
            {
            guess_two[1] = alpha[j];
            guess_two[2] = '\0';
            check = crypt(guess_two, salt);
            if (strcmp(pw_entered, check) == 0)
            {
                printf("%s\n", guess_two);
                return 0;
            }
            }
        }

        //third guess - 3 letters

        for (int l = 0; l<strlen(alpha); l++)
        {

            char guess_three[4];
            guess_three[0] = alpha[l];

            for (int m = 0; m<strlen(alpha); m++)
            {
                guess_three[1] = alpha[m];
                for (int n = 0; n<strlen(alpha); n++)
                {
                    guess_three[2] = alpha[n];
                    guess_three[3] = '\0';
                    check = crypt(guess_three, salt);
                    if (strcmp(pw_entered, check) == 0)
                        {
                        printf("%s\n", guess_three);
                        return 0;
                        }
                }

            }
        }

        //fourth guess - 4 letters;

        for (int o = 0; o<strlen(alpha); o++)
        {

            char guess_four[5];
            guess_four[0] = alpha[o];

            for (int p = 0; p<strlen(alpha); p++)
            {
                guess_four[1] = alpha[p];
                for (int q = 0; q<strlen(alpha); q++)
                {
                    guess_four[2] = alpha[q];
                    for (int r = 0; r<strlen(alpha); r++)
                    {
                        guess_four[3] = alpha[r];
                        guess_four[4] = '\0';
                        check = crypt(guess_four, salt);
                        if (strcmp(pw_entered, check) == 0)
                        {
                        printf("%s\n", guess_four);
                        return 0;
                        }
                    }

                }

            }
        }

        //fifth guess - 5 letters;

        for (int s = 0; s<strlen(alpha); s++)
        {

            char guess_five[6];
            guess_five[0] = alpha[s];

            for (int t = 0; t<strlen(alpha); t++)
            {
                guess_five[1] = alpha[t];
                for (int u = 0; u<strlen(alpha); u++)
                {
                    guess_five[2] = alpha[u];
                    for (int v = 0; v<strlen(alpha); v++)
                    {
                        guess_five[3] = alpha[v];
                        for(int w = 0; w<strlen(alpha); w++)
                        {
                        guess_five[4] =alpha[w];
                        guess_five[5] = '\0';
                        check = crypt(guess_five, salt);
                        if (strcmp(pw_entered, check) == 0)
                        {
                        printf("%s\n", guess_five);
                        return 0;
                        }
                        }
                    }

                }

            }
        }

        printf("Password not found\n");
        return 0;
    }
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

}