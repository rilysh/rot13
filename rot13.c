// A tiny rot13 implementation in C
// Public domain

#include <stdio.h>
#include <stdlib.h>

char rot13(int code) {
    if (code >= 65 && code <= 90) {
        code = 65 + (code - 65 + 13) % 26;
    } else if (code >= 97 && code <= 122) {
        code = 97 + (code - 97 + 13) % 26;
    }
    return code;
}

int main(int argc, char *argv[]) {
    if (argv[1] == NULL) {
        fprintf(stderr, "please provide a file");
        exit(1);
    }
    FILE *stream = fopen(argv[1], "r");
    
    if (stream == NULL) {
        fprintf(stderr, "%s not found", argv[1]);
        exit(1);
    }
    int c;
    while ((c = fgetc(stream)) != EOF) {
        c = rot13(c);
        fprintf(stdout, "%c", c);
    }
    exit(1);
}
