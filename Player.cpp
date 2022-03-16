#include "Player.h"
#include <iostream>
#include <sstream>

using namespace std;

Player::Player() {
   firstName = "";
   lastName = "";
   jerseyNumber = -1;
  // is_active = false;
   team_nickname = "";
   preferred = -1; 
   size = 1; 
   elements = 0;
   career = new string[size]; 
   

   
}

Player::Player(const std::string &first, const std::string &last,
		unsigned int jersey, /*bool active,*/ const std::string &nickname) {
   firstName = first;
   lastName = last;
   jerseyNumber = jersey;
  // is_active = active;
   team_nickname = nickname;
   preferred = jersey;  
   size = 1; 
   elements = 0; 
   career = new string[size];
}

Player::Player(const Player& rhs){
   firstName = rhs.firstName; 
   lastName = rhs.lastName; 
   jerseyNumber = rhs.jerseyNumber; 
   team_nickname = rhs.team_nickname; 
   preferred = rhs.preferred; 
   size = rhs.size; 
   elements = rhs.elements; 
   career = new std::string[size]; 
   for(unsigned int i=0; i < elements; i++)
         career[i] = rhs.career[i]; 
} 

Player& Player:: operator=(const Player& rhs){
   if(this != &rhs){
         delete[] career; 
         size = rhs.size; 
         elements = rhs.elements; 
         career = new std::string[size];

         for(unsigned int i = 0; i < elements; i++){
               career[i] = rhs.career[i];
         } 
   }
   return *this;

}


bool Player::read() {
   std::string line;
   std::cout << "       First Name: "; 
   std::getline(cin, firstName);
   std::cout << "        Last Name: "; 
   std::getline(cin, lastName);
   std::cout << "           Number: "; 
   std::getline(cin, line);

   std::stringstream is;	       
   is.str(line);
   is >> jerseyNumber; 

   /*std::cout << "     Active (y/n): "; 
   std::getline(cin, line);
   is_active = false;
   if (!line.empty() && line[0] == 'y')
       is_active = true;
       */
         
   std::cout << "             Team: "; 
   std::getline(cin, team_nickname);

   return true; 
}

void Player::show() const {
   std::cout << lastName << ", " << firstName << " (#" << jerseyNumber << ") "
	     /*<< " [" << (!is_active ? "not " : "") << "active]" */ << std::endl;
}

bool Player::record(const std::string &teamName, unsigned int num){
   std::string t = std::to_string(num); 
   std::string recording = teamName + "(#" + t + ")";
   //cout<< "CHEck" << endl; 

   if(size == elements){
      std::string* tempArray = new std::string[size + 1]; 
      size++; 
      for(unsigned int i = 0; i < elements; i++){
         tempArray[i] = career[i];
      }
      delete[] career; 
      career = tempArray; 
   }
   career[elements] = recording;
   elements++; 
   return true;
}

void Player::showCareer(){
   cout << "dO SOMETHING" << endl;
   for(unsigned int i = 0; i < elements; i++){
      cout << career[i] << endl; 
   }
   

}