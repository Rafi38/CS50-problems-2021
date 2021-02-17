#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check input number
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    // check if valid digit
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    // take input
    string plaintext = get_string("plaintext: ");
    // start printing cipher text letter by letter
    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        int pt_ith; // "i"th char of plain text
        int ct_ith; // "i"th char of cypher text

        if (isupper(plaintext[i]))
        {
            pt_ith = plaintext[i] - 65;
            ct_ith = (pt_ith + key) % 26 + 65;
            printf("%c", ct_ith);
        }
        else if (islower(plaintext[i]))
        {
            pt_ith = plaintext[i] - 97;
            ct_ith = (pt_ith + key) % 26 + 97;
            printf("%c", ct_ith);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}