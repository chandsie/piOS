#include <stdio.h>
#include <stdlib.h>

typedef enum TokenType {
    IDENTIFIER,
    INTEGER,
    OPERATOR
} TokenType;

typedef struct Token {
    TokenType token_type;
    union {
        int integer;
        char* raw_value;
    } token_value;
} Token;

int lexer(FILE* inFile) {
    int c;

    while ((c = fgetc(inFile)) != EOF) {
        putchar(c);
    }

    if (ferror(inFile)) {
        puts("I/O error when reading");
    } else if (feof(inFile)) {
        puts("End of file reached successfully");
    }
    return 0;
}

int main(int argc, char** argv) {

    if (argc == 1) {
        puts("Error: Input file name not provided.");
        exit(1);
    } else if (argc == 2) {
        FILE* inFile = fopen(argv[1], "r");
        if (inFile == NULL) {
            printf("Error: Could not read from input file '%s'.\n", argv[1]);
            exit(1);
        } else {
            go(inFile);
        }
    } else {
        puts("Error: Too many arguments provided.");
        exit(1);
    }
}
