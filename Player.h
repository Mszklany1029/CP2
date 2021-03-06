#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>

class Player {
   private:
      std::string firstName;
      std::string lastName;
      unsigned int jerseyNumber;
      std::string team_nickname;
      unsigned int preferred;
      std::string* career; 
      unsigned int elements; 
      unsigned int size; 
      unsigned int recent; 
     

   public:
      Player();
      Player(const std::string &first, const std::string &last,
             unsigned int jersey, const std::string &nickname);

      Player(const Player& rhs);
      Player& operator=(const Player& rhs);
      ~Player(); 
      
      std::string getTeam() {return team_nickname;};
      bool read();
      void show() const;
      std::string getLastName(){return lastName;};
      unsigned int getJerseyNum() {return jerseyNumber;}; 
      unsigned int getPreferred() {return preferred;}; 
      void setJerseyNum(unsigned int num){jerseyNumber = num;};
      bool record(const std::string &teamName, unsigned int num); 
      void showCareer(); 
      bool isEmpty(); 
      void setRecent(unsigned int recNum){recent = recNum;}; 
      unsigned int getRecent(){return recent;}; 
      
   
};

#endif // _PLAYER_H
