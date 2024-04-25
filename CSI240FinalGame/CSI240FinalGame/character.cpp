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
        std::cout << charTarg.getName() << "'s " << target.getName() << " was dealt " << damageDealt << " damage." << endl;
    }
    else if (charTarg.getAlive() == true && target.getAlive() != true)
    {
        std::cout << charTarg.getName() << "'s " << target.getName() << " was dealt " << damageDealt << " damage and " << target.getName() << " was destroyed!" << endl;
    }
    else if (charTarg.getAlive() != true)
    {
        std::cout << charTarg.getName() << "'s " << target.getName() << " was dealt " << damageDealt << " damage and " << charTarg.getName() << " was killed!" << endl;
        std::cout << "You won! Congratulations" << endl;
        exit(1);
    }
}
ability::healPart(character charTarg, part target, int healing)
{
    int healingDone = healing + healMod;
    if(target.isAlive == true)
    {
        target.addToHealth(healingDone);
        charTarg.addToHealth(healingDone);
        std::count << charTarg.getName() << "'s " << target.getName() << " was healed by " << healingDone << " hp." << endl;
    }
    else
    {
        std::cout << "Cannot heal a part that is no longer there" << endl;
    }

}
ability::printAbility()
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
ability::getCanAttack()
{
    return canAttack;
}
ability::getCanHeal()
{
    return canHeal;
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
part::printStatus()
{
    if(isAlive != true)
    {
        std::cout << name << " is destroyed";
    }
    else
    {
        std::cout << name << " has " << curHealth << "/" << maxHealth << " left" << endl;
    }
}
//implementation of classes derived from part, polymorphism is present
	arm::arm() : part()
    {
        capabilities = new ability();
    }
	arm::arm(int health, std::string name, ability capabilities) : part(health, name)
    {
        this->capabilities = capabilities;
    }
	arm::printInfo()
    {
        std::cout << "This is an arm with " << this->curHealth << " hp, and " << capabilities.printAbility() << endl;
    }

	chest::chest() : part()
    {
        
    }
	chest(int health, std::string name) : part(health, name)
    {
        
    }
	chest::printInfo()
    {
        std::cout << "This is the torso with " << this->curHealth << " hp, and it can't do anything" << endl;
    }

	head::head() : part()
    {

    }
	head::head(int, std::string) : part(int, std::string)
    {

    }
	head::printInfo()
    {
        std::cout << "This is the head with " << this->curHealth << " hp, and it can't do anything" << endl;
    }

	leg::leg() : part()
    {
        capabilities = new ability();
    }
	leg::leg(int health, std::string name, ability capabilities) : part(health, name)
    {
        this->capabilities = capabilities;
    }
	leg::printInfo()
    {
        std::cout << "This is a leg with " << this->curHealth << " hp, and" << capabilities.printAbility() << endl;
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
	character::character(int maxHealth, int damage, int defense, part armOne, part armTwo, part legOne, part legTwo, part torso, part head, std::string name)
    {
        this->maxHealth = maxHealth;
        curHealth = maxHealth;
        this->damage = damage;
        this->defense = defense;
        isAlive = true;
        isGuarding = false;
        this->armOne = armOne;
        this->armTwo = armTwo;
        this->legOne = legOne;
        this->legTwo = legTwo;
        this->torso = torso;
        this->head = head;
        this->name = name;
    }
    //deconstructor
    character::~character() 
    {
        delete armOne;
        delete armTwo;
        delete legOne;
        delete legTwo;
        delete torso;
        delete head;
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
    //functions for damage and defense values
    character::getDamage()
    {
        return damage;
    }
    character::getDefense()
    {
        return defense;
    }
    character::setDamage(int damage)
    {
        this->damage = damage;
    }
    character::setDefense(int defense)
    {
        this->defense = defense;
    }
    //boolean functions for isAlive and isGuarding
    character::getAlive()
    {
        return isAlive;
    }
    character::getGuarding()
    {
        return isGuarding;
    }
    character::setAlive(bool isAlive)
    {
        this->isAlive = isAlive;
    }
    character::setGuarding(bool isGuarding)
    {
        this->isGuarding = isGuarding;
    }
    character::autoSetAlive()
    {
        if (head.getAlive() != true)
        {
            isAlive = false;
        }
        else if (armOne.getAlive() != true && armTwo.getAlive() != true && legOne.getAlive() != true && legTwo.getAlive() != true)
        {
            isAlive = false;
        }
        else if (torso.getAlive() != true)
        {
            isAlive = false;
        }
    }
    //functions for the character's name
    character::getName()
    {
        return name;
    }
    character::setName(std::string name)
    {
        this->name = name;
    }
    character::printFullInfo()
    {
        std::cout << "Character: " << this->name << "'s current status is: " << endl;
        if(isAlive != true)
        {
            std::cout << "Dead, game over" << endl;
            exit(1);
        }
        else
        {
            cout << "Health: " << curHealth << "/" << maxHealth << endl << "Limb status: " << endl;
            armOne.printStatus();
            armTwo.printStatus();
            legOne.printStatus();
            legTwo.printStatus();
            torso.printStatus();
            head.printStatus();
        }
    }
    character::getAttackAbility()
    {
        if(armOne.getAlive() == true && armOne.getCanAttack() == true)
        {
            return armOne;
        }
        else if(armTwo.getAlive() == true && armTwo.getCanAttack() == true)
        {
            return armTwo;
        }
        else if(legOne.getAlive() == true && legOne.getCanAttack() == true)
        {
            return legOne;
        }
        else if(legTwo.getAlive() == true && legTwo.getCanAttack() == true)
        {
            return legTwo;
        }
        else
        {
            return NULL;
        }
    }
    character::getHealAbility()
    {
        if(armOne.getAlive() == true && armOne.getCanHeal() == true)
        {
            return armOne;
        }
        else if(armTwo.getAlive() == true && armTwo.getCanHeal() == true)
        {
            return armTwo;
        }
        else if(legOne.getAlive() == true && legOne.getCanHeal() == true)
        {
            return legOne;
        }
        else if(legTwo.getAlive() == true && legTwo.getCanHeal() == true)
        {
            return legTwo;
        }
        else
        {
            return NULL;
        }
    }
    character:getPart(int index)
    {
        switch(index)
        {
            case(1):
            return armOne;
            break;

            case(2):
            return armTwo;
            break;

            case(3):
            return legOne;
            break;

            case(4):
            return legTwo;
            break;

            case(5):
            return torso;
            break;

            case(6):
            return head;
            break;

            default:
            return NULL;
            break;
        }
    }