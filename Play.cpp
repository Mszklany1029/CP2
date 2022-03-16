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
  // string command;  
   Team team;
   Player player;
   League league;
   string line;
   int int_param;
   Team freeAgents("", "Free Agents"); 
   //int try_this; 
//hi
  //freeAgents = Team("", "Free Agents");
 // league.addTeam(freeAgents); 
   while (1) {
      //freeAgents = Team("", "Free Agents");
      //league.addTeam(freeAgents); 


      std::string teamName;
      cout << endl << "Enter a command: " << endl;
      cout << "Choose from [\"Team\" \"Player\" \"League\" \"Roster\" \"Quit\"]" << endl; 
      cout << ": "; 

      std::getline(std::cin, line);
      Parser command(line); 

      if (command.getOperation()  == "Team"){
		Team team = Team(command.getArg1(), command.getArg2());
		
            if (!league.teamExists(team.getNickname())){
               league.addTeam(team);
	    	do_AddTeam(command.getArg1(), command.getArg2()); 
	    }
	    	
            else 
	       cout << "Duplicate team nickname " << team.getNickname() <<       
		       " not added" << std::endl;;
        // }
	// else
          //  cout << "Team didn't read properly" << std::endl;
      }
      else if (command.getOperation() == "Player") {
     
          
		if (Parser::isInteger(command.getArg3())){
			 int_param = stoi(command.getArg3());
           Player player = Player(command.getArg1(), command.getArg2(), int_param, command.getArg4());
           cout << player.getLastName() << ", " << player.getJerseyNum() << endl;

            if(command.getArg4() == ""){
               freeAgents.addPlayer(player);

            }else if(!league.addPlayer(player, player.getTeam())){
		         cout << "Could not add the player to team" << player.getTeam() << std::endl;;
              
             }else{
                 do_AddPlayer(command.getArg1(), command.getArg2(), int_param, command.getArg4() );
                 
                  Player* temp = league.getTeam(command.getArg4())->getPlayer(command.getArg2()); 
                 // temp->record(command.getArg4(), temp->getJerseyNum());



                 //player.record(command.getArg4(), int_param); 
                 //FIX HERE

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
               //league.showPlayers("Free Agents");
               freeAgents.showPlayers();
               do_GetRoster("Free Agents");
            }else{

        //    cout << "Team: ";
	   // std::getline(std::cin, teamName);
            league.showPlayers(teamName);
            do_GetRoster(command.getArg1()); 
            }
      }
      else if (command.getOperation() == "Quit") {
         break;
      }else if(command.getOperation() == "Release"){
         
            if(league.getTeam(command.getArg2()) != nullptr){
                  Team *temp = league.getTeam(command.getArg2());
                  //NULLPTR ERROR HERE??
                  freeAgents.addPlayer(temp->releasePlayer(command.getArg1()));
                  
                  do_ReleasePlayer(command.getArg1(), command.getArg2());


            }else{
                cout << "Error: team " << command.getArg2() << " does not exist." << endl;
            }

      }else if(command.getOperation() == "Sign"){
            
         if(league.getTeam(command.getArg2()) != nullptr){
            if(!freeAgents.onTeam(command.getArg1())){
               cout<< "Error: Player " << command.getArg1() << " is not a free agent" << endl;
            }else{
               
            Team *temp = league.getTeam(command.getArg2()); 
            
            //if(!temp->numAvailable(freeAgents.getPlayer(command.getArg1())->getPreferred())){
              //    freeAgents.getPlayer(command.getArg1())->setJerseyNum(temp->lowestAvailableNumber());
            //}

            temp->addPlayer(freeAgents.releasePlayer(command.getArg1()));
            unsigned int hold = temp->getPlayer(command.getArg1())->getJerseyNum();
            temp->getPlayer(command.getArg1())->record(command.getArg2(), hold); 
            //FIX HERE^^^

            }

         }else{
            cout << "Error: team " << command.getArg2() << " does not exist" << endl; 
         }

         
       
   }else if(command.getOperation() == "Career"){ 
         //cout<< "HOLD" << endl; 
            
            if(freeAgents.onTeam(command.getArg1())){
               freeAgents.getPlayer(command.getArg1())->showCareer(); 
            }else{
               league.searchTeams(command.getArg1())->showCareer(); 
               
            }

         
         
         /*if(freeAgents.onTeam(command.getArg1())){
            freeAgents.getPlayer(command.getArg1()).showCareer(); 
            
               
            
         }else{
            
           // league.searchTeams(command.getArg1()).showCareer(); 
         }*/
         


   }else{
         cout << "Command " << command.getOperation() << " not recognized. Please try again." << endl; 
      }
}
}
