#include <cs50.h>
#include <math.h>
#include <stdio.h>

void length(long number);
void first_number(long number);
void second_number(long number);
void luhn(long number);

int result;
int count;
int n = 0;
int num1;
int num2;

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    if (result == 0)
    {
        printf("AMEX\n");
    }
    else if (result == 1)
    {
        printf("MASTERCARD\n");
    }
    else if (result == 2)
    {
        printf("VISA\n");
    }
    else if (result == 3 || result == 4)
    {
        printf("INVALID");
    }
}

void length(long number) // counting the number of digits in the card
{
    long num = number;
    do
    {
        num = num / 10;
        n++;
    }
    while (num > 0);
}

void first_number(long number)
{
    int len1 = n - 1;
    num1 = number / pow(10, len1);
}

void second_number(long number)
{
    int len2 = n - 2;
    num2 = number / pow(10, len2);
    num2 = num2 % 10;
}

void luhn(long number)
{
    long num_1 = number;
    long num_2 = number / 10;
    int sum_1 = 0;
    int sum_2 = 0;
    int sum_3 = 0;
    int value_1;
    int value_2;

    for (int a = 0; a < n; a = a + 2) // to get sum of every other number starting from the last
    {
        value_1 = num_1 % 10;
        sum_1 = sum_1 + value_1;
        num_1 = num_1 / 100;
    }

    for (int b = 0; b < n; b = b + 2) // to get sum of every other number starting from the second-to-last digit
    {
        value_2 = num_2 % 10;
        sum_2 = sum_2 + value_2;
        num_2 = num_2 / 100;
    }
    sum_2 = sum_2 * 2;
    sum_3 = sum_1 + sum_2; // last sum of Luhn's algorithm

    if (sum_3 % 10 == 0)
    {
        if (n == 15 && num1 == 3 && (num2 == 4 || num2 == 7))
        {
            result = 0;
        }
        else if (n == 16 && num1 == 5 && (num2 == 1 || num2 == 2 || num2 == 3 || num2 == 4 || num2 == 5))
        {
            result = 1;
        }
        else if ((n == 13 || n == 16) && num1 == 4)
        {
            result = 2;
        }
        else
        {
            result = 3;
        }
    }
    else
    {
        result = 4;
    }
}
