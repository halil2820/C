#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // за isupper()
#define MAXN 1000
char caesar_encrypt_char(char p, int k) {
    if (isupper(p)) {
        return ( (p - 'A' + k) % 26 ) + 'A';
    }
    else if(islower(p))
    {
        return ( (p - 'a' + k) % 26 ) + 'a';
    }
    return p; // Ако не е буква (напр. цифра), връщаме без промяна
}

char caesar_decrypt_char(char p, int k) {
    if (isupper(p)) {
        return ( (p - 'A' - k + 26) % 26 ) + 'A';
    }
    else if(islower(p))
    {
        return ( (p - 'a' - k + 26) % 26 ) + 'a';
    }
    return p;
}


char* caesar_dencrypt(char *text, int key) {
    int len = strlen(text);
    char* plaintext = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        result[i] = caesar_encrypt_char(text[i], key);
    }
    result[len] = '\0';
    return result;
}
int main() {
    char plaintext[MAXN] = "Hello";
    int key = 3;
   
    printf("Original: %s\n", text);
    for (int i = 0; text [i] != '\0'; i++) {
        text[i]= caesar_encrypt_char(text[i], key);
    } 
    printf("Decrypted: %s\n", text);
    for int i = 0; text [i] != '\0'; i++) {
        text[i]= caesar_decrypt_char(text[i], key);
    }  
    printf("Decrypted: %s\n", text);
    return 0;
}                           