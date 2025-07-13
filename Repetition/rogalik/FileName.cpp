#include<iostream>
#include<ctime>
#include<cmath>
#include<string>

struct Master_of_element {
	int luck;
	int defence;
	int status_count_burn = 0;//������� ���������� ����� ��� �������� 
	int status_count_aura = 0;//������� ���������� ����� ��� �����
	int status_count_weak = 0;//������� ���������� ����� ��� ���������
	int max_health;
	double health;
	double attack_power;
	double recharge;
	bool alive = true;
	bool status_regen = false;
	bool aura = false;//������� ����
	std::string magic;
	std::string potion;
	std::string status; //������,���
	Master_of_element InitPlayer()
	{
		choice_of_hero();
		int choice;
		std::cin >> choice;
		Master_of_element player1;
		switch (choice)
		{
		case 1:
		{
			player1.health = 60;
			player1.max_health = 100;
			player1.attack_power = 15;
			player1.defence = 5;
			player1.recharge = 6;
			player1.magic = "Burn"; // ��������� ���������,������ ��� � ������� ��������� 3 ����� ��������� ����.
			player1.luck = 20;
			break;
		}

		case 2:
		{
			player1.health = 150;
			player1.max_health = 150;
			player1.attack_power = 8;
			player1.defence = 7;
			player1.recharge = 3;
			player1.magic = "Aura"; // ������� ���� ����, ������� ��������������� ����� �� 4 ����.
			player1.luck = 25;
			break;
		}

		case 3:
		{
			player1.health = 90;
			player1.max_health = 90;
			player1.attack_power = 8;
			player1.defence = 15;
			player1.recharge = 5;
			player1.magic = "Weak"; // ����������� �����, ������� ����������� �� ��������� �������� � ������� �� 3 ����.
			player1.luck = 15;
			break;
		}

		case 4:
		{
			player1.health = 130;
			player1.max_health = 130;
			player1.attack_power = 11;
			player1.defence = 5;
			player1.recharge = 4;
			player1.magic = "Thunder"; // ���������� ���������,� ��������� ��� �� �� ������ ���������.
			player1.luck = 22;
			break;
		}
		}
		return player1;
	}
	int countOfActions(Master_of_element& player1)
	{
		if (player1.status == "Shock")
		{
			player1.status.clear();
			return 0;
		}
		return 1;
	}
	void isAura(Master_of_element& player1)
	{
		if (player1.aura == true && player1.status_count_aura == 4)
		{
			player1.aura = false;
			player1.status_count_aura = 0;
			return;
		}
		if (player1.aura == true)
		{
			(player1.health + 4) > 150 ? player1.health = 150 : (player1.health + 4);
			(player1.status_count_aura)++;
		}
		return;
	}
	void isBurn(Master_of_element& player1)
	{
		if (player1.status_count_burn == 3 && player1.status == "Burn")
		{
			player1.status_count_burn = 0;
			player1.status.clear();
			return;
		}
		if (player1.status == "Burn")
		{
			player1.health -= ((player1.max_health) * 0.05);
			(player1.status_count_burn)++;
		}
		return;
	}
	void isWeak(Master_of_element& player1)
	{
		if (player1.status_count_weak == 3 && player1.status == "Weak")
		{
			player1.status_count_weak = 0;
			player1.status.clear();
			player1.luck += 5;
			player1.attack_power += 2;
			return;
		}
		if (player1.status_count_weak == 0 && player1.status == "Weak")
		{
			player1.luck -= 5;
			player1.attack_power -= 2;
		}
		if (0 < player1.status_count_weak && player1.status_count_weak < 3 && player1.status == "Weak") {
			(player1.status_count_weak)++;
		}
		return;
	}
	void isRegeneration(Master_of_element& player1)
	{
		if (player1.status_regen == true)
		{
			(player1.health + (player1.health * 0.02)) > player1.max_health ? player1.health = player1.max_health : player1.health = (player1.health + (player1.health * 0.02));
		}
	}
	void usePotion(Master_of_element& player1)
	{
		if (player1.potion == "����� �����")
		{
			std::cout << "�� ������ ����� ����" << "\n";
			player1.attack_power *= 1.3;
			player1.potion.clear();
			return;
		}
		if (player1.potion == "����� �����")
		{
			std::cout << "�� ������ ����� �����" << "\n";
			player1.luck += 10;
			player1.potion.clear();
			return;
		}
		if (player1.potion == "����� ���������")
		{
			std::cout << "�� ������ ����� ���������" << "\n";
			player1.defence += 5;
			player1.potion.clear();
			return;
		}
		if (player1.potion == "����� �����������")
		{
			std::cout << "�� ������ ����� �����������" << "\n";
			player1.status_regen = true;
			player1.potion.clear();
			return;
		}

		std::cout << "�� ��� ������ �����" << "\n";

	}
	void printStats(Master_of_element& player1)
	{
		std::cout << "�������� - " << player1.health << "\n";
		std::cout << "���� ������� - " << player1.attack_power << "\n";
		std::cout << "������ - " << player1.defence << "\n";
		std::cout << "����������� - " << player1.recharge << "\n";
		std::cout << "����� - " << player1.luck << "\n";
		std::cout << player1.potion << "\n";
		std::cout << player1.status << "\n";
	}
	void printActions()
	{
		std::cout << "1.��������� ���������� �������" << "\n";
		std::cout << "2.������������ �����" << "\n";
		std::cout << "3.������������ �����" << "\n";
	}
	void choice_of_hero()
	{
		std::cout << "������ ������� ������" << "\n";
		std::cout << "1.������ ����" << "\n";
		std::cout << "2.������ ����" << "\n";
		std::cout << "3.������ �����" << "\n";
		std::cout << "4.������ ������" << "\n";
	}
	void choicepotion()
	{
		std::cout << "������ �����" << "\n";
		std::cout << "1.����� �����(����������� ���� � 1.3 ����)" << "\n";
		std::cout << "2.����� �����������(��������������� 2% �� ������������� ��������)" << "\n";
		std::cout << "3.����� �����(�������� ���� ��������� ����� �� 10%)" << "\n";
		std::cout << "4.����� ���������(�������� ������ �� 5)" << "\n";
	}
	void useMagic(Master_of_element& player1, Master_of_element& player2)
	{
		int luck_work = rand() % 100;
		if (luck_work <= player1.luck)
		{
			std::cout << "����� ���������" << "\n";
			if (player1.magic == "Burn")
			{
				player2.status = "Burn";
				return;
			}
			if (player1.magic == "Aura")
			{
				player1.aura = true;
				return;
			}
			if (player1.magic == "Weak")
			{
				player2.status = "Weak";
				return;
			}
			if (player1.magic == "Thunder")
			{
				player2.status = "Shock";
				return;
			}
		}
		std::cout << "����� �� ���������" << "\n";
	}
	void choice_of_potion(Master_of_element& a)
	{
		choicepotion();
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			a.potion = "����� �����";
			break;
		}
		case 2:
		{
			a.potion = "����� �����������";
			break;
		}
		case 3:
		{
			a.potion = "����� �����";
			break;
		}
		case 4:
		{
			a.potion = "����� ���������";
			break;
		}
		}
	}
	void check_alive(Master_of_element& a)
	{
		if (a.health <= 0)
		{
			a.alive = false;
		}
	}
	void battleAction(Master_of_element& player1, Master_of_element& player2, bool& changer)
	{
		int count;
		int choice;
		switch (changer)
		{
		case true://player 1 turn
		{
			isAura(player1);
			isBurn(player1);
			isWeak(player1);
			isRegeneration(player1);
			count = countOfActions(player1);
			if (count != 0)
			{
				printStats(player1);
				printActions();

				std::cin >> choice;
				switch (choice)
				{
				case 1:
				{
					double damage = player1.attack_power - rand() % (player2.defence);
					player2.health -= damage;
					changer = false;
					break;
				}
				case 2:
				{
					usePotion(player1);
					changer = false;
					break;
				}
				case 3:
				{
					useMagic(player1, player2);
					changer = false;
					break;
				}
				}
			}
			break;
		}

		case false://player 2 turn
		{
			isAura(player2);
			isBurn(player2);
			isWeak(player2);
			isRegeneration(player2);
			count = countOfActions(player2);
			if (count != 0)
			{
				printStats(player2);
				printActions();
				std::cin >> choice;
				switch (choice)
				{
				case 1:
				{
					double damage = player2.attack_power - rand() % (player1.defence);
					player1.health -= damage;
					changer = true;
					break;
				}
				case 2:
				{
					usePotion(player2);
					changer = true;
					break;
				}
				case 3:
				{
					useMagic(player2, player1);
					changer = true;
					break;
				}
				}
			}
			break;
		}
		}
	}
	void battle(Master_of_element& player1, Master_of_element& player2)
	{
		int choice;
		int count;//���������� ��������
		bool changer = true;//true - ����� player 1,false - ����� player 2
		while (player1.alive == true && player2.alive == true)
		{
			check_alive(player1);
			if (player1.alive == false)
			{
				std::cout << "������� ����� 2" << "\n";
				return;
			}
			check_alive(player2);
			if (player2.alive == false)
			{
				std::cout << "������� ����� 1" << "\n";
				return;
			}
			battleAction(player1, player2, changer);
		}
	}
};


int main(int argc, char* argv[])
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	Master_of_element game;
	Master_of_element player1 = game.InitPlayer();
	Master_of_element player2 = game.InitPlayer();
	player1.choice_of_potion(player1);
	player2.choice_of_potion(player2);
	game.battle(player1, player2);
	return 0;
}