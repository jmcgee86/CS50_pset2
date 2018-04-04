#include<stdio.h>
#include<cs50.h>
#include <string.h>
#include<ctype.h>

int main (void)
{
    string name;
    //bool ready = true;
    do
    {
        name = get_string();
    }
    while (!name);

    printf("%c",toupper(name[0]));

    for (int i=1; i<strlen(name); i++)
    {
//    printf("%c",toupper(name[0]));

        if(!isalpha(name[i]))
        {
        //i++;
        printf("%c", toupper(name[i+1]));
        }
    }
        printf("\n");
        return 0;
}