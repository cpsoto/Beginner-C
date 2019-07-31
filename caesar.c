#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])

{
    //Make sure argument count is 2, if not, print error and exit program, return 1
    if (argc != 2)
    {
    printf ("Erroneous command-line argument\n");
    return 1;
    }
    //Convert argv[1] into an int
    string key = argv[1];
    int X = atoi(key);

    //Ask user for plaintext to be cyphered
    string plaintext;
    do
    {
        printf ("plaintext:");
        plaintext = get_string();
    }
    while (plaintext == NULL);

    //Cypher plaintext and print cyphertext
    printf ("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
    if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf ("%c", (((plaintext[i] - 65) + X) % 26) + 65);
            }
            if (islower(plaintext[i]))
            {
                printf ("%c", (((plaintext[i] - 97) + X) % 26) + 97);
            }
        }
    //leave non alphabetical character as they are
    else
    {
        printf ("%c", (plaintext[i]));
    }

    }
    //print new line return 0, all is good
    printf ("\n");
    return 0;
}
