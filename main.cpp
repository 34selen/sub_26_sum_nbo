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
    uint32_t count = argc - 1;
    uint32_t *array = (uint32_t *)calloc(count, sizeof(uint32_t));
    uint32_t sum = 0;
    // printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        FILE *file = fopen(argv[i + 1], "rb");
        if (!file)
        {
            printf("Failed to open file");
            continue;
        }
        if (fread(&array[i], sizeof(uint32_t), 1, file) != 1)
        {
            printf("read data error");
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
        sum += array[i];
        printf("%d(%#x) + ", array[i], array[i]);
    }
    printf("\b\b= %d(%#x)", sum, sum);

    free(array);
    return 0;
}