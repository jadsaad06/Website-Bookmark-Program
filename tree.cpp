//File Name: tree.cpp
//Purpose: Holds all information regarding the Tree ADT
//Has a add, retrieve, and two remove functions including
//multiple private functions to allow for solid encapsulation



#include "tree.h"


//constructor
Tree::Tree(){
    root = nullptr;
    size = 0;
}



//destructor
Tree::~Tree(){
    deleteTree(root);
}





//recursively deletes tree
//called in destructor
void Tree::deleteTree(Node *& currRoot){
    if(currRoot){
        deleteTree(currRoot->left);
        deleteTree(currRoot->right);
        delete currRoot;
        currRoot = nullptr;
    }
}




//prints a node in a the chain
void Tree::printNode(Node *& root) const{
    cout << "\nTopic: " << root->website->getTopicName();
    cout << "\nKeyword: " << root->website->getKeyword();
    cout << "\nWeb Address: " << root->website->getWebAddress();
    cout << "\nSummary: " << root->website->getSummary();
    cout << "\nReview: " << root->website->getReview();
    cout << "\nRating(0-5): " << root->website->getRating();
    cout << '\n';
}





//fills one match 
bool Tree::retrieve(Node*& root, const char keyword[], Website*& match) {
    // Base case: If the tree is empty or the keyword is not found
    if (root == nullptr) {
        return false;
    }

    // Check if the keyword is equal to the current node's key
    if (strcmp(keyword, root->website->getKeyword()) == 0) {
        match = root->website;
        return true;
    } else if (strcmp(keyword, root->website->getKeyword()) < 0) {
        return retrieve(root->left, keyword, match);
    } else {
        return retrieve(root->right, keyword, match);
    }

}

//retrieve based on keyword
Website* Tree::get(const char keyword[]){
    Website* match = nullptr;

    if(!retrieve(this->root, keyword, match)){
        cout << "\nNo match found!";
    }

    return match;
}



//reads from the bookmark.txt file
bool Tree::readFromFile(){
    ifstream inFile;
    bool loaded = true;

    inFile.open("bookmarks.txt");

    if(inFile.is_open()){
        char topicName[MAX_CHAR];
        const char* keywordPos = nullptr;
        char keyword[MAX_CHAR];
        char webAddress[MAX_CHAR];
        char summary[MAX_CHAR];
        char review[MAX_CHAR];
        int rating = 0;
        
        inFile.getline(topicName, MAX_CHAR, ';');

        while(!inFile.eof()){
            inFile.getline(webAddress, MAX_CHAR, ';');
            inFile.getline(summary, MAX_CHAR, ';');
            inFile.getline(review, MAX_CHAR, ';');
            inFile >> rating;
            inFile.ignore();
            

            keywordPos = strstr(webAddress, ".com/");

            if(keywordPos != nullptr){
                strcpy(keyword, keywordPos + 5);
            }else{
                strcpy(keyword, webAddress); //if there's no keyword, use website and strstr later for search
            }              

            Website website(topicName, keyword, webAddress, summary, review, rating);
            add(website);

            inFile.getline(topicName, MAX_CHAR, ';');
        }
    }else{
        loaded = false;
    }

    return loaded;
} 



//helper for add function
void Tree::add(const Website& website){
    add(this->root, website);
}



//add a node to the BST
void Tree::add(Node*& currRoot, const Website& website){
    if(!currRoot){
        currRoot = new Node(website);
        size++;
        return;
    }

    if(strcmp(website.getKeyword(), currRoot->website->getKeyword()) < 0){
        add(currRoot->left, website);
    }else{
        add(currRoot->right, website);
    }
}



//print helper
void Tree::print(){
    print(this->root);
}



//print the BST
void Tree::print(Node*& currRoot) const{
    if(currRoot){
        print(currRoot->left);
        printNode(currRoot);
        print(currRoot->right);
    }
}



//hleper to remove the keyword match
bool Tree::removeMatch(const char keyword[]){
    return removeMatch(root, keyword);
}



//helper remove matches by topic
bool Tree::removeAllMatches(const char topicName[]){
    return removeAllMatches(root, topicName);
}



//remove the keyword match
bool Tree::removeMatch(Node*& currRoot, const char keyword[]){
    if(!currRoot){
        return false;
    }
    
    int temp = strcmp(currRoot->website->getKeyword(), keyword);

    if(temp == 0){
        removeNode(currRoot);
        size--;
        return true;
    }else if(temp < 0){
       return removeMatch(currRoot->left, keyword);
    }else{
       return removeMatch(currRoot->right, keyword);
    }
}

      

//remove all topic names      
bool Tree::removeAllMatches(Node*& currRoot, const char topicName[]){
    if (!currRoot) {
        return false;
    }

    removeAllMatches(currRoot->left, topicName);
    removeAllMatches(currRoot->right, topicName);

    int temp = strcmp(currRoot->website->getTopicName(), topicName);

    if (temp == 0) {
        removeNode(currRoot);
        size--;
        return true;
    }
   return false; 
}



//remove node in general
void Tree::removeNode(Node*& target) {
   if(!target->left && !target->right){
       delete target;
       target = nullptr;
   }
   else if(!target->right){
       Node* temp = target;
       target = target->left;
       delete temp;
   }
   else if(!target->left){
       Node* temp = target;
       target = target->right;
       delete temp;
   }else{
       Node* prev = nullptr;
       Node* curr = target->right;
       
       while(curr->left){
           prev = curr;
           curr = curr->left;
       }
       
       delete target->website;
       target->website = curr->website;
       curr->website = nullptr;
       
       if(!prev){
           target->right = curr->right;
       }else{
           prev->left  = curr->right;
       }

       delete curr;
   }
}

      


//find max between left and right
int Tree::max(int left, int right){
    if(left >= right){
        return left;
    }else{
        return right;
    }
}



//return the height
int Tree::getHeight(Node* currRoot){
    if(!currRoot){
        return 0;
    }

    int left = getHeight(currRoot->left);
    int right = getHeight(currRoot->right);
    return max(left, right) + 1;
}


//helper for the getHeight function
int Tree::getHeight(){
    return getHeight(root);
}



//returns the size
int Tree::getSize(){
    return size;
}
