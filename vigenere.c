#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000

char *viginere_encrypt(const char *plaintext, const char *key)
{
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int key_index = 0;
    
    char* output = malloc(sizeof(char) * (plaintext_len + 1));
    for (int i = 0; i < plaintext_len; i++)
    {
        char symbol = plaintext[i];
        if (isalpha(symbol))
        {
            char key_symbol = toupper(key[key_index % key_len]);
            int shift = key_symbol - 'A';
            if (isupper(symbol))

            {
                output[i] = ((symbol - 'A' + shift) % 26) + 'A';
            }
            else if (islower(symbol))
            {
                output[i] = ((symbol - 'a' + shift) % 26) + 'a';
            }
            key_index++;
        }
        else
        {
            output[i] = plaintext[i];
        }
    }
    output[plaintext_len] = '\0';
    return output;
}
int main()
{
    char plaintext[MAXN];
    scanf("%s", plaintext);
    char key[MAXN];
    scanf("%s", key);

    char *cipher = viginere_encrypt(plaintext, key);
    printf("Encrypt: %s\n", cipher);
    return EXIT_SUCCESS;
}
