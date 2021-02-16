#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card_num;
    int get_digit;
    int count_digits = 0;
    int other_digit;
    int other_sum = 0;
    long start_number = 0;
    int checksum = 0;
    bool visa_digits;
    bool amex_start;
    bool mcard_start;

    //Get the card number
    card_num = get_long("What's is you credit card card_number? ");
    //Run the loop while there are numbers on the card
    while (card_num != 0)
    {
        //Get the last digit
        get_digit = card_num % 10;

        //Separete the other digits
        if (count_digits % 2 != 0)
        {
            //Multiply the other digit by two
            other_digit = get_digit * 2;

            //If the multiplication gets 2 digits than sum the digits
            other_sum += (other_digit % 100 == 0) ? other_digit :
                         other_digit % 10 + other_digit / 10;
        }
        else
        {
            //Sum of the digits that weren’t multiplied by 2
            checksum += get_digit;
        }
        //Get's the start number
        if (card_num / 100 == 0 && start_num == 0)
        {
            start_num = card_num;
        }

        //Eliminate the last digit from the card numbem then increment the count
        card_num = card_num / 10;
        count_digits++;
    }
    //Get checksum las digit
    checksum = (checksum + other_sum) % 10;

    //Check the condition for each card then print
    visa_digits = count_digits == 13 || count_digits == 16;

    amex_start = start_num == 34 || start_num == 37;

    mcard_start = start_num == 51 || start_num == 52 || start_num == 53 ||
                       start_num == 54 || start_num == 55;

    if (checksum == 0 && count_digits == 15 && amex_start)
    {
        printf("AMEX\n");
    }
    else if (checksum == 0 && start_num / 10 == 4 && visa_digits)
    {
        printf("VISA\n");
    }
    else if (checksum == 0 && count_digits == 16 && mcard_start)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

 
