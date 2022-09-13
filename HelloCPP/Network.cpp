/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file

  std::ifstream infs (fileName);
  std::string line = "";
  std::string part = "";
  std::string firstPart = "";
  std::string secondPart = "";
  int secondPartInt = 0;
  std::string thirdPart = "";
  std::string postText = "";
  int count = 0;
  if(infs.is_open()){
    while(getline(infs, line)){
        std::stringstream reader(line);
        while(!reader.eof()){
          reader >> part;
          
          //checking if neither user or post
          if (count == 0 && !(part == "Post" || part == "User")){ //if it is the first part or if not "Post" or "User"
            throw std::runtime_error("Neither Post nor User");
          }

          //assigning firstPart to "User" or "Post" for later use
          if (count == 0){
            firstPart = part;
          }


          //checking if the second part is a digit
          
          
          

          //add user and post using functions
          if (firstPart == "User" && count == 1){
            if (count == 1){
              secondPart = part;
            }
            try{
              addUser(secondPart);
            }
            catch(...){
              throw std::runtime_error("addUser failed!");
            }
            
          }

          if (firstPart == "Post"){
            if (count == 1){
              secondPart = part;
              //checking if second part is a digit
              bool isDigit = true;
              for(int i = 0; i < part.length(); i++){
                if( !( isdigit(part.at(i)) ) ){
                  isDigit = false;
                }
              }

              //if it's the second place and not a digit
              if ( !(isDigit) ){ 
                throw std::runtime_error("Second part is not a digit");
              }

              //converting the ID to an integer
              secondPartInt = stoi(secondPart);


            }
            if (count == 2){
              thirdPart = part;
            }

            if (count >= 3){ 
              postText += part + " "; //------------------------------------------Adds extra space to end, remove out of while loop
            }
          }


          count++;
        }

        //erase the last character (becuase it is an extra space)
        //postText.erase(postText.length()-1, 1);

        if(count < 2){ //checking if there is only one thing in the line
          throw std::runtime_error("Only one thing in this line!");
        }
        if(firstPart == "Post"){ //throwing error if addPost doesn't work
          try{
            postText.erase(postText.length()-1, 1);
            addPost(secondPartInt, thirdPart, postText);
          }
          catch(...){
            throw std::runtime_error("Adding post did not work!");
          }
        }

        postText = "";
        count = 0;
    }
  }
  else{
    throw std::invalid_argument("File could not be opened!");
  }
  


  
}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
  for (int i = 0; i < userName.length(); i++){
    userName[i] = tolower(userName[i]);
  }


  for (int i = 0; i < users.size(); i++){
    if (users[i]->getUserName() == userName){
      throw std::invalid_argument("UserName already exists!");
    }
  }


  User* newUser = new User(userName);
	users.push_back(newUser);
  std::cout << "Added User " << userName << std::endl;

}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
  
  //checking if user exists
  bool userExists = false;
  for (int i = 0; i < users.size(); i++){
    if (users.at(i)->getUserName() == userName){
      userExists = true;
    }
  }
  if (!userExists){
    throw std::invalid_argument("User does not exist!");
  }

  //checking if post ID already exists
  for (int i = 0; i < posts.size(); i++){
    if (posts.at(i)->getPostId() == postId){
      throw std::invalid_argument("Post already exists!");
    }
  }

  //creating new post
  Post* newPost = new Post(postId, userName, postText);
  
  //adding post to Network data member posts
  posts.push_back(newPost);

  //Addition of post information to correspoding users // -----------------------------------------------------Error GetTagPosts is empty
  for (int i = 0; i < users.size(); i++){
    if (userName == users.at(i)->getUserName()){
      users.at(i)->addUserPost(newPost);
    }
  }

  
  //Extraction of candidate hashtags contained within post
  vector<std::string> postHashtags = newPost->findTags();

  //Searching if tag already exists
  bool alreadyExists = false;
  for (int i = 0; i < postHashtags.size(); i++){
    alreadyExists = false;
    for(int j = 0; j <  tags.size(); j++){
      if (postHashtags.at(i) == tags.at(j)->getTagName() ){
        alreadyExists = true;
        tags.at(j)->addTagPost(newPost);
        break;
      }
    }
    if (!alreadyExists){
      //try creating the variable and catch all exceptions
      try{
        Tag* newTag = new Tag(postHashtags.at(i));
        newTag->addTagPost(newPost);
        tags.push_back(newTag);
      }catch(...){
        continue;
      }      

    }

  }

  std::cout << "Added Post " << postId << " by " << userName << std::endl;
  

}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  if (userName == ""){
    throw std::invalid_argument("Given Username is blank");
  }
  for (int i = 0; i < users.size(); i++){
    if (users.at(i)->getUserName() == userName){
      return users.at(i)->getUserPosts();
    }
  }
  throw std::invalid_argument("User does not exist!");
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  if (tagName == ""){
    throw std::invalid_argument("Given Tag is blank");
  }
  for (int i = 0; i < tags.size(); i++){
    if (tags.at(i)->getTagName() == tagName){
      return tags.at(i)->getTagPosts();
    }
  }
  throw std::invalid_argument("Tag does not exist!");
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts

  //loop through tags
  vector<std::string> ans;
  int killMe = 0;
  for (int i = 0; i < tags.size(); i++){
    if ((tags.at(i)->getTagPosts()).size() == killMe){
      ans.push_back(tags.at(i)->getTagName());
    }
    else if((tags.at(i)->getTagPosts()).size() > killMe){
      ans.clear();
      ans.push_back(tags.at(i)->getTagName());
      killMe = (tags.at(i)->getTagPosts()).size();
    }
  }

  return ans;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
