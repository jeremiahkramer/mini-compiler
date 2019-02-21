/****************************
 ** Program: driver.c
 ** Author: Jeremiah Kramer
 ** Date: 6/10/17
 ** Description: mini compiler that checks for closing parenthesis, brackets, and curly braces after their corresponding opening parenthesis, brackets, curly braces
 ** Input: brackets, parenthesis, curly braces
 ** Output: Accepted or Rejected
 ***************************/
#include <stdio.h> //printf(), scanf()
#include <stdlib.h> //malloc/free and NULL
#include <string.h> //strlen
#include "list.h" //linked list implementation



/*****************************
 ** Function: get_input
 ** Description: gets a string of characters regardless if there is whitespace or not
 ** Parameters: char *
 ** Pre- Conditions: none
 ** Post- Conditions: char array is filled
 ** Return: none
 ****************************/
void get_input(char *c){
	printf("Enter a string of brackets: ");
	scanf("%[^\n]%*c", c); //special edit conversion code for C that allows to read all characters of a string including whitespaces
	printf("\n"); 

}

/*****************************
 ** Function: push_or_pop_stack
 ** Description: opening brackets, curly braces, parenthesis will push an int value on the stack. If corresponding clsoing brackets, curly braces, and parenthesis are inputted, the  						 int value will be popped off the stack
 ** Parameters: struct list *, char *
 ** Pre- Conditions: char array filled (or not - it accepts something without input, which makes sense)
 ** Post- Conditions: ints pushed on stack (if closing bracket, etc. doesn't correspond) or all int popped off stack (empty)
 ** Return: none
 ****************************/
void push_or_pop_stack(struct list *l, char *c){
	int i, length;
	length = strlen(c);

	for (i = 0; i < length; i++){
		//if there is an opening bracket, assign int value to 0 and put on top of stack
		if (c[i] == '['){
			push_front(l, 0);
		}
		//if there is an opening curly brace, assign int value to 1 and put on top of stack
		else if (c[i] == '{'){
			push_front(l, 1);
		}
		//if there is an opening parenthesis, assign int value to 2 and put on top of stack
		else if (c[i] == '('){
			push_front(l, 2);
		}
		//if there is a closing bracket, check to see what int value there is at the top of the stack, and if it is 0, pop 0 off the top of the stack
		else if ((c[i] == ']' && front(*l) == 0)){
			remove_front(l);
		}
		//if there is a closing curly brace, check to see what int value there is at the top of the stack, and if it is 1, pop 1 off the top of the stack
		else if ((c[i] == '}' && front(*l) == 1)){
			remove_front(l);
		}
		//if there is a closing parenthesis, check to see what int value there is at the top of the stack, and if it is 2, pop 2 off the top of the stack
		else if ((c[i] == ')' && front(*l) == 2)){
			remove_front(l);
		}
		//if there is a closing bracket, etc., and the stack is empty, push some int value on the stack (5) because there shouldn't be a closing bracket without an opening one
		else if ((c[i] == ']' || c[i] == '}' || c[i] == ')') && empty(*l) == 1){
			push_front(l, 5);
		}
		//if there is a closing bracket, and the top of the stack isn't the corresponding int value, push some int value on the stack (5), because they don't correspond
		else if (c[i] == ']' && front(*l) != 0){
			push_front(l, 5);
		}
		//if there is a closing curly brace, and the top of the stack isn't the corresponding int value, push some int value on the stack (5), because they don't correspond
		else if (c[i] == '}' && front(*l) != 1){
			push_front(l, 5);
		}
		//if there is a closing parenthesis, and the top of the stack isn't the corresponding int value, push some int value on the stack (5), because they don't correspond
		else if (c[i] == ')' && front(*l) != 2){
			push_front(l, 5);
		}	
	}
}
/*****************************
 ** Function: accept_reject
 ** Description: checks to see if the list is empty and wil print out a message if it is accepted/empty or not(rejected)
 ** Parameters: struct list *
 ** Pre- Conditions: stuff in list (or not - will just print accepted/empty then)
 ** Post- Conditions: none
 ** Return: none
 ****************************/
void accept_reject(struct list *l){
	//empty(struct list *) function returns 1 (true) if it is empty
	if (empty(*l) == 1){
		printf("Accepted\n");
	}
	//not empty
	else{
		printf("Rejected\n");
	}
}



int main(){
	//declare all variables at top for C
	int i, length;
	struct list l;
	char c[256]; //static char array of max size

	//initialize list
	init(&l);
	//get character array
	get_input(c);
	//push stuff on stack then pop it all off or leave some int if brackets, etc. don't correspond
	push_or_pop_stack(&l, c);
	//print message if string of bracets, etc. are valid
	accept_reject(&l);
	//free memory allocation
	delete(&l);

	return 0;
}
