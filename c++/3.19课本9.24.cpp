#include <iostream>
#include <algorithm>
using namespace std;

class Card {
public:
	int face;
	int suit;
	Card(int a=0, int b=0) :face(a), suit(b) {

	}
	static string faces[13];
	static string suits[4];
	string toString() {
		return faces[face] + " of " + suits[suit];
	}
};
string Card::faces[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
string Card::suits[4] = { "Hearts","Diamonds","Spades","Clubs" };

class DeckOfCards {
public:
	Card deck[52];
	int currentCard;
	DeckOfCards() {
		currentCard = 0;
		for (int i = 0; i < 52; i++) {
			deck[i] = { i / 4,i % 4 };
		}
	}
	void shuffle() {
		Card temp;
		for(int i = 0; i < 52; i++) {
			int r = rand() % 52;
			temp = deck[r];
			deck[r] = deck[i];
			deck[i] = temp;
		}
	}
    Card* dealcard(){
		currentCard += 5;
		return &deck[currentCard - 5];
	}
	bool moreCards() {
		if (currentCard < 47) {
			return 1;
		}
		else {
			return 0;
		}
	}
};
bool CheckPair(Card(& a)[5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (a[i].face==a[j].face) {
				return 1;
			}
		}
	}
	return 0;
}
bool CheckTwoPairs(Card(&a)[5]) {
	int pairs = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (a[i].face == a[j].face) {
				pairs++;
				if (pairs == 2) {
					return true;
				}
			}
		}
	}
	return false;
}
bool CheckThreeOfAKind(Card(&a)[5]) {
	for (int i = 0; i < 5; i++) {
		int count = 0;
		for (int j = 0; j < 5; j++) {
			if (a[i].face == a[j].face) {
				count++;
				if (count == 3) {
					return true;
				}
			}
		}
	}
	return false;
}
bool CheckFourOfAKind(Card(&a)[5]) {
	for (int i = 0; i < 5; i++) {
		int count = 0;
		for (int j = 0; j < 5; j++) {
			if (a[i].face == a[j].face) {
				count++;
				if (count == 4) {
					return true;
				}
			}
		}
	}
	return false;
}
bool CheckFlush(Card(&a)[5]) {
	for (int i = 1; i < 5; i++) {
		if (a[i].suit != a[0].suit) {
			return false;
		}
	}
	return true;
}
bool CheckStraight(Card(&a)[5]) {
	int values[5];
	for (int i = 0; i < 5; i++) {
		values[i] = a[i].face;
	}
	std::sort(values, values + 5);
	for (int i = 0; i < 4; i++) {
		if (values[i] + 1 != values[i + 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	DeckOfCards deck;
	deck.shuffle();
	Card hand[5];
	Card* a = deck.dealcard();
	for (int i = 0; i < 5; i++) {
		hand[i] = *(a + i);
		cout << hand[i].toString() << endl;
	}

	cout << "Check Pair: " << (CheckPair(hand) ? "Yes" : "No") << endl;
	cout << "Check Two Pairs: " << (CheckTwoPairs(hand) ? "Yes" : "No") << endl;
	cout << "Check Three of a Kind: " << (CheckThreeOfAKind(hand) ? "Yes" : "No") << endl;
	cout << "Check Four of a Kind: " << (CheckFourOfAKind(hand) ? "Yes" : "No") << endl;
	cout << "Check Flush: " << (CheckFlush(hand) ? "Yes" : "No") << endl;
	cout << "Check Straight: " << (CheckStraight(hand) ? "Yes" : "No") << endl;

	return 0;
}
