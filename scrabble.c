#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute(string word);
int compare(int a, int b);
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player_1 = get_string("Player 1: ");
    string player_2 = get_string("Player 2: ");

    int player1_score = compute(player_1);
    int player2_score = compute(player_2);

    int result = compare(player1_score, player2_score);

    if (result == 0)
    {
        printf("Player 2 wins!\n");
    }
    else if (result == 1)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute(string word)
{
    int score = 0;
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
        else
        {
            score += 0;
        }
    }
    return score;
}

int compare(int a, int b)
{
    int case_1;
    if (a < b)
    {
        case_1 = 0;
    }
    else if (a > b)
    {
        case_1 = 1;
    }
    else
    {
        case_1 = 2;
    }
    return case_1;
}
