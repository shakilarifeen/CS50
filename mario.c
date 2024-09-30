#include <cs50.h>
#include <stdio.h>

void print_grid(int n);
void blank(int x);
void hash(int y);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (0 >= height || height > 8);
    print_grid(height);
}

void print_grid(int n)
{
    int p = n - 1;
    int q = 1;
    for (int a = 0; a < n; a++)
    {
        blank(p);
        hash(q);
        printf("  ");
        hash(q);
        printf("\n");
        p--;
        q++;
    }
}

void blank(int x)
{
    for (int a = 0; a < x; a++)
    {
        printf(" ");
    }
}

void hash(int y)
{
    for (int a = 0; a < y; a++)
    {
        printf("#");
    }
}