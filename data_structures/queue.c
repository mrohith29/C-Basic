/*
 * Queues in C
 *
 * --Introduction--
 * Queues are a type of container adaptors which operate in a first in first out
 * (FIFO) type of arrangement. Elements are inserted at the back (end) and are
 * deleted from the front. This is similar to a queue in real life, where the
 * person in the front of the queue is served first.
 *
 * --Operations on Queue--
 *  1. enqueue() - Insert an element at the back of the queue
 *  2. dequeue() - Remove an element from the front of the queue
 *  3. front() - Return the front (first) element of the queue
 *  4. rear() - Return the last element of the queue
 *  5. isEmpty() - Check if the queue is empty
 *  6. isFull() - Check if the queue is full
 *  7. display() - Display the elements of the queue
 *
 * --Implementation--
 *  In this example, we will implement a queue using an array.
 *  The array will be of fixed size and will be used to store the elements of
 * the queue. We will use two variables to keep track of the front and rear
 * elements. The front points to the first element of the queue and rear points
 * to the last element of the queue. Initially, both front and rear will be set
 * to -1. When an element is inserted into the queue, we will increment the rear
 * and insert the element at rear position. When an element is deleted from the
 * queue, we will increment the front. The front will always point to the first
 * element of the queue and rear will always point to the last element of the
 * queue. If the queue is empty, both front and rear will be -1. If the queue is
 * full, rear will be equal to the size of the array.
 *
 *  --Time Complexity--
 *  The time complexity of enqueue(), dequeue(), front(), rear(), isEmpty() and
 * isFull() operations is O(1). The time complexity of display() operation is
 * O(n).
 *
 *  --Applications--
 *  1. CPU scheduling, Disk Scheduling
 *  2. When data is transferred asynchronously between two processes.The queue
 * is used for synchronization.
 *  3. IO Buffers
 *
 *  --Notes--
 *  1. Queue is an abstract data structure, somewhat similar to Stacks.
 *  2. Unlike stacks, a queue is open at both its ends.
 *  3. One end is always used to insert data (enqueue) and the other is used to
 * remove data (dequeue).
 *  4. Queue follows First-In-First-Out methodology, i.e., the data item stored
 * first will be accessed first.
 *  5. A real-world example of queue can be a single-lane one-way road, where
 * the vehicle enters first, exits first.
 *  6. We do not actually change the elements of the queue, we only change the
 * front and rear indices.
 *  7. Hence, the time complexity of enqueue() and dequeue() operations is O(1).
 *  8. The elements are there in the queue, but we can access them only from
 * front to rear.
 * */

#include <stdio.h>
#include <stdlib.h> // Mostlly for exit() function

// Queue size
#define SIZE 10

// Global variables

int queue[SIZE];
int front = -1;
int rear = -1;

// Helper functions like isEmpty, isFull, etc.

int isEmpty() {
  if (front == -1 && rear == -1)
    return 1;
  else
    return 0;
}

int isFull() {
  if (rear == SIZE - 1)
    return 1;
  else
    return 0;
}

// Queue operations

void enqueue(int ele) {
  if (isFull()) {
    printf("Queue is full!\n");
    return;
  } else if (isEmpty()) {
    // If queue is empty, then front and rear are both 0
    front = rear = 0;
  } else {
    // If queue is not empty, then rear is incremented
    rear++;
  }
  queue[rear] = ele;
}

void dequeue() {
  if (isEmpty()) {
    printf("Queue is empty!\n");
    return;
  } else if (front == rear) {
    // If queue has only one element, then front and rear are both -1
    // Now, the queue is empty
    front = rear = -1;
  } else {
    // If queue has more than one element, then front is incremented
    // Now, the front element is dequeued
    // The front element is not actually deleted, but it is not accessible
    front++;
  }
}

// The display function
void display() {
  if (isEmpty()) {
    printf("Queue is empty!\n");
    return;
  }

  // Looping from front to rear
  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

void clear() {
  if (isEmpty()) {
    printf("Queue is empty!\n");
  } else {
    // Remember we are not actually deleting the elements
    // We are just making the queue empty
    // So, front and rear are both -1
    front = rear = -1;
  }
}

int main() {
  int choice, ele;
  while (1) {
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      scanf("%d", &ele);
      enqueue(ele);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
      break;
    case 5:
      clear();
    }
  }
}
