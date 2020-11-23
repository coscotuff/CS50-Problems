#include<stdio.h>

int main(void)
{
    int p;
    do // this loop is there to ensure that if we put a wrong card no by mistake, we can simply enter it again.
    {
        long CCNumber;
        do
        {
            printf("Please enter a valid CC Number: ");
            scanf("%ld", &CCNumber);
        }
        while (CCNumber <= 0);

        long CheckCCNumber = CCNumber;
        int addition = 0;
// for the 1st set of Numbers
        while (CheckCCNumber > 0)
        {
            int FirstSet = CheckCCNumber % 10; //gives last digit and alternate ones after that.
            addition += FirstSet;
            CheckCCNumber = CheckCCNumber / 100; // helps to skip ahead 2 digits.
        }
//for the Second set of Numbers
        CheckCCNumber = CCNumber / 10;
        while (CheckCCNumber > 0)
        {
            int SecondSet = CheckCCNumber % 10; //gives second last digit and alternate ones after that.
            int TwiceSecondSet = SecondSet * 2;
            addition += (TwiceSecondSet % 10) + (TwiceSecondSet / 10); // to take the chance of TwiceSecondSet being 2 digits.
            CheckCCNumber = CheckCCNumber / 100;
        }
//how many digits it is
        int count = 0;
        CheckCCNumber = CCNumber;
        while (CheckCCNumber > 0)
        {
            CheckCCNumber = CheckCCNumber / 10;
            count++;
        }
// finding what we will be dividing by to get the first or first 2 digits.
        long Divisor = 1;
        CheckCCNumber = CCNumber;
        for (int i = 0; i < count - 2; i++)
        {
            Divisor = Divisor * 10;
        }

        int FirstDigit = CCNumber / Divisor;
        int FirstTwoDigits = (CCNumber * 10) / Divisor;
// And finally, the job itself 
        if (addition % 10 == 0)
        {
            if ((count == 13 || count == 16) && FirstDigit == 4)
            {
                printf("VISA\n");
                p = 0;
            }
       
            else if ((50 < FirstTwoDigits || FirstTwoDigits < 56) && count == 16)
            {
                printf("Mastercard\n");
                p = 0;
            }
        
            else if ((FirstTwoDigits == 34 || FirstTwoDigits == 37) && count == 15)
            {
                printf("American Express\n");
                p = 0;
            }
       
            else
            {
                printf("VALID, but Not Identified\n");
                p = 0;
            }
        }

        else
        {
            printf("INVALID\n");
            p = 1;
        }
    
    } while (p == 1);


}