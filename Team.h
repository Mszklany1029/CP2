#ifndef _TEAM_H
#define _TEAM_H

#include "Player.h"
#include <iostream>
#include <string>

class Team {
   private:
      std::string location;
      std::string nickname;
      Player *playerArray; 
      unsigned int size; 
      unsigned int elements;

   public:
      Team(); 
      Team(const std::string &loc, const std::string &name);
      Team(const Team& rhs); 
      Team& operator=(const Team& rhs); 
      ~Team(); 
      std::string getNickname() const {return nickname;};
      bool addPlayer(const Player &p);
      void showTeam() const;
      void showPlayers() const;
      bool read();
      bool onTeam(const std::string &lastName); 
      Player* getPlayer(const std::string &lastName); 
      friend std::ostream &operator<<(std::ostream &out, const Team &tm);
      Player releasePlayer(const std::string &lastName); 
      unsigned int lowestAvailableNumber(); 
      bool numAvailable(unsigned int preferred); 
};

#endif // _TEAM_H
