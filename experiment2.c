// // #include <stdio.h>
// // #include <stdlib.h>

// // struct Node {
// // 	int data;
// // 	struct Node* next;
// // };

// // void insertElement(struct Node* head)
// // {

// // 	head = (struct Node*)malloc(sizeof(struct Node));

// //     printf("Enter data for node : ");
// //     scanf("%d", &head->data);
// // 	head->next = NULL;
// // }
// // void printList(struct Node* n)
// // {
// // 	while (n != NULL)
// //     {
// // 		printf(" %d ", n->data);
// // 		n = n->next;
// // 	}
// // }

// // int main()
// // {
// // 	struct Node* head = NULL;

// // 	insertElement(head);
// //  	printList(head);

// // 	return 0;
// // }

// // C program to determine class, Network
// // and Host ID of an IPv4 address

// #include <stdio.h>
// #include <string.h>

// // Function to find out the Class
// char findClass(char str[])
// {
//     char arr[4];
//     int i = 0;
//     while (str[i] != '.')
//     {
//         arr[i] = str[i];
//         i++;
//     }
//     i--;

//     int ip = 0, j = 1;
//     while (i >= 0)
//     {
//         ip = ip + (str[i] - '0') * j;
//         j = j * 10;
//         i--;
//     }

//     if (ip >= 1 && ip <= 126)
//     {
//         return 'A';
//     }

//     else if (ip >= 128 && ip <= 191)
//     {
//         return 'B';
//     }

//     else if (ip >= 192 && ip <= 223)
//     {
//         return 'C';
//     }
// }

// // Function to separate Network ID as well as
// // Host ID and print them
// void separate(char str[], char ipClass, int sub)
// {
//     // Initializing network and host array to NULL
//     char network[12], host[12];
//     for (int k = 0; k < 12; k++)
//         network[k] = host[k] = '\0';

//     if (ipClass == 'A')
//     {
//         int i = 0, j = 0;
//         while (str[j] != '.')
//             network[i++] = str[j++];
//         i = 0;
//         j++;
//         while (str[j] != '\0')
//             host[i++] = str[j++];
//         printf("Network ID is %s\n", network);
//         printf("Host ID is %s\n", host);
//     }

//     // for class B, first two octet are Network ID
//     // and rest are Host ID
//     else if (ipClass == 'B')
//     {
//         int i = 0, j = 0, dotCount = 0;

//         while (dotCount < 2)
//         {
//             network[i++] = str[j++];
//             if (str[j] == '.')
//                 dotCount++;
//         }
//         i = 0;
//         j++;

//         while (str[j] != '\0')
//             host[i++] = str[j++];

//         printf("Network ID is %s\n", network);
//         printf("Host ID is %s\n", host);
//     }

//     // for class C, first three octet are Network ID
//     // and rest are Host ID
//     else if (ipClass == 'C')
//     {
//         int i = 0, j = 0, dotCount = 0;

//         // storing in network[] up to 3rd dot
//         // dotCount keeps track of number of
//         // dots or octets passed
//         while (dotCount < 3)
//         {
//             network[i++] = str[j++];
//             if (str[j] == '.')
//                 dotCount++;
//         }

//         i = 0;
//         j++;

//             while (str[j] != '\0')
//             host[i++] = str[j++];

//         printf("Network ID is %s\n", network);
//         printf("Host ID is %s\n", host);
//         if (sub == 24)
//         {
//             printf("subnet range is : ");
//             for (int i = 1; i < 256; i++)
//             {
//                 printf("%s.%d\n", network, i);
//             }
//         }
//         if (sub == 25)
//         {
//             printf("subnet range is : ");
//             for (int i = 1; i < 128; i++)
//             {
//                 printf("%s.%d\n", network, i);
//             }
//         }
//     }

//     // Class D and E are not divided in Network
//     // and Host ID
//     else
//         printf("In this Class, IP address is not"
//                " divided into Network and Host ID\n");
// }

// // Driver function is to test above function
// int main()
// {
//     char str[20];
//     int sub;
//     printf("Enter IP : ");
//     scanf("%s", str);
//     printf("Enter subnet mask : ");
//     scanf("%d", &sub);
//     char ipClass = findClass(str);
//     printf("Given IP address belongs to Class %c\n", ipClass);
//     separate(str, ipClass, sub);
//     return 0;
// }


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define B1 0
#define B2 1
#define B3 2
#define B4 3
#define CIDR 4

void ConvertIpToInt(char address[], int address_block[]);

int main(int argc, char** argv) {

    int address_block[4], netmask_block[4];

    char address[] = "128.42.0.0/25";

    ConvertIpToInt(address, address_block);

    char literal_netmask_bin[32];
    int bit_counter, net_bit_counter = 0;
    while (bit_counter != 33) {
        while (net_bit_counter != address_block[CIDR]) {
            literal_netmask_bin[bit_counter] = '1';
            net_bit_counter += 1;
            bit_counter += 1;
        }
        literal_netmask_bin[bit_counter] = '0';
        bit_counter += 1;
    }

    int i, block_counter, sqN_value, sqN = 0;
    bit_counter = 0;
    for (i = 0; i < 33; i++) {
        bit_counter += 1;
        if (literal_netmask_bin[i] == '1') {
            sqN_value += pow(2, 7 - sqN);
        }
        sqN += 1;
        if (bit_counter == 8) {
            netmask_block[block_counter] = sqN_value;
            bit_counter = 0;
            sqN = 0;
            sqN_value = 0;
            block_counter += 1;
        }
    }

    int wildcard_netmask_block[4];
    i = 0;
    for (i = 0; i < 4; i++) {
        wildcard_netmask_block[i] = ~netmask_block[i] & 0xFF;
    }

    printf("> [GENERAL]\n\n");
    printf("Address:---------------------> %d.%d.%d.%d\n", address_block[B1], address_block[B2], address_block[B3], address_block[B4]);
    printf("Network Mask:----------------> %d.%d.%d.%d => %d\n", netmask_block[B1], netmask_block[B2], netmask_block[B3], netmask_block[B4], address_block[CIDR]);
    printf("Wildcard Mask:---------------> %d.%d.%d.%d\n", wildcard_netmask_block[B1], wildcard_netmask_block[B2], wildcard_netmask_block[B3], wildcard_netmask_block[B4]);
    printf("Network Address:-------------> %d.%d.%d.%d\n", address_block[B1] & netmask_block[B1], address_block[B2] & netmask_block[B2], address_block[B3] & netmask_block[B3], address_block[B4] & netmask_block[B4]);
    printf("Broadcast Address:-----------> %d.%d.%d.%d\n", wildcard_netmask_block[B1] | address_block[B1], wildcard_netmask_block[B2] | address_block[B2], wildcard_netmask_block[B3] | address_block[B3], wildcard_netmask_block[B4] | address_block[B4]);
    printf("Minimum Usable Address:------> %d.%d.%d.%d\n", address_block[B1] & netmask_block[B1], address_block[B2] & netmask_block[B2], address_block[B3] & netmask_block[B3], (address_block[B4] & netmask_block[B4]) + 1);
    printf("Maximum Usable Address:------> %d.%d.%d.%d\n", wildcard_netmask_block[B1] | address_block[B1], wildcard_netmask_block[B2] | address_block[B2], wildcard_netmask_block[B3] | address_block[B3], (wildcard_netmask_block[B4] | address_block[B4]) - 1);
    printf("Number of Hosts:-------------> %d\n", (int) pow(2, 32 - address_block[CIDR]) - 2);
    printf("Total Hosts:-----------------> %d\n\n", (int) pow(2, 32 - address_block[CIDR]));
}

void ConvertIpToInt(char address[], int address_block[]) {
    char * pch;
    char delimeters[] = "./";
    pch = strtok(address, delimeters);
    int i = 0;
    while (pch != NULL) {
        address_block[i] = strtol(pch, NULL, 10);
        i += 1;
        pch = strtok(NULL, delimeters);
    }
}