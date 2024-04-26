#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "ability.h"


//forward declaration so classes can reference ability
class ability;

//author: Joshua Scalia, all code included is my own

class part
{
protected:
	//the health of the body part
	int maxHealth, curHealth;
	//the boolean that determines whether or not the part is still there
	bool isAlive;
	//name for the part
	std::string name;
public:
	//default constructor
	part();
	//constructor
	part(int, std::string);
	//deconstructor
	~part();
	//functions to adjust and retrieve health values
	void setCurHealth(int);
	void subFromHealth(int);
	void addToHealth(int);
	int getCurHealth();
	int getMaxhealth();
	//function to retrieve the name of the part
	std::string getName();
	//functions to adjust and retrieve the living status of the part
	void setAlive(bool);
	bool getAlive();
	//information functions, one will be virtual to be overriden
	void printStatus();
	virtual void printInfo();
	virtual ability getAbilities();
	friend class character;

};

class arm : public part
{
protected:
	ability* capabilities;
public:
	arm();
	arm(int, std::string, ability);
	void printInfo() override;
	ability getAbilities() override;
};

class chest : public part
{
public:
	chest();
	chest(int, std::string);
	void printInfo() override;
};

class head : public part
{
public:
	head();
	head(int, std::string);
	void printInfo() override;
};

class leg : public part
{
protected:
	ability* capabilities;
public:
	leg();
	leg(int, std::string, ability);
	void printInfo() override;
	ability getAbilities() override;
};

class character
{
protected:
	//ints for the overall health, damage, and defense of the character. Seperate from the parts' data
	int maxHealth, damage, defense, curHealth;
	//bool that will control whether or not the character is still alive, and whether or not the character is guarding
	bool isAlive, isGuarding;
	//the parts of the character's body
	part armOne, armTwo, legOne, legTwo, torso, head;
	//the character's name
	std::string name;
public:
	//default constructor
	character();
	//constructor
	character(int, int, int, part, part, part, part, part, part, std::string);
	//deconstructor
	~character();
	//functions for health
	int getMaxhealth();
	int getCurHealth();
	void subFromHealth(int);
	void addToHealth(int);
	//functions for damage and defense values
	int getDamage();
	int getDefense();
	void setDamage(int);
	void setDefense(int);
	//boolean functions for isAlive and isGuarding
	bool getAlive();
	bool getGuarding();
	void setAlive(bool);
	void setGuarding(bool);
	void autoSetAlive();
	//functions for the character's name
	std::string getName();
	void setName(std::string);
	//function to print the full info and status of the player
	void printFullInfo();
	//function to find whether or not the player can attack and if so which part is the first that can
	part* getAttackAbility();
	//same as above but with healing
	part* getHealAbility();
	//part getter for damage purposes
	part* getPart(int);
};