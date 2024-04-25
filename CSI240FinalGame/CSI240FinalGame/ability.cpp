#include "ability.h"


//implementation for the ability class
//constructors
ability::ability()
{
    canAttack = true;
    canHeal = true;
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
void ability::attackPart(character charTarg, part target, int damage)
{
    int damageDealt = damage + atMod - charTarg.getDefense();
    //double check that the damage isn't negative
    if (damageDealt < 0)
    {
        damageDealt = 0;
    }
    target.subFromHealth(damageDealt);
    charTarg.subFromHealth(damageDealt);
    charTarg.autoSetAlive();
    if (charTarg.getAlive() == true && target.getAlive() == true)
    {
        std::cout << charTarg.getName() << "'s " << target.getName() << " was dealt " << damageDealt << " damage." << std::endl;
    }
    else if (charTarg.getAlive() == true && target.getAlive() != true)
    {
        std::cout << charTarg.getName() << "'s " << target.getName() << " was dealt " << damageDealt << " damage and " << target.getName() << " was destroyed!" << std::endl;
    }
    else if (charTarg.getAlive() != true)
    {
        std::cout << charTarg.getName() << "'s " << target.getName() << " was dealt " << damageDealt << " damage and " << charTarg.getName() << " was killed!" << std::endl;
        std::cout << "You won! Congratulations" << std::endl;
        exit(1);
    }
}
void ability::healPart(character charTarg, part target, int healing)
{
    int healingDone = healing + healMod;
    if(target.getAlive() == true)
    {
        target.addToHealth(healingDone);
        charTarg.addToHealth(healingDone);
        std::cout << charTarg.getName() << "'s " << target.getName() << " was healed by " << healingDone << " hp." << std::endl;
    }
    else
    {
        std::cout << "Cannot heal a part that is no longer there" << std::endl;
    }

}
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
bool ability::getCanAttack()
{
    return canAttack;
}
bool ability::getCanHeal()
{
    return canHeal;
}