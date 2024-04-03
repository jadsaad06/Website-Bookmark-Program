//File Name: website.cpp
//Purpose: Holds all infomration regarding the website class
//Includes all constructors, destructors, setters, and getters



#include "website.h"



Website::Website(){//constructor
    topicName = nullptr;
    keyword = nullptr;
    webAddress = nullptr;
    summary = nullptr;
    review = nullptr;
}



Website::~Website(){//destructor
    delete[] topicName;
    delete[] keyword;
    delete[] webAddress;
    delete[] summary;
    delete[] review;
}



//parameterized constructor
Website::Website(char topicName[], char keyword[], char webAddress[], char summary[], char review[], int rating){
    this->topicName = new char[strlen(topicName) + 1];    
    strcpy(this->topicName, topicName);

     this->keyword = new char[strlen(keyword) + 1];
     strcpy(this->keyword, keyword);

     this->webAddress = new char[strlen(webAddress) + 1];    
     strcpy(this->webAddress, webAddress);

     this->summary = new char[strlen(summary) + 1];    
     strcpy(this->summary, summary);

     this->review  = new char[strlen(review) + 1]; 
     strcpy(this->review, review);

     this->rating = rating;
}


//copy constructor
Website::Website(const Website& website){
    topicName = new char[strlen(website.topicName) + 1];    
    strcpy(topicName, website.topicName);
    
    keyword = new char[strlen(website.keyword) + 1];
    strcpy(keyword, website.keyword);

    webAddress = new char[strlen(website.webAddress) + 1];    
    strcpy(webAddress, website.webAddress);

    summary = new char[strlen(website.summary) + 1];    
    strcpy(summary, website.summary);

    review  = new char[strlen(website.review) + 1]; 
    strcpy(review, website.review);

    rating = website.rating;
}



//copy assignment operator
Website Website::operator=(const Website*& other){
   if (this != other) {
        // Delete the existing memory
        delete[] topicName;
        delete[] keyword;
        delete[] webAddress;
        delete[] summary;
        delete[] review;

        // Perform a deep copy of all attributes
        topicName = new char[strlen(other->topicName) + 1];
        strcpy(topicName, other->topicName);

        keyword = new char[strlen(other->keyword) + 1 ];
        strcpy(keyword, other->keyword);

        webAddress = new char[strlen(other->webAddress) + 1];
        strcpy(webAddress, other->webAddress);

        summary = new char[strlen(other->summary) + 1];
        strcpy(summary, other->summary);

        review = new char[strlen(other->review) + 1];
        strcpy(review, other->review);

        rating = other->rating;
    }
    return *this;
}



//setters
void Website::setTopicName(const char topicName[]){
        this->topicName = new char[strlen(topicName) + 1];    
        strcpy(this->topicName, topicName);
}


void Website::setKeyword(const char keyword[]){
    this->keyword = new char[strlen(keyword) + 1];
    strcpy(this->keyword, keyword);
}

void Website::setWebAddress(const char webAddress[]){
        this->webAddress = new char[strlen(webAddress) + 1];    
        strcpy(this->webAddress, webAddress);
}

void Website::setSummary(const char summary[]){
        this->summary = new char[strlen(summary) + 1];    
        strcpy(this->summary, summary);
}


void Website::setReview(const char review[]){
        this->review  = new char[strlen(review) + 1]; 
        strcpy(this->review, review);
}

void Website::setRating(const int rating){
    this->rating = rating;
}



//getters
const char* Website::getTopicName() const{
    return topicName;
}

const char* Website::getKeyword() const{
    return keyword;
}

const char* Website::getWebAddress() const{
    return webAddress;
}

const char* Website::getSummary() const{
    return summary;
}

const char* Website::getReview() const{
    return review;
}

const int Website::getRating() const{
    return rating;
}
