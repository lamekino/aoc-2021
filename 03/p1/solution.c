#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 20
#define DISPLAY_BUFFER(xs, len) \
do { \
    for (size_t i = 0; i < len; i++) \
        if (i != 0) printf(", %d", xs[i]); \
        else printf("%s#%d: { %d", __func__, __LINE__, xs[i]); \
    puts(" }"); \
} while (0);

int solution(int *xs, size_t len, size_t bits) {
    // this will store the counts for each bit column in xs
    // - positive values map to the most common bit being one
    // - negative values map to the most common bit being zero
    int *counts = calloc(bits, sizeof(int));

    for (size_t i = 0; i < len; i++) {
        int x = xs[i];

        // iterate over the binary number
        for (size_t bit = 0; bit < bits; bit++) {
            if ((x >> bit) & 1) { // if the current bit is one
                counts[bit]++;
            }
            else {  // if the current bit is zero
                counts[bit]--;
            }
        }
    }

    int gamma = 0, epsilon = 0;
    for (size_t bit = 0; bit < bits; bit++) {
        if (counts[bit] > 0) {
            // add one to gamma[bit]
            gamma = (1 << bit) | gamma;
        }
        else if (counts[bit] < 0) {
            // add one to epsilon[bit]
            epsilon = (1 << bit) | epsilon;
        }
    }

    free(counts);
    return gamma * epsilon;
}

int main() {
    char buffer[INPUT_SIZE] = { 0 };

    int *input = calloc(1, sizeof(int));
    size_t input_size = 1;
    size_t bits = 0;

    // load first line to get bit length
    fgets(buffer, INPUT_SIZE, stdin);
    bits = strlen(buffer) - 1;
    input[0] = strtol(buffer, NULL, 2);

    // load binary string into memory
    while (fgets(buffer, INPUT_SIZE, stdin)) {
        input_size++;
        input = realloc(input, sizeof(int) * input_size);

        input[input_size - 1] = strtol(buffer, NULL, 2);
    }

    printf("%d\n", solution(input, input_size, bits));

    free(input);
    return 0;
}
