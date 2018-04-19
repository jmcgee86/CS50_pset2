#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key;
    string plain_text;
    int shift;
    int key_index = 0;
    int l;
    if (argc == 2)
    {
        key = argv[1];
        l = strlen(key);
        for (int c = 0; c < l; c++)
        {
            if (!isalpha(key[c]))
            {
                printf("Usage: ./vigenere k\n");
                return 1;
            }
        }
        do
        {
            plain_text = get_string("plaintext: ");
        }
        while (strlen(plain_text) == 0);
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plain_text); i < n; i++)
        {
            if (!isalpha(plain_text[i]))
            {
                printf("%c", plain_text[i]);
            }
            else if (isupper(plain_text[i]))
            {
                shift = tolower(key[key_index]) - 'a';
                printf("%c", toupper((((plain_text[i] - 'A') + shift) % 26) + 'A'));
                key_index = (key_index + 1) % l;
            }
            else
            {
                shift = tolower(key[key_index]) - 'a';
                printf("%c", tolower((((plain_text[i] - 'a') + shift) % 26) + 'a'));
                key_index = (key_index + 1) % l;
            }
        }
    }
    else
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    printf("\n");
    return 0;
}

/*
****PEER REVIEW****
I appreciate how this solution is written to show the user the usage instead of a prompt to do something.
You have to stop and discern the purpose of the usage instead of being told/reminded what to do.


The variables and operations are easy to understand (i.e. key, key_index, shift) and the code looks clean/organized. Its clear to see order of operations happening on lines:

40              (Using the index of the string to select a letter/character and using the ASCII value of the character to equalize it by the value of the letter a/A)
41 and 47       (Where the character is printed after the letter selected from the string by the loop is equalized by its ASCII value and the value of a/A, and then its divided into 26 and the value of a/A is added back in)


My only recommendation is to store the number 26 as a character mostly because its a magic number but also beacuse if I had no idea what the
code was meant to do then I might not understand the point of using 26.




*/