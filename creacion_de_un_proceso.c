#include <stdio.h>
#include <unistd.h>

int main() {
    int p2c[2], c2p[2];
    pipe(p2c);
    pipe(c2p);
    char s = 's';

    if (fork() > 0) {
        for (int i = 1; i <= 10000; i++) {
            printf("Padre: %d\n", i);
            fflush(stdout);
            write(p2c[1], &s, 1);
            read(c2p[0], &s, 1);
        }
    } else {
        for (int i = 10000; i >= 1; i--) {
            read(p2c[0], &s, 1);
            printf("Hijo: %d\n", i);
            fflush(stdout);
            write(c2p[1], &s, 1);
        }
    }
    return 0;
}
