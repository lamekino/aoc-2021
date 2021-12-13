#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 128
#define STR_SIZE 8 // largest string is "forward"

typedef struct pair {
    char str[STR_SIZE];
    int num;
} Pair;

int solution(size_t size, Pair *directions) {
    int x = 0, y = 0;
    for (size_t s = 0; s < size; s++) {
        if (strncmp(directions[s].str, "forward", STR_SIZE) == 0) {
            x += directions[s].num;
        }
        else if (strncmp(directions[s].str, "down", STR_SIZE) == 0) {
            y += directions[s].num;
        }
        else if (strncmp(directions[s].str, "up", STR_SIZE) == 0) {
            y -= directions[s].num;
        }
    }

    return x * y;
}

int main() {
    size_t size = 0;
    Pair *pairs = NULL;
    char buffer[BUFFER_SIZE] = { 0 };

    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        size++;
        char *token = strtok(buffer, " ");

        // realloc the list of pairs and copy the token to .str
        pairs = realloc(pairs, sizeof(Pair) * size);
        strncpy(pairs[size - 1].str, token, STR_SIZE);

        // get the number and add it to .num
        token = strtok(NULL, " ");
        pairs[size - 1].num = atoi(token);
    }

    printf("%d\n", solution(size, pairs));

    free(pairs);
    return 0;
}
