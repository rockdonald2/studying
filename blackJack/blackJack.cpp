#include <iostream>
#include <array>
#include <vector>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

enum class CardSuit {
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS
};

enum class CardRank {
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
	MAX_RANKS
};

enum class Verdict {
	VERDICT_LOST,
	VERDICT_DRAW,
	VERDICT_WON,
	MAX_VERDICTS
};

struct Card {
	CardSuit suit;
	CardRank rank;
};

class Blackjack {
private:
	std::array<Card, 52> m_deck;
	std::vector<Card> m_playerCards;
	std::vector<Card> m_dealerCards;

	int getRandomNumber(int min, int max) {
		static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	}

	char getPlayerChoice() {
		using namespace std;

		char choice;

		cout << "(h) to hit, or (s) to stand: ";

		do {
			cin >> choice;
		} while (choice != 'h' && choice != 's');

		return choice;
	}

	void swapCard(Card& a, Card& b) {
		Card temp = a;
		a = b;
		b = temp;
	}

	void shuffleDeck() {
		for (unsigned int index = 0; index < m_deck.size(); ++index) {
			swapCard(m_deck[index], m_deck[getRandomNumber(0, 51)]);
		}
	}

	bool evaluateGame(const Verdict& verdict) {
		using namespace std;

		if (verdict == Verdict::VERDICT_WON) {
			cout << "You win!";
			return true;
		}
		else if (verdict == Verdict::VERDICT_LOST) {
			cout << "You lost!";
			return false;
		}
		else if (verdict == Verdict::VERDICT_DRAW) {
			cout << "It's a draw!";
			return true;
		}
		else {
			return false;
		}
	}

	int getCardValue(const Card& card) {
		switch (card.rank) {
			case CardRank::RANK_2:  return 2;
			case CardRank::RANK_3:  return 3;
			case CardRank::RANK_4:  return 4;
			case CardRank::RANK_5:  return 5;
			case CardRank::RANK_6:  return 6;
			case CardRank::RANK_7:  return 7;
			case CardRank::RANK_8:  return 8;
			case CardRank::RANK_9:  return 9;
			case CardRank::RANK_10:  return 10;
			case CardRank::RANK_JACK:  return 10;
			case CardRank::RANK_QUEEN:  return 10;
			case CardRank::RANK_KING:  return 10;
			case CardRank::RANK_ACE:  return 11;
		}

		return 0;
	}

public:
	Blackjack() {
		int card = 0;

		for (unsigned int suit = 0; suit < static_cast<int>(CardSuit::MAX_SUITS); ++suit) {
			for (unsigned int rank = 0; rank < static_cast<int>(CardRank::MAX_RANKS); ++rank) {
				m_deck[card].suit = static_cast<CardSuit>(suit);
				m_deck[card].rank = static_cast<CardRank>(rank);

				++card;
			}
		}

		m_playerCards.reserve(26);
		m_dealerCards.reserve(26);
	}

	void printCard(const Card& card) {
		using namespace std;

		switch (card.rank) {
			case CardRank::RANK_2:  cout << '2'; break;
			case CardRank::RANK_3:  cout << '3'; break;
			case CardRank::RANK_4:  cout << '4'; break;
			case CardRank::RANK_5:  cout << '5'; break;
			case CardRank::RANK_6:  cout << '6'; break;
			case CardRank::RANK_7:  cout << '7'; break;
			case CardRank::RANK_8:  cout << '8'; break;
			case CardRank::RANK_9:  cout << '9'; break;
			case CardRank::RANK_10:  cout << 'T'; break;
			case CardRank::RANK_JACK:  cout << 'J'; break;
			case CardRank::RANK_QUEEN:  cout << 'Q'; break;
			case CardRank::RANK_KING:  cout << 'K'; break;
			case CardRank::RANK_ACE:  cout << 'A'; break;
		}

		switch (card.suit) {
			case CardSuit::SUIT_CLUB: cout << "C\n"; break;
			case CardSuit::SUIT_DIAMOND: cout << "D\n"; break;
			case CardSuit::SUIT_HEART: cout << "H\n"; break;
			case CardSuit::SUIT_SPADE: cout << "S\n"; break;
		}
	}

	void printDeck() {
		using namespace std;

		for (const auto& card : m_deck) {
			printCard(card);
			cout << ' ';
		}

		std::cout << '\n';
	}

	void playBlackjack() {
		using namespace std;

		shuffleDeck();

		const Card* cardPtr = &m_deck[0];

		int playerTotal = 0;
		int dealerTotal = 0;

		m_dealerCards.push_back(*cardPtr);
		printCard(*cardPtr);
		dealerTotal += getCardValue(*cardPtr++);
		cout << "The dealer is showing " << dealerTotal << endl;

		m_playerCards.push_back(*cardPtr);
		printCard(*cardPtr);
		playerTotal += getCardValue(*cardPtr++);
		m_playerCards.push_back(*cardPtr);
		printCard(*cardPtr);
		playerTotal += getCardValue(*cardPtr++);

		while (true) {
			cout << "The player is showing " << playerTotal << endl;

			char choice = getPlayerChoice();

			if (choice == 'h') {
				m_playerCards.push_back(*cardPtr);
				printCard(*cardPtr);
				playerTotal += getCardValue(*cardPtr++);
			}
			else if (choice == 's') {
				break;
			}

			if (playerTotal > 21) {
				cout << "The player is showing " << playerTotal << endl;
				evaluateGame(Verdict::VERDICT_LOST);
				return;
			}
		}

		while (dealerTotal < 17) {
			m_dealerCards.push_back(*cardPtr);
			printCard(*cardPtr);
			dealerTotal += getCardValue(*cardPtr++);
			cout << "The dealer is showing " << dealerTotal << endl;
		}

		if (dealerTotal > 21) {
			evaluateGame(Verdict::VERDICT_WON);
			return;
		}

		if (playerTotal > dealerTotal) {
			evaluateGame(Verdict::VERDICT_WON);
			return;
		}
		else if (playerTotal < dealerTotal) {
			evaluateGame(Verdict::VERDICT_LOST);
			return;
		}
		else {
			evaluateGame(Verdict::VERDICT_DRAW);
			return;
		}
	}
};


int main() {
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Blackjack newGame;
	newGame.playBlackjack();

	return 0;
}