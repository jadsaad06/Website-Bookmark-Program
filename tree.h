//File: tree.h
//Purpose: holds everything related to the Tree ADT
//Includes the node struct, construtors, and destructors
//as well as all prootypes for tree.cpp


#ifndef TREE_H_
#define TREE_H_

#include "myutil.h"
#include "website.h"


class Tree{
public: 
    Tree();
    ~Tree();
    
    bool readFromFile();
    
    
    //helper function
    void print();
    void add(const Website& website);
    bool removeMatch(const char keyword[]);
    bool removeAllMatches(const char topicName[]);
    Website* get(const char keyword[]);

    //getters
    int getHeight();
    int getSize();



private: 
    struct Node{
        Website* website;
        Node* left;
        Node* right;

        Node(){
            website = nullptr;
            left = right = nullptr;
        };

        ~Node(){
            delete website;
        };
            
        Node(const Website website){
            this->website = new Website(website);
            left = right = nullptr;
        };
    };


    Node* root;
    int size;
  
    //node manipulation
    void add(Node*& currRoot, const Website& website); 
    void removeNode(Node *& target);
    void deleteTree(Node *& root);
    bool removeMatch(Node*& currRoot, const char keyword[]);
    bool removeAllMatches(Node*& currRoot, const char topicName[]);

    
    //printing
    void printNode(Node *& root) const;   
    void print(Node*& currRoot) const;



    //MISC
    int getHeight(Node* currRoot);
    int  max(int left, int right); 
    bool retrieve(Node*& root, const char keyword[], Website*& match);
};


#endif
