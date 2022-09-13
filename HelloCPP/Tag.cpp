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
#include "Tag.h"

using std::string;
using std::vector;

Tag::Tag(string tagName) : tagName(tagName) { //-----------------------------------------Vector initialized to {}??????? ---------ERROR-----------
  // TODO(student): implement constructor checks
  int intChar = tagName[1];
  if (tagName.length() < 2 || tagName[0] != '#' || tagName[tagName.length() - 1] == '!' || tagName[tagName.length() - 1] == ',' || tagName[tagName.length() - 1] == '.' || tagName[tagName.length() - 1] == '?'){
    throw std::invalid_argument("Invalid Tag!");
  }
  if (intChar < 97 || intChar > 122 ){
    throw std::invalid_argument("Invalid Tag!");
  }

  //checking for uppercase letters
  int temp = 0;
  for(int i = 1; i < tagName.length(); i++){ //starts after the hashTag
    temp = tagName[i];
    if (temp >= 65 && temp <= 90){
      throw std::invalid_argument("Tag has a capitol letter!");
    }
  }

}


string Tag::getTagName() {
  // TODO(student): implement getter
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return tagPosts;

}

void Tag::addTagPost(Post* post) {
  // TODO(student): add post to tag posts
  if (post == nullptr){
    throw std::invalid_argument("Post is nullptr!");
  }
  else{
    tagPosts.push_back(post);
  }
}
