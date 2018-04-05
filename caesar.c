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
    if (argc == 2)
    {
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
        else
        {
            printf("Usage: ./caesar k\n");
            return 1;
        }
        printf("\n");
        return 0;
    }