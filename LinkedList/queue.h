#pragma once

// queue.h - function prototypes // defines QueueNode and Queue structures 
//defines function prototypes for managing (enqueue, dequeue, and checking for empty queue)
#ifndef QUEUE_H
#define QUEUE_H

#include "user.h"

typedef struct QueueNode {  //struct to define the queuenode
    User data;  //store data in each node
    struct QueueNode* next; //pointer to next node in queue
} QueueNode;

typedef struct {    //defines the queue struct with pointers to head and tail of queue
    QueueNode* head;
    QueueNode* tail;
} Queue;

void initializeQueue(Queue* q); //function to inititalize an empty queue

int isQueueEmpty(Queue* q); //function to check if queue is empty

int enqueue(Queue* q, User user); //function to add a user to queue (enqueue user)

int dequeue(Queue* q, User* user); //function to remove a user form the queue (dequeue user)

int enqueueRandomUsers(Queue* q, int count); //function to enqueue specified number of random generated users

#endif