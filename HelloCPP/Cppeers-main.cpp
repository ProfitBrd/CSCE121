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
#include <vector>
#include "Network.h"

using std::cout, std::cin, std::endl;
using std::string, std::vector;

void printMenu() {
  cout << "Welcome to CPPeers" << endl;
  cout << "The options are: " << endl;
  cout << "1. load data file and add information" << endl;
  cout << "2. show posts by user" << endl;
  cout << "3. show posts with hashtag" << endl;
  cout << "4. show most popular hashtag" << endl;
  cout << "9. quit" << endl;
  cout << "--------> Enter your option: ";
}

void processLoad(Network& cppeers) {
  string fileName = "";
  cout << "Enter filename: ";
  cin >> fileName;
  cppeers.loadFromFile(fileName);
}

void processPostsByUser(Network& cppeers) {
  // TODO(student): implement
  string userName = "";
  cout << "Enter username: ";
  cin >> userName;
  vector<Post*> temp = cppeers.getPostsByUser(userName);
  for(int i = 0; i < temp.size(); i++){
    cout << temp.at(i)->getPostText() << endl;
  }


}

void processPostsWithHashtags(Network& cppeers) {
  // TODO(student): implement
  string tagName = "";
  cout << "Enter tagname: ";
  cin >> tagName;
  vector<Post*> temp = cppeers.getPostsWithTag(tagName);

  for(int i = 0; i < temp.size(); i++){
    cout << temp.at(i)->getPostText() << endl;
  }

}

void processMostPopularHashtag(Network& cppeers) {
  // TODO(student): implement
  vector<string> temp = cppeers.getMostPopularHashtag();
  for(int i = 0; i < temp.size(); i++){
    cout << temp.at(i) << endl;
  }
}

int main() {

  /*
  Post newPost(1234, "Mike", "#hello#to #To! #test!,");
  vector<string> hello;
  hello = newPost.findTags();
  cout << hello.size() << endl;
  for (int i = 0; i < hello.size(); i++){
    cout << hello.at(i) << endl;
  }
  
 Network *  n = new Network();
 n->loadFromFile("Test1.txt");
 n->getPostsWithTag("#dynamic");
 */
  
  

  try {
    Network cppeers;

    int choice = 0;

    // present menu
    do {
      printMenu();
      cin >> choice;
      if(choice == 9){
        break;
      }
      switch(choice) {
        case 1: {
          processLoad(cppeers);
          break;
        }
        case 2: {
          processPostsByUser(cppeers);
          break;
        }
        case 3: {
          processPostsWithHashtags(cppeers);
          break;
        }
        case 4: {
          processMostPopularHashtag(cppeers);
          break;
        }
      }
    } while (choice != 9);
  } catch (std::exception& exc) {
    std::cout << exc.what() << endl;
  }

  return 0;
}