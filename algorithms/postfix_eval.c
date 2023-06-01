#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int stack[100];
int pop();
void push(int);
int operate(int, int, char);
int top = -1;
int main(){
    int val,res,op1,op2,i=0;
    char ch;
    char choice[100];
    scanf("%s", choice);
    while(choice[i] != '\0'){
        ch = choice[i];
        if(isalpha(ch)){
            scanf("%d", &val);
            push(val);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            op2 = pop();
            op1 = pop();
            res = operate(op1, op2, ch);
            push(res);
        }
        i++;
    }
    res = pop();
    printf("The simplified answer for %s = %d", choice, res);
}

int pop(){
    int n ;
    n = stack[top];
    top--;
    return n;
}

void push(int element){
    top++;
    stack[top] = element;
}

int operate(int op1, int op2, char ch){
    int temp;
    switch(ch){
        case '^':
        temp = pow(op1, op2);
        break;
        case '+':
        temp = op1 + op2;
        break;
        case '-':
        temp = op1 - op2;
        break;
        case '*':
        temp = op1 * op2;
        break;
        case '/':
        temp = op1/op2;
        break;
    }
    return temp;
}
