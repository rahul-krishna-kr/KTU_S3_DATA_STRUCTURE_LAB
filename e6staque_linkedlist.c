/*#include <stdio.h>

#define MAX_SIZE 3

typedef struct CircularQueue {
    int queue[MAX_SIZE];
    int front, rear;
} CircularQueue;

typedef struct PrioElm{
	int data;
	int prio;
}PrioElm;

typedef struct PriorityQueue {
    PrioElm queue[MAX_SIZE];
    int size;
} PriorityQueue;

void initCircularQueue(CircularQueue *cq) {
    cq->front = cq->rear = -1;
}

int isCircularQueueEmpty(const CircularQueue *cq) {
    return cq->front == -1 && cq->rear == -1;
}

int isCircularQueueFull(const CircularQueue *cq) {
    return (cq->rear + 1) % MAX_SIZE == cq->front;
}

void enqueueCircularQueue(CircularQueue *cq, int item) {
    if (isCircularQueueFull(cq)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isCircularQueueEmpty(cq)) {
            cq->front = cq->rear = 0;
        } else {
            cq->rear = (cq->rear + 1) % MAX_SIZE;
        }
        cq->queue[cq->rear] = item;
        printf("%d enqueued successfully.\n", item);
    }
}

void dequeueCircularQueue(CircularQueue *cq) {
    if (isCircularQueueEmpty(cq)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued successfully.\n", cq->queue[cq->front]);
        if (cq->front == cq->rear) {
            cq->front = cq->rear = -1;
        } else {
            cq->front = (cq->front + 1) % MAX_SIZE;
        }
    }
}

void displayCircularQueue(const CircularQueue *cq) {
    if (isCircularQueueEmpty(cq)) {
        printf("Queue is empty.\n");
    } else {
        int i = cq->front;
        printf("Queue elements: ");
        do {
            printf("%d ", cq->queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (cq->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

void initPriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}

int isPriorityQueueEmpty(const PriorityQueue *pq) {
    return pq->size == 0;
}

int isPriorityQueueFull(const PriorityQueue *pq) {
    return pq->size == MAX_SIZE;
}

void enqueuePriorityQueue(PriorityQueue *pq, PrioElm item) {
    if (isPriorityQueueFull(pq)) {
        printf("Priority queue is full. Cannot enqueue.\n");
    } else {
        int i = pq->size - 1;
        while (i >= 0 && item.prio < pq->queue[i].prio) {
            pq->queue[i + 1] = pq->queue[i];
            i--;
        }
        pq->queue[i + 1] = item;
        pq->size++;
        printf("%d enqueued successfully.\n", item.data);
    }
}

void dequeuePriorityQueue(PriorityQueue *pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued successfully.\n", pq->queue[0].data);
        for (int i = 1; i < pq->size; i++) {
            pq->queue[i - 1].data = pq->queue[i].data;
        }
        pq->size--;
    }
}

void displayPriorityQueue(const PriorityQueue *pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Priority queue elements: ");
        for (int i = 0; i < pq->size; i++) {
            printf("%d ", pq->queue[i].data);
        }
        printf("\n");
    }
}


void cq(){
	 
	 initCircularQueue(&circularQueue);
	 int chchoice;
	 while(chchoice!=)
	 switch (choice) {
            case 1:
                printf("Enter an item to enqueue in Circular Queue: ");
                scanf("%d", &item);
                enqueueCircularQueue(&circularQueue, item);
                break;
            case 2:
                dequeueCircularQueue(&circularQueue);
                break;
            case 3:
                displayCircularQueue(&circularQueue);
                break;
}

int main() {
   CircularQueue circularQueue;
    PriorityQueue priorityQueue;
    int choice, item;
    PrioElm elm;

    
    initPriorityQueue(&priorityQueue);

    do {
        printf("\nMain Menu:\n");
        printf("1. Circular Queue - Enqueue\n");
        printf("2. Circular Queue - Dequeue\n");
        printf("3. Circular Queue - Display\n");
        printf("4. Priority Queue - Enqueue\n");
        printf("5. Priority Queue - Dequeue\n");
        printf("6. Priority Queue - Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        
            case 4:
                printf("Enter an item to enqueue in Priority Queue: ");
                scanf("%d", &elm.data);
                printf("Enter Priority of element: ");
                scanf("%d", &elm.prio);
                enqueuePriorityQueue(&priorityQueue, elm);
                break;
            case 5:
                dequeuePriorityQueue(&priorityQueue);
                break;
            case 6:
                displayPriorityQueue(&priorityQueue);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *top = NULL;  // Stack top pointer
Node *front = NULL;  // Queue front pointer
Node *rear = NULL;  // Queue rear pointer

void push(int data) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = data;
  temp->next = top;
  top = temp;
}

int pop() {
  if (top == NULL) {
    printf("Stack is empty!\n");
    return -1;
  }

  Node *temp = top;
  int data = temp->data;
  top = top->next;
  free(temp);
  return data;
}

void displayStack() {
  if (top == NULL) {
    printf("Stack is empty!\n");
    return;
  }

  Node *temp = top;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void enqueue(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (front == NULL) {
    front = newNode;
    rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int dequeue() {
  if (front == NULL) {
    printf("Queue is empty!\n");
    return -1;
  }

  Node *temp = front;
  int data = temp->data;
  front = front->next;
  free(temp);

  if (front == NULL) {
    rear = NULL;  // Queue becomes empty after dequeue
  }

  return data;
}

void displayQueue() {
  if (front == NULL) {
    printf("Queue is empty!\n");
    return;
  }

  Node *temp = front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int choice, data;

  while (1) {
    printf("\nChoose operation:\n");
    printf("1. Push to stack\n");
    printf("2. Pop from stack\n");
    printf("3. Display stack\n");
    printf("4. Insert to queue\n");
    printf("5. Delete from queue\n");
    printf("6. Display queue\n");
    printf("7. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to push: ");
        scanf("%d", &data);
        push(data);
        displayStack();
        break;

      case 2:
        data = pop();
        if (data != -1) {
          printf("Popped element: %d\n", data);
          displayStack();
        }
        break;

      case 3:
        displayStack();
        break;

      case 4:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        enqueue(data);
        displayQueue();
        break;

      case 5:
        data = dequeue();
        if (data != -1) {
          printf("Deleted element: %d\n", data);
          displayQueue();
        }
        break;

      case 6:
        displayQueue();
        break;

      case 7:
        exit(0);
        break;

      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}

