#include "ability.h"

//author: Joshua Scalia, all code included is my own
// 
//implementation for the ability class
//constructors
//default
ability::ability()
{
    canAttack = true;
    canHeal = true;
    atMod = 0;
    healMod = 0;
}
//normal constructor
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
void ability::attackPart(character* charTarg, part *target, int damage)
{
    //calculate damage dealt based on targets defense
    int damageDealt = damage + atMod - charTarg->getDefense();
    //double check that the damage isn't negative
    if (damageDealt < 0)
    {
        damageDealt = 0;
    }
    //execute the damage
    target->subFromHealth(damageDealt);
    charTarg->subFromHealth(damageDealt);
    //check whether or not player is alive
    charTarg->autoSetAlive();
    //output what happened after that action
    if (charTarg->getAlive() == true && target->getAlive() == true)
    {
        std::cout << charTarg->getName() << "'s " << target->getName() << " was dealt " << damageDealt << " damage." << std::endl;
    }
    else if (charTarg->getAlive() == true && target->getAlive() != true)
    {
        std::cout << charTarg->getName() << "'s " << target->getName() << " was dealt " << damageDealt << " damage and " << target->getName() << " was destroyed!" << std::endl;
    }
    else if (charTarg->getAlive() != true)
    {
        std::cout << charTarg->getName() << "'s " << target->getName() << " was dealt " << damageDealt << " damage and " << charTarg->getName() << " was killed!" << std::endl;
        std::cout << "You won! Congratulations" << std::endl;
        exit(1);
    }
}
//function to heal a given player's chosen part
void ability::healPart(character* charTarg, part* target, int healing)
{
    //calculate total healing
    int healingDone = healing + healMod;
    //make sure the part still exists then heal and output what happened
    if(target->getAlive() == true)
    {
        target->addToHealth(healingDone);
        charTarg->addToHealth(healingDone);
        std::cout << charTarg->getName() << "'s " << target->getName() << " was healed by " << healingDone << " hp." << std::endl;
    }
    //tell the player they can't heal a nonexistent part
    else
    {
        std::cout << "Cannot heal a part that is no longer there" << std::endl;
    }

}
//this function prints out what the ability can do
std::string ability::printAbility()
{
    if(canAttack == true && canHeal == true)
    {
        return "this part can both attack and heal.";
    }
    else if(canAttack == true && canHeal != true)
    {
        return "this part can only attack.";
    }
    else if(canAttack != true && canHeal == true)
    {
        return "this part can only heal.";
    }
    else
    {
        return "this part can neither heal nor attack.";
    }
}
//return whether or not they can attack
bool ability::getCanAttack()
{
    return canAttack;
}
//return whether or not they can heal
bool ability::getCanHeal()
{
    return canHeal;
}