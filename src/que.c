#include"que.h"

struct Queue* createQueue(unsigned capacity) {

    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

      queue->capacity = capacity;
      queue->front = queue->size = 0;
      queue->rear = capacity - 1;  // This is important, see the enqueue
      queue->array = (int*)malloc(queue->capacity*sizeof(int));

    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue) {
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
	return (queue->size == 0);
}

// find queue size
int queuedIteams(struct Queue* queue) {
  return (queue->rear);
}

int remaining(struct Queue* queue) {
  return (queue->capacity-queue->rear);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item) {

    if (isFull(queue)) {
				printf("queue is full \n");
        return;
		}

        queue->rear = (queue->rear + 1)%queue->capacity;
        queue->array[queue->rear] = item;
        queue->size = queue->size + 1;
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)){
      printf("queue is empty\n");
      return INT_MIN;
    }

      int item = queue->array[queue->front];
      queue->front = (queue->front + 1)%queue->capacity;
      queue->size = queue->size - 1;

    return item;
}

// Function to get front of queue
int front(struct Queue* queue) {
    if (isEmpty(queue)){
        return INT_MIN;
    }

    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        return INT_MIN;
      }

    return queue->array[queue->rear];
}


void clearMem(struct Queue* queue) {
    free(queue->array);
    free(queue);
}
