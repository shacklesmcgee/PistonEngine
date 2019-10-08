#include "SpecialAbilityComponent.h"
#include <iostream>

using namespace std;

	SpecialAbility::SpecialAbility()
	{
		AbilityType = 1;
		AbilityPower = 17;
		AbilityChargeTime = 4;
		AbilityRestrictions = "Land Only";
	};

	void SpecialAbility::activateAbility()
	{
		//Ability effects go here
		cout << "Boom!" << endl;
	};

	void SpecialAbility::learnAbility()
	{
		//attach special ability component to Actor
		cout << "Ability learned!" << endl;
	};