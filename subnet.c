
#include <stdio.h>
#include <math.h>
int subnetMask(int input, int *net1, int *net2, int *net3, int *net4);
int ip(int a, int b, int c, int d);
int gettingNetworkId(int a, int b, int c, int d, int net1, int net2, int net3, int net4, int num, int input);

int main()
{
    
    int input, tmp, num;
    int net1, net2, net3, net4, a, b, c, d, a1, b1, c1, d1;

    printf("Enter a subnet mask : ");
    scanf("%d", &input);

    //num is used to find the total usable host of an ip address by the formula 2^(32-input)
    if (input > 0 && input < 32)
    {
        num = pow(2, 32 - input);
        num -= 2;
        printf("Number of Usable Hosts:	 = %d\n", num);
    }

    else if (input == 32)
    {
        printf("No usabe host \n");
        num = 0;
    }

    else if (input ==0)
    {
        return 0;
    }
    

    else
    {
        printf("Enter a valid subnet mask\n");
        return 0;
    }

    //we are taking ip in four parts i.e. a,b,c,d
    printf("Enter ip : ");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    printf("%d.%d.%d.%d", a, b, c, d);

    subnetMask(input, &net1, &net2, &net3, &net4);
    // ipInDecimal(a, b, c, d, a1, b1, c1, d1);
    gettingNetworkId(a, b, c, d, net1, net2, net3, net4, num, input);
    // return 0;

    
}

/*This function will convert your input into subnet mask form i.e 24 into 255.255.255.0 form 
basic formula is used 2^8 - 2^(8-input)
for 0-8 it will be stored in net1
for 9-16 it will be stored in net2
for 17-24 it will be stored in net3
for 25-32 it will be stored in net4
*/
int subnetMask(int input, int *net1, int *net2, int *net3, int *net4)
{
    if (input > 0 && input <= 8)
    {
        *net1 = pow(2, 8) - pow(2, (8 - input));
        *net2 = 0;
        *net3 = 0;
        *net4 = 0;
        printf("%ls", net1);
    }

    else if (input > 8 && input <= 16)
    {
        *net1 = 255;
        input = input - 8;
        *net2 = pow(2, 8) - pow(2, (8 - input));
        *net3 = 0;
        *net4 = 0;
        printf("%ls", net2);
    }

    else if (input > 16 && input <= 24)
    {
        *net1 = 255;
        *net2 = 255;
        input = input - 16;
        *net3 = pow(2, 8) - pow(2, (8 - input));
        *net4 = 0;
        printf("%ls", net3);
    }

    else if (input > 24 && input <= 32)
    {
        *net1 = 255;
        *net2 = 255;
        *net3 = 255;
        input = input - 24;
        *net4 = pow(2, 8) - pow(2, (8 - input));
        printf("%ls", net4);
    }

    else
        printf("not a subset mask");
}

/*xnor of ip to subnet mask storing in x1,x2,x3,x4
and operator on x1,2,3,4 to subnet mask (net1,2,3,4) to get the network id and storing its value in x1,x2,x3,x4 again
*/
int gettingNetworkId(int a, int b, int c, int d, int net1, int net2, int net3, int net4, int num, int input)
{
    int x1, x2, x3, x4;
    x1 = (a & net1) | ((!a) & (!net1));
    x2 = (b & net2) | ((!b) & (!net2));
    x3 = (c & net3) | ((!c) & (!net3));
    x4 = (d & net4) | ((!d) & (!net4));

    x1 &= net1;
    x2 &= net2;
    x3 &= net3;
    x4 &= net4;

    printf("\nnetwork id is %d.%d.%d.%d ", x1, x2, x3, x4);

    printf("\nIP Min : %d.%d.%d.%d\n", x1, x2, x3, x4 + 1);
    for (int i = 0; i < num; i++)
    {
        x4++;
        if (x4 > 255)
        {
            x4 = 0;
            x3++;

            if (x3 > 255)
            {
                x3 = 0;
                x2++;

                if (x2 > 255)
                {
                    x2 = 0;
                    x1++;
                }
            }
        }
    }
    printf("\nIP Max : %d.%d.%d.%d\n", x1, x2, x3, x4);
}