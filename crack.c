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
        char guess_one[2];
        //guess_two[2];
   // while (strcmp(pw_entered, check) != 0)
    //{

    //first guess - 1 letter
        for (int i = 0; i<strlen(alpha); i++)
        {
            guess_one[0] = alpha[i]; //alphi[i] is placeholder, write code to iterate through alphabet (upper and lower) to check for single char password match
            guess_one[1] = '\0';
            guess = guess_one;
            check = crypt(guess_one, salt);
            //guess = guess_one;
            //eprintf("%d", i);
            //eprintf("%s\n", guess);
            //eprintf("%s", check);
        }

    //second guess - 2 letters
        for (int k = 0; k<strlen(alpha); k++)
        {
            char guess_two[3];
            guess_two[0] = alpha[k];

            for (int j = 0; j<strlen(alpha); j++)
            {
            //guess_two[0] = alpha[i];
            guess_two[1] = alpha[j];
            guess_two[2] = '\0';
            //guess_two =
            check = crypt(guess_two, salt);
            guess = guess_two;
            //eprintf("%d", i);
            //eprintf("%d", j);
            //eprintf("%c%c\n", guess_two[0], guess_two[1]);
          //eprintf("%s\n", guess);
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
                    guess = guess_three;
                    //eprintf("%s\n",guess_three);
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
                        //guess = guess_four;
                        //eprintf("%s", guess_four);
                        if (strcmp(pw_entered, check) == 0)
                        {
                        eprintf("%s", guess_four);
                        return 0;
                        }
                    }
                    // guess_three[3] = '\0';
                    // check = crypt(guess_three, salt);
                    // guess = guess_three;
                    //eprintf("%s\n",guess_three);
                }

            }
        }

        printf("Password not found\n");
        return 0;

    //}
    //printf("%c\n", guess_one[0]);
    //printf("%s\n", guess);
    //return 0;
    }
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

}