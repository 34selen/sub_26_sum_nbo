#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t my_ntohl(uint32_t n)
{
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
    uint32_t *array = (uint32_t *)calloc(count, sizeof(uint32_t)); // 인자 개수만큼 배열 생성
    uint32_t sum = 0;
    for (int i = 0; i < count; i++)
    {
        FILE *file = fopen(argv[i + 1], "rb");
        if (!file)
        {
            printf("open file error");
            return (1);
        }
        if (fread(&array[i], sizeof(uint32_t), 1, file) != 1) // 파일 읽어서 array에 저장
        {
            printf("less then 4 byte"); // 읽기 에러(4바이트 이하)
            free(array);
            fclose(file);
            return (1);
        }

        fclose(file);
    }

    for (int i = 0; i < count; i++)
    {
        array[i] = my_ntohl(array[i]); // 바이트 순서 뒤집기기
    }
    for (int i = 0; i < count; i++)
    {
        sum += array[i];                          // 하나씩 더하기기
        printf("%d(%#x) + ", array[i], array[i]); // 더하기 출력력
    }
    printf("\b\b= %d(%#x)\n", sum, sum);

    free(array);
    return 0;
}