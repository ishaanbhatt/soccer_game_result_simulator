//Randomized Result Simulator for Barcelona vs Real Madrid
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <time.h> //used in conjunction with srand() to generate random numbers
using namespace std;

int main();

int event_describer = 0; //variable declarations
int team1_goals = 0; // team1_ prefix is used for FC Barcelona
int team2_goals = 0;//team2_ prefix is used for Real Madrid CF
int team1_ontarget = 0;
int team2_ontarget = 0;
int team1_offgoal = 0;
int team2_offgoal = 0;
int team1_blocked = 0;
int team2_blocked = 0;
int team1_yellow = 0;
int team1_red = 0;
int team2_yellow = 0;
int team2_red = 0;
int team1_fouls = 0;
int team2_fouls = 0;

int events(int lowvalv, int highvalv) { //function that calculates the number of events based on a max and min value that can be changed
	int num_events = lowvalv + rand() % highvalv;
	return num_events; //return value of function
}

void shots_on_target(bool team_Barca) { //function to determine outcome of a shot, parameter is bool team_Barca
	//This parameter is used in order to differentiate the teams

	int shot_outcome = rand() % 4; //randomized integer from  to 3 used to determine shot outcome
	if (team_Barca) { //bool statement that evaluates true for FC Barcelona
		if (shot_outcome == 0) { // required if statement for goal to occur for Barca
			cout << "**Barca attempts a shot. GOOAALLLLLLLLLLLLLLLL for Barca." << endl; //description of generated event
			team1_goals++; // adding to the amount of team goals
			team1_ontarget++;
		} //adding to team stats

		else if (shot_outcome == 1) { // different outcome if 1 is the randomized integer
			cout << "**Barca attempts a shot. Madrids's goalkeeper makes an amazing save" << endl;
			team1_ontarget++; //adding to stats
			team2_blocked++;
		}
		else if (shot_outcome == 2) { //outcome for 2
			cout << "**Barca attempts a shot. The shot attempt is not on goal!" << endl;
			team1_offgoal++;
		}
		else { //else statement; outcome for 3
			cout << "**Barca attempts a shot. Amazing block by Madrid defender Sergio Ramos!" << endl;
			team2_blocked++;
		}
	}
	else { //bool statement evaluates to false for Madrid, so else statement is ran
		if (shot_outcome == 0) { //shot outcome for Madrid
			cout << "**Madrid attempts a shot. GOAL! Madrid has scored! " << endl;
			team2_goals++;
			team2_ontarget++;
		}
		else if (shot_outcome == 1) {
			cout << "**Madrid attempts a shot. Barca's Ter Stegen makes an amazing save" << endl;
			team2_ontarget++;
		}
		else if (shot_outcome == 2) {
			cout << "**Madrid attempts a shot. Madrid's shot attempt is not on goal!" << endl;
			team2_offgoal++;
		}
		else {
			cout << "**Madrid attempts a shot. Wow. Amazing defensive display by Pique leads to Madrid's shot being blocked" << endl;
			team1_blocked++;
		}
	}
}
void penalty(bool team_Barca) { //fuction used to detemine outcome of penalty, parameter is bool team_Barca
	int penalty = rand() % 3;//random integer generated to determine penalty outcome
	if (team_Barca) {//evaluates to true for Barca
		if (penalty == 0) { // if statement leading to goal
			cout << "Messi to take the penalty for Barca. GOOAALLLLLLLLLLLLLLLL for Barca, Messi scores!.";
			team1_goals++;
			team1_ontarget++;
		}

		else if (penalty == 1) { //else if statement leading to save
			cout << "Messi to take the penalty. Madrids's goalkeeper makes an amazing save, and Messi is denied.";
			team1_ontarget++;
			team2_blocked++;
		}
		else { //else penalty is off goal and missed
			cout << "Penalty missed, and off goal!";
			team1_offgoal++;
		}
	}
	else { //else if not Barca
		if (penalty == 0) { //penalty outcome determined uing if and else statements
			cout << "Madrid goal. penalty is converted! ";
			team2_goals++;
			team2_ontarget++;
		}
		else if (penalty == 1) {
			cout << "Madrid's penalty is saved by Barca's goalkeeper!";
			team2_ontarget++;
		}
		else {
			cout << "Madrid attempts a shot. Madrid's shot attempt is not on goal!";
			team2_offgoal++;
		}
	}
}

void is_card_given(int event_describer, bool team_Barca) {//function used to determine punishments for fouls
	// parameters are bool team_Barca to differentiate teams, and event_describer to link the type of event generated to disciplinary ones
	//handled by this function
	int rand_card = rand() % 3;//random integer from 0 to 2
	if (team_Barca) {
		if (event_describer == 3 && rand_card == 0) { //if else statements to determine punishment or foul
			cout << "Barca receive a foul. No card given. " << endl;
			team1_fouls++;
		}
		else if (event_describer == 3 && rand_card == 1) {
			cout << "Barca has receieved a yellow card." << endl;
			team1_yellow++;
			team1_fouls++;
		}
		else if (event_describer == 3 && rand_card == 2) {
			cout << "Barca has receieved a red card after a foul was committed, and are reduced to 10 men. Big trouble" << endl;
			team1_red++;
			team1_fouls++;
		}
		else;
	}

	else {
		if (event_describer == 4 && rand_card == 0) {
			cout << "Real Madrid have commited a foul. No card given." << endl;
			team2_fouls++;
		}
		else if (event_describer == 4 && rand_card == 1) {
			cout << "Madrid have commited a foul and have receieved a yellow card." << endl;
			team2_yellow++;
			team2_fouls++;
		}
		else if (event_describer == 4 && rand_card == 2) {
			cout << "Madrid has receieved a red card after a foul was committed, and are reduced to 10 men. Big trouble" << endl;
			team2_red++;
			team2_fouls++;
		}
		else;
	}
}
int main() { //main function
	srand(time(NULL)); // srand() is required in order to generate a random integer

	int highvalv = 0;//defining low and high values tied to first function in order to determine number of game events
	int lowvalv = 0;
	bool team_Barca;

	const string team1 = "FC Barcelona"; //string variables for team names
	const string team2 = "Real Madrid CF";

	cout << "Welcome to a simulation of " << team1 << " vs " << team2 << endl; //welcome statement for program
	int number_of_events = events(1, 30); //setting variable equal to output of events function, by calling function

	shots_on_target(true); //calling function that determines shot outcome
	shots_on_target(false);
	is_card_given(event_describer, true); //calling function that determines the punishment for a committed foul
	is_card_given(event_describer, false);

	for (int i = 1; i <= number_of_events / 2; ++i) { //for loop that increments at least once, until it stops after reaching the number of game events

		int event_describer = rand() % 6 + 1; //random integer that determines the type of event generated

		if (event_describer == 1) { // integer 1 is linked with a shot for FB Barcelona
			shots_on_target(1); // //(1) makes bool team_Barca true, therefore this statement is associated with Barca
		}
		else if (event_describer == 2) { //integer 2 is linked with a shot for Real Madrid CF
			shots_on_target(0);
		}
		else if (event_describer == 3) {//integer 3 is linked to a free kick for Barca, and foul for Madrid
			shots_on_target(1);
			is_card_given(event_describer, true);
			cout << "**Barca gets a free kick. Barca free kick, and potential Madrid punishment outcome:: " << endl;
			//freekicks are managed within this if statement. If a free kick is generated, in order to determine the
			//outcome of the freekick, the shot_outcome function is called.
			shots_on_target(1);
			is_card_given(4, 0); // (4,0). The 4 indicates the event_describer, and 0 indicates false for bool team_Barca
			// to determine the foul punishment for Madrid, the is_card_given function is called
		}
		else if (event_describer == 4) {
			shots_on_target(0);
			is_card_given(event_describer, false);
			cout << "**Madrid gets a free kick. Madrid free kick, and potential Barca punishment outcome: " << endl;
			shots_on_target(0);
			is_card_given(3, 1);
		}
		else if (event_describer == 5) { // statement that generates Barca penalties linked with integer 5 in event_describer
			is_card_given(event_describer, true); //Madrid punishment for penalty
			cout << "**Barca have received a penalty. Penalty outcome :" << endl;
			penalty(1); // penalty function is called, with the 1 indicating bool_Barca to be true
			is_card_given(4, 0);
		}
		else { //handles penalties for Madrid
			is_card_given(event_describer, false);
			cout << "**Real Madrid have received a penalty. Penalty outcome:" << endl;
			penalty(0); //peanlty function called to determine outcome of penalty
			is_card_given(3, 1); // punishment for Barca in is_card-given function. (3,1). 1 indicates its Barca, 3 indicates
			//the event-describer which is another parameter for is_card_given function.
		}


		if (i == number_of_events / 4) { // stops the game when half the number of events plus one have occurred. HALF TIME
			cout << "============================HALF-TIME=============================" << endl;
			// output of the current score, and breakdown stats of each team.
			/*Stats have been tracked throughout program using ++, in conjunction with the global variables defined at the start
			of the program*/
			cout << "Score : FC Barcelona " << team1_goals << " - " << team2_goals << " Real Madrid CF" << endl;
			cout << "FC Barcelona: " << endl;
			cout << "Goals :" << team1_goals << endl;
			cout << "Shoots on goal :" << team1_ontarget << endl;
			cout << "Shots off goal :" << team1_offgoal << endl;
			cout << "Shots blocked : " << team1_blocked << endl;
			cout << " Fouls : " << team1_fouls << endl;
			cout << " Yellow cards : " << team1_yellow << endl;
			cout << "Red cards : " << team1_red << endl;
			cout << "--------------------------------------------" << endl;
			cout << "Real Madrid CF :" << endl;
			cout << "Goals : " << team2_goals << endl;
			cout << "Shots on goal : " << team2_ontarget << endl;
			cout << "Shots off goal : " << team2_offgoal << endl;
			cout << "Shots blocked : " << team2_blocked << endl;
			cout << "Fouls : " << team2_fouls << endl;
			cout << "Yellow cards : " << team2_yellow << endl;
			cout << "Red cards : " << team2_red << endl;
			cout << "=================================================================" << endl;
		}

	}
	cout << "============================FULL- TIME=============================" << endl;
	// FULL TIME. Final score and stats for each time.
	cout << "FINAL SCORE : FC Barcelona " << team1_goals << " - " << team2_goals << " Real Madrid CF" << endl;
	cout << "FC Barcelona: " << endl;
	cout << "Goals :" << team1_goals << endl;
	cout << "Shots on goal :" << team1_ontarget << endl;
	cout << "Shots off goal :" << team1_offgoal << endl;
	cout << "Shots blocked : " << team1_blocked << endl;
	cout << " Fouls : " << team1_fouls << endl;
	cout << " Yellow cards : " << team1_yellow << endl;
	cout << "Red cards : " << team1_red << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Real Madrid CF :" << endl;
	cout << "Goals : " << team2_goals << endl;
	cout << "Shots on goal : " << team2_ontarget << endl;
	cout << "Shots off goal : " << team2_offgoal << endl;
	cout << "Shots blocked : " << team2_blocked << endl;
	cout << "Fouls : " << team2_fouls << endl;
	cout << "Yellow cards : " << team2_yellow << endl;
	cout << "Red cards : " << team2_red << endl;
	cout << "=================================================================" << endl;

	return 0;
}//end of program
