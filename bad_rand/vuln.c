#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    sleep(1);
    time_t seed = time(NULL);
    srand(seed);
    int secret = rand();

    puts("(g)uess my secret");
    puts("(s)how my secret");
    printf("choose one: ");
    fflush(stdout);

    int c = fgetc(stdin);

    if (c == 'g') {
        printf("What's my secret? ");
        fflush(stdout);

        int guess;
        scanf("%d", &guess);
        if (guess == secret) {
            puts("COMP6841{the real flag will be here on the server!} (this is not the real flag)");
        } else {
            puts("nope. better luck next time");
        }
    } else if (c == 's') {
        printf("%d\n", secret);
        printf("%lx\n", seed);
    } else {
        printf("%c is not an option!\n", c);
        puts("pick either g or s");
    }

    fflush(stdout);
}
