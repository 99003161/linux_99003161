#ifndef STACK_SEM_H_INCLUDED
#define STACK_SEM_H_INCLUDED

#include<pthread.h>

#include<semaphore.h>
#include<unistd.h>

#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
void* push(void* pv)	//consumer
{

    int *val=(int*)pv;
	
    sem_wait(ps);

   // pthread_mutex_lock(&m1);
	if(m_top<=10){
        m_arr[++m_top]=val;
         printf("pushed val:%d\n",val);
         pthread_mutex_unlock(&m1);
    }
   //pthread_mutex_unlock(&m1);
  sem_post(ps);
		sem_post(qs);
   
   
}
void* pop(void* pv)	//producer
{
 sem_wait(qs);
		sem_wait(ps);

    int temp=0;
   
   // pthread_mutex_lock(&m1);
	if(m_top!=-1){
        //temp+=1;
        temp=m_arr[m_top--];
        
        printf("VAlue:%d\n",temp);
        pthread_mutex_unlock(&m1);
    }
    //pthread_mutex_unlock(&m1);
   sem_post(ps);
	//pthread_exit(temp);
}

#endif // STACK_SEM_H_INCLUDED
