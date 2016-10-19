#include <stdio.h>
#include <stdlib.h>


/*
created by 刘昊  
*/
#define FULL 1
#define EMPTY 2
#define NOT_FullAndEmpty 3

#define DEFAULTLENGTH 5

typedef struct
{
	int *data;
	int length;
	
	int front,rear;
	int hasUsed;
	
	int LastOp;//1 is delete;0 is enter
}Queue;


int QueueState(Queue *q)//作业2 
{
	 if( q->front!=q->rear )
	 {
	 	return NOT_FullAndEmpty;
	 }
	 else
	 {
	 	if(q->LastOp)//finall operation is delete 
	 	{
	 		return EMPTY;
		}
		return FULL;
	 }
}

////////////////////////////////////////////////作业1 

void enQueue(Queue *q,int e)
{
	if( QueueState(q)==FULL )//if full,double length
	{
		
		int *t=(int*)malloc(q->length*2*sizeof(int)+sizeof(int));
		
		int i;
		for( i=0;i< q->length;i++ )
		{
			t[i]=q->data[i];
		}
		
		q->length*=2;
		q->length+=1;
		
		free(q->data);
		q->data=t;
		
	}
	
	q->rear++;
	q->rear%=q->length;
	
	
	q->data[q->rear]=e;
	q->LastOp=0;
	q->hasUsed++;
}

void deQueue(Queue *q,int *e)
{
	int NumOfEle=q->hasUsed;
	
	if( NumOfEle*4 > q->length )//if Num is too small,half length
	{
		int *t=(int*)malloc(q->length/2*sizeof(int));
		
		int i;
		for( i=0;i<NumOfEle;i++ )
		{
			t[i]=q->data[i];
		}
		
		q->length/=2;
		
		free(q->data);
		q->data=t;
		
	}

	
	
	q->front++;
	*e=QueueGetLast(q);
	q->front%=q->length;
	q->LastOp=1;
	q->hasUsed--;
}

/////////////////////////////////////////////////////////

