#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t num) 
{
    char buffer[35]; // '0b' + 32 бита + '\0'
    buffer[0] = '0';
    buffer[1] = 'b';
    for (int i = 31; i >= 0; i--) {
        uint32_t mask = (uint32_t)1 << i;
        buffer[33 - i] = (num & mask) ? '1' : '0';
    }
    buffer[34] = '\0';
    printf("%s \n", buffer);
}

struct date
{
uint32_t day : 5;
uint32_t month : 4;
uint32_t year : 4;
};

int main (void)
{
uint32_t month = 500;
struct date dat = {31, month, 0};
uint32_t udat = *((uint32_t *)&dat);


printf("%d:%d:%d \n", dat.day, dat.month, dat.year);
print_binary(udat);

return 0;
}

