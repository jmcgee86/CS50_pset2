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

    for (int i=0; i<strlen(name); i++)//iterates through each char in name string
    {
        if(!isalpha(name[i]))//checks if the char is not alphabetic, ie a space
        {
            ready = true; // if char is not alphabetic, set ready to true
        }
        if(isalpha(name[i]) && ready) // if char is alpha and ready is true...
        {
            printf("%c",toupper(name[i])); //prints letter char in upper case
            ready = !ready; //and sets ready to false
        }
    }
        printf("\n");
        return 0;
}