#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    int n = 2;
    int remain;
    do
    {
        remain = number % n;
        n++;
    }
    while (remain != 0);
    if (number == (n - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
