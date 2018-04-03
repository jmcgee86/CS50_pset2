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
