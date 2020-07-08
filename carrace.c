#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>

// you can change the prototype of existing
// functions, add new routines and global variables
// cheatmode, car1, car2, report are different threads
// they communicate with each other via shared memory


int abhiyug=0,himmat=0;
pthread_mutex_t lock;
int flag=1;int flag2=1;
struct bewafa
{
	int loyalty;  //car number
	int nature;  // new location
};

struct bewafa shubhleen;

void *helper(void *arg)
{
	shubhleen.loyalty=0;
	
	shubhleen.nature=-1;
	while(1)
	{
		if(shubhleen.loyalty==1)
		{	pthread_mutex_lock(&lock);
			printf("%s","bhai");
			
			abhiyug=shubhleen.nature;
			pthread_mutex_unlock(&lock);
			shubhleen.loyalty=0;
			shubhleen.nature=-1;
			
			
		}
		else if(shubhleen.loyalty==2)
		{	pthread_mutex_lock(&lock);
			himmat=shubhleen.nature;
			pthread_mutex_unlock(&lock);
			shubhleen.loyalty=0;
			shubhleen.nature=-1;
			
		}
	}
}


// the cheatmode thread
void *cheatmode(void *arg)
{
	

	while(flag)
	{
		printf("Do you wish to cheat? y/n \n");
		char choice;
		scanf("%c", &choice);
		
		if(choice=='y' || choice=='Y')
		{
			flag2=0;
			printf("car1 or car2  1/2 \n");
			int cn;
			pthread_mutex_lock(&lock);
			scanf("%d",&cn);
			shubhleen.loyalty=cn;
			printf("Enter the new position \n");
			int nl;
			scanf("%d",&nl);
			shubhleen.nature=nl;
			if(cn==1)
				abhiyug=nl;
			else
			{
					himmat=nl;
			}
			

			pthread_mutex_unlock(&lock);
			flag2=1;
		} 
		
		
		
	}
	return NULL;
}

// the car1 thread
void *car1(void *arg)
{
	while(flag)
	{
		sleep(1);
		int devil=rand();
		//printf("%d",devil);
		int plus= devil%11;
		pthread_mutex_lock(&lock);
		abhiyug+=plus;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

// the car2 thread
void *car2(void *arg)
{
	while(flag)
	{
		sleep(1);
		int devil=rand();
		int plus= devil%11;
		pthread_mutex_lock(&lock);
		himmat+=plus;
		pthread_mutex_unlock(&lock);
	}

	return NULL;
}

// the report thread
void *report(void *arg)
{
	pthread_t duniya,zalim,hai;
	pthread_create(&duniya,NULL,&cheatmode,NULL);
	pthread_create(&zalim,NULL,&car1,NULL);
	pthread_create(&hai,NULL,&car2,NULL);
	while(flag)
	{
		int abhi=abhiyug;
		int himz=himmat;
		
		if(abhi>=100 && himz >=100)
		{
			printf("Draw! \n");
			flag=0;
		}
		if(abhi>=100)
		{
			printf("Winner is Car1 \n");
			flag=0;
		}
		if(himz>=100)
		{
			printf("Winner is Car2 \n");
			flag=0;
		}
		if(flag2)
		{
			printf("Position of Car1 %d",abhi);
			printf("\n");
			printf("Position of Car2 %d",himz);
			printf("\n");
			printf("\n");
		}
		


		sleep(1);
	}

	return NULL;
}

// create all threads
int main()
{
	pthread_mutex_init(&lock, NULL);
	pthread_t hoteshwari;
	pthread_create(&hoteshwari,NULL,&report,NULL);
	pthread_t ex;
	pthread_create(&ex,NULL,&helper,NULL);
	pthread_join(hoteshwari, NULL);
	
	pthread_mutex_destroy(&lock);
	return 0;
}
