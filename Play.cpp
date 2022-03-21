#include "Player.h"
#include "Team.h"
#include "League.h"
#include "Parser.h"
#include <iostream>
#include <string>
using namespace std;

void do_AddPlayer(string first, string last, int jersey, string team){
	cout << "do_AddPlayer(" << first << ", " << last << ", " << jersey << ", "  << team << " )" << endl; 
}
 
void do_AddTeam(string location, string nickname){
	cout << "do_AddTeam(" << location << ", " << nickname << ")" << endl; 
}

void do_GetLeague(){
	cout << "do_GetLeague()" << endl; 
}

void do_GetRoster(string teamName){
	cout << "do_GetRoster(" << teamName << ")" << endl; 	
}

void do_ReleasePlayer(string lastName, string teamName){
   cout << "do_ReleasePlayer(" << lastName << ", " << teamName << ")" << endl; 
}

void do_SignPlayer(string lastName, string teamName){
   cout << "do_SignPlayer(" << lastName << ", " << teamName << ")" << endl;  
}

int main() {
 
   Team team;
   Player player;
   League league;
   string line;
   int int_param;
   Team freeAgents("", "Free Agents"); 
  
   while (1) {
     
      std::string teamName;
      cout << endl << "Enter a command: " << endl;
      cout << "Choose from "<< endl; 
      cout << "Team <location> <team-nickname>" << endl; 
      cout << "Player <firstname> <lastname> <number> [<team-nickname>]" << endl; 
      cout << "League" << endl; 
      cout << "Roster [<team-nickname>]" << endl;
      cout << "Release <lastname> <team-nickname>" << endl; 
      cout << "Sign <lastname> <team-nickname>" << endl; 
      cout << "Career <lastname>" << endl; 
      cout << "Quit" << endl; 
      cout << ": "; 

      std::getline(std::cin, line);
      Parser command(line); 
     

      if (command.getOperation()  == "Team"){
		   Team team = Team(command.getArg1(), command.getArg2());
         if (!league.teamExists(team.getNickname())){
            league.addTeam(team);
	    	do_AddTeam(command.getArg1(), command.getArg2()); 
	   }else 
	      cout << "Duplicate team nickname " << team.getNickname() << " not added" << std::endl;;
      }
      else if (command.getOperation() == "Player") {        
		   if (Parser::isInteger(command.getArg3())){
			   int_param = stoi(command.getArg3());
            player = Player(command.getArg1(), command.getArg2(), int_param, command.getArg4());
            cout << player.getLastName() << ", " << player.getJerseyNum() << endl;

            if(command.getArg4() == ""){
               freeAgents.addPlayer(player);
            }else{ 
               Team* adding = &league.getTeam(command.getArg4());

               if(!adding->numAvailable(int_param)){
                  player.setJerseyNum(adding->lowestAvailableNumber()); 
               } 
               
               if(!league.addPlayer(player, player.getTeam())){
                  cout << "Could not add the player to team" << player.getTeam() << std::endl;;
               }else{
                  Player *temp = league.getTeam(command.getArg4()).getPlayer(command.getArg2());
                  temp->record(command.getArg4(), temp->getJerseyNum()); 
               }
             }
         }else{
            cout << "Error: arg 3: " << command.getArg3() << " is not an integer" << endl; 
         }    
      }
      else if (command.getOperation()  == "League")
         league.showTeams();
      else if (command.getOperation() == "Roster") {
         teamName = command.getArg1(); 
         if(teamName == "" ){
            freeAgents.showPlayers();
            do_GetRoster("Free Agents");
         }else{
            league.showPlayers(teamName);
            do_GetRoster(command.getArg1()); 
         }
      }
      else if (command.getOperation() == "Quit") {
         break;   
      }else if(command.getOperation() == "Release"){
         if(league.teamExists(command.getArg2())){
            Team* temp = &league.getTeam(command.getArg2());
                
            if(temp->getPlayer(command.getArg1()) == nullptr){
               cout << "Error: Player " << command.getArg1() << " not found." << endl; 
            }else{
               freeAgents.addPlayer(temp->releasePlayer(command.getArg1()));
               Player* released = freeAgents.getPlayer(command.getArg1());
               released->setRecent(released->getJerseyNum());
               do_ReleasePlayer(command.getArg1(), command.getArg2());
            }

            }else{
                cout << "Error: team " << command.getArg2() << " does not exist." << endl;
            }
      }else if(command.getOperation() == "Sign"){
            
         if(league.teamExists(command.getArg2())){
            if(!freeAgents.onTeam(command.getArg1())){
               cout<< "Error: Player " << command.getArg1() << " is not a free agent" << endl;
            }else{
               Team* temp = &league.getTeam(command.getArg2()); 
               Player* temp_player = freeAgents.getPlayer(command.getArg1()); 
               if(!temp->numAvailable(temp_player->getPreferred())){
                  if(temp->numAvailable(temp_player->getRecent())){
                     temp_player->setJerseyNum(temp_player->getRecent()); 
                  }else{
                     temp_player->setJerseyNum(temp->lowestAvailableNumber());
                  }
            }
            
            temp->addPlayer(freeAgents.releasePlayer(command.getArg1()));
            unsigned int hold = temp->getPlayer(command.getArg1())->getJerseyNum();
            temp->getPlayer(command.getArg1())->record(command.getArg2(), hold); 
            }
         }else{
            cout << "Error: team " << command.getArg2() << " does not exist" << endl; 
         }
      }else if(command.getOperation() == "Career"){ 
               
         if(freeAgents.onTeam(command.getArg1())){
            Player &temp = *freeAgents.getPlayer(command.getArg1());    
            temp.showCareer(); 
         }else{      
            Player *temp = league.searchTeams(command.getArg1()); 
            if(temp != nullptr){
               temp->showCareer(); 
            }else{
               cout << "Error: Player " << command.getArg1() << " could not be found." << endl;
            }
         }
   }else{
      cout << "Command " << command.getOperation() << " not recognized. Please try again." << endl; 
   }
}
}
