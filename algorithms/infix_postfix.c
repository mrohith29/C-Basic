#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 20

int top = -1;
char stack[MAX_SIZE];

void push(char stack[], char element){
  if(top == MAX_SIZE-1){
    printf("StackOverflow");
  }
  else{
    top++;
    stack[top] = element;
  }
}

char pop(char stack[]){
  if(top == -1){
    printf("Stackunderflow");
  }
  else{
    return stack[--top];
  }
}

int getpriority(char op) {
  if (op == '^')
    return 2;
  else if (op == '/' || op == '*' || op == '%')
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else
    return -1;
}

int main(){
  char infix[100], postfix[100], temp;
  int i,j=0;
  scanf("%s", infix);
  for(i = 0; infix[i]!='\0'; i++){
    if(infix[i] == '('){
      push(stack, infix[i]);
    }
    else if(isalpha(infix[i]) || isdigit(infix[i])){
      postfix[i] = infix[i];
      j++;
    }
    else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%' || infix[i] == '^'){
      while(getpriority(stack[top]) >= getpriority(infix[i])){
        postfix[i]  = pop(stack);
        j++;
      }
      push(stack, infix[i]);
    }
    else if(infix[i] == ')'){
      while(stack[top] != '('){
        postfix[i] = pop(stack);
        j++;
      }
    }
  }
  while (top != -1) {
    postfix[j] = pop(stack);
    j++;
  }
  postfix[j] = '\0';
  printf("%s", postfix);

  return 0;
}