#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//user.c - main generator for users details

char getRandomChar() {  //function to get random character for usernames
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";  //list of all possible characters
    return charset[rand() % (sizeof(charset) - 1)]; //generate random character for list
}

void generateRandomUsername(char* username) {   //function to generate random username from random character picker
    for (int i = 0; i < USERNAME_LENGTH; i++) {
        username[i] = getRandomChar();  //pick random character from charset list
    }
    username[USERNAME_LENGTH] = '\0';   //NULL terminate the string
}

User generateRandomUser() { //function to generate random user with randomized username, level, and faction
    User user;
    generateRandomUsername(user.username);  //generate random username
    user.level = (rand() % 60) + 1; //generate random level between 1 - 60
    user.faction = rand() % 3;  //choose from 3 factions and assign either red, blue, or green
    return user;
}

void printUser(User user) { //function to print the users deatils
    const char* factionNames[] = { "RED", "BLUE", "GREEN" };    //print faction names either RED, BLUE, or GREEN
    printf("Username: %s, Level: %d, Faction: %s\n", user.username, user.level, factionNames[user.faction]);    //print username, level, and faction
}