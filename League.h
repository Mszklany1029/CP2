#ifndef _LEAGUE_H
#define _LEAGUE_H
#include <iostream>
#include <vector>
#include "Team.h"

class League {
   private:
      // std::vector<Team> team;
       Team *team;
      unsigned int size;
      unsigned int elements;  

   public:
       League() {
	      size = 1; 
         elements = 0; 
         team = new Team[size];
       //Team freeAgents("", "Free Agents"); 
       //team[0] = freeAgents; 
       //elements = 1;
       //^^^^ MEMORY LEAK HERE^^^^
       };
       ~League();
      // League(const League& rhs); 
       //League& operator=(const League& rhs); 

       bool addTeam(const Team &new_team);
       bool teamExists(const std::string &nickname) const;
       bool addPlayer(const Player &new_player, const std::string &teamMascot);
       void showTeams() const;
       bool showPlayers(const std::string &nickname) const;
       unsigned int numTeams(){return elements;}; 
       Player* searchTeams(const std::string &lastName); 
       Team& getTeam(const std:: string &nickname);
        
};

#endif // _LEAGUE_H
