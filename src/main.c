#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("cannot open file");
        exit(1);
    }
    
    char *buffer[16];
    int current_size = 0;
    
    do {
        current_size = fread(buffer, sizeof(char), sizeof(buffer), f);
    } while(current_size > 0);

    printf("%s\n", buffer);

    fclose(f);

    return 0;
}