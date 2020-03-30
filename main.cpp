#include "add_nbo.h"

void usage()
{
    printf("syntax : add_nbo <file1> <file2>\n");
    printf("sample : add_nbo a.bin c.bin\n");

}

uint32_t byte_order(char* argv)
{
    FILE *Binary;

    uint32_t Data, Big_Endian;

    Binary = fopen(argv, "rb");

    if (Binary == NULL)
    {
        printf("Error\n");

        return 0;
    }

    Big_Endian = fread(&Data, sizeof(uint32_t), 1, Binary);

    Big_Endian = ntohl(Data);

    fclose(Binary);

    return Big_Endian;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        usage();

        return 0;

    }

    uint32_t Bin_1, Bin_2, Sum;

    Bin_1 = byte_order(argv[1]);
    Bin_2 = byte_order(argv[2]);


    Sum = Bin_1 + Bin_2;

    printf("%d(%#x) + %d(%#x) = %d(%#x)\n", Bin_1, Bin_1, Bin_2, Bin_2, Sum, Sum);


    return 0;
}
