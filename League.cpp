#include "League.h"
using namespace std;

League::League(const League& rhs){
   size = rhs.size; 
   elements = rhs.elements; 
   team = new Team[size]; 
   for(unsigned int i = 0; i < elements; i++){
      team[i] = rhs.team[i]; 
   }

}

League& League::operator=(const League& rhs){
   if(this != &rhs){
      delete[] team; 
      size = rhs.size; 
      elements = rhs.elements; 
      team = new Team[size]; 
      for(unsigned int i = 0; i < elements; i++){
         team[i] = rhs.team[i];   
      }

   }
   return *this;

}



bool League::addTeam(const Team &new_team) {
   if (new_team.getNickname().empty())
      return false;
   if (teamExists(new_team.getNickname()))
      return false;
  
   if(size == elements){
   Team* temp = new Team[size + 1];
    for(unsigned int i = 0; i < elements; i++){
	temp[i] = team[i]; 
    } 
    delete[] team; 
    size++;
    elements++; 
    team = temp; 
     
    team[size-1] = new_team;
    }else if(elements == 0){
         team[elements] = new_team; 
         elements++; 
    }else{
      team[size - elements] = new_team; 
      elements++; 
    } 
    //MEMORY LEAK HERE???? 

//   team.push_back(new_team);
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
         //Player player = Player("joe", "Mama", 233, "Giants"); 
         team[i].addPlayer(new_player);
         //cout << "seg fault????" << endl; 
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
            //static Player temp = team[i].getPlayer(lastName;
            return team[i].getPlayer(lastName);
      }
   }
   return nullptr; 

}

/*Player League::searchTeams(const std::string &lastName){
   for(unsigned int i = 0; i < elements ; i++){
      if(team[i].onTeam(lastName)){
         return team[i].getPlayer(lastName); 

      }

   }  
   return team[0].getPlayer(lastName); 

}*/ 

Team& League::getTeam(const std::string &nickname){
   for(unsigned int i = 0; i < elements; i++){
         if(nickname == team[i].getNickname()){
            return team[i]; 
         }

   }
   static Team temp = Team("NULL", "NUll"); 
   return temp; 

}
