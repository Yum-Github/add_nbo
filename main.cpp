#include "add_nbo.h"

int main()
{
    FILE *binary_1, *binary_2;
    uint32_t data_1, data_2, sum;

    binary_1 = fopen(Binary_Path "1.bin", "rb");
    {
        fread(&data_1, sizeof(int), 1, binary_1);
        data_1 = ntohl(data_1);
        fclose(binary_1);
    }

    binary_2 = fopen(Binary_Path "2.bin", "rb");
    {
        fread(&data_2, sizeof(int), 1, binary_2);
        data_2 = ntohl(data_2);
        fclose(binary_2);
    }

    sum = data_1 + data_2;


    printf("%d(%#x) + %d(%#x) = %d(%#x)\n", data_1, data_1, data_2, data_2, sum, sum);

}
