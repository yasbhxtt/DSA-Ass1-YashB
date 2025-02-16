
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

//queue.c - queue function implementation for enqueueing, dequeueing, and checking for empty queue.

QueueNode* createNode(User user) { //function to create a new node with given user data

    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)); //allocate memory for the new code

    if (!newNode) return NULL;  //return null for failed memory allocation
    newNode->data = user;   //set user data into new node
    newNode->next = NULL;   // set next pointer to NULL

    return newNode; //return the new node

}

void initializeQueue(Queue* q) {    //function initialize an empty queue

    q->head = q->tail = NULL;   //both head and tail are NULL (empty queue at first)
}

int isQueueEmpty(Queue* q) {    //function to check if the queue is empty

    return q->head == NULL;     //if head is NULL the queue is empty
}
//enqueue function
int enqueue(Queue* q, User user) { // function to add new user to queue

    QueueNode* newNode = createNode(user);  //create new node for user

    if (!newNode) return -1;   //return error if node creation fails
    if (q->tail) q->tail->next = newNode; //if queue isn't empty link the new node to tail

    q->tail = newNode;  //update tail to new node

    if (!q->head) q->head = newNode;    //if queue is empty the new node is head

    return 0;
}

//dequeue function
int dequeue(Queue* q, User* user) { //function to remove user from front of queue

    if (isQueueEmpty(q)) return -1; //return error if queue is empty
    QueueNode* temp = q->head;  //temporary pointer to first node
    *user = temp->data; //copy user data to pointer

    q->head = temp->next;   //move head pointer to next node

    if (!q->head) q->tail = NULL;   // if queue becomes empty, set tail to NULL

    free(temp); // free memory of dequeued node
    return 0;
}

int enqueueRandomUsers(Queue* q, int count) {   // function to enqueue specified number of randomly generated users
    for (int i = 0; i < count; i++) {
        User user = generateRandomUser();   //generate a random user
        if (enqueue(q, user) != 0) {    //enqueue user, return error if fails
            printf("ERROR enqueueing user %d\n", i + 1);    //print error if enqueueing user fails
            return -1;
        }
    }
    return 0;
}