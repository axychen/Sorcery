#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "player.h"
#include "cardtype.h"
#include "minion.h"
using namespace std;


bool overwrite(ifstream &ifs, istream &is, string &s) {
	if (!getline(ifs,s)) {
		if (!getline(is,s)) {
			return false;
		}
	}
 	return true;
}

vector<string> loadDeck(string file) {
	ifstream ifs{file};
	string s;
	vector<string> vec;
	while (getline(ifs,s)) {
		vec.emplace_back(s);
	}
	return vec;
}

void updateCurr(Player *&curr, Player *player1, Player * player2) {
	if (curr == player1) {
		curr = player2;
	} else {
		curr = player1;
	}
}

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  ifstream init;

  for (int i = 1; i < argc - 1; i++) {
	  istringstream iss(argv[i]);
	  string argument;
	  iss >> argument;
	  if (argument == "-deck1") {

	  } else if (argument == "-deck2") {

	  } else if (argument == "-init") {
		  istringstream iss(argv[i+1]);
		  iss >> argument;
		  init.open(argument,ifstream::in);
		  i++;
	  } else if (argument == "-testing") {

	  } else if (argument == "-graphics") {

	  }
  }


  try {
	  Cardtype ct{};
	  string p1;
	  string p2;
	  overwrite(init,cin,p1);
	  overwrite(init,cin,p2);
	  Player player1{p1, loadDeck("default.deck"), false};
	  Player player2{p2, loadDeck("default.deck"), false};
/*
	  cout << player1.getName() << endl;
	  	  for (string &s : player1.getDeck()) {
	  		  cout << s << endl;
	  	  }
	  	  cout << player2.getName() << endl;
	  	  for (string &s : player2.getDeck()) {
	  	  		  cout << s << endl;
	  	  }
*/
	  Player *curr = &player1;

	  while (overwrite(init,cin,cmd)) {
		  cout << cmd << endl;
		  istringstream line(cmd);
		  string next;
		  line >> next;
		  if (next == "help") {

		  } else if (next == "end") {
			  curr->endTurn();
			  updateCurr(curr,&player1,&player2);
			  curr->startTurn();
		  } else if (next == "quit") {

		  } else if (next == "draw") {

		  } else if (next == "discard") {

		  } else if (next == "attack") {
			  int attacker, victim;
			  if (line >> attacker) {
				  if (line >> victim) {
					  //attack opposing minion
				  } else {
					  std::cout << "reach 1" << std::endl;
					  if (curr == &player1) {
						  curr->attack(attacker-1, player2);
					      std::cout << "reach 2" << std::endl;
					  }
					  else curr->attack(attacker-1, player1);
				  }
			  }
		  } else if (next == "play") {
			  std::cout << "reach play in main" << std::endl;
			  int mine, player, yours;
			  if (line >> mine) {
				  if ((line >> player) && (line >> yours)){

				  } else {
					  std::string name = curr->getHand().at(mine-1);
					  std::pair<Type,int> p = ct.construct(name);
					  if (p.first == Type::Minion) {
						  curr->play(ct.minions.at(p.second));
					  } else if (p.first == Type::Spell) {
					  } else if (p.first == Type::Enchantment) {
					  } else if (p.first == Type::Ritual) {
					  } else if (p.first == Type::NA) {
					  }

					  curr->removeHand(mine-1);
				  }
			  }
		  } else if (next == "use") {

		  } else if (next == "describe") {

		  } else if (next == "hand") {

		  } else if (next == "board") {

		  }
	  }
	  cout << "loop ends" << endl;
  }
  catch (ios::failure &) {cout << "got here" << endl;}
}