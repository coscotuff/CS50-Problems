//Code to make mario pyramid of variable height

#include<stdio.h>

int main (void)
{
    int i = 0;
 // Taking height of pyramid(?)   
    do
    {
       printf("Height: ");
       scanf("%i", i);
    }
    while (i <= 1 || i >= 8);
    
    for (int k = 0; k < i; k++)
    {
        int l = i - k - 1;  // here we define l to create spaces that will correctly place each row.
// Part 1 : Put in the Initial spaces      
        for (int m = 0; m < l; m++)
        {
            printf(" ");
        }
// Part 2 : Put in first side of Pyramid 
        for (int j = 0; j <= k; j++)
        {
            printf("#");
        }
      
        printf(" ");
// Part 3 : Put in second side of Pyramid        
        for (int t = 0; t <= k; t++)
        {
            printf("#");
        }
        
        printf("\n");
    } 
}