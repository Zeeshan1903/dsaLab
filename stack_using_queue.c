#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

struct Node {
	int value;
	struct Node *next;
};

void enqueue(struct Node **q_1, struct Node **head, struct Node **tail, int value){

	struct Node *temp = malloc(sizeof(struct Node));
	temp -> value = value;
	temp -> next = NULL;  
	//here i have to check if the queue is emepty then i have to set both the tail and the head to one and if not empty then i ahve to inc the tail 
	if(*head == NULL ){
		*head = temp;
		*tail = temp;		
		return;
	}
	(*tail) -> next = temp ;
	(*tail) = temp;
	return;
}

void  dequeue(struct Node **q_2, struct Node **head, struct Node **tail){
	
	//first of all copy all the elements fromthe queue_one and then do or add here 
	//check if the queue is empty or not 
	if(*head == NULL && *tail == NULL){
		return ;
	}
	(*head) = (*head) ->next;
	return;	
}
int is_empty(struct Node **q_1,struct Node **head, struct Node **tail){
	if((*head) == NULL && ((*tail) == NULL)){
		return 1;
	}
	return 0;
}
void push(struct Node **q_1, struct Node **head, struct Node **tail, int value){
	
	//for pushing push it to the first queue
	enqueue(q_1, head, tail, value);		
}
void pop(struct Node **q_1, struct Node **q_2, struct Node **head_one, struct Node **head_t, struct Node **t_one, struct Node **t_two){
	
	//here the thing will be ill dequeue the first queue until it becomes emepty and will enqueue until the last appears and then show it and finally ill return that queue again  
	if(is_empty(q_1, head_one, t_one)){
		printf("Stack is empty\n");	
		return;
	}
	
	struct Node *temp = *head_one;
	while(temp -> next != NULL){
		
		int value = (temp)-> value;
		temp = temp -> next;
		dequeue(q_1,head_one, t_one);
		enqueue(q_2, head_t, t_two,value );
	}
	printf("Popped value : %d\n", (*head_one) -> value);
	dequeue(q_1, head_one,  t_one);
	
	
	temp = *head_t;
	while(temp != NULL){
	
		int value = (temp )-> value;
		temp = temp -> next;
		dequeue( q_2,  head_t,   t_two);
	       	enqueue(  q_1,  head_one, t_one, value);
	}
	return;
}
void print(struct Node **q_1, struct Node **head){
	if(*head == NULL){
		printf("Stack is empty while printing\n");
		return;
	}
	struct Node *temp =(*head);
	while(temp != NULL){
		printf("%d ",temp -> value);
		temp = temp -> next;
	}
	printf("\n");
}
int main(){
	
	//Here my goal is to implement a stack using queue 
	//Operations in queue : Enqueue add items at the end and Dequeue : removes items from start 
	//Stack both at the head
	//so what ill do is i will make two queues and enqueue in one and for dequeueing ill copy paste all elements to other queue and dequeue from it 
	
	
	struct Node *queue_one = NULL, *queue_two = NULL, *head_one = NULL, *head_two = NULL, *tail_one = NULL, *tail_two = NULL;
	print(&queue_one, &head_one);
	push(&queue_one, &head_one,&tail_one, 10);
	push(&queue_one, &head_one,&tail_one, 20);
	push(&queue_one, &head_one,&tail_one, 30); 
	push(&queue_one, &head_one,&tail_one, 40);
	print(&queue_one, &head_one);
	pop(&queue_one, &queue_two, &head_one, &head_two, &tail_one, &tail_two);
	print(&queue_one, &head_one);
	push(&queue_one, &head_one,&tail_one, 50);
	print(&queue_one, &head_one);
	push(&queue_one, &head_one,&tail_one, 60); 
	push(&queue_one, &head_one,&tail_one, 70);
	print(&queue_one, &head_one);
	pop(&queue_one, &queue_two, &head_one, &head_two, &tail_one, &tail_two);
	pop(&queue_one, &queue_two, &head_one, &head_two, &tail_one, &tail_two);
	pop(&queue_one, &queue_two, &head_one, &head_two, &tail_one, &tail_two);
	print(&queue_one, &head_one);
}
