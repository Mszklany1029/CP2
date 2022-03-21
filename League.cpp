#include "League.h"
using namespace std;

League::~League(){
   delete[] team; 
}

bool League::addTeam(const Team &new_team) {
   if (new_team.getNickname().empty())
      return false;
   if (teamExists(new_team.getNickname()))
      return false;
  
   if(size == elements){
      int newSize = size*2; 
      Team* temp = new Team[newSize];
      for(unsigned int i = 0; i < elements; i++){
	      temp[i] = team[i]; 
      } 
      delete[] team; 
      team = temp; 
      size = newSize; 
   }
   team[elements] = new_team; 
   elements++; 
   return true; 
  
} 

bool League::teamExists(const std::string &nickname) const {
   for (unsigned i = 0; i < elements; i++) 
      if (team[i].getNickname() == nickname)
         return true;
   return false;
}

bool League::addPlayer(const Player &new_player, const std::string &nickname) { 
   for (unsigned i = 0; i < elements; i++){
      if (team[i].getNickname() == nickname) {
         team[i].showTeam();  
         team[i].addPlayer(new_player);
         return true;
      }
   }
   return false;
} 

void League::showTeams() const {
   cout << "Teams: " << elements  << std::endl;
   for (unsigned i = 0; i < elements; i++) 
      team[i].showTeam();
   return;
}

bool League::showPlayers(const std::string &nickname) const {  
   for (unsigned int i = 0; i < elements ; i++) 
      if (team[i].getNickname() == nickname) {
         team[i].showTeam();
         team[i].showPlayers();
         return true;
      }
   return false;
}

Player* League::searchTeams(const std::string &lastName){
   for(unsigned int i = 0; i < elements; i++){
      if(team[i].onTeam(lastName)){ 
         return team[i].getPlayer(lastName);
      }
   }
   return nullptr; 
}

Team& League::getTeam(const std::string &nickname){
   for(unsigned int i = 0; i < elements; i++){
      if(nickname == team[i].getNickname()){
         return team[i]; 
      }
   }
   static Team temp = Team("NULL", "NUll"); 
   return temp; 
}
