#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])

{
//Verify that command line arg has a argc of 2, else print error and exit

    if (argc != 2)
    {
        printf ("Erroneous command-line argument\n");
        return 1;
    }

//Verify that command line arg is only letters, else print error and exit

    string key = argv[1];
    int keylen = strlen(key);
    for (int i = 0; i < keylen; i++)
    {
        if (!isalpha(key[i]))
        {
            printf ("Erroneous command-line argument\n");
            return 1;
        }
    }
// Prompt user for text to be encyrpted
    string plaintext;
    do
    {
        printf ("plaintext:");
        plaintext = get_string();
    }
    while (plaintext == NULL);

//Encrypt text and print output
    printf ("ciphertext: ");
    for (int j = 0, i = 0, m = strlen(plaintext); j < m; j++)
    {
//Loop through key continously
        i = i % keylen;
//Encrypt text
        if (isupper(plaintext[j]) && isupper(key[i]))
            {
                printf ("%c", ((((plaintext[j] - 'A') + (key[i] - 'A')) %26) + 'A'));
                i++;
            }
        else if (islower(plaintext[j]) && islower(key[i]))
            {
                printf ("%c", ((((plaintext[j] - 'a') + (key[i] - 'a')) %26) + 'a'));
                i++;
            }
        else if (islower(plaintext[j]) && isupper(key[i]))
            {
                printf ("%c", ((((plaintext[j] - 'a') + (key[i] - 'A')) %26) + 'a'));
                i++;
            }
        else if (isupper(plaintext[j]) && islower(key[i]))
            {
                printf ("%c", ((((plaintext[j] - 'A') + (key[i] - 'a')) %26) + 'A'));
                i++;
            }
        else
            {
                printf ("%c", plaintext[j]);
            }
    }
    {
        printf ("\n");
    }
    return 0;
}
