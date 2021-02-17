#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");

    int count_letter = 0, count_word = 1, count_sentence = 0, len = strlen(text);

    // check every char
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count_letter++; // is alpha = letter
        }

        else if (text[i] == ' ' && text[i + 1] != ' ')
        {
            count_word++; // if space = word
        }

        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') // new sentence
        {
            count_sentence++;
        }
    }

    //count everything
    float L = (float)count_letter / (float)count_word;
    float S = (float)count_sentence / (float)count_word;
    float index = 0.0588 * (100 * L) - 0.296 * (100 * S) - 15.8;
    index = round(index);

    if (index < 1) //final result
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16 && index >= 1)
    {
        printf("Grade %i\n", (int)index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}