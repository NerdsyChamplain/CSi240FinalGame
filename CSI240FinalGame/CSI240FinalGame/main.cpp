#include "character.h"
//#include "ability.h"
//
/*Author:         	         Joshua Scalia
Class : Csi240 - 03
Assignment : CSI-240 Final Project
	Date Assigned : Start of year
Due Date :
4/23/2024 11:59pm
Description:
My final project for CSI-240, it is a turn based combat game that shows everything we learned this semester

Certification of Authenticity :
I certify that this is entirely my own work, except where I have given fully - documented references 
to the work of others.I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, 
for the purpose of assessing this assignment :
	-Reproduce this assignment and provide a copy to another member of academic staff; and /or
	-Communicate a copy of this assignment to a plagiarism checking service(which may then retain 
	a copy of this assignment on its database for the purpose of future plagiarism checking)
*/
//a menu that will operate the playable part of the program and return a value that shows who won the game
int menu(character* charOne, character* charTwo)
{
	//code for the output system, outputs a log of the actions chosen
	const std::string OUTPUT_FILE_NAME = "output.txt";
	std::ofstream logOut;
	logOut.open(OUTPUT_FILE_NAME, std::ios::out);
	//check if the .txt file failed to open and if so throw an exception
	if (logOut.fail())
	{
		throw std::string("File has failed to open");
	}
	//base values for the damage and heal functions to use
	const int BASE_DAMAGE = 10, BASE_HEALING = 10;
	//vars for looping the menu and choosing which part to attack
	int choice = 1, targetChoice;
	do
	{
		//display menu choices
		std::cout << "1: Redisplay tutorial information" << std::endl;
		std::cout << "2: Display Player One character info and status" << std::endl;
		std::cout << "3: Display Player Two character info and status" << std::endl;
		std::cout << "4: Player One Attack" << std::endl;
		std::cout << "5: Player One Heal" << std::endl;
		std::cout << "6: Player Two Attack" << std::endl;
		std::cout << "7: Player Two Heal" << std::endl;
		std::cout << "8: Abort Program" << std::endl;
		std::cin >> choice;
		//do the switch for actions
		switch(choice)
		{
			//display tutorial information
			case(1):
			std::cout << "Welcome to my final project game for CSI 240." << std::endl << "This is a turn based combat game where two players try to defeat each other." << std::endl;
			std::cout << "Each player has three actions: Heal, Defend, and Attack." << std::endl <<"When attacking and healing you get to choose which body part you target." << std::endl;
			std::cout << "A player loses when they lose one of the following: Their max health, their head, their torso, or all of their arms and legs." << std::endl;
			std::cout << "Player one will have higher defense but lower offense while player two has higher offense but lower defense." << std::endl;
			logOut << "Redisplayed tutorial info" << std::endl;
			break;

			//print player one's information
			case(2):
			charOne->printFullInfo();
			logOut << "Player one's info was displayed" << std::endl;
			break;

			//print player two's information
			case(3):
			charTwo->printFullInfo();
			logOut << "Player two's info was displayed" << std::endl;
			break;

			//have player one attack and choose a target
			case(4):
			if(charOne->getAttackAbility() != nullptr)
			{
					std::cout << "Potential targets: " << std::endl;
			charTwo->printFullInfo();
			std::cout << "1: ArmOne \n 2: ArmTwo \n 3: LegOne \n 4: LegTwo \n 5: Chest \n 6: Head \n";
			std::cin >> targetChoice;
			//switch based on chosen target
				switch(targetChoice)
				{
					case(1):
						//check to make sure the character can even attack
					if(charOne->getAttackAbility() != NULL)
					{
						charOne->getAttackAbility()->getAbilities().attackPart(charTwo, charTwo->getPart(1), BASE_DAMAGE);
						logOut << "Player one attacked player two's " << charTwo->getPart(1)->getName() << std::endl;
					}
					break;

					case(2):
					if(charOne->getAttackAbility() != NULL)
					{
						charOne->getAttackAbility()->getAbilities().attackPart(charTwo, charTwo->getPart(2), BASE_DAMAGE);
						logOut << "Player one attacked player two's " << charTwo->getPart(2)->getName() << std::endl;
					}
					break;

					case(3):
					if(charOne->getAttackAbility() != NULL)
					{
						charOne->getAttackAbility()->getAbilities().attackPart(charTwo, charTwo->getPart(3), BASE_DAMAGE);
						logOut << "Player one attacked player two's " << charTwo->getPart(3)->getName() << std::endl;
					}
					break;

					case(4):
					if(charOne->getAttackAbility() != NULL)
					{
						charOne->getAttackAbility()->getAbilities().attackPart(charTwo, charTwo->getPart(4), BASE_DAMAGE);
						logOut << "Player one attacked player two's " << charTwo->getPart(4)->getName() << std::endl;
					}
					break;

					case(5):
					if(charOne->getAttackAbility() != NULL)
					{
						charOne->getAttackAbility()->getAbilities().attackPart(charTwo, charTwo->getPart(5), BASE_DAMAGE);
						logOut << "Player one attacked player two's " << charTwo->getPart(5)->getName() << std::endl;
					}
					break;

					case(6):
					if(charOne->getAttackAbility() != NULL)
					{
						charOne->getAttackAbility()->getAbilities().attackPart(charTwo, charTwo->getPart(6), BASE_DAMAGE);
						logOut << "Player one attacked player two's " << charTwo->getPart(6)->getName() << std::endl;
					}
					break;

					default:
					std::cout << "Not a valid target" << std::endl;
					logOut << "Player one chose an invalid target, oopsies" << std::endl;
					break;
			}
			}
			//if player can't attack execute this
			else
			{
				std::cout << "This player can no longer attack" << std::endl;
				logOut << "Player one cannot attack any more : (" << std::endl;
			}
			break;

			//player one heals and chooses part to heal
			case(5):
				//check that player can heal
			if(charOne->getHealAbility() != NULL)
			{
				std::cout << "Potential healing targets (player will heal same amount regardless of chosen part): " << std::endl;
			charOne->printFullInfo();
			std::cout << "1: ArmOne \n 2: ArmTwo \n 3: LegOne \n 4: LegTwo \n 5: Chest \n 6: Head \n";
			std::cin >> targetChoice;
			//switch based on chosen part
			switch(targetChoice)
			{
				case(1):
				charOne->getHealAbility()->getAbilities().healPart(charOne, charOne->getPart(1), BASE_HEALING);
				logOut << "Player one healed their " << charTwo->getPart(1)->getName() << std::endl;
				break;

				case(2):
				charOne->getHealAbility()->getAbilities().healPart(charOne, charOne->getPart(2), BASE_HEALING);
				logOut << "Player one healed their " << charTwo->getPart(2)->getName() << std::endl;
				break;

				case(3):
				charOne->getHealAbility()->getAbilities().healPart(charOne, charOne->getPart(3), BASE_HEALING);
				logOut << "Player one healed their " << charTwo->getPart(3)->getName() << std::endl;
				break;

				case(4):
				charOne->getHealAbility()->getAbilities().healPart(charOne, charOne->getPart(4), BASE_HEALING);
				logOut << "Player one healed their " << charTwo->getPart(4)->getName() << std::endl;
				break;

				case(5):
				charOne->getHealAbility()->getAbilities().healPart(charOne, charOne->getPart(5), BASE_HEALING);
				logOut << "Player one healed their " << charTwo->getPart(5)->getName() << std::endl;
				break;

				case(6):
				charOne->getHealAbility()->getAbilities().healPart(charOne, charOne->getPart(6), BASE_HEALING);
				logOut << "Player one healed their " << charTwo->getPart(6)->getName() << std::endl;
				break;

				default:
				std::cout << "That is not a valid target" << std::endl;
				logOut << "Player one chose an invalid target" << std::endl;
				break;
			}
			}
			//if player cannot heal show the user thus
			else
			{
				std::cout << "This player can no longer heal" << std::endl;
				logOut << "Player one can no longer heal " << std::endl;
			}
			
			break;

			//player two attacking
			case(6):
			std::cout << "Potential targets: " << std::endl;
			charOne->printFullInfo();
			std::cout << "1: ArmOne \n 2: ArmTwo \n 3: LegOne \n 4: LegTwo \n 5: Chest \n 6: Head \n";
			std::cin >> targetChoice;
			//switch based on chosen target
			switch(targetChoice)
			{
				case(1):
					//check whether or not player two can attack
				if(charTwo->getAttackAbility() != NULL)
					{
						charTwo->getAttackAbility()->getAbilities().attackPart(charOne, charOne->getPart(1), BASE_DAMAGE);
						logOut << "Player two attacked player one's " << charOne->getPart(1)->getName() << std::endl;
					}
				break;

				case(2):
				if(charTwo->getAttackAbility() != NULL)
					{
						charTwo->getAttackAbility()->getAbilities().attackPart(charOne, charOne->getPart(2), BASE_DAMAGE);
						logOut << "Player two attacked player one's " << charOne->getPart(2)->getName() << std::endl;
					}
				break;

				case(3):
				if(charTwo->getAttackAbility() != NULL)
					{
						charTwo->getAttackAbility()->getAbilities().attackPart(charOne, charOne->getPart(3), BASE_DAMAGE);
						logOut << "Player two attacked player one's " << charOne->getPart(3)->getName() << std::endl;
					}
				break;

				case(4):
				if(charTwo->getAttackAbility() != NULL)
					{
						charTwo->getAttackAbility()->getAbilities().attackPart(charOne, charOne->getPart(4), BASE_DAMAGE);
						logOut << "Player two attacked player one's " << charOne->getPart(4)->getName() << std::endl;
					}
				break;

				case(5):
				if(charTwo->getAttackAbility() != NULL)
					{
						charTwo->getAttackAbility()->getAbilities().attackPart(charOne, charOne->getPart(5), BASE_DAMAGE);
						logOut << "Player two attacked player one's " << charOne->getPart(5)->getName() << std::endl;
					}
				break;

				case(6):
				if(charTwo->getAttackAbility() != NULL)
					{
						charTwo->getAttackAbility()->getAbilities().attackPart(charOne, charOne->getPart(6), BASE_DAMAGE);
						logOut << "Player two attacked player one's " << charOne->getPart(6)->getName() << std::endl;
					}
				break;
				//show if player chose an invalid index
				default:
				std::cout << "Not a valid target" << std::endl;
				logOut << "Player twp picked an invalid target" << std::endl;

				break;
			}
			break;

			//player two healing
			case(7):
				//check that player two can still heal
			if(charTwo->getHealAbility() != NULL)
			{
				std::cout << "Potential healing targets (player will heal same amount regardless of chosen part): " << std::endl;
			charTwo->printFullInfo();
			std::cout << "1: ArmOne \n 2: ArmTwo \n 3: LegOne \n 4: LegTwo \n 5: Chest \n 6: Head \n";
			std::cin >> targetChoice;
			//switch based on chosen part to heal
			switch(targetChoice)
			{
				case(1):
				charTwo->getHealAbility()->getAbilities().healPart(charTwo, charTwo->getPart(1), BASE_HEALING);
				logOut << "Player two healed their " << charTwo->getPart(1)->getName() << std::endl;
				break;

				case(2):
				charTwo->getHealAbility()->getAbilities().healPart(charTwo, charTwo->getPart(2), BASE_HEALING);
				logOut << "Player two healed their " << charTwo->getPart(2)->getName() << std::endl;
				break;

				case(3):
				charTwo->getHealAbility()->getAbilities().healPart(charTwo, charTwo->getPart(3), BASE_HEALING);
				logOut << "Player two healed their " << charTwo->getPart(3)->getName() << std::endl;
				break;

				case(4):
				charTwo->getHealAbility()->getAbilities().healPart(charTwo, charTwo->getPart(4), BASE_HEALING);
				logOut << "Player two healed their " << charTwo->getPart(4)->getName() << std::endl;
				break;

				case(5):
				charTwo->getHealAbility()->getAbilities().healPart(charTwo, charTwo->getPart(5), BASE_HEALING);
				logOut << "Player two healed their " << charTwo->getPart(5)->getName() << std::endl;
				break;

				case(6):
				charTwo->getHealAbility()->getAbilities().healPart(charTwo, charTwo->getPart(6), BASE_HEALING);
				logOut << "Player two healed their " << charTwo->getPart(6)->getName() << std::endl;
				break;

				default:
				std::cout << "That is not a valid target" << std::endl;
				logOut << "Player two chose an invalid target" << std::endl;
				break;
			}
			}
			//if player two cannot heal show them thus
			else
			{
				std::cout << "This player can no longer heal" << std::endl;
				logOut << "Player two can no longer heal" << std::endl;
			}
			break;

			//abort the program early
			case(8):
				logOut.close();
			exit(2);
			break;

			//default value for if invalid index is chosen
			default:
			std::cout << "Invalid value entered, try again" << std::endl;
			break;
		}
		//at the end of each loop check if player one is alive, if they aren't then show that player two won and stop menu function with a return showing player two won
		if (charOne->getAlive() != true)
		{
			logOut << "Player two won!" << std::endl;
			logOut.close();
			return 2;
		}
		//at the end of each loop check if player two is alive, if they aren't then show that player one won and stop menu function with a return showing player one won
		else if (charTwo->getAlive() != true)
		{
			logOut << "Player one won!" << std::endl;
			logOut.close();
			return 1;
		}
	}while(choice != 8);
}

//main function
int main()
{

	//strings for the player names
	std::string playOneName, playTwoName;
	//constant variables for the max healths of each part of the character and the character themself
	const int MAX_HEALTH = 100, MAX_LIMB_HEALTH = 10, MAX_HEAD_HEALTH = 20, MAX_TORSO_HEALTH = 20;
	//variables for the player's defense and offense values
	const int OFF_DAMAGE = 10, DEF_DAMAGE = 5, OFF_DEFENSE = 2, DEF_DEFENSE = 5, OFF_HEAL = 5, DEF_HEAL = 10;
	//objects being created to be used in the creation of each character
	//first player parts' abilities
	ability* playOneArms = new ability(true, true, DEF_DAMAGE, DEF_HEAL);
	ability* playOneLegs = new ability(true, false, DEF_DAMAGE, DEF_HEAL);
	//first player's parts
	arm* playOneArmOne = new arm(MAX_LIMB_HEALTH, "PlayerOneArmOne", *playOneArms);
	arm* playOneArmTwo = new arm(MAX_LIMB_HEALTH, "PlayerOneArmTwo", *playOneArms);
	leg* playOneLegOne = new leg(MAX_LIMB_HEALTH, "PlayerOneLegOne", *playOneLegs);
	leg* playOneLegTwo = new leg(MAX_LIMB_HEALTH, "PlayerOneLegTwo", *playOneLegs);
	chest* playOneChest = new chest(MAX_TORSO_HEALTH, "PlayerOneChest");
	head* playOneHead = new head(MAX_HEAD_HEALTH, "PlayerOneHead");
	//player two's abilities
	ability* playTwoArms = new ability(true, true, OFF_DAMAGE, OFF_HEAL);
	ability* playTwoLegs = new ability(true, false, OFF_DAMAGE, OFF_HEAL);
	//player two's parts
	arm* playTwoArmOne = new arm(MAX_LIMB_HEALTH, "PlayerTwoArmOne", *playTwoArms);
	arm* playTwoArmTwo = new arm(MAX_LIMB_HEALTH, "PlayerTwoArmTwo", *playTwoArms);
	leg* playTwoLegOne = new leg(MAX_LIMB_HEALTH, "PlayerTwoLegOne", *playTwoLegs);
	leg* playTwoLegTwo = new leg(MAX_LIMB_HEALTH, "PlayerTwoLegTwo", *playTwoLegs);
	chest* playTwoChest = new chest(MAX_TORSO_HEALTH, "PlayerTwoChest");
	head* playTwoHead = new head(MAX_HEAD_HEALTH, "PlayerTwoHead");
	//output information on how to play game
	std::cout << "Welcome to my final project game for CSI 240." << std::endl << "This is a turn based combat game where two players try to defeat each other." << std::endl;
	std::cout << "Each player has three actions: Heal, Defend, and Attack." << std::endl <<"When attacking and healing you get to choose which body part you target." << std::endl;
	std::cout << "A player loses when they lose one of the following: Their max health, their head, their torso, or all of their arms and legs." << std::endl;
	std::cout << "Player one will have higher defense but lower offense while player two has higher offense but lower defense." << std::endl;
	std::cout << "If you have any questions you can reload this dialogue through the menu later." << std::endl;
	//take in both players' names
	std::cout << "Please enter your name player one: " << std::endl;
	std::getline (std::cin,playOneName);
	std::cout << "Please enter your name player two: " << std::endl;
	std::getline (std::cin,playTwoName);
	//create both player objects with objects set above and input names
	character* playerOne = new character(MAX_HEALTH, DEF_DAMAGE, DEF_DEFENSE, *playOneArmOne, *playOneArmTwo, *playOneLegOne, *playOneLegTwo, *playOneChest, *playOneHead, playOneName);
	character* playerTwo = new character(MAX_HEALTH, OFF_DAMAGE, OFF_DEFENSE, *playTwoArmOne, *playTwoArmTwo, *playTwoLegOne, *playTwoLegTwo, *playTwoChest, *playTwoHead, playTwoName);
	//execute the game portion
	int victor = menu(playerOne, playerTwo);
	//check who won and show the relevant message
	if (victor == 1)
	{
		std::cout << "Congratulations " << playerOne->getName() << ", you are the winner!" << std::endl;
	}
	else if (victor == 2)
	{
		std::cout << "Congratulations " << playerTwo->getName() << ", you are the winner!" << std::endl;
	}
	//make sure everythhing is deleted so no memory leaks occur, also set them to nullptr just to be safe
	delete playerOne;
	playerOne = nullptr;
	delete playerTwo;
	playerTwo = nullptr;
	delete playOneArms;
	playOneArms = nullptr;
	delete playTwoArms;
	playTwoArms = nullptr;
	delete playOneLegs;
	playOneLegs = nullptr;
	delete playTwoLegs;
	playTwoLegs = nullptr;
	delete playOneChest;
	playOneChest = nullptr;
	delete playOneHead;
	playOneHead = nullptr;
	delete playTwoChest;
	playTwoChest = nullptr;
	delete playTwoHead;
	playTwoHead = nullptr;
	return 0;
}