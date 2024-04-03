//File: main.h
//Purpose: Holds functin prototypes for main.cpp


#ifndef MAIN_H_
#define MAIN_H_

#include "myutil.h"
#include "website.h"
#include "tree.h"


void displayMenu();
char processRequest(Tree& list);
void displayMatching(Tree& list);
void add(Tree& list);
void removeMatch(Tree& list);
void removeAllMatches(Tree& list);
void get(Tree& list);




#endif
