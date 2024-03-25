#include <stdio.h>
#include <stdint.h>

int main() {
    unsigned char values[] = {100, 200, 150, 10}; 
    uint16_t sum = 0;

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        sum += values[i];
        sum %= 256;
    }

    printf("Sum: %d\n", sum);

    return 0;
}
