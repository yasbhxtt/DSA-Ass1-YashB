#pragma once


//user.h - user data struct // defines user structure, faction, random user generation and printing
#ifndef USER_H
#define USER_H

#define USERNAME_LENGTH 10 //define max length for username to 10

typedef enum { RED, BLUE, GREEN } Faction; //enum for different factions users could belong to


typedef struct {    //struct to store username, level, faction 
    char username[USERNAME_LENGTH + 1];
    int level;  //level from 1-60
    Faction faction; //user faction (RED, BLUE, GREEN)
} User;

void generateRandomUsername(char* username);    //function for generating random usernames

User generateRandomUser();  //function to generate random users

void printUser(User user);  //function to print user name


#endif