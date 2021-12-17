#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *my_Func(void *received_arr)
{

    int *arr = (int *)received_arr;

    for (int i = 0; i < 5; i++)
    {
        printf("Value %d:  %d\n", i + 1, arr[i]);
    }

}

int main()
{
    int values[5];

    printf("\nEnter 5 numbers:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &values[i]);
    }
    pthread_t tid;
    pthread_create(&tid, NULL, my_Func, (void *)values);
    pthread_join(tid, NULL);
}