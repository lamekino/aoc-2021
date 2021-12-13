#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 128
#define STR_SIZE 8 // largest string is "forward"

typedef enum direction {
    FORWARD,
    DOWN,
    UP
} Direction;

typedef struct pair {
    Direction direction;
    int num;
} Pair;

long long solution(size_t size, Pair *ds) {
    long long x = 0, y = 0;
    long long aim = 0;
    for (size_t s = 0; s < size; s++) {
        if (ds[s].direction == FORWARD) {
            x += ds[s].num;
            y += aim * ds[s].num;
        }
        else if (ds[s].direction == DOWN) {
            aim += ds[s].num;
        }
        else if (ds[s].direction == UP) {
            aim -= ds[s].num;
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
        pairs = realloc(pairs, sizeof(Pair) * size);

        // compare the first split before space with
        // a possible Direction
        char *token = strtok(buffer, " ");
        if (strncmp(token, "forward", STR_SIZE) == 0) {
            pairs[size - 1].direction = FORWARD;
        }
        else if (strncmp(token, "down", STR_SIZE) == 0) {
            pairs[size - 1].direction = DOWN;
        }
        else if (strncmp(token, "up", STR_SIZE) == 0) {
            pairs[size - 1].direction = UP;
        }

        // get the number and add it to .num
        token = strtok(NULL, " ");
        pairs[size - 1].num = atoi(token);
    }

    printf("%lld\n", solution(size, pairs));

    free(pairs);
    return 0;
}
