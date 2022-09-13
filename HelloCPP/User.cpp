/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"

using std::string;
using std::vector;

User::User(string userName) : userName(userName) {
  int firstLetter = userName[0];
  if (userName == "" || (firstLetter < 97 || firstLetter > 122)){
    throw std::invalid_argument("Invalid username!");
  }

  //checking if its uppercase
  int temp = 0;
  for(int i = 0; i < userName.length(); i++){
    userName = userName[i];
    if (temp >= 65 && temp <= 90){
      throw std::invalid_argument("Username has a capitol letter!");
    }
  }


}

string User::getUserName() {
  // TODO(student): implement getter
  return userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if (post == nullptr){
    throw std::invalid_argument("The post is nullptr!");
  }
  else{
    userPosts.push_back(post);
  }
}
