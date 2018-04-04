#include<stdio.h>
#include<cs50.h>
#include <string.h>
#include<ctype.h>

int main (void)
{
    string name;
    bool ready = true;
    do
    {
        name = get_string();
    }
    while (!name);

    for (int i=0; i<strlen(name); i++)
    {
        if(!isalpha(name[i]))
        {
            ready = true;
        }
        if(isalpha(name[i]) && ready)
        {
            printf("%c",toupper(name[i]));
            ready = !ready;
        }
    }
        printf("\n");
        return 0;
}