#pragma once
#include <string>

class Ability
{
public:
	virtual void activateAbility() = 0;
	virtual void learnAbility() = 0;

protected: 
	int AbilityType;
	int AbilityPower;
	int AbilityChargeTime;
	std::string AbilityRestrictions;
};
