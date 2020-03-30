#include "add_nbo.h"

void add_nbo()
{
    printf("syntax : add_nbo <file1> <file2>\n");
    printf("sample : add_nbo a.bin c.bin\n");

}

int byte_order(char* argv)
{
    FILE *binary;

    uint32_t data, Byte;

    binary = fopen(argv, "rb");

    Byte = fread(&data, sizeof(int), 1, binary);

    Byte = ntohl(data);

    fclose(binary);

    return Byte;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        add_nbo();

        return 0;

    }

    uint32_t Binary_1, Binary_2, sum;

    Binary_1 = byte_order(argv[1]);
    Binary_2 = byte_order(argv[2]);


    sum = Binary_1 + Binary_2;

    printf("%d(%#x) + %d(%#x) = %d(%#x)", Binary_1, Binary_1, Binary_2, Binary_2, sum, sum);


    return 0;
}
