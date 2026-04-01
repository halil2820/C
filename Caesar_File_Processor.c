#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char encrypt_char(char ch, int key)
{
    if (isupper(ch))
        return ((ch - 'A' + key) % 26) + 'A';
    else if (islower(ch))
        return ((ch - 'a' + key) % 26) + 'a';

    return ch;
}

char decrypt_char(char ch, int key)
{
    if (isupper(ch))
        return ((ch - 'A' - key + 26) % 26) + 'A';
    else if (islower(ch))
        return ((ch - 'a' - key + 26) % 26) + 'a';

    return ch;
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage:\n");
        printf("Encrypt: %s -e input.txt key.txt output.txt\n", argv[0]);
        printf("Decrypt: %s -d input.txt key.txt output.txt\n", argv[0]);
        return 1;
    }

    char mode = argv[1][1];

    if (mode != 'e' && mode != 'd')
    {
        printf("Invalid mode. Use -e or -d.\n");
        return 1;
    }

    FILE *input = fopen(argv[2], "r");
    if (!input)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *keyFile = fopen(argv[3], "r");
    if (!keyFile)
    {
        printf("Error opening key file.\n");
        fclose(input);
        return 1;
    }

    FILE *output = fopen(argv[4], "w");
    if (!output)
    {
        printf("Error opening output file.\n");
        fclose(input);
        fclose(keyFile);
        return 1;
    }

    int key;
    if (fscanf(keyFile, "%d", &key) != 1)
    {
        printf("Invalid key format.\n");
        fclose(input);
        fclose(keyFile);
        fclose(output);
        return 1;
    }

    key = key % 26;  

    int ch;

    while ((ch = fgetc(input)) != EOF)
    {
        if (mode == 'e')
            ch = encrypt_char(ch, key);
        else
            ch = decrypt_char(ch, key);

        fputc(ch, output);
    }

    fclose(input);
    fclose(keyFile);
    fclose(output);

    printf("Operation completed successfully.\n");
    return 0;
}