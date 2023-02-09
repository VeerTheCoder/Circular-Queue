#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void enqueue();
void dequeue();
void display();
int queue[SIZE],front=-1,rare=-1;
int main(){
	int c;
	printf("Press 1. to Insert\n");
	printf("Press 2. to Delete\n");
	printf("Press 3. to Display\n");
	printf("Press 4. to Exit\n");
	while(1){
		printf("Enter your Choice:");
		scanf("%d",&c);
		switch(c){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}
void enqueue(){
	if((rare==SIZE-1&&front==0)||(front==rare+1)){
		printf("Can not Insert...Queue overflow\n");
	}
	else{ 
		int e;
		printf("Enter Element:");
		scanf("%d",&e);
		if(rare==-1){
			rare=front=0;
			queue[rare]=e;
		}
		else if(rare==SIZE-1){
			rare=0;
			queue[rare]=e;
		}
		else{
			rare++;
			queue[rare]=e;
		}
		printf("Inserted Element=%d\n",e);
	}
}
void dequeue(){
	if(front==-1){
		printf("Can not Delete...Queue Underflow\n");
	}
	else{
		if(front==rare){
		printf("Deleted Element is %d\n",queue[front]);
		rare=front=-1;
		}
		else if(front==SIZE-1){
			front=0;
			printf("Deleted Element is %d\n",queue[front]);
		}
		else{
			printf("Deleted Element is %d\n",queue[front]);
			front++;
		}
	}
}
void display(){
	if(front==-1){
		printf("There is no Element..Queue underflow\n");
	}
	else{
		int i;
		if(rare<front){
			for(i=front;i<=SIZE-1;i++)
				printf("%d ",queue[i]);
			for(i=0;i<=rare;i++)
				printf("%d ",queue[i]);
		}
		else{
			for(i=front;i<=rare;i++)
				printf("%d ",queue[i]);
		}
		printf("\n");
	}
}
