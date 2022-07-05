#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TOTAL_IP 256

uint32_t ipToUInt(const char *ip)
{
    int a, b, c, d;
    uint32_t addr = 0;

    if (sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d) != 4)
        return 0;

    addr = a << 24;
    addr |= b << 16;
    addr |= c << 8;
    addr |= d;
    return addr;
}

int main()
{
    uint32_t mask, network, net_lower = 0, net_upper = 0;
    int num;
    int bytes_lw[4];
    char ip[32];
    char cidr[50] = "192.168.200.200/23";
    char *ptr;
    ptr = strtok(cidr, "/");
    printf("%s\n", ptr);
    mask = atoi(strtok(NULL, "/"));
    if (mask > 0 && mask <= 32)
    {
        num = pow(2, 32 - mask);
    }
    printf("%d\n", mask);

    mask = mask ? 0xFFFFFFFF << (32 - mask) : 0; //converting mask into 32 bit for calculating lower and upper subnet
    printf("mask = %u\n", mask);
    network = ipToUInt(ptr); //converts IP string to int
    net_lower = (network & mask);
    printf("net lower = %u\n", net_lower);
    net_upper = (net_lower | (~mask));
    printf("net upper = %u\n", net_upper);

    bytes_lw[0] = net_lower & 0xFF;
    bytes_lw[1] = (net_lower >> 8) & 0xFF;
    bytes_lw[2] = (net_lower >> 16) & 0xFF;
    bytes_lw[3] = (net_lower >> 24) & 0xFF;
    sprintf(ip, "%d.%d.%d.%d", bytes_lw[3], bytes_lw[2], bytes_lw[1], bytes_lw[0]);
    printf("ip = %d\n", ip);

    for (int i = 0; i < num; i++)
    {
        sprintf(ip, "%d.%d.%d.%d", bytes_lw[3], bytes_lw[2], bytes_lw[1], bytes_lw[0]);
        printf("ip = %s\n", ip);
        bytes_lw[0]++;
        if (bytes_lw[0] > 255)
        {
            bytes_lw[0] = 0;
            bytes_lw[1]++;

            if (bytes_lw[1] > 255)
            {
                bytes_lw[1] = 0;
                bytes_lw[2]++;

                if (bytes_lw[3] > 255)
                {
                    bytes_lw[3] = 0;
                    bytes_lw[4]++;
                }
            }
        }
    }

    sprintf(ip, "%d.%d.%d.%d", bytes_lw[3], bytes_lw[2], bytes_lw[1], bytes_lw[0]);
    // printf("last ip is %s", ip);
    return 0;
}
