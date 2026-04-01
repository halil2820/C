#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void vigenere_encrypt(const char *plaintext, const char *key, char *output) {
    int key_len = strlen(key);
    int key_index = 0; // Следим коя буква от ключа ползваме

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char p = toupper(plaintext[i]);

        if (isalpha(p)) {
            // 1. Подготвяме отместването (Shift) от ключа
            char k_char = toupper(key[key_index % key_len]);
            int shift = k_char - 'A';

            // 2. Криптираме
            // TODO: output[i] = ... (Не забравяйте 'A', % 26)

            // 3. Минаваме на следващата буква от ключа
            key_index++;
        } else {
            // Не криптираме специални символи
            output[i] = plaintext[i];
        }
    }
    output[strlen(plaintext)] = '\0';
}
