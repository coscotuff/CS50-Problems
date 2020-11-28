#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main(void)
{   
    string t = get_string("Please Input a Text: ");
    
    int N_Letters, N_Words, N_Sentences;  //different parameters used

    N_Letters = N_Words = N_Sentences = 0;

    int length = strlen(t);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(t[i]))  // To literally go from char to char, checking whether or not we have an alphabet.
            N_Letters++;

        if (t[i] == ' ' && t[i + 1] != ' ' && i != length - 1) // Words have spaces between them.
        {
            N_Words++;
        }

        if ((t[i] == '.') || (t[i] == ':') || (t[i] == '!') || (t[i] == '?')) // sentences are being assumed to end with . / ! / ? / :
        {
            N_Sentences++;
        }
    }

    float S = ( N_Sentences / (float)N_Words ) * 100;
    float L = ( N_Letters / (float)N_Words ) * 100;

    float Readability_Index = ( 0.0588 * L ) - ( 0.296 * S ) - 16.8;

    int Grade = round(Readability_Index); //rounding it to nearest whole number
    
    if (Grade <= 1)
    {
        printf("Before Grade 1"); // now we procede to make the different possible cases.
    }

    else if (Grade > 1 || Grade < 16)
    {
        printf("Grade %i", Grade);
    }

    else (Grade >= 16)
    {
        printf("Grade 16+")
    }
}