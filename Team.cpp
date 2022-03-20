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
      Player* tempArray = new Player[size + 1]; 
      size++; 
      for(unsigned int i = 0; i < elements; i++){
         tempArray[i] = playerArray[i];
      }
      delete[] playerArray; 
      playerArray = tempArray; 
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




//unsigned int Team::lowestAvailableNumber(){
      //unsigned int lowest = 1; 

     /*for(unsigned int i = 0; i < elements; i++){
                  unsigned int low = playerArray[i].getJerseyNum();
            for(unsigned int x = 1; x < elements; x++){
                  unsigned int check = playerArray[x].getJerseyNum();  
               if(check < low){
                     Player temp = playerArray[i]; 
                     playerArray[i] = playerArray[x]; 
                     playerArray[x] = temp; 
               }
            }
      }*/

  /*    for(unsigned int i = 1; i < elements; i++){
         unsigned int key = playerArray[i].getJerseyNum(); 
         unsigned int x = i - 1; 
         while(key < playerArray[x].getJerseyNum() && x >= 0){
            playerArray[x + 1] = playerArray[x];
               --x; 
         }
         playerArray[x + 1].setJerseyNum(key); 
      }*/
      
      //we need, starting position on right, and starting position on left
     // unsigned int left = playerArray[0].getJerseyNum(); 
      //unsigned int right = playerArray[elements - 1].getJerseyNum();
      //unsigned int mid = left + (right - left)/2; 

    /*  while(right >= left){
         //unsigned int mid = left + (right - left)/2; 
            unsigned int mid  = (left + right)/2; 

            if(playerArray[mid].getJerseyNum() != mid + 1 && playerArray[mid -1].getJerseyNum() == mid){
               return mid +1; 
            }else if(playerArray[mid].getJerseyNum() == mid + 1){
               left = mid + 1; 
            }else{
               right = mid - 1; 
            }*/



         /*if(playerArray[mid].getJerseyNum() != mid){
            if(/*mid == 1 ||*/ //playerArray[mid - 1].getJerseyNum() == mid -1)
              /* return mid; 
            right = mid - 1;
            //mid = mid -1; 
         }else{
            left = mid +1;
           // mid = mid + 1; 
         }*/ 

   //   }

 /*     if(playerArray[0].getJerseyNum() != 1){
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
         
      }*/

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
     // return 0; 

//}
