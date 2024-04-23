#include "character.h"

//implementation for the ability class
//constructors
ability::ability()
{
    canAttack = false;
    canHeal = false;
    atMod = 0;
    healMod = 0;
}
ability::ability(bool canAttack, bool canHeal, int atMod, int healMod)
{
    this->canAttack = canAttack;
    this->canHeal = canHeal;
    this->atMod = atMod;
    this->healMod = healMod;
}
//deconstructor
ability::~ability(){}
//functions for ability to interact with the parts 
ability::attackPart(character charTarg, part target, int damage)
{
    target.subFromHealth(damage + atMod);
    charTarg.subFromHealth(damage + atMod);
}
ability::heal(character charTarg, part target, int healing)
{
    target.addToHealth(healing + healMod);
    charTarg.addToHealth(healing + healMod);
}


//implementation for the parts class
//constructors
part::part()
{
    maxHealth = 1;
    curHealth = maxHealth;
    isAlive = true;
    name = "";
}
part::part(int maxHealth, std::string name)
{
    this->maxHealth = maxHealth;
    curHealth = this->maxHealth;
    isAlive = true;
    this->name = name;
}
//deconstructor
part::~part(){}
//health based functions for the part
//sets the current health and if the number being set is higher than max health it will also raise the max to the given value
part::setCurHealth(int health)
{
    curHealth = health;
    if(health > maxHealth)
    {
        maxHealth = health;
    }
}
//two getter functions
part::getCurHealth()
{
    return curHealth;
}
part::getMaxhealth()
{
    return maxHealth;
}
//subtract the input number from health and set isAlive to false if health falls below zero
part::subFromHealth(int damage)
{
    curHealth -= damage;
    if(curHealth <= 0)
    {
        isAlive = false;
    }
}
//add health to curHealth equal to the input value, if curHealth becomes larger than maxHealth reset curHealth to maxHealth's value
part::addToHealth(int healing)
{
    curHealth += healing;
    if(curHealth > maxHealth)
    {
        curHealth = maxHealth;
    }
}
//name getter
part::getName()
{
    return name;
}
//functions for the boolean isAlive
part::setAlive(bool isAlive)
{
    this->isAlive = isAlive;
}
part::getAlive()
{
    return isAlive;
}


//character class implementation
//default constructor
	character::character()
    {
        maxHealth = 1;
        curHealth = maxHealth;
        damage = 1;
        defense = 1;
        isAlive = true;
        isGuarding = false;
    }
	//constructor
	character::character(int maxHealth, int damage, int defense)
    {
        this->maxHealth = maxHealth;
        curHealth = maxHealth;
        this->damage = damage;
        this->defense = defense;
        isAlive = true;
        isGuarding = false;
    }
	//functions for health
	character::getMaxhealth()
    {
        return maxHealth;
    }
	character::getCurHealth()
    {
        return curHealth;
    }
	character::subFromHealth(int damageTaken)
    {
        curHealth -= damageTaken;
        if(curHealth <= 0)
        {
            isAlive = false;
        }
    }
	character::addToHealth(int healing)
    {
        curHealth += healing;
        if(curHealth > maxHealth)
        {
            curHealth = maxHealth;
        }
    }