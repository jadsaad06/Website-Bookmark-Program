//File: website.h
//Purpose: holds all private data for the website class
//holds all prototypes for website.cpp


#ifndef WEBSITE_H_
#define WEBSITE_H_

#include "myutil.h"

class Website{
private:
    char* topicName;
    char* keyword;
    char* webAddress;
    char* summary;
    char* review;
    int rating;


public:
    //constructors
    Website();
    Website(char topicName[], char keyword[], char webAddress[], char summary[], char review[], int rating);
    Website(const Website& website);
    ~Website();
    Website operator=(const Website *& other);

    //setters
    void setTopicName(const char topicName[]);
    void setKeyword(const char keyword[]);
    void setWebAddress(const char webAddress[]);
    void setSummary(const char summary[]);
    void setReview(const char review[]);
    void setRating(const int rating);



    //getters
    const char* getTopicName() const;
    const char* getKeyword() const;
    const char* getWebAddress() const;
    const char* getSummary() const;
    const char* getReview() const;
    const int getRating() const;
};


#endif
