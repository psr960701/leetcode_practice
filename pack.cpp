#include <stdio.h>
#pragma   pack(8)
#pragma pack(push)
#pragma   pack(4)
struct CC {
    double d;
    char b;
    int a;
    short c;
};

#pragma   pack(1)
struct BB{
    double d;
    char b;
    int a;
    short c;
};
#pragma pack(pop)
struct AA{
    double d;
    char b;
    int a;
    short c;
};
int main(void)
{

    printf("%u\n%u\n%u\n",sizeof(struct CC),sizeof(struct BB),sizeof(struct AA));
    getchar();
    return 0;
}