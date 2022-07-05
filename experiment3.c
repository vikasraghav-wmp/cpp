#include <stdio.h>
#include <stdint.h>
#define TOTAL_IP 256;
int main(int argc, char const *argv[])
{
    uint32_t mask = 28, network = 1921688855, net_lower = 0, net_upper = 0;
    unsigned char bytes_lw[4];
    char ip[30];
    mask = mask ? 0xFFFFFFFF << (32 - mask) : 0; //converting mask into 32 bit for calculating lower and upper subnet
    printf("mask = %u\n", mask);
    net_lower = (network & mask);
    printf("net lower = %u\n", net_lower);
    net_upper = (net_lower | (~mask));
    printf("net upper = %u\n", net_upper);

    while (net_lower < net_upper)
    {
        bytes_lw[0] = net_lower & 0xFF;
        bytes_lw[1] = (net_lower >> 8) & 0xFF;
        bytes_lw[2] = (net_lower >> 16) & 0xFF;
        bytes_lw[3] = (net_lower >> 24) & 0xFF;
        sprintf(ip, "%d.%d.%d.%d", bytes_lw[3], bytes_lw[2], bytes_lw[1], bytes_lw[0]);
        net_lower += TOTAL_IP;
    }
    printf("ip = %s\n", ip);
    printf("1..%d\n", bytes_lw[0]);
    printf("2..%d\n", bytes_lw[1]);
    printf("3..%d\n", bytes_lw[2]);
    printf("4..%d\n", bytes_lw[3]);
    printf("net lower = %u", net_lower);

    return 0;
}
