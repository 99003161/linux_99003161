#include "sumarr.h"

int main()
{
    int arr[100];
    int final_sum=0;
    void* sum;
    for(int i=0;i<=100;i++)
    {
        arr[i]=i;
    }
    pthread_t threads[10];
    for(int i=0;i<10;i++)
    {
        int* sub_array=arr + (i*10);
        pthread_create(&threads[i],NULL,sum_fun,(void*) sub_array);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(threads[i],&sum);
        final_sum+=(int)sum;
    }
    printf("total = %d\n",final_sum);
    return 0;
}
