#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */

typedef struct str_thdata
{
    int x;
    int data[9];
} thdata;

int check[27];

void *checker(void *arg)
{
	int arr[10];
	int i;
	for(i=0;i<=9;i++)
	{
		arr[i]=0;
	}
	thdata *th=(thdata*)arg;
	/*for(i=0;i<9;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("ARRAY: \n");
	for(i=0;i<9;i++)
	{
		printf("%d ",th->data[i]);
	}
	printf("\n");*/
	for(i=0;i<9;i++)
	{
		//printf("arr: %d data: %d \n",arr[th->data[i]],th->data[i]);
		if(arr[th->data[i]]==1)
		{
			check[th->x]=0;
			//printf("Thread: %d\n",th->x);
			break;
		}
		else
		{
			arr[th->data[i]]=1;
		}
		
		
		
	}
	//printf("check: %d\n",check[th->x]);
}
int main()
{
	int li;
	for( li=0;li<27;li++)
		{
			check[li]=1;
		}
	/*for( li=0;li<27;li++)
		{
			printf("%d ",check[li]);
		}*/
	printf("Enter the 2-d matrix of soduko \n");
	int soduko[9][9];
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d",&soduko[i][j]);
		}	
	}
	pthread_t threadid[27];
	
	thdata threads[27];
	for(i=0;i<9;i++)
	{
		threads[i].x=i;
		//threads[i].arg=1;
		for(j=0;j<9;j++)
		{
			threads[i].data[j]=soduko[i][j];
		}
		// printf("data[j] of %d thread:",i);
		// for(li=0;li<9;li++)
		// {
		// 	printf("%d ",threads[i].data[li]);
		// }
		// printf("\n");
		pthread_create(&threadid[i], NULL, checker, &threads[i]);
		/*if(check==0)
		{
			printf("Sudoku is not valid!!! \n");
			return 0;
		}*/
		//pthread_join(threadid[i], NULL);
	}
	for(i=9;i<18;i++)
	{
		threads[i].x=i;
		//threads[i].arg=2;
		for(j=0;j<9;j++)
		{
			threads[i].data[j]=soduko[j][i-9];
		}
		// printf("data[j] of %d thread:",i);
		// for(li=0;li<9;li++)
		// {
		// 	printf("%d ",threads[i].data[li]);
		// }
		// printf("\n");
		pthread_create(&threadid[i], NULL, checker, &threads[i]);
		/*if(check==0)
		{
			printf("Sudoku is not valid!!! \n");
			return 0;
		}*/
		//pthread_join(threadid[i], NULL);
		
	}
	int x=0;
	int y=0;
	for(i=18;i<21;i++)
	{
		threads[i].x=i;
		//threads[i].arg=3;
		
		int r,c,n;
		x=0;
		n=0;
		for(r=x;r<x+3;r++)
		{
			for(c=y;c<y+3;c++)
				threads[i].data[n++]=soduko[r][c];
		}
		y=y+3;
		// printf("data[j] of %d thread:",i);
		// for(li=0;li<9;li++)
		// {
		// 	printf("%d ",threads[i].data[li]);
		// }
		// printf("\n");
		pthread_create(&threadid[i], NULL, checker, &threads[i]);
		/*if(check==0)
		{
			printf("Sudoku is not valid!!! \n");
			return 0;
		}*/
		//pthread_join(threadid[i], NULL);
	}
	y=0;
	for(i=21;i<24;i++)
	{
		threads[i].x=i;
		//threads[i].arg=3;
		
		int r,c,n;
		x=3;
		n=0;
		for(r=x;r<x+3;r++)
		{
			for(c=y;c<y+3;c++)
				threads[i].data[n++]=soduko[r][c];
		}
		y=y+3;
		// printf("data[j] of %d thread:",i);
		// for(li=0;li<9;li++)
		// {
		// 	printf("%d ",threads[i].data[li]);
		// }
		// printf("\n");
		pthread_create(&threadid[i], NULL, checker, &threads[i]);
		/*if(check==0)
		{
			printf("Sudoku is not valid!!! \n");
			return 0;
		}*/
		//pthread_join(threadid[i], NULL);
		
	}
	y=0;
	for(i=24;i<27;i++)
	{
		threads[i].x=i;
		//threads[i].arg=3;
		
		int r,c,n;
		x=6;
		n=0;
		for(r=x;r<x+3;r++)
		{
			for(c=y;c<y+3;c++)
				threads[i].data[n++]=soduko[r][c];
		}
		y=y+3;
		// printf("data[j] of %d thread:",i);
		// for(li=0;li<9;li++)
		// {
		// 	printf("%d ",threads[i].data[li]);
		// }
		// printf("\n");
		pthread_create(&threadid[i], NULL, checker, &threads[i]);
		/*if(check==0)
		{
			printf("Sudoku is not valid!!! \n");
			return 0;
		}*/
		//pthread_join(threadid[i], NULL);
	}
	
	for (i = 0; i < 27; ++i) 
	{
	    pthread_join(threadid[i], NULL);
	}
	
	for(i=0;i<27;i++)
	{
		if(check[i]==0)
		{
			printf("Soduko is invalid!!!\n");
			return 0;
		}
	}
	
	printf("Sudoku is valid!!! \n");
	return 0;
	
}
