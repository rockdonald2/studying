#include "stdafx.h"
#include <iostream>

/*****/

#include <cmath>

// 1
/*
1a)Írj egy classot Point2d néven,
	tartalmaznia kell 2 double típusú változót: m_x és m_y, amelynek az alapértelmezett értéke 0.0
	biztosíts egy konstruktőrt, és egy kiir funkciót.
1b)Most adj hozzá egy tag funkciót distanceTo néven, ami fog még egy Point2d objectet és kiszámolja a kettő közötti távolságot
		- két kétdimenziós pont közötti távolság gyökalatt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))
		- a gyök funkció a <cmath> headerben van
1c)Változtasd meg a distanceTo() funkciót tag funkcióról nem-tag barát funkcióvá, ami befogad két pontot mint paraméter,
	valamit nevezd át distanceFrom-má.
	
*/
/*
class Point2d
{
private:
	double m_x;
	double m_y;

public:
	Point2d(double x = 0.0, double y = 0.0) : m_x(x), m_y(y)
	{}

	//double distanceTo(const Point2d &s) const
	//{
		//return sqrt(((m_x - s.m_x)*(m_x - s.m_x)) + (m_y - s.m_y)*(m_y - s.m_y));
	//}

	void print() const
	{
		std::cout << "Az x erteke = " << m_x << ", es az y erteke = " << m_y << ".\n";
		std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
	}

	friend double distanceFrom(const Point2d &f, const Point2d &s);
};

double distanceFrom(const Point2d &f, const Point2d &s) 
{
	return sqrt(((f.m_x - s.m_x)*(f.m_x - s.m_x)) + (f.m_y - s.m_y)*(f.m_y - s.m_y));
}

int main()
{
	Point2d first;
	Point2d second(3.0, 4.0);

	first.print();
	second.print();

	//std::cout << "A ket pont kozotti tavolsag: " << first.distanceTo(second) << "\n";
	std::cout << "A ket pont kozotti tavolsag: " << distanceFrom(first, second) << "\n";

	return 0;
}*/


//2
/*
Írj egy destruktőrt az alábbi classhoz.
*/
/*
class HelloWorld
{
private:
	char *m_data;

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char *init = "Hello, World!";
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
		std::cout << "Torlodik a string.\n";
		delete[] m_data;
	}

	void print() const
	{
		std::cout << m_data << "\n";
	}
};

int main()
{
	HelloWorld hello;
	hello.print();

	return 0;
}*/

//3
/*
Készítsünk egy random szörny generátort.
3a)Először, hozz létre egy enum-ot a MonsterType néven, ami a következőket tartalmazza: dragon, goblin, ogre, orc, skeleton,
	troll, vampire, és zombie.
		- Adj hozzá egy további MAX_MONSTER_TYPES enumot is, hogy megszámolhassuk hány enumerátorod is van.
3b)Most hozzuk létre a Monster classunkat.
	A mi szörnyünknek 4 féle tulajdonsága lesz(tag változók): típus(MonsterType), név(std::string), üvöltés(roar, std::string),
		és egy bizonyos számű életerőpont(int).
3c)az a) pontban létrehozott enum a Monster class szerves része, mozgasd át a classba a public részbe.
3d)hozz létre egy konstruktőrt ami lehetőve teszi, hogy inicializáld minden tag változódat.
3e)most azt akarnánk, hogy kiírjuk a saját szörnyünket, hogy leellenőrízzük, hogy helyes-e.
	ehhez, szükségünk van egy olyan funkcióra ami átalakítja a MonsterType-t std::string-be.
	- írj egy ilyen funkciót getTypeString() néven, valamint egy print tag funkciót-
3f)most készítsük el a random szörny generátorunkat.
	- készíts egy static MonsterGenerator classt, és egy static funkciót generateMonster() néven, ez vissza kellene adjon egy
		Monstert. ! return anonymous
3g)most, a monsterGeneratorunk random tulajdonságokat kéne generáljon.
   - ehhez használjuk a két szám közötti random szám generátor funkciónkat és rakjuk azt a classba static funkcióként.
3h)most, modosítsuk a generateMonster() funkciónkat, hogy random MonsterType-ot generáljon (0, és a max között), és random
		hp-t(1 és 100 között).
		Majd, határozz meg két static fixed arrayt 6 hosszal a funkción belül, (s_names, s_roars néven), és inicializáld őket
			6 névvel, és 6 hangutánzóval. Válassz random neveket ezekből az arrayokból.
*/

#include <string>
#include <ctime>
#include <cstdlib>
/*
class Monster
{
public:
	enum MonsterType
	{
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES,
	};

private:
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hp;

public:
	Monster(MonsterType type, std::string name, std::string roar, int hp) 
		: m_type(type), m_name(name), m_roar(roar), m_hp(hp) 
	{}

	std::string getTypeString(MonsterType m_type) const
	{
		switch (m_type)
		{
		case DRAGON:
			return "dragon";
		case GOBLIN:
			return "goblin";
		case OGRE:
			return "ogre";
		case ORC:
			return "orc";
		case SKELETON:
			return "skeleton";
		case TROLL:
			return "troll";
		case VAMPIRE:
			return "vampire";
		case ZOMBIE:
			return "zombie";

		default:
			return "???";
		}
	}

	void print() const
	{
		std::cout << "Ez egy " << getTypeString(m_type) << " aminek a neve " << m_name << " es " << m_hp << " hpja van." << m_roar << "\n";
	}


};

class MonsterGenerator
{
public:
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster()
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES));
		static std::string s_names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
		static std::string s_roars[6]{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };
		int hp = getRandomNumber(1, 100);

		return Monster(type, s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], hp);
	}

	
};

int main()
{
	srand(static_cast<int>(time(0)));
	rand(); // elvetjük az első sor random értéket.

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	return 0;
}*/

//4
/*
Írj újra az arrayokból elkészített BlackJack játékot classokkal.
	De először írd meg arrayokkal!

Kezdjük is hát,
	először, egy kártyapakli ugye 52 darab kártyából áll(13 kard rank, 4 típusból).
		hozz létre egy enum-ot a card rankoknak(2-től Ace-ig), és típusoknak(clubs, diamonds, hearts, spades)
	minden kártyát képviseli egy struct aminek a neve Card, és tartalmaz egy rank-ot és egy suit-ot.
		hozd létre a structot.
	hozz létre egy printCard() funkciót, ami fog egy const Card hivatkozást paraméterként, és kiírja a kártya rankját és értékét,
		mint egy 2-betűs kód(pl. jack of spades mint JS)
	egy kártyapakli 52 kártya, hozz létre egy arrayt hogy ábrázold a kártyapaklit, és inicializáld minden egyes kártyáját.
	hozz létre egy funkciót printDeck() néven ami fogja a deck-et const hivatkozásként paraméterben, és kiírja az összes kártya
		értékét a kártyapakliban. Használj for-each loopot.
	írj egy swapCard funkciót ami fog két kártyát és megcseréli az értéküket.
	hozz létre egy shuffleDeck() funkciót.
		ahhoz, hogy ezt csináld használj egy for loopot, hogy végig lépkedj az összes elemen az arrayodból.
		válassz egy random számot 1 és 52 között, és hívd le a swapCard-ot a jelenlegi kártyával, és a random választott kártyával.
		frissítsd a main funkciódat, hogy keverd át a paklit, és írja ki újra.
	írj egy funkciót getCardValue() néven, ami visszaadja egy kártya értékét(2 2-t ér, 10, jack, queen, king 11-et, és ace 11-t)

	
	MOST jön a nehezebb része, megírni a blackjack játékot.
*/

/*enum CardRanks
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS,
};

enum CardSuits
{
	SUIT_CLUBS,
	SUIT_DIAMONDS,
	SUIT_HEARTS,
	SUIT_SPADES,
	MAX_SUITS,
};

struct Card
{
	CardRanks rank;
	CardSuits suit;
};

void printCard(const Card &c)
{
	switch (c.rank)
	{
	case RANK_2 :
		std::cout << "2"; break;
	case RANK_3:
		std::cout << "3"; break;
	case RANK_4:
		std::cout << "4"; break;
	case RANK_5:
		std::cout << "5"; break;
	case RANK_6:
		std::cout << "6"; break;
	case RANK_7:
		std::cout << "7"; break;
	case RANK_8:
		std::cout << "8"; break;
	case RANK_9:
		std::cout << "9"; break;
	case RANK_10:
		std::cout << "10"; break;
	case RANK_JACK:
		std::cout << "J"; break;
	case RANK_QUEEN:
		std::cout << "Q"; break;
	case RANK_KING:
		std::cout << "K"; break;
	case RANK_ACE:
		std::cout << "A"; break;
	default:
		std::cout << "???"; break;
	}

	switch (c.suit)
	{
	case SUIT_CLUBS:
		std::cout << "C"; break;
	case SUIT_DIAMONDS:
		std::cout << "D"; break;
	case SUIT_HEARTS:
		std::cout << "H"; break;
	case SUIT_SPADES:
		std::cout << "S"; break;
	default:
		std::cout << "???"; break;
	}
}

#include <array>

void printDeck(const std::array<Card, 52> &deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
}

void swapCard(Card &f, Card &s)
{
	Card temp = f;
	f = s;
	s = temp;
}

#include <ctime>
#include <cstdlib>

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52> &deck)
{
	for (int index = 0; index < 52; ++index)
	{
		int random = getRandomNumber(0, 51);
		swapCard(deck[index], deck[random]);
	}
}

int getCardValue(const Card &c)
{
	switch (c.rank)
	{
	case RANK_2:
		return 2;
	case RANK_3:
		return 3;
	case RANK_4:
		return 4;
	case RANK_5:
		return 5;
	case RANK_6:
		return 6;
	case RANK_7:
		return 7;
	case RANK_8:
		return 8;
	case RANK_9:
		return 9;
	case RANK_10:
		return 10;
	case RANK_JACK:
		return 10;
	case RANK_QUEEN:
		return 10;
	case RANK_KING:
		return 10;
	case RANK_ACE:
		return 11;

	default:
		return 0;
	}
}

enum ResultCodes
{
	WIN,
	LOSE,
	TIE,
};

ResultCodes playBlackJack(const std::array<Card, 52> sD)
{
	const Card *cardPtr = &sD[0];

	int totalPlayer = 0;
	int totalDealer = 0;
	int aceCounterP = 0;
	int aceCounterD = 0;

	if (getCardValue(*cardPtr) == 11)
		++aceCounterD;
	totalDealer += getCardValue(*cardPtr++);
	std::cout << "A kartyak osszege az osztonal " << totalDealer << '\n';

	if (getCardValue(*cardPtr) == 11)
		++aceCounterP;
	totalPlayer += getCardValue(*cardPtr++);
	if (getCardValue(*cardPtr) == 11)
		++aceCounterP;
	totalPlayer += getCardValue(*cardPtr++);
	std::cout << "A kartyak osszege jelenleg " << totalPlayer << '\n';

	// player goes first

	while (1)
	{
		std::cout << "Kersz tobb kartyat? H-igen, S-maradok. \n";
		char bill;
		std::cin >> bill;
		if (bill == 'h')
		{
			totalPlayer += getCardValue(*cardPtr++);
			std::cout << "A kartyak osszege jelenleg " << totalPlayer << '\n';
			if (getCardValue(*cardPtr) == 11)
				++aceCounterP;
		}
		if (bill == 's')
		{
			std::cout << "A kartyak osszege jelenleg " << totalPlayer << '\n';
			break;
		}

		while (totalPlayer > 21 && aceCounterP > 0)
		{
			totalPlayer = totalPlayer - 10;
			--aceCounterP;
			std::cout << "A kartyak osszege jelenleg " << totalPlayer << '\n';
		}

		if (totalPlayer > 21)
			return ResultCodes::LOSE;
	}

	// dealer goes second

	while (totalDealer < 17)
	{
		if (getCardValue(*cardPtr) == 11)
			++aceCounterD;
		totalDealer += getCardValue(*cardPtr++);
		
		if (totalDealer > 21 && aceCounterD > 0)
		{
			totalDealer = totalDealer - 10;
			--aceCounterD;
		}

		std::cout << "A kartyak osszege az osztonal " << totalDealer << '\n';
	}

	if (totalDealer > 21)
		return ResultCodes::WIN;

	else if (totalPlayer == totalDealer)
		return ResultCodes::TIE;

	else if (totalPlayer > totalDealer)
		return ResultCodes::WIN;

	else if (totalPlayer < totalDealer)
		return ResultCodes::LOSE;

}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	std::array<Card, 52> deck;
	int card = 0;
	for (int suit = 0; suit < CardSuits::MAX_SUITS; ++suit)
		for (int rank = 0; rank < CardRanks::MAX_RANKS; ++rank)
			{
				deck[card].suit = static_cast<CardSuits>(suit);
				deck[card].rank = static_cast<CardRanks>(rank);
				++card;
			}

	printDeck(deck);

	std::cout << "\n";

	shuffleDeck(deck);
	printDeck(deck);

	std::cout << "\n";

	switch (playBlackJack(deck))
	{
	case ResultCodes::WIN:
		std::cout << "Gyoztel!\n";
		return 0;
	case ResultCodes::LOSE:
		std::cout << "Veszitettel!\n";
		return 0;
	case ResultCodes::TIE:
		std::cout << "Dontetlen!\n";
		return 0;
	}
}*/

//5
/*
Most írd újra az egész blackjack játékot classok segítségével.
*/

enum ResultCodes
{
	WIN,
	LOSE,
	TIE,
};

class Card
{
public:
	enum CardRanks
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS,
	};

	enum CardSuits
	{
		SUIT_CLUBS,
		SUIT_DIAMONDS,
		SUIT_HEARTS,
		SUIT_SPADES,
		MAX_SUITS,
	};

private:
	CardRanks m_rank;
	CardSuits m_suit;

public:
	Card(CardRanks rank = Card::RANK_2, CardSuits suit=Card::SUIT_SPADES) : m_rank(rank), m_suit(suit)
	{
		
	}

	void printCard() const
	{
		switch (m_rank)
		{
		case RANK_2:
			std::cout << "2"; break;
		case RANK_3:
			std::cout << "3"; break;
		case RANK_4:
			std::cout << "4"; break;
		case RANK_5:
			std::cout << "5"; break;
		case RANK_6:
			std::cout << "6"; break;
		case RANK_7:
			std::cout << "7"; break;
		case RANK_8:
			std::cout << "8"; break;
		case RANK_9:
			std::cout << "9"; break;
		case RANK_10:
			std::cout << "10"; break;
		case RANK_JACK:
			std::cout << "J"; break;
		case RANK_QUEEN:
			std::cout << "Q"; break;
		case RANK_KING:
			std::cout << "K"; break;
		case RANK_ACE:
			std::cout << "A"; break;
		default:
			std::cout << "???"; break;
		}

		switch (m_suit)
		{
		case SUIT_CLUBS:
			std::cout << "C"; break;
		case SUIT_DIAMONDS:
			std::cout << "D"; break;
		case SUIT_HEARTS:
			std::cout << "H"; break;
		case SUIT_SPADES:
			std::cout << "S"; break;
		default:
			std::cout << "???"; break;
		}
	}

	int getCardValue() const
	{
		switch (m_rank)
		{
		case RANK_2:
			return 2;
		case RANK_3:
			return 3;
		case RANK_4:
			return 4;
		case RANK_5:
			return 5;
		case RANK_6:
			return 6;
		case RANK_7:
			return 7;
		case RANK_8:
			return 8;
		case RANK_9:
			return 9;
		case RANK_10:
			return 10;
		case RANK_JACK:
			return 10;
		case RANK_QUEEN:
			return 10;
		case RANK_KING:
			return 10;
		case RANK_ACE:
			return 11;

		default:
			return 0;
		}
	}
};

#include <array>
#include <ctime>
#include <cstdlib>
#include <assert.h>

class Deck
{
private:
	std::array<Card, 52> m_deck;
	int m_cardIndex{ 0 };

public:
	Deck()
	{
		int card = 0;
		for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
			for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
			{
				m_deck[card] = Card(static_cast<Card::CardRanks>(rank), static_cast<Card::CardSuits>(suit));
				++card;
			}
	}

	void printDeck() const
	{
		for (const auto &card : m_deck)
		{
			card.printCard();
			std::cout << ' ';
		}
	}

private:
	static void swapCard(Card &f, Card &s)
	{
		Card temp = f;
		f = s;
		s = temp;
	}

	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

public:
	void shuffleDeck()
	{
		for (int index = 0; index < 52; ++index)
		{
			int random = getRandomNumber(0, 51);
			swapCard(m_deck[index], m_deck[random]);
		}
		m_cardIndex = 0;
	}

	const Card& dealCard()
	{
		assert(m_cardIndex < 52);
		return m_deck[m_cardIndex++];
	}

	ResultCodes playBlackJack()
	{
		int totalPlayer = 0;
		int totalDealer = 0;
		int aceCounterP = 0;
		int aceCounterD = 0;

		if (m_deck[m_cardIndex].getCardValue() == 11)
			++aceCounterD;
		totalDealer += dealCard().getCardValue();
		std::cout << "A kartyak osszege az osztonal " << totalDealer << '\n';

		if (m_deck[m_cardIndex].getCardValue() == 11)
			++aceCounterP;
		totalPlayer += dealCard().getCardValue();
		if (m_deck[m_cardIndex].getCardValue() == 11)
			++aceCounterP;
		totalPlayer += dealCard().getCardValue();
		std::cout << "A kartyak osszege jelenleg " << totalPlayer << '\n';

		// player goes first

		while (1)
		{
			std::cout << "Kersz tobb kartyat? H-igen, S-maradok. \n";
			char bill;
			std::cin >> bill;
			if (bill == 'h')
			{
				totalPlayer += dealCard().getCardValue();
				std::cout << "A kartyak osszege jelenleg " << totalPlayer << '\n';
				if (m_deck[m_cardIndex].getCardValue() == 11)
					++aceCounterP;
			}
			if (bill == 's')
			{
				std::cout << "A kartyak osszege jelenleg " << totalPlayer << '\n';
				break;
			}

			while (totalPlayer > 21 && aceCounterP > 0)
			{
				totalPlayer = totalPlayer - 10;
				--aceCounterP;
				std::cout << "A kartyak osszege jelenleg " << totalPlayer << '\n';
			}

			if (totalPlayer > 21)
				return ResultCodes::LOSE;
		}

		// dealer goes second

		while (totalDealer < 17)
		{
			if (m_deck[m_cardIndex].getCardValue() == 11)
				++aceCounterD;
			totalDealer += dealCard().getCardValue();

			if (totalDealer > 21 && aceCounterD > 0)
			{
				totalDealer = totalDealer - 10;
				--aceCounterD;
			}

			std::cout << "A kartyak osszege az osztonal " << totalDealer << '\n';
		}

		if (totalDealer > 21)
			return ResultCodes::WIN;

		else if (totalPlayer == totalDealer)
			return ResultCodes::TIE;

		else if (totalPlayer > totalDealer)
			return ResultCodes::WIN;

		else if (totalPlayer < totalDealer)
			return ResultCodes::LOSE;

	}
};

int main()
{
	/*std::cout << "\nAz elso teszt\n";
	const Card cardQueenHearts(Card::RANK_QUEEN, Card::SUIT_HEARTS);
	cardQueenHearts.printCard();
	std::cout << "\nA sziv kiralyno erteke: " << cardQueenHearts.getCardValue() << " \n";

	std::cout << "\n**********\n";

	std::cout << "\nA masodik teszt\n";
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Deck deck;
	deck.printDeck();
	std::cout << "\n**********\n";
	deck.shuffleDeck();
	deck.printDeck();
	std::cout << "\n**********\n";

	std::cout << "\nA harmadik teszt\n";
	std::cout << "\nAz elso kartya erteke: " << deck.dealCard().getCardValue() << '\n';
	std::cout << "\nA masodik kartya erteke: " << deck.dealCard().getCardValue() << '\n';

	std::cout << "\nA negyedik teszt\n";*/

	srand(static_cast<unsigned int>(time(0)));
	rand();

	Deck deck;
	deck.printDeck();
	std::cout << "\n-------------\n";
	deck.shuffleDeck();
	deck.printDeck();
	std::cout << "\n-------------\n";

	switch (deck.playBlackJack())
	{
	case ResultCodes::WIN:
		std::cout << "Gyoztel!\n";
		return 0;
	case ResultCodes::LOSE:
		std::cout << "Veszitettel!\n";
		return 0;
	case ResultCodes::TIE:
		std::cout << "Dontetlen!\n";
		return 0;

	}
	
}
