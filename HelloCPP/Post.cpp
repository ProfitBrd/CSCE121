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
#include <string>
#include <stdexcept>
#include <sstream>
#include "Post.h"

using std::string;
using std::vector;

Post::Post(unsigned int postId, string userName, string postText) 
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}


unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  vector<string> result;
  string temp = "";
  bool underHashtag = false;

  string reading_text = getPostText();
  std::stringstream reader(reading_text);

  while(!reader.eof()){
    reader >> reading_text;

    if (reading_text.at(0) == '#'){
      for(int i = reading_text.size() - 1; i >=2; i--){
        if (reading_text.at(i) == '!' || reading_text.at(i) == ',' || reading_text.at(i) == '.' || reading_text.at(i) == '?'){
          reading_text.erase(i,1);
        }

        for(int i = 0; i < reading_text.size(); i++){
          reading_text.at(i) = tolower(reading_text.at(i));
        }

      }

      result.push_back(reading_text);


    }
  }
  
  /*for (int i = 0; i < postText.length(); i++){
    
    if (postText[i] == '#'){
      underHashtag = true;
    }



    //ending the hashtag -----------------------------------------------------------------------------------------------------------------------------Missing edge case where two hashtags are together ##
    if (postText[i] == ' ' && underHashtag){
      underHashtag = false;
      
      //checking if ending has punctuation - and removing them
      if(temp[temp.length() - 1] == '!' || temp[temp.length() - 1] == ',' || temp[temp.length() - 1] == '.' || temp[temp.length() - 1] == '?'){
        int i = temp.length() - 1;
        while(temp[i] == '!' || temp[i] == ',' || temp[i] == '.' || temp[i] == '?'){
          i--;
        }
        temp = temp.substr(0, i + 1);
      }

      //checking if any uppercase letters
      int tempInt = 0;
      for(int i = 0; i < temp.length() - 1; i++){
        tempInt = temp[i];
        if (tempInt >= 65 && tempInt <= 90){
          temp[i] = temp[i] + 32;
        }
      }




      result.push_back(temp);
      temp = "";
    }

    if (underHashtag){
      
      temp += postText[i];
    }


  }

  if(underHashtag){
    //checking if ending has punctuation - and removing them
      if(temp[temp.length() - 1] == '!' || temp[temp.length() - 1] == ',' || temp[temp.length() - 1] == '.' || temp[temp.length() - 1] == '?'){
        int i = temp.length() - 1;
        while(temp[i] == '!' || temp[i] == ',' || temp[i] == '.' || temp[i] == '?'){
          i--;
        }
        temp = temp.substr(0, i + 1);
      }

      //checking if any uppercase letters
      int tempInt = 0;
      for(int i = 0; i < temp.length() - 1; i++){
        tempInt = temp[i];
        if (tempInt >= 65 && tempInt <= 90){
          temp[i] = temp[i] + 32;
        }
      }

    result.push_back(temp);
  }*/

  return result;






}
