#include "pch.h"
#include <iostream>

/////////

#include <string> // string
#include <cstdlib> // rand, srand
#include <ctime> // time

/*class Fruit
{
protected:
	std::string m_name;
	std::string m_color;

public:
	Fruit(std::string name, std::string color) : m_name(name), m_color(color) {}

	std::string getName() { return m_name; }
	std::string getColor() { return m_color; }
};

class Apple : public Fruit
{
public:
	Apple(std::string color = "red", std::string name = "apple") : Fruit(name, color) {}
};

class Banana : public Fruit
{
public:
	Banana(std::string name = "banana", std::string color = "yellow") : Fruit(name, color) {}
};

class GrannySmith : public Apple
{
public:
	GrannySmith(std::string name = "granny smith apple", std::string color = "green") : Apple(color, name) {}
};

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}*/

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_hp;
	int m_dps;
	int m_gold;

public:
	Creature(std::string name = "", char symbol = ' ', int hp = 0, int dps = 0, int gold = 0) :
		m_name(name), m_symbol(symbol), m_hp(hp), m_dps(dps), m_gold(gold) {}

	const std::string& getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHp() { return m_hp; }
	int getDps() { return m_dps; }
	int getGold() { return m_gold; }

	void reduceHealth(int rHP)
	{
		m_hp -= rHP;
	}
	
	bool isDead()
	{
		return (m_hp <= 0);
	}

	void addGold(int gold)
	{
		m_gold += gold;
	}
};

class Player : public Creature
{
private:
	int m_pLevel;

public:
	Player(std::string name = "", char symbol = '@', int hp = 10, int dps = 1, int gold = 0) :
		Creature(name, symbol, hp, dps, gold)
	{
		m_pLevel = 1;
	}

	void levelUp()
	{
		++m_pLevel;
		++m_dps;
	}

	int getLevel() { return m_pLevel; }

	bool hasWon()
	{
		if (m_pLevel == 20)
			return true;
		else
			return false;
	}
};

class Monster : public Creature
{
public:
	Monster() {}

	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES,
	};

	struct MonsterData
	{
		std::string name;
		char symbol;
		int hp;
		int dps;
		int gold;
	};

	static MonsterData monsterData[Monster::MAX_TYPES];

	Monster(Type type) : Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].hp, monsterData[type].dps, monsterData[type].gold)
	{}

	static Monster getRandomMonster()
	{
		int rand = getRandomNumber(0, MAX_TYPES - 1);

		Monster m(static_cast<Type>(rand));

		return m;
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{"dragon", 'D', 20, 4, 100},
	{"orc", 'O', 6, 2, 25},
	{"slime", 'S', 1, 1, 5}
};

void attackMonster(Player &p, Monster &m)
{
	if (p.isDead())
		return;

	m.reduceHealth(p.getDps());

	std::cout << "You have hit the " << m.getName() << " for " << p.getDps() << " damage.\n";

	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << '\n';

		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << '\n';

		p.addGold(m.getGold());
		std::cout << "You found " << m.getGold() << " gold.\n";
	}
}

void attackPlayer(Player &p, Monster &m)
{
	if (m.isDead())
		return;

	p.reduceHealth(m.getDps());

	std::cout << "The " << m.getName() << " hit you for " << m.getDps() << " damage.\n";
}

void fightMonster(Player &p)
{
	Monster m = Monster::getRandomMonster();

	std::cout << "You have encountered a " << m.getName() << "(" << m.getSymbol() << ")" << '\n';

	while (!m.isDead() && !p.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char choice;
		std::cin >> choice;

		if (choice == 'f' || choice == 'F')
		{
			attackMonster(p, m);
			attackPlayer(p, m);
		}
		if (choice == 'r' || choice == 'R')
		{
			if (getRandomNumber(0, 1) == 0)
			{
				std::cout << "You have successfully fled.\n";
				return;
			}
			else
			{
				std::cout << "You failed to flee.\n";
				attackPlayer(p, m);
				continue;
			}
		}
	}
}

int main()
{
	// test
	/*Creature o("orc", 'o', 4, 2, 10);

	o.addGold(5);
	o.reduceHealth(1);

	std::cout << "The " << o.getName() << " has " << o.getHp() << " health and is carrying " << o.getGold() << " golds.\n";

	std::cout << '\n';

	std::cout << "Enter your name: ";
	std::string playerName;
	std::getline(std::cin, playerName);
	Player p(playerName);
	std::cout << "Welcome, " << p.getName() << '\n';
	std::cout << "You have " << p.getHp() << " health and are carrying " << p.getGold() << " golds." << '\n';

	std::cout << '\n';

	Monster m(Monster::Type::DRAGON);
	std::cout << "A " << m.getName() << "(" << m.getSymbol() << ")" << " was created.\n";

	srand(static_cast<unsigned int>(time(0)));
	rand();

	for (int i = 0; i < 10; ++i)
	{
		Monster m = Monster::getRandomMonster();

		std::cout << "A " << m.getName() << "(" << m.getSymbol() << ")" << " was created.\n";
	}*/

	srand(static_cast<unsigned int>(time(0)));
	rand();

	std::string name = "";
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
	Player p(name);
	std::cout << "Welcome, " << p.getName() << '\n';

	while (!p.isDead() && !p.hasWon())
	{
		fightMonster(p);
	}

	if (!p.isDead())
	{
		std::cout << "You won the game with " << p.getGold() << " gold.\n";
	}
	else
	{
		std::cout << "You died with " << p.getGold() << " gold, at level " << p.getLevel() << ".\n";
		std::cout << "Too bad you can't take it with you.\n";
	}

	return 0;
}