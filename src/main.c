#include "main.h"

int main(int argc, char *argv[]) {

  struct Queue* queue = createQueue(MAX_CAPACITY);

  for(int i = MAX_CAPACITY; i--;){
    enqueue(queue, i);
  }

/*
    printf("size of queue:  %ld \n", sizeof(queue));
    printf("%d Items in Queue\n", queuedIteams(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d Space Remaining\n", remaining(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
*/
  int sum = 0;

  for (int i = MAX_CAPACITY; i--;){
    sum+=dequeue(queue);
  }


  clearMem(queue);

  return 0;
}
