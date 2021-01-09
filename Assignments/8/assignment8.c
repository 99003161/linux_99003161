#include <pthread.h> 
#include <stdio.h> 
 
void* max(void* sub_array)
{
    int* partarray = (int*)sub_array;
    int maxim=0;
    for(int i=0;i<10;i++)
    {
    	if(partarray[i]>maxim)
    	     maxim=partarray[i];
    }
    pthread_exit((void*)maxim);

}
int main()
{
    int array[100];
    int final_value=0;
    void* maxim;
    for(int i=0;i<=100;i++)
    {
        array[i]=i;
    }
    pthread_t threads[10];
    for(int i=0;i<10;i++)
    {
        int* sub_array=array + (i*10);
        pthread_create(&threads[i],NULL,max,(void*) sub_array);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(threads[i],&maxim);
        final_value=(int)maxim;
    }
    printf("maxvalue  = %d\n",final_value);
    return 0;
}


