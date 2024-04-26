#pragma once
#include "character.h"
//author: Joshua Scalia, all code included is my own

//using forward declarations so classes can work
class part;

class character;

class arm;

class leg;

class ability
{
protected:
	//booleans to check whether or not the respective part can do certain actions
	bool canAttack, canHeal;
	//values to modify the actions so some parts can be better at doing things than others ex. staff arm better at healing than sword arm, but worse at defense
	int atMod, healMod;
public:
	//default constructor
	ability();
	//constructor
	ability(bool, bool, int, int);
	//deconstructor
	~ability();
	//functions to interact with parts, through damage and support effects
	void attackPart(character*, part*, int);
	void healPart(character*, part*, int);
	//information displayer
	std::string printAbility();
	//functions to get booleans
	bool getCanAttack();
	bool getCanHeal();
	//FRIENDSHIP : ), classes that are friends of this class
	friend class part;
	friend class character;
	friend class arm;
	friend class leg;
};