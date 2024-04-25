#include "character.h"

//
static bool playTurn = true;
int menu(character charOne, character charTwo)
{
	//base values for the damage and heal functions to use
	const int BASE_DAMAGE = 10, BASE_HEALING = 10;
	//vars for looping the menu and choosing which part to attack
	int choice = 1, targetChoice;
	do
	{
		std::cout << "1: Redisplay tutorial information" << std::endl;
		std::cout << "2: Display Player One character info and status" << std::endl;
		std::cout << "3: Display Player Two character info and status" << std::endl;
		std::cout << "4: Player One Attack" << std::endl;
		std::cout << "5: Player One Heal" << std::endl;
		std::cout << "6: Player Two Attack" << std::endl;
		std::cout << "7: Player Two Heal" << std::endl;
		std::cout << "8: Abort Program" << std::endl;
		std::cin >> choice;
		switch(choice)
		{
			case(1):
			std::cout << "Welcome to my final project game for CSI 240." << std::endl << "This is a turn based combat game where two players try to defeat each other." << std::endl;
			std::cout << "Each player has three actions: Heal, Defend, and Attack." << std::endl <<"When attacking and healing you get to choose which body part you target." << std::endl;
			std::cout << "A player loses when they lose one of the following: Their max health, their head, their torso, or all of their arms and legs." << std::endl;
			std::cout << "Player one will have higher defense but lower offense while player two has higher offense but lower defense." << std::endl;
			break;

			case(2):
			charOne.printFullInfo();
			break;

			case(3):
			charTwo.printFullInfo();
			break;

			case(4):
			if(charOne.getAttackAbility() != NULL)
			{
					std::cout << "Potential targets: " << std::endl;
			charTwo.printFullInfo();
			std::cout << "1: ArmOne \n 2: ArmTwo \n 3: LegOne \n 4: LegTwo \n 5: Chest \n 6: Head \n";
			std::cin >> targetChoice;
				switch(targetChoice)
				{
					case(1):
					if(charOne.getAttackAbility() != NULL)
					{
						charOne.getAttackAbility().attackPart(charTwo, charTwo.getPart(1), BASE_DAMAGE);
					}
					break;

					case(2):
					if(charOne.getAttackAbility() != NULL)
					{
						charOne.getAttackAbility().attackPart(charTwo, charTwo.getPart(2), BASE_DAMAGE);
					}
					break;

					case(3):
					if(charOne.getAttackAbility() != NULL)
					{
						charOne.getAttackAbility().attackPart(charTwo, charTwo.getPart(3), BASE_DAMAGE);
					}
					break;

					case(4):
					if(charOne.getAttackAbility() != NULL)
					{
						charOne.getAttackAbility().attackPart(charTwo, charTwo.getPart(4), BASE_DAMAGE);
					}
					break;

					case(5):
					if(charOne.getAttackAbility() != NULL)
					{
						charOne.getAttackAbility().attackPart(charTwo, charTwo.getPart(5), BASE_DAMAGE);
					}
					break;

					case(6):
					if(charOne.getAttackAbility() != NULL)
					{
						charOne.getAttackAbility().attackPart(charTwo, charTwo.getPart(6), BASE_DAMAGE);
					}
					break;

					default:
					std::cout << "Not a valid target" << std::endl;
					break;
			}
			}
			else
			{
				std::cout << "This player can no longer attack" << std::endl;
			}
			break;

			case(5):
			if(charOne.getHealAbility() != NULL)
			{
				std::cout << "Potential healing targets (player will heal same amount regardless of chosen part): " << std::endl;
			charOne.printFullInfo();
			std::cout << "1: ArmOne \n 2: ArmTwo \n 3: LegOne \n 4: LegTwo \n 5: Chest \n 6: Head \n";
			std::cin >> targetChoice;
			switch(targetChoice)
			{
				case(1):
				charOne.getHealAbility().healPart(charOne, charOne.getPart(1), BASE_HEALING);
				break;

				case(2):
				charOne.getHealAbility().healPart(charOne, charOne.getPart(2), BASE_HEALING);
				break;

				case(3):
				charOne.getHealAbility().healPart(charOne, charOne.getPart(3), BASE_HEALING);
				break;

				case(4):
				charOne.getHealAbility().healPart(charOne, charOne.getPart(4), BASE_HEALING);
				break;

				case(5):
				charOne.getHealAbility().healPart(charOne, charOne.getPart(5), BASE_HEALING);
				break;

				case(6):
				charOne.getHealAbility().healPart(charOne, charOne.getPart(6), BASE_HEALING);
				break;

				default:
				std::cout << "That is not a valid target" << std::endl;
				break;
			}
			}
			else
			{
				std::cout << "This player can no longer heal" << std::endl;
			}
			
			break;

			case(6):
			std::cout << "Potential targets: " << std::endl;
			charOne.printFullInfo();
			std::cout << "1: ArmOne \n 2: ArmTwo \n 3: LegOne \n 4: LegTwo \n 5: Chest \n 6: Head \n";
			std::cin >> targetChoice;
			switch(targetChoice)
			{
				case(1):
				if(charTwo.getAttackAbility() != NULL)
					{
						charTwo.getAttackAbility().attackPart(charOne, charOne.getPart(1), BASE_DAMAGE);
					}
				break;

				case(2):
				if(charTwo.getAttackAbility() != NULL)
					{
						charTwo.getAttackAbility().attackPart(charOne, charOne.getPart(2), BASE_DAMAGE);
					}
				break;

				case(3):
				if(charTwo.getAttackAbility() != NULL)
					{
						charTwo.getAttackAbility().attackPart(charOne, charOne.getPart(3), BASE_DAMAGE);
					}
				break;

				case(4):
				if(charTwo.getAttackAbility() != NULL)
					{
						charTwo.getAttackAbility().attackPart(charOne, charOne.getPart(4), BASE_DAMAGE);
					}
				break;

				case(5):
				if(charTwo.getAttackAbility() != NULL)
					{
						charTwo.getAttackAbility().attackPart(charOne, charOne.getPart(5), BASE_DAMAGE);
					}
				break;

				case(6):
				if(charTwo.getAttackAbility() != NULL)
					{
						charTwo.getAttackAbility().attackPart(charOne, charOne.getPart(6), BASE_DAMAGE);
					}
				break;

				default:
				std::cout << "Not a valid target" << std::endl;
				break;
			}
			break;

			case(7):
			if(charTwo.getHealAbility() != NULL)
			{
				std::cout << "Potential healing targets (player will heal same amount regardless of chosen part): " << std::endl;
			charTwo.printFullInfo();
			std::cout << "1: ArmOne \n 2: ArmTwo \n 3: LegOne \n 4: LegTwo \n 5: Chest \n 6: Head \n";
			std::cin >> targetChoice;
			switch(targetChoice)
			{
				case(1):
				charTwo.getHealAbility().healPart(charTwo, charTwo.getPart(1), BASE_HEALING);
				break;

				case(2):
				charTwo.getHealAbility().healPart(charTwo, charTwo.getPart(2), BASE_HEALING);
				break;

				case(3):
				charTwo.getHealAbility().healPart(charTwo, charTwo.getPart(3), BASE_HEALING);
				break;

				case(4):
				charTwo.getHealAbility().healPart(charTwo, charTwo.getPart(4), BASE_HEALING);
				break;

				case(5):
				charTwo.getHealAbility().healPart(charTwo, charTwo.getPart(5), BASE_HEALING);
				break;

				case(6):
				charTwo.getHealAbility().healPart(charTwo, charTwo.getPart(6), BASE_HEALING);
				break;

				default:
				std::cout << "That is not a valid target" << std::endl;
				break;
			}
			}
			else
			{
				std::cout << "This player can no longer heal" << std::endl;
			}
			break;

			case(8):
			exit(2);
			break;

			default:
			std::cout << "Invalid value entered, try again" << std::endl;
			break;
		}
	}while(choice != 8);
}


int main()
{
	//strings for the player names
	std::string playOneName, playTwoName;
	//constant variables for the max healths of each part of the character and the character themself
	const int MAX_HEALTH = 100, MAX_LIMB_HEALTH = 10, MAX_HEAD_HEALTH = 20, MAX_TORSO_HEALTH = 20;
	//variables for the player's defense and offense values
	const int OFF_DAMAGE = 10, DEF_DAMAGE = 5, OFF_DEFENSE = 2, DEF_DEFENSE = 5, OFF_HEAL = 5, DEF_HEAL = 10;
	ability* playOneArms = new ability(true, true, DEF_DAMAGE, DEF_HEAL);
	ability* playOneLegs = new ability(true, false, DEF_DAMAGE, DEF_HEAL);
	arm* playOneArmOne = new arm(MAX_LIMB_HEALTH, "PlayerOneArmOne", *playOneArms);
	arm* playOneArmTwo = new arm(MAX_LIMB_HEALTH, "PlayerOneArmTwo", *playOneArms);
	leg* playOneLegOne = new leg(MAX_LIMB_HEALTH, "PlayerOneLegOne", *playOneLegs);
	leg* playOneLegTwo = new leg(MAX_LIMB_HEALTH, "PlayerOneLegTwo", *playOneLegs);
	chest* playOneChest = new chest(MAX_TORSO_HEALTH, "PlayerOneChest");
	head* playOneHead = new head(MAX_HEAD_HEALTH, "PlayerOneHead");
	ability* playTwoArms = new ability(true, true, OFF_DAMAGE, OFF_HEAL);
	ability* playTwoLegs = new ability(true, false, OFF_DAMAGE, OFF_HEAL);
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
	std::cout << "Please enter your name player one: " << std::endl;
	std::getline (std::cin,playOneName);
	std::cout << "Please enter your name player two: " << std::endl;
	std::getline (std::cin,playTwoName);
	character* playerOne = new character(MAX_HEALTH, DEF_DAMAGE, DEF_DEFENSE, *playOneArmOne, *playOneArmTwo, *playOneLegOne, *playOneLegTwo, *playOneChest, *playOneHead, playOneName);
	character* playerTwo = new character(MAX_HEALTH, OFF_DAMAGE, OFF_DEFENSE, *playTwoArmOne, *playTwoArmTwo, *playTwoLegOne, *playTwoLegTwo, *playTwoChest, *playTwoHead, playTwoName);
	menu(playerOne, playerTwo);






	return 0;
}