#include <cs50.h>
#include <stdio.h>
int main(void)
{
    long number = get_long("Number: ");
    long original = number;
    //printf("You typed:%li\n",number);
    //int digit = number%10;
    //printf("Last digit: %i\n",digit);
    //number = number/10;
    //printf("Romaining number:%li\n",number);
    int sum = 0;
    int position = 0;
    while (number>0)
    {
        int digit = number%10;
        if (position %2 ==1)
        {
            int x = digit *2;
            sum += x/10 +x%10;
        }
        else
        {
            sum+= digit;
        }
        number = number/10;
        position++;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    int length = 0;
    long temp = original;
    while (temp >0)
    {
        temp = temp/10;
        length++;
    }
    long start = original;
    while (start >= 100)
    {
        start = start /10;
    }
    int first_two = start;
    int first = start/10;
    if(length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two >= 51 && first_two <= 55) )
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16)&& first == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
