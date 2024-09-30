#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int real_digit(string text1);
void rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2) // more than 01 key given
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else // Only 01 key provided
    {
        if (real_digit(argv[1]) == 0) // key is valid
        {
            if (atoi(argv[1]) < 0) // key is negative
            {
                printf("Usage: %s key\n", argv[0]);
                return 2;
            }
            else if (atoi(argv[1]) > 0) // key is positive
            {
                string plaintext = get_string("plaintext:  ");
                printf("ciphertext: ");
                for (int i = 0, length = strlen(plaintext); i < length; i++)
                {
                    rotate(plaintext[i], atoi(argv[1]));
                }
                printf("\n");
                return 0;
            }
        }
        else // key is not a digit
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }
}

int real_digit(string text1) // checking if the key provided is valid
{
    int truedigit = 0;
    for (int i = 0, length = strlen(text1); i < length; i++)
    {
        if (isdigit(text1[i]))
        {
            truedigit += 0;
        }
        else
        {
            truedigit += 1;
        }
    }
    return truedigit;
}
void rotate(char c, int n)
{
    int rota = (int) c;
    int new1; // new number after rotation
    int new11 = 0;
    int new2;          // char of new1
    int new3 = n % 26; // actual rotation value in case n is more than 25
    if (isalpha(c))    // is alphabetical
    {

        if (isupper(c)) // character considered is capital
        {
            new1 = rota + new3;
            if (new1 > 90)
            {
                new11 = new1 - 26;
            }
            else if (new1 < 90)
            {
                new11 = new1;
            }
            new2 = (char) new11;
            printf("%c", new2);
        }
        else if (islower(c)) // character considered is capital
        {
            new1 = rota + new3;
            if (new1 > 122)
            {
                new11 = new1 - 26;
            }
            else if (new1 < 122)
            {
                new11 = new1;
            }
            new2 = (char) new11;
            printf("%c", new2);
        }
    }
    else // not alphabetical
    {
        printf("%c", c);
    }
}
