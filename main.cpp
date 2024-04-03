//Author: Jad Saad
//Date: 12/4/2023
//Class Number: CS260
//Program 4
//
//
/*********PURPOSE********/
/************************/
//This program is a website bookmark saver that allows for 
//the addition, deletion, editing, and displaying of 
//bookmarks based on a variety of parameters. Whether
//that's a specific topic or all the topics, this program
//does it all through the use of the Tree ADT



//File Name: main.cpp
//Purpose: Holds all functions that encapsulate the ADT from
//the user. Includes all user interaction based functions

#include "main.h"


int main(){
    Tree list;

    if(!list.readFromFile()){
        cout << "Error opening file!\n";
        return 1;
    }

    cout << left << "Welcome to Jad's Website Bookmark Program!\n";

    do{
        displayMenu();
    }while(processRequest(list) != 'q');



    return 0;
}



//displays menu
void displayMenu(){
   cout << "\n(a) Add a bookmark"
        << "\n(b) Choose a website to display on keyword"
        << "\n(c) Remove based on keyword"
        << "\n(d) Remove based on topic"
        << "\n(e) Display All Websites"
        << "\n(f) Display Height and Size"
        << "\n(q) Quit";
}



//processes request
char processRequest(Tree& list){
    char option;
    cout << "\nPlease select an option from above: ";
    cin >> option;
    cin.ignore(100, '\n');

    option = tolower(option);

    switch(option){
        case 'a':
            add(list);
            break;
        case 'b':
            get(list);
            break;
        case 'c':
            removeMatch(list);
            break;
        case 'd':
            removeAllMatches(list);
            break;
        case 'e':
            list.print();
            break;
        case 'f':
            cout << "\nHeight: " << list.getHeight();
            cout << "\nSize: " << list.getSize();
            break;
        case 'q':
            cout << "\nThank you for using my Jad's Website Bookmark Program!\n";
            break;
        default:
            cout << "\nIncorrect Input!";
            break;
    }




    return option;

}



//helper for the add function
void add(Tree& list){
    char topicName[MAX_CHAR];
    const char* keywordPos = nullptr;
    char keyword[MAX_CHAR];
    char webAddress[MAX_CHAR];
    char summary[MAX_CHAR];
    char review[MAX_CHAR];
    int rating = 0;

    cout << "\nEnter the topic of this website: ";
    cin.getline(topicName, MAX_CHAR);

    cout << "\nEnter the web address: ";
    cin.getline(webAddress, MAX_CHAR);

    cout << "\nEnter a summary of the website: ";
    cin.getline(summary, MAX_CHAR);

    cout << "\nEnter a review of the website: ";
    cin.getline(review, MAX_CHAR);

    cout << "\nEnter a rating (1-5): ";
    cin >> rating;

    while(!cin || rating  <= 0 || rating > 5){
        cin.clear();
        cin.ignore(100, '\n');

        cout << "Invalid Input!\n";
        cout << "Enter a rating (1-5): ";
        cin >> rating;
    }

    keywordPos  = strstr(webAddress, ".com/");
    
    if(keywordPos != nullptr){
        strcpy(keyword, keywordPos + 5);
    }else{
        strcpy(keyword, webAddress); //if there's no keyword, use website and strstr later for search
    }              



    Website website(topicName, keyword, webAddress, summary, review, rating);

    list.add(website);
}



//helper for the removeAllMatches function
void removeAllMatches(Tree& list){
    char topicName[MAX_CHAR];

    cout << "\nEnter topic you'd like to remove: ";
    cin.getline(topicName, MAX_CHAR);

    cout << endl;

    if(list.removeAllMatches(topicName)){
        cout << "\nRemoved All Matches!\n";
    }else{
        cout << "\nNo match found.\n";
    }
}

//helper for the removeMatch function
void removeMatch(Tree& list){
    char keyword[MAX_CHAR];

    cout << "\nEnter keyword you'd like to remove: ";
    cin.getline(keyword, MAX_CHAR);

    cout << endl;

    if(list.removeMatch(keyword)){
        cout << "\nRemoved Successfully!\n";
    }else{
        cout << "\nNo match found.\n";
    }
}


//helper for the get function
void get(Tree& list){
    char keyword[MAX_CHAR];

    cout << "Enter the keyword of the bookmark you'd like to view: ";
    cin.getline(keyword, MAX_CHAR);

    Website* website = list.get(keyword);

    if(website){
        cout << "\nTopic: " << website->getTopicName();
        cout << "\nWeb Address: " << website->getWebAddress();
        cout << "\nSummary: " << website->getSummary();
        cout << "\nReview: " << website->getReview();
        cout << "\nRating(0-5): " << website->getRating();
        cout << '\n';
    }
}

