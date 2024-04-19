
#pragma once
#include <string>

class ability
{
protected:
	//booleans to check whether or not the respective part can do certain actions
	bool canAttack, canDefend, canHeal;
	//values to modify the actions so some parts can be better at doing things than others ex. staff arm better at healing than sword arm, but worse at defense
	int defMod, atMod, healMod;
public:
	//functions to interact with parts, through damage and support effects
	void attackPart(part, int);
	void defend(part, int);
	void heal(part, int);
	//default constructor
	ability();
	//constructor
	ability(bool, bool, bool, int, int, int);
	//deconstructor
	~ability();
};


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
	part(int, int, std::string);
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
	void setAlive();
	bool getAlive();
};

class arm : part
{
protected:
	ability capabilities;
public:


};

class chest : part
{
protected:
	ability capabilities;
};

class head : part
{
protected:
	ability capabilities;
};

class leg : part
{
protected:
	ability capabilities;
};

class character
{
protected:
	//ints for the overall health, damage, and defense of the character. Seperate from the parts' data
	int maxHealth, damage, defense;
	//bool that will control whether or not the character is still alive
	bool isAlive;
public:
	//default constructor
	character();
	//constructor
	character(int, int, int);
};