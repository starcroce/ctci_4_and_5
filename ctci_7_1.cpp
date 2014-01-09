enum suit{
	SPADE, HEART, CLUB, DIAMOND
};

class Card{
private:
	int val;
	suit su;
	bool available;
public:
	card(){
		available = true;
	}
	setCard(int v, suit s){
		val = v;
		su = s;
		available = true;
	}
	int getValue(){
		return val;
	}
	suit getSuit(){
		return su;
	}
	bool isAvailable(){
		return available;
	}
	void markUnavailable(){
		available = false;
	}
	void markAvailable(){
		available = true;
	}
};

class Deck{
private:
	vector<Card> deck;
	int used;
public:
	deck(){
		for(int i=0; i<13; i++){
			for(int j=0; j<4; j++){
				deck.push_back(setCard(i, (suit)j));
			}
		}
		used = 0;
	}
	void suffle(){
		srand((unsigned)time(NULL));
		for(int i=0; i<deck.size(); i++){
			int j = rand()%(deck.size()-i)+i;
			Card tmp = deck[i];
			deck[i] = deck[j];
			deck[j] = tmp;
		}
	}
	int remainCards(){
		return deck.size()-used;
	}
	Card dealCard(){
		Card c = deck[used];
		deck[used].markUnavailable();
		used++;
		return c;
	}
};