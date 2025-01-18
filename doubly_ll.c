#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*	Goal : To make a doubly linkedlist 
 *	Approach : First of all i have to make a sturct anode and it will have two thing next, previous pointer
 *	Next pointer will store the address of the next and the previous will store the address of previous
 *	Fn : print_forward(), print_reverse(), add_forward(), add_backward(), delete_forward(), delete_backward()
 */

struct Node {
	int value;
	struct Node *next;
	struct Node *previous;
};

void add_forward(struct Node **ll,struct Node **start , struct Node **end,int value){
	
	//Here first of all check if the ll is empty or not if empty then initialize start and end
	struct Node *temp = malloc(sizeof(struct Node));	
	temp -> next = NULL;
	temp -> previous = NULL;
	temp -> value = value;	
	if((*start) == NULL && (*end) == NULL){
		
		(*start) = temp;
		(*end) = temp;	
		return;	
	}
	(*end) ->next = temp;
	temp -> previous = (*end);
	(*end) = temp;	
	return;	
}
void add_backward(struct Node **ll,struct Node **start, struct Node **end, int value){

	struct Node *temp = malloc(sizeof(struct Node));
	temp ->next = NULL;
	temp -> previous = NULL;
	temp -> value = value;
	if((*start) == NULL && (*end) == NULL){
		*start = temp;
		*end = temp;
	
		return;
	}
	(*start)->previous = temp;
	temp -> next = *start;
	(*start) = temp;

	return;	

}

int is_empty(struct Node **ll, struct Node **start , struct Node **end){
	if((*start) == NULL && (*end) == NULL){
		printf("Linkedlist is empty\n");
		return 1;
	}
	return 0;
}
void delete_forward(struct Node **ll, struct Node **start, struct Node **tail){
	
	//check if empty

	if(is_empty(ll,start,tail)){
		return;		
	}
	struct Node *temp = NULL;
	temp = (*tail);
	printf("Forward Deleted %d\n",temp -> value);
	(*tail) = (*tail)-> previous;
//	(*tail) -> next = NULL;
//	free(temp);	
}

void delete_backward(struct Node **ll, struct Node **start, struct Node **tail){
	//check ifempy
	if(is_empty(ll,start,tail)){
		return;
	}
	struct Node *temp = NULL;
	temp  = (*start);
	printf("Backward Deleted %d\n",temp->value);
	(*start) = (*start) -> next;
//	(*start) -> previous = NULL;
//	free(temp);	
}

void print_forward(struct Node **ll, struct Node **start, struct Node **tail){
	if(is_empty(ll,start,tail)){
		return;
	}
	printf("Forward : ");
	struct Node *temp = *start;
	while(temp != NULL){
		printf("%d ",temp -> value);
		temp = temp -> next;	
	}
	printf("\n");
}
void print_backward(struct Node **ll, struct Node **start, struct Node **tail){
	if(is_empty(ll,start,tail)){
		return;
	}
	printf("\nBackward : ");
	struct Node *temp = *tail;
	while( temp != NULL){
		printf("%d ",temp -> value);
		temp = temp -> previous;
	}
	printf("\n");
}
int main(){
	struct Node *ll = NULL;
	struct Node *start = ll, *end = ll;
	add_forward(&ll,&start,&end,10);
	add_forward(&ll,&start,&end,20);
	print_forward(&ll,&start,&end);
	print_backward(&ll,&start,&end);
	add_backward(&ll,&start,&end,20);
	add_backward(&ll,&start,&end,30);
	add_backward(&ll,&start,&end,40);
	print_forward(&ll,&start,&end);
	delete_forward(&ll,&start,&end);	
	print_backward(&ll,&start,&end);
	delete_backward(&ll,&start,&end);
	print_forward(&ll,&start,&end);
}
