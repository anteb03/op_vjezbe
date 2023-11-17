#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

class Card {
public:
    string suit;
    string label;

    vector<string> suits = { "S", "B", "D", "C" };
    vector<string> labels = { "1", "2", "3", "4", "5", "6", "7", "11", "12", "13" };

    Card(const string& s, const string& l) : suit(s), label(l) {}

    Card() {
        shuffleLabelsAndSuits();
    }

    void shuffleLabelsAndSuits() {
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(suits.begin(), suits.end());
        random_shuffle(labels.begin(), labels.end());
    }
};

class Deck {
public:
    vector<Card> cards;

    Deck() {
        initializeDeck();
        shuffle();
    }

    void initializeDeck() {
        cards.clear();
        for (const auto& suit : Card().suits) {
            for (const auto& label : Card().labels) {
                cards.push_back(Card{ suit, label });
            }
        }
    }

    void shuffle() {
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(cards.begin(), cards.end());
    }

    bool isEmpty() const {
        return cards.empty();
    }

    Card dealCard() {
        Card dealtCard = cards.back();
        cards.pop_back();
        return dealtCard;
    }
};

class Player {
public:
    string name;
    vector<Card> hand;

    Player(const string& n) : name(n) {} 

    void receiveCard(const Card& card) {
        hand.push_back(card);
    }

    int calculatePoints() const {
        int points = 0;
        if (hasNapolitana()) {
            points += 3;
        }
        points += countAkuzaPoints();
        return points;
    }

    int countAkuzaPoints() const {
        int countA = 0;
        int count2 = 0;
        int count3 = 0;
        for (const auto& card : hand) {
            if (card.label == "1") {
                countA++;
            }
            else if (card.label == "2") {
                count2++;
            }
            else if (card.label == "3") {
                count3++;
            }
        }
        int akuzaCount = 0;
        if (countA == 3) {
            akuzaCount+=3;
        }
        if (count2 == 3) {
            akuzaCount+=3;
        }
        if (count3 == 3) {
            akuzaCount+=3;
        }
        if (countA == 4) {
            akuzaCount+=4;
        }
        if (count2 == 4) {
            akuzaCount+=4;
        }
        if (count3 == 4) {
            akuzaCount+=4;
        }
        return akuzaCount;
    }

    bool hasAkuza() {
        int countA = 0;
        int count2 = 0;
        int count3 = 0;
        for (const auto& card : hand) {
            if (card.label == "1") {
                countA++;
            }
            else if (card.label == "2") {
                count2++;
            }
            else if (card.label == "3") {
                count3++;
            }
        }
        if (countA >= 3 || count2 >= 3 || count3 >= 3) {
            return true;
        }
        return false;
    }
    bool hasNapolitana() const{
        for (const auto& suit : Card().suits) {
            bool hasA = false;
            bool has2 = false;
            bool has3 = false;

            for (const auto& card : hand) {
                if (card.suit == suit) {
                    if (card.label == "1") {
                        hasA = true;
                    }
                    else if (card.label == "2") {
                        has2 = true;
                    }
                    else if (card.label == "3") {
                        has3 = true;
                    }
                }
            }
            if (hasA && has2 && has3) {
                return true;
            }
        }
        return false;
    }
    
};

int main() {
    int numPlayers;
    cout << "Unesite broj igrača (2 ili 4): ";
    cin >> numPlayers;

    if (numPlayers != 2 && numPlayers != 4) {
        cout << "Greška: Dozvoljeni brojevi igrača su samo 2 ili 4." << endl;
        return 1;
    }

    vector<Player> players;

    for (int i = 0; i < numPlayers; i++) {
        string playerName;
        cout << "Unesite ime igrača " << i + 1 << ": ";
        cin >> playerName;
        players.push_back(Player(playerName));
    }

    Deck deck;

    deck.initializeDeck();
    Card().shuffleLabelsAndSuits();

    int cardsPerPlayer = 10;
    for (int i = 0; i < numPlayers; i++) {
        cout << players[i].name << endl;

        for (int j = 0; j < cardsPerPlayer; j++) {
            deck.shuffle();

            if (!deck.isEmpty()) {
                Card card = deck.dealCard();
                players[i].receiveCard(card);
            }
            else {
                cout << "Greška: Špil je prazan. Nemoguće je djeliti karte svakom igraču." << endl;
                return 1;
            }
        }

        for (const auto& card : players[i].hand) {
            cout << card.label << card.suit << " ";
        }
        cout << " Bodovi: " << players[i].calculatePoints();

        if (players[i].hasAkuza()) {
            cout << " | Ima Akuzu!";
        }

        if (players[i].hasNapolitana()) {
            cout << " | Ima Napolitanu!";
        }
     
        cout << endl << endl; 
    }
    return 0;
}
