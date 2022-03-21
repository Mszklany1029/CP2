#include "Team.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <string>

using namespace std;

Team::Team() {
   location = "";
   nickname = "";
   size = 1;
   elements = 0;  
   playerArray = new Player[size]; 
}

Team::Team(const std::string &loc, const std::string &name) {
   location = loc; 
   nickname = name;
   size = 1; 
   elements = 0; 
   playerArray = new Player[size];
}

Team::Team(const Team& rhs){
   location = rhs.location; 
   nickname = rhs.nickname; 
   size = rhs.size; 
   elements = rhs.elements; 
   playerArray = new Player[size]; 
   for(unsigned int i = 0; i < elements; i++){
      playerArray[i] = rhs.playerArray[i]; 
   }
}

Team& Team::operator=(const Team& rhs){
   if(this != &rhs){
      location = rhs.location; 
      nickname = rhs.nickname;
      size = rhs.size; 
      elements = rhs.elements; 
      delete[] playerArray; 
      playerArray = new Player[size]; 
      for(unsigned int i = 0; i < elements; i++){
         playerArray[i] = rhs.playerArray[i];
      }
   }
   return *this; 
}

Team::~Team(){
   delete[] playerArray;
}

bool Team::addPlayer(const Player &p) {
   if(size == elements){
      int newSize = size * 2; 
      Player* tempArray = new Player[newSize]; 
      for(unsigned int i = 0; i < elements; i++){
         tempArray[i] = playerArray[i];
      }
      delete[] playerArray; 
      playerArray = tempArray;
      size = newSize;  
   }
   playerArray[elements] = p; 
   elements++; 
   return true; 
}

void Team::showTeam() const {
   std::cout << location << " " << nickname << endl;	 
}

void Team::showPlayers() const {
   std::cout << "   Players:" << std::endl;
   for (unsigned int i = 0; i < elements; i++) {
      playerArray[i].show();
   }
}

bool Team::read() {
   string line;

   std::cout << "     Location: "; 
   std::getline(std::cin, location);
   std::cout << "     Nickname: "; 
   std::getline(std::cin, nickname);
   return true; 
}

std::ostream &operator<<(std::ostream &out, const Team &tm) {
   tm.showTeam();
   return out;
}

Player Team::releasePlayer(const std::string &lastName){
   Player p; 
   for(unsigned int i = 0; i < elements; i++){
      if(playerArray[i].getLastName() == lastName){
         p = playerArray[i]; 
         playerArray[i] = playerArray[--elements]; 
         return p; 
      }
   }  
   cout << "Error: Player: " << lastName << " not on team" << endl;   
   return p;
}

bool Team::onTeam(const std::string &lastName){
      for(unsigned int i = 0; i< elements; i++){
         if(lastName == playerArray[i].getLastName()){
            return true;
         }
      }
   return false;

}

Player* Team::getPlayer(const std::string &lastName){ 
   for(unsigned int i = 0; i < elements; i++){
      if(lastName == playerArray[i].getLastName()){
         return (&playerArray[i]); 
      }
   }
   return nullptr; 
}


bool Team::numAvailable(unsigned int preferred){
   for(unsigned int i = 0; i < elements; i++){
      if(preferred == playerArray[i].getJerseyNum()){
         return false; 
      }
   }
   return true; 
}

unsigned int Team::lowestAvailableNumber(){
  unsigned int search = 1; 
   while(search <= elements){
      for(unsigned int i = 0; i <= elements; i++){
         if(i == elements){
            return search; 
         }else if(playerArray[i].getJerseyNum() == search){
            break; 
         }  
      }
      search++; 
   }
   return elements+1; 
}
