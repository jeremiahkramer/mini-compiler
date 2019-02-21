/****************************
 ** Program: list.c
 ** Author: Jeremiah Kramer
 ** Date: 6/10/17
 ** Description: implementation for list.h file
 ** Input: N/A
 ** Output: N/A
 ***************************/
#include "list.h"



/*****************************
 ** Function: init
 ** Description: initializes list by setting the head and the tail to null
 ** Parameters: struct list *
 ** Pre- Conditions: none
 ** Post- Conditions: list initialized
 ** Return: none
 ****************************/
void init(struct list *l){
	l->head = NULL;
	l->tail = NULL;
}

/*****************************
 ** Function: size
 ** Description: returns the size of the list (number of nodes in the list)
 ** Parameters: struct list *
 ** Pre- Conditions: list created
 ** Post- Conditions: you have the amount of nodes in the list
 ** Return: int
 ****************************/
int size(struct list l){
	int count = 0;
	if (l.head == NULL)
		return 0;
	else{
		//loop through the list, increasing the count each time
		while(l.head != NULL){
			++count;
			l.head = l.head->next;
		}
		return count;
	}
}

/*****************************
 ** Function: print
 ** Description: prints the values in each node 
 ** Parameters: struct list 
 ** Pre- Conditions: list created, preferably stuff in the list
 ** Post- Conditions: values printed out
 ** Return: none
 ****************************/
void print(struct list l){
	//loop through the list, printing the value each time
	while(l.head != NULL){
		printf("%d\n", l.head->val);
		l.head = l.head->next;
	}
}

/*****************************
 ** Function: push_front
 ** Description: pushes an int value (given from parameter) into the front of the list 
 ** Parameters: struct list *, int
 ** Pre- Conditions: list created
 ** Post- Conditions: new int value in beginning of list
 ** Return: none
 ****************************/
void push_front(struct list *l, int n){
	//new node temp
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	//assign temp the new value
	temp->val = n;
	//temp next points to head
	temp->next = l->head;
	//head then points to temp
	l->head = temp;
}

/*****************************
 ** Function: push_back
 ** Description: pushes an int value (given from parameter) into the back of the list 
 ** Parameters: struct list *, int
 ** Pre- Conditions: list created
 ** Post- Conditions: new int value in end of list
 ** Return: none
 ****************************/
void push_back(struct list *l, int n){
	//new node temp
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	//assign temp the new value
	temp->val = n;
	//temp next points to null (it will be at the end of list)
	temp->next = NULL;
	//if list empty
	if(l->head == NULL){
		l->head = temp;
		l->tail = temp;
	}
	else{
		//loop through list, starting at the head
		struct node *current = l->head;	
		while(current->next != NULL){
			current = current->next;
		}
		//assign last node pointing tho next to point to temp
		current->next = temp;
	}
}

/*****************************
 ** Function: front
 ** Description: returns the value of the front of the list (-1 if empty)
 ** Parameters: struct list 
 ** Pre- Conditions: list created
 ** Post- Conditions: you have the value of the front of the list
 ** Return: int
 ****************************/
int front(struct list l){
	//return -1 if empty
	if (l.head == NULL){
		return -1;
	}
	else{
		//return value at head of list
		return l.head->val;
	}
}

/*****************************
 ** Function: back
 ** Description: returns the value of the back of the list (-1 if empty)
 ** Parameters: struct list 
 ** Pre- Conditions: list created
 ** Post- Conditions: you have the value of the back of the list
 ** Return: int
 ****************************/
int back(struct list l){
	//return -1 if empty
	if (l.head == NULL){
		return -1;
	}
	else{
		//loop thorugh list, starting at the head
		struct node *current = l.head;	
		while(current->next != NULL){
			current = current->next;
		}
		//return last nodes value
		return current->val;
	}
}

/*****************************
 ** Function: pop_back
 ** Description: removes node at the end of the list and returns it's value
 ** Parameters: struct list *
 ** Pre- Conditions: list created
 ** Post- Conditions: you have the value of the back of the list, and node at the end of the list is removed
 ** Return: int
 ****************************/
int pop_back(struct list *l){
	//if empty, print message and return -1
	if (l->head == NULL){
		printf("List is empty");
		return -1;
	}
	else{
		int x;
		struct node *current = l->head; //to loop through list
		struct node *temp; //to not lose the list after deleting end
		while(current->next != NULL){
			//temp node points to current node
			temp = current;
			//current points to next current
			current = current->next;
		}
		//save value at end of node before deleting it
		x = current->val;
		temp->next = current->next;
		//free last node in list
		free(current);
		return x;
	}

}

/*****************************
 ** Function: remove_front
 ** Description: removes node at the begninning of the list and returns it's value
 ** Parameters: struct list *
 ** Pre- Conditions: list created
 ** Post- Conditions: you have the value of the front of the list, and node at the beginnning of the list is removed
 ** Return: int
 ****************************/
int remove_front(struct list *l){
	int x;
	struct node *temp;
	//if empty, print message and return -1
	if (l->head == NULL){
		printf("List is empty");
		return -1;
	}
	else{
		//temp points to head
		temp = l->head;
		//head points to head next
		l->head = l->head->next;
		//save int from temp(prev head)
		x = temp->val;
		//delete temp
		free(temp);
		return x;
	}
}

/*****************************
 ** Function: empty
 ** Description: checks if list is empty and returns true (1) if empty, false (0) if not
 ** Parameters: struct list
 ** Pre- Conditions: list created
 ** Post- Conditions: you know if the list is empty or not
 ** Return: int
 ****************************/
int empty(struct list l){
	//return 1 if empty
	if (l.head == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

/*****************************
 ** Function: delete
 ** Description: removes all node from thee list and free memory allocation
 ** Parameters: struct list *
 ** Pre- Conditions: list created
 ** Post- Conditions: no memory leaks
 ** Return: none
 ****************************/
void delete(struct list *l){
	//get out of function if empty
	if (l->head == NULL){
		return;
	}
	else{
		struct node *temp1 = l->head; //to loop thorugh list
		struct node *temp2; //to not lose list while deleting stuff
		while (temp1 != NULL){
			//point temp2 to temp1 next
			temp2 = temp1->next;
			//delete temp11
			free(temp1);
			//temp1 now points to temp2
			temp1 = temp2;
		}
		//point head to null once done
		l->head = NULL;
	}
}
