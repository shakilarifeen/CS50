#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    int end_size;
    int born;
    int deceased;
    int final_num = 0;
    int count = 0;

    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);

    do
    {
        end_size = get_int("End Size: ");
    }
    while (end_size < start_size);

    if (start_size == end_size)
    {
        printf("Years: %i\n", count);
    }

    else
    {
        do
        {
            born = start_size / 3;                    // number of ilamas born during an year
            deceased = start_size / 4;                // number of ilamas passed away during an year
            final_num = start_size + born - deceased; // number of ilamas at the end of an year
            start_size = final_num;
            count++; // number of years elapsed
        }
        while (final_num < end_size);
        printf("Years: %i\n", count);
    }
}
