
#ifndef ABILITY_H_
#define ABILITY_H_
#include <string>
#include <memory>

class Minion;
class Player;

class Ability {
	std::string description;
public:
	Ability(std::string description);
	virtual ~Ability() = default;
	std::string getDescription();
	virtual bool usedOn(Player &player) = 0;
	virtual bool usedOn(Player &player, int pos) = 0;
};



#endif
