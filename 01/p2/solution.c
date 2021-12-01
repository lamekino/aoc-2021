#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 128

int solution(size_t length, int *depths) {
    int increases = 0;
    int previous_sum = 0;
    for (int i = 0; i < length - 3; i++) {
        int sum = depths[i] + depths[i + 1] + depths[i + 2];
        if (previous_sum < sum) {
            increases++;
        }
        previous_sum = sum;
    }

    return increases;
}

int main() {
    size_t size = 0;
    int *numbers = NULL;
    char buffer[BUFFER_SIZE] = { 0 };

    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        size++;
        numbers = realloc(numbers, size * sizeof(int));
        numbers[size - 1] = atoi(buffer);
    }

    printf("%d\n", solution(size, numbers));

    free(numbers);
    return 0;
}
