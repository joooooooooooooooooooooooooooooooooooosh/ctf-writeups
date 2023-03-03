#include <stdio.h>
#include <stdlib.h>

void print_flag() {
    // for security purposes, this function has been [[REDACTED]]
}

int main(int argc, char **argv) {
    int i = rand();
    printf("hi! your random number is: %d\n", i);

    if (i == -5) {
        print_flag();
    }

    return EXIT_SUCCESS;
}
