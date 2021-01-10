#include<stdio.h>
#include<pthread.h>
void* sum_fun(void* sub_array)
{
    int* partarray = (int*)sub_array;
    int sum=0;
    for(int i=0;i<10;i++)
    {
        sum+=partarray[i];
    }
    pthread_exit((void*)sum);

}
