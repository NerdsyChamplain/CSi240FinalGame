#include "character.h"
#include "ability.h"

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
void part::setCurHealth(int health)
{
    curHealth = health;
    if(health > maxHealth)
    {
        maxHealth = health;
    }
}
//two getter functions
int part::getCurHealth()
{
    return curHealth;
}
int part::getMaxhealth()
{
    return maxHealth;
}
//subtract the input number from health and set isAlive to false if health falls below zero
void part::subFromHealth(int damage)
{
    curHealth -= damage;
    if(curHealth <= 0)
    {
        isAlive = false;
    }
}
//add health to curHealth equal to the input value, if curHealth becomes larger than maxHealth reset curHealth to maxHealth's value
void part::addToHealth(int healing)
{
    curHealth += healing;
    if(curHealth > maxHealth)
    {
        curHealth = maxHealth;
    }
}
//name getter
std::string part::getName()
{
    return name;
}
//functions for the boolean isAlive
void part::setAlive(bool isAlive)
{
    this->isAlive = isAlive;
}
bool part::getAlive()
{
    return isAlive;
}
void part::printStatus()
{
    if(isAlive != true)
    {
        std::cout << name << " is destroyed" << std::endl;
    }
    else
    {
        std::cout << name << " has " << curHealth << "/" << maxHealth << " left" << std::endl;
    }
}
//implementation of classes derived from part, polymorphism is present
	arm::arm() : part()
    {
        capabilities = ability();
    }
	arm::arm(int health, std::string name, ability capabilities) : part(health, name)
    {
        this->capabilities = capabilities;
    }
	void arm::printInfo()
    {
        std::cout << "This is an arm with " << this->curHealth << " hp, and " << capabilities.printAbility() << std::endl;
    }
    ability arm::getAbilities()
    {
        return capabilities;
    }

	chest::chest() : part()
    {
        
    }
	chest::chest(int health, std::string name) : part(health, name)
    {
        
    }
	void chest::printInfo()
    {
        std::cout << "This is the torso with " << this->curHealth << " hp, and it can't do anything" << std::endl;
    }

	head::head() : part()
    {

    }
	head::head(int health, std::string name) : part(health, name)
    {

    }
	void head::printInfo()
    {
        std::cout << "This is the head with " << this->curHealth << " hp, and it can't do anything" << std::endl;
    }

	leg::leg() : part()
    {
        capabilities = ability();
    }
	leg::leg(int health, std::string name, ability capabilities) : part(health, name)
    {
        this->capabilities = capabilities;
    }
	void leg::printInfo()
    {
        std::cout << "This is a leg with " << this->curHealth << " hp, and" << capabilities.printAbility() << std::endl;
    }
    ability leg::getAbilities()
    {
        return capabilities;
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
        delete &armOne;
        delete &armTwo;
        delete &legOne;
        delete &legTwo;
        delete &torso;
        delete &head;
    }
	//functions for health
	int character::getMaxhealth()
    {
        return maxHealth;
    }
	int character::getCurHealth()
    {
        return curHealth;
    }
	void character::subFromHealth(int damageTaken)
    {
        curHealth -= damageTaken;
        if(curHealth <= 0)
        {
            isAlive = false;
        }
    }
	void character::addToHealth(int healing)
    {
        curHealth += healing;
        if(curHealth > maxHealth)
        {
            curHealth = maxHealth;
        }
    }
    //functions for damage and defense values
    int character::getDamage()
    {
        return damage;
    }
    int character::getDefense()
    {
        return defense;
    }
    void character::setDamage(int damage)
    {
        this->damage = damage;
    }
    void character::setDefense(int defense)
    {
        this->defense = defense;
    }
    //boolean functions for isAlive and isGuarding
    bool character::getAlive()
    {
        return isAlive;
    }
    bool character::getGuarding()
    {
        return isGuarding;
    }
    void character::setAlive(bool isAlive)
    {
        this->isAlive = isAlive;
    }
    void character::setGuarding(bool isGuarding)
    {
        this->isGuarding = isGuarding;
    }
    void character::autoSetAlive()
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
    std::string character::getName()
    {
        return name;
    }
    void character::setName(std::string name)
    {
        this->name = name;
    }
    void character::printFullInfo()
    {
        std::cout << "Character: " << this->name << "'s current status is: " << std::endl;
        if(isAlive != true)
        {
            std::cout << "Dead, game over" << std::endl;
            exit(1);
        }
        else
        {
            std::cout << "Health: " << curHealth << "/" << maxHealth << std::endl << "Limb status: " << std::endl;
            armOne.printStatus();
            armTwo.printStatus();
            legOne.printStatus();
            legTwo.printStatus();
            torso.printStatus();
            head.printStatus();
        }
    }
    part character::getAttackAbility()
    {
        if(armOne.getAlive() == true && armOne.getAbilities().getCanAttack() == true)
        {
            return armOne;
        }
        else if(armTwo.getAlive() == true && armTwo.getAbilities().getCanAttack() == true)
        {
            return armTwo;
        }
        else if(legOne.getAlive() == true && legOne.getAbilities().getCanAttack() == true)
        {
            return legOne;
        }
        else if(legTwo.getAlive() == true && legTwo.getAbilities().getCanAttack() == true)
        {
            return legTwo;
        }
        /*else
        {
            return NULL;
        }*/
    }
    part character::getHealAbility()
    {
        if(armOne.getAlive() == true && armOne.getAbilities().getCanHeal() == true)
        {
            return armOne;
        }
        else if(armTwo.getAlive() == true && armTwo.getAbilities().getCanHeal() == true)
        {
            return armTwo;
        }
        else if(legOne.getAlive() == true && legOne.getAbilities().getCanHeal() == true)
        {
            return legOne;
        }
        else if(legTwo.getAlive() == true && legTwo.getAbilities().getCanHeal() == true)
        {
            return legTwo;
        }
       /* else
        {
            return NULL;
        }*/
    }
    part character::getPart(int index)
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
            //return NULL;
            break;
        }
    }