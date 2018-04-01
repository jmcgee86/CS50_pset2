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
//int alpha_position;
int shift;
    if (argc == 2)
    {
        k = argv[1];
        key = atoi(k);
        printf("Key: %i\n", key);
        shift = key%26;

        do
        {
            plain_text = get_string("plaintext: ");
        }
        while (strlen(plain_text)==0);
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plain_text); i < n; i++)
        {
        if (!isalpha(plain_text[i]))
        {
            printf("%c", plain_text[i]);
        }
        else if (isupper(plain_text[i]))
        {
            //alpha_position = plain_text[i] - A;

            printf("%c", toupper((((plain_text[i] - 'A') + shift) % 26) + 'A'));
        }
        else
        printf("%c", tolower((((plain_text[i] - 'a') + shift) % 26) + 'a'));
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