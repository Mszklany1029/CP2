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
   //elements = 0;  
   // playerArray = new Player[size]; 
   // MEMORY LEAK HERE ^^^^^
   //num_players = 0;
}

Team::Team(const std::string &loc, const std::string &name) {
   location = loc; 
   nickname = name;
   size = 1; 
   elements = 0; 
   playerArray = new Player[size];

  // size = 0; 
  // playerArray = new Player[size]; 
   
   //num_players = 0; 
}

bool Team::addPlayer(const Player &p) {
   //if (num_players == MAX_PLAYERS)
     // return false;
   if(size == elements){
   Player* tempArray = new Player[size + 1]; 

   for(unsigned int i = 0; i < elements; i++){
         tempArray[i] = playerArray[i];
   }
   delete[] playerArray; 
   size++; 
   elements++; 
   playerArray = tempArray; 

   playerArray[size - 1] = p;
   }else if (elements == 0){
          playerArray[0] = p;
          elements++; 
      }else{
      playerArray[size - elements] = p; 
      elements++; 

   } 
  /* if(getNickname() != "Free Agents"){
       playerArray[elements-1].record(getNickname(), playerArray[elements-1].getJerseyNum()); 

   }*/
 //cout << elements << endl; 
   //player[num_players++] = p;
   //num_players++;
   //player[0] = p;  
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

Player* Team::releasePlayer(const std::string &lastName /*, const std::string &nickName*/){
      Player temp = playerArray[0]; 
     // cout << elements << endl; 
   for(unsigned int i = 0; i < elements; i++){
      //cout << "enter loop" << endl;
         
      if(playerArray[i].getLastName() == lastName){
        // cout << "enter if" << endl; 
          
          static Player *temp = (&playerArray[i]); 
 

         playerArray[i] = playerArray[elements - 1]; 

         /*for(unsigned int x = i; x < elements -1 ; x++){
            playerArray[x] = playerArray[x+1];
            //FIX THIS
         }*/
         elements = elements - 1; 
         //cout << elements << endl; 
         return temp; 
         

         
      }else{
         cout << "Error: Player: " << lastName << " not on team" << endl;   
      }


   }
   return nullptr; 
   

};

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
         if(preferred == playerArray[i].getPreferred()){
            return false; 
         }
   }
   return true; 
}

unsigned int Team::lowestAvailableNumber(){
      //unsigned int lowest = 1; 

     for(unsigned int i = 0; i < elements; i++){
                  unsigned int low = playerArray[i].getJerseyNum();
            for(unsigned int x = 1; x < elements; x++){
                  unsigned int check = playerArray[x].getJerseyNum();  
               if(check < low){
                     Player temp = playerArray[i]; 
                     playerArray[i] = playerArray[x]; 
                     playerArray[x] = temp; 
               }
            }
      }
      if(playerArray[0].getJerseyNum() != 1){
         return 1;
      }else if((playerArray[elements - 1].getJerseyNum()) - (playerArray[0].getJerseyNum()) == elements-1){

         return (playerArray[elements-1].getJerseyNum()) + 1; 
      }else{
         for(unsigned int i = 1; i < elements; i++){
            int diff = playerArray[i].getJerseyNum() - playerArray[i-1].getJerseyNum();
            if(diff > 1){
               return (playerArray[i-1].getJerseyNum()) + 1; 
            }
         }
         
      }

   /*  
   if(playerArray[0].getJerseyNum() != 1){
      return 1; 
   }else{

         unsigned int diff = 0; 
         for(unsigned int i = 1; i < elements; i++){
             diff = playerArray[i].getJerseyNum() - playerArray[i-1].getJerseyNum(); 
             if(diff > 1){
                return playerArray[i-1].getJerseyNum() + 1;       
             }


         }
   }*/
      return 0; 

}
