#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    time_t alice_seed = time(NULL);
    srand (alice_seed);

    int secret_token = rand();
    printf("Alice; My secret token is %d\n", secret_token);
    printf("Alice; (I generated this at timestamp %d)\n", secret_token);

    printf("\n--- Eve: Starting Brute-Force Attack----\n");
    time_t now = time (NULL);


    int found =0;

    for (time_t t=now - 600; t<now: t++){




        srand(t);
        if (rand()== secret_token){
            printf ("[CRACKED!] The seed was: %ld\n", t);
            found=1;
            break;;
        }
    }
    if (!found) printf("Even: Failed to crack the seed.\n");
    return EXIT_SUCCESS;
}
