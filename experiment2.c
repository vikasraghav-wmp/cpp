// // // #include <stdio.h>
// // // #include <stdlib.h>

// // // struct Node {
// // // 	int data;
// // // 	struct Node* next;
// // // };

// // // void insertElement(struct Node* head)
// // // {

// // // 	head = (struct Node*)malloc(sizeof(struct Node));

// // //     printf("Enter data for node : ");
// // //     scanf("%d", &head->data);
// // // 	head->next = NULL;
// // // }
// // // void printList(struct Node* n)
// // // {
// // // 	while (n != NULL)
// // //     {
// // // 		printf(" %d ", n->data);
// // // 		n = n->next;
// // // 	}
// // // }

// // // int main()
// // // {
// // // 	struct Node* head = NULL;

// // // 	insertElement(head);
// // //  	printList(head);

// // // 	return 0;
// // // }

// // // C program to determine class, Network
// // // and Host ID of an IPv4 address

// // #include <stdio.h>
// // #include <string.h>

// // // Function to find out the Class
// // char findClass(char str[])
// // {
// //     char arr[4];
// //     int i = 0;
// //     while (str[i] != '.')
// //     {
// //         arr[i] = str[i];
// //         i++;
// //     }
// //     i--;

// //     int ip = 0, j = 1;
// //     while (i >= 0)
// //     {
// //         ip = ip + (str[i] - '0') * j;
// //         j = j * 10;
// //         i--;
// //     }

// //     if (ip >= 1 && ip <= 126)
// //     {
// //         return 'A';
// //     }

// //     else if (ip >= 128 && ip <= 191)
// //     {
// //         return 'B';
// //     }

// //     else if (ip >= 192 && ip <= 223)
// //     {
// //         return 'C';
// //     }
// // }

// // // Function to separate Network ID as well as
// // // Host ID and print them
// // void separate(char str[], char ipClass, int sub)
// // {
// //     // Initializing network and host array to NULL
// //     char network[12], host[12];
// //     for (int k = 0; k < 12; k++)
// //         network[k] = host[k] = '\0';

// //     if (ipClass == 'A')
// //     {
// //         int i = 0, j = 0;
// //         while (str[j] != '.')
// //             network[i++] = str[j++];
// //         i = 0;
// //         j++;
// //         while (str[j] != '\0')
// //             host[i++] = str[j++];
// //         printf("Network ID is %s\n", network);
// //         printf("Host ID is %s\n", host);
// //     }

// //     // for class B, first two octet are Network ID
// //     // and rest are Host ID
// //     else if (ipClass == 'B')
// //     {
// //         int i = 0, j = 0, dotCount = 0;

// //         while (dotCount < 2)
// //         {
// //             network[i++] = str[j++];
// //             if (str[j] == '.')
// //                 dotCount++;
// //         }
// //         i = 0;
// //         j++;

// //         while (str[j] != '\0')
// //             host[i++] = str[j++];

// //         printf("Network ID is %s\n", network);
// //         printf("Host ID is %s\n", host);
// //     }

// //     // for class C, first three octet are Network ID
// //     // and rest are Host ID
// //     else if (ipClass == 'C')
// //     {
// //         int i = 0, j = 0, dotCount = 0;

// //         // storing in network[] up to 3rd dot
// //         // dotCount keeps track of number of
// //         // dots or octets passed
// //         while (dotCount < 3)
// //         {
// //             network[i++] = str[j++];
// //             if (str[j] == '.')
// //                 dotCount++;
// //         }

// //         i = 0;
// //         j++;

// //             while (str[j] != '\0')
// //             host[i++] = str[j++];

// //         printf("Network ID is %s\n", network);
// //         printf("Host ID is %s\n", host);
// //         if (sub == 24)
// //         {
// //             printf("subnet range is : ");
// //             for (int i = 1; i < 256; i++)
// //             {
// //                 printf("%s.%d\n", network, i);
// //             }
// //         }
// //         if (sub == 25)
// //         {
// //             printf("subnet range is : ");
// //             for (int i = 1; i < 128; i++)
// //             {
// //                 printf("%s.%d\n", network, i);
// //             }
// //         }
// //     }

// //     // Class D and E are not divided in Network
// //     // and Host ID
// //     else
// //         printf("In this Class, IP address is not"
// //                " divided into Network and Host ID\n");
// // }

// // // Driver function is to test above function
// // int main()
// // {
// //     char str[20];
// //     int sub;
// //     printf("Enter IP : ");
// //     scanf("%s", str);
// //     printf("Enter subnet mask : ");
// //     scanf("%d", &sub);
// //     char ipClass = findClass(str);
// //     printf("Given IP address belongs to Class %c\n", ipClass);
// //     separate(str, ipClass, sub);
// //     return 0;
// // }

// #include<stdio.h>
// #include<stdlib.h>
// int main(){
// int a[10],n,i;
// printf("Enter the number to convert: ");
// scanf("%d",&n);
// for(i=0;n>0;i++)
// {
// a[i]=n%2;
// n=n/2;
// }
// printf("\nBinary of Given Number is=");
// for(i=i-1;i>=0;i--)
// {
// printf("%d",a[i]);
// }
// return 0;
// }

// char first_string[20];  // declaration of char array variable
// char second_string[20]; // declaration of char array variable
// int i;                  // integer variable declaration
// printf("Enter the first string");
// scanf("%s", first_string);
// printf("\nEnter the second string");
// scanf("%s", second_string);
// for (i = 0; first_string[i] != '\0'; i++);

// for (int j = 0; second_string[j] != '\0'; j++)
// {

//     first_string[i] = second_string[j];
//     i++;
// }
// first_string[i] = '\0';
// printf("After concatenation, the string would look like: %s", first_string);

// #include <stdio.h>
// #include <math.h>
// int subnetMask(int input,int net, char netchar[20]);
// int main()
// {
//     int input, tmp;
//     int net,a,b,c,d;
//     char netchar[20];
//     printf("Enter a subnet mask : ");
//     scanf("%d",&input);
//     printf("Enter ip : ");
//     scanf("%d.%d.%d.%d", &a,&b,&c,&d);
//     printf("%d.%d.%d.%d", a,b,c,d);
//     printf("%d",a);
//     printf("%d",b);
//     printf("%d",c);
//     printf("%d",d);

//     tmp = input;
//     subnetMask(input,net,netchar);

//     return 0;
// }

// int subnetMask(int input, int net, char netchar[20])
// {
//     if (input > 0 && input <= 8)
//     {
//         net = pow(2, 8) - pow(2, (8 - input));
//         sprintf(netchar, "%d", net);
//         printf("%s", netchar);
//     }

//     else if (input > 8 && input <= 16)
//     {
//         input = input - 8;
//         net = pow(2, 8) - pow(2, (8 - input));
//         sprintf(netchar, "255.%d", net);
//         printf("%s", netchar);
//     }

//     else if (input > 16 && input <= 24)
//     {
//         input = input - 16;
//         net = pow(2, 8) - pow(2, (8 - input));
//         sprintf(netchar, "255.255.%d", net);
//         printf("%s", netchar);
//     }

//     else if (input > 24 && input <= 32)
//     {
//         input = input - 24;
//         net = pow(2, 8) - pow(2, (8 - input));
//         sprintf(netchar, "255.255.255.%d", net);
//         printf("%s", netchar);
//     }

//     else
//     printf("not a subset mask");

// }

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int input, tmp;
    int net, a, b, c, d, a1[10], b1[10], c1[10], d1[10];
    char netchar[20];
    printf("Enter a subnet mask : ");
    scanf("%d", &input);
    tmp = input;
    printf("Enter ip : ");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    printf("ip = %d.%d.%d.%d \n", a, b, c, d);
    if (input > 24 && input <= 32)
    {
        input = input - 24;
        net = pow(2, 8) - pow(2, (8 - input));
        sprintf(netchar, "255.255.255.%d", net);
        printf("subnet in binary is %s", netchar);
    }
    net= atoi(netchar);
    printf("%d",net);
    return 0;
}