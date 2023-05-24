/* <STACKS>
 *
 * --Introduction--
 * Stacks are a basic data structure in C.
 * They are used in a wide variety of applications.
 * They are useful for storing data in a way that follows a last-in-first-out
 *(LIFO) sequence. This means that the last item to be added to the stack is the
 *first one to be removed.
 *
 * --Uses--
 * Stacks are useful for reversing the order of items.
 * They are also useful for parsing expressions.
 *
 *--Implementation--
 * Stacks can be implemented using arrays or linked lists.
 * This is an implementation of them using arrays
 *
 * --Functions--
 *  - push() - adds an item to the stack
 *  - pop() - removes an item from the stack
 *  - peek() - returns the top item in the stack
 *  - isEmpty() - returns true if the stack is empty
 *  - isFull() - returns true if the stack is full
 *	- printStack() - prints the stack
 *	- clearStack() - clears the stack
 *	- stackTop() - returns the top of the stack
 *
 *	--Time Complexity--
 *	- push() - O(1)
 *	- pop() - O(1)
 *	- peek() - O(1)
 *	- isEmpty() - O(1)
 *	- isFull() - O(1)
 *	- printStack() - O(n)
 *	- clearStack() - O(1)
 *	- stackTop() - O(1)
 *
 *	--Way It Works--
 *	> An array is used to store the items in the stack.
 *	> An integer variable is used to keep track of the top of the stack.
 *	> When an item is pushed onto the stack, the top variable is
 *incremented. > When an item is popped from the stack, the top variable is
 *decremented. > When an item is peeked at, the item at the top variable is
 *returned. > When the stack is cleared, the top variable is set to -1.
 * */

// Basic Stuff

#include <stdio.h>
#include <stdlib.h> // Mostly for the exit() function

#define STACK_SIZE 10 // Can be changed to whatever you want

// Global Variables
// Can also be declared in main() and passed to the functions
// but with static variables, they are only initialized once
// and can be used in any function in this file

int stack[STACK_SIZE];
int top = -1;

// A few stack helper functions like isEmpty(), isFull(), etc.

int isEmpty() {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int isFull() {
  if (top == STACK_SIZE - 1) {
    return 1;
  } else {
    return 0;
  }
}

void push(int ele) {

  // If the stack is full, then the element cannot be pushed
  if (isFull()) {
    printf("Stack Overflow\n");
  }

  // If the stack is not full, then the element can be pushed
  else {
    // Increment the top variable and add the element to the stack
    top++;
    stack[top] = ele;
  }
}

void pop() {
  // Cannot pop if the stack is empty
  if (isEmpty()) {
    printf("Stack Underflow\n");
  } else {
    // Decrement the top variable
    top--;
  }
}

void clear() {
  // Set the top variable to -1
  top = -1;
}

void display() {
  if (isEmpty()) {
    printf("Stack Underflow\n");
  } else {
    // Print the elements of the stack
    for (int i = top; i >= 0; i--) {
      printf("%d ", stack[i]);
    }
    printf("\n");
  }
}

// The main function
int main() {
  int choice, ele;
  while (1) {
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      scanf("%d", &ele);
      push(ele);
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      clear();
      break;
    case 5:
      exit(0);
    }
  }
}

/*
 * Just a few things to note:
 * 1. The stack is a global variable, so it can be used in any function
 * 2. We do not actually clear the stack, we just set the top variable to -1
 * 3. The stack is a LIFO data structure, so the last element that is pushed
 *   will be the first element that is popped
 *  4. The top variable is the index of the topmost element in the stack
 *  5. The top variable is initialized to -1, so that the first element that is
 *  pushed will be at index 0
 *  6. The top variable is incremented before pushing an element, so that the
 *  first element that is pushed will be at index 0
 *  7. The top variable is decremented after popping an element, so that the
 *  topmost element is removed
 *  8. We do not actually remove the element, we just decrement the top variable
 *  9. Hence the time complexity of push and pop is O(1)
 *  10. The element is there, but it is not accessible
 * */
