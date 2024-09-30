#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute(int count, int count_1, int count_2);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int index = compute(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (1 <= index && index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            count += 1;
        }
        else
        {
            count += 0;
        }
    }
    return count;
}

int count_words(string text)
{
    int count_1 = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isblank(text[i]))
        {
            count_1 += 1;
        }
        else
        {
            count_1 += 0;
        }
    }
    count_1 += 1; // counting the ending word of the sentence
    return count_1;
}

int count_sentences(string text)
{
    int count_2 = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_2 += 1;
        }
    }
    return count_2;
}

int compute(int count, int count_1, int count_2)
{
    float avg_let = (count / (float) count_1) * 100;
    float avg_sen = (count_2 / (float) count_1) * 100;

    float index_1 = 0.0588 * avg_let - 0.296 * avg_sen - 15.8;
    int index = round(index_1);
    return index;
}
