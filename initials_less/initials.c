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

/*
***Peer Review***
Excellent solution!

For more style points be consistent with where you place/start your comments
Right now they are on lines 11, 15, 18, and 20.
Some of them are on their own lines and some are on the same line as the code.
Some of them are indented and some of them are not.
This is visually displeasing and I am displeased

And if you want even more style points promt the user for their name on line 12 in the get_sting()
i.e. get_string("Enter your name here: ");
*/