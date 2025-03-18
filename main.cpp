#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t my_ntohl(uint32_t n)
{ // 3412
    uint32_t output = 0;
    char size = sizeof(n);
    for (int i = 0; i < size; i++)
    {
        output = output | ((n >> (i * 8)) & 0xFF) << ((size - i - 1) * 8);
    }
    return output;
}
int main(int argc, char *argv[])
{
    int count = argc - 1;
    uint32_t *array = (uint32_t *)calloc(count, sizeof(uint32_t));
    printf("%d\n", count);
    for (int i = 1; i <= count; i++)
    {
        FILE *file = fopen(argv[i], "rb");
        if (!file)
        {
            printf("Failed to open file");
            continue;
        }
        if (fread(&array[i - 1], sizeof(uint32_t), 1, file) != 1)
        {
            printf("Failed to read data");
            fclose(file);
            continue;
        }
        fclose(file);
    }

    for (int i = 0; i < count; i++)
    {
        array[i] = my_ntohl(array[i]);
    }
    for (int i = 0; i < count; i++)
    {
        printf("Raw value (Hex): 0x%X\n", array[i]);
        printf("Raw value (Dec): %d\n", array[i]);
    }

    free(array);
    return 0;
}