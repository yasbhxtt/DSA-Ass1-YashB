
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//main.c - main logic and queue testing // main logic for testing queue / generation of random users, enqueueing, dequeueing, and printing user information
int main(int argc, char* argv[]) {
    if (argc != 2) {    //check if number of arguments is correct
        printf("Usage: %s <number_of_users>\n", argv[0]);
        return 1;   //exit with error if number is invalid
    }

    int numUsers = atoi(argv[1]);   //convert argument to integer
    if (numUsers <= 0) {    //to make sure number of users is positive number
        printf("Invalid number of users.\n");   //print invalid number of users if condition not met
        return 1;
    }

    srand(time(NULL));  //seed random number generator with current time
    Queue q;    //declaration of a queue
    initializeQueue(&q);    //initialize the queue as empty

    if (enqueueRandomUsers(&q, numUsers) != 0) {    //enqueue the specified number of users
        printf("Error enqueueing users.\n");    //print error if enqueue fails
        return 1;
    }

    printf("Dequeuing users:\n");   //print dequeueing users if successfull
    User user;
    while (!isQueueEmpty(&q)) {
        dequeue(&q, &user); //dequeue user
        printUser(user);    //print the users details after dequeueing 
    }
    return 0;
}