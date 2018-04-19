#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key;
    string k;
    string plain_text;
    int shift;
    if (argc!=2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

        k = argv[1];
        key = atoi(k);
        printf("Key: %i\n", key);
        shift = key % 26; //take key entered and calculates shift using % to reduce large int entered - helps speed up and simplify.
        do
        {
            plain_text = get_string("plaintext: ");
        }
        while (strlen(plain_text) == 0);
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plain_text); i < n; i++) //iterates through user generated text and prints out encoded text using shift
        {
            if (!isalpha(plain_text[i])) //if character isn't upper or lowercase letter, prints out original character as specified in challenge description
            {
                printf("%c", plain_text[i]);
            }
            else if (isupper(plain_text[i])) //if char is upper, converts to 0-25 alpha numeric notation, adds shift, % by 26 for wrap around and adds back ascii value of A to convert encoded char back to ascii to print
            {
                printf("%c", toupper((((plain_text[i] - 'A') + shift) % 26) + 'A'));
            }
            else
            {
                printf("%c", tolower((((plain_text[i] - 'a') + shift) % 26) + 'a')); //if char is lower, converts to 0-25 alpha numeric notation, adds shift, % by 26 for wrap around and adds back ascii value of A to convert encoded char back to ascii to print
            }
        }

        printf("\n");
        return 0;
    }

/*
****PEER REVIEW****

Interesting to see this written with a Do/While loop, I did something different with my code

Line 22: the int shift is a helpful tactic to store the interger after % 26 is applied to it.
This keeps the code organized

I would recommend storing strlen(plain_text) as a variable.
Its only used twice but it could be considered good practice and add to the organization of the code.
But on a side note I rememeber having issues with scope when I stored strlen(plain_text) as a variable so just dont do it the way I did.

*/