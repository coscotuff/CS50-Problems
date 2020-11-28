#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>

int condition_validity(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || condition_validity(argv[1]) == 1)
    {
        return 1;
    }

    int k = atoi(argv[1]);

    string text = get_string("plainttext : ");

    int length = strlen(text);

    printf("ciphertext : ");
    
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            char pole = 'A';
            
            if (islower(text[i]))
                    pole = 'a';
            
            printf("%c", (text[i] + k - pole ) % 26 + pole);
        }

        else
            printf("text[i]");
    }

    printf("\n");

}

int condition_validity(string s)
{
    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(s[i]))
            return 1;
    }

    return 0;
}

