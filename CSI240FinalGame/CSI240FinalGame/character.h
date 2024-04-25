#pragma once
#include <string>

class ability
{
protected:
	//booleans to check whether or not the respective part can do certain actions
	bool canAttack, canHeal;
	//values to modify the actions so some parts can be better at doing things than others ex. staff arm better at healing than sword arm, but worse at defense
	int atMod, healMod;
public:
	//functions to interact with parts, through damage and support effects
	void attackPart(character, part, int);
	void healPart(character, part, int);
	//default constructor
	ability();
	//constructor
	ability(bool, bool, int, int);
	//deconstructor
	~ability();
	//information displayer
	std::string printAbility();
	//functions to get booleans
	bool getCanAttack();
	bool getCanHeal();
	//FRIENDSHIP : )
	friend class part;
	friend class character;
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
	friend class character;
	friend class ability;
};

class arm : public part
{
protected:
	ability capabilities;
public:
	arm() : part();
	arm(int, std::string, ability) : part(int, std::string);
	void printInfo();
};

class chest : public part
{
public:
	chest() : part();
	chest(int, std::string) : part(int, std::string);
	void printInfo();
};

class head : public part
{
public:
	head() : part();
	head(int, std::string) : part(int, std::string);
	void printInfo();
};

class leg : public part
{
protected:
	ability capabilities;
public:
	leg() : part();
	leg(int, std::string, ability) : part(int, std::string);
	void printInfo();
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
	part getAttackAbility();
	//same as above but with healing
	part getHealAbility();
	//part getter for damage purposes
	part getPart(int);
};