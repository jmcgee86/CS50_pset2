#include<stdio.h>
#include<cs50.h>
#include <string.h>
#include<ctype.h>

int main(void)
{
    string name;
    do
    {
        //prompts user to enter name as string
        name = get_string();
    }
    while (!name);
//prints first initial in uppercae
    printf("%c", toupper(name[0]));

    for (int i = 1; i < strlen(name); i++)//iterates through remain characters in name string
    {
        if (!isalpha(name[i]))//if char is a space, prints next char in uppercase
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
    return 0;
}