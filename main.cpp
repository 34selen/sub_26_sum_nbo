#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h>  // for printf

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
}