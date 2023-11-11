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
    vector<string> labels = { "A", "2", "3", "4", "5", "6", "7", "J", "Q", "K" };

    Card(const string& s, const string& l) : suit(s), label(l) {}

    Card() {
        shuffleLabelsAndSuits();
    }

    void shuffleLabelsAndSuits() {
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

    int calculatePoints() {
        int points = 0;
        int whiteCount = 0;
        for (const auto& card : hand) {
            if (card.label == "K" || card.label == "Q" || card.label == "J") {
                whiteCount++;
            }
        }
        if (whiteCount >= 3) {
            points += 1;
        }

        for (const auto& card : hand) {
            if (card.label == "A" || card.label == "3" || card.label == "2") {
                points += 1;
            }
        }

        return points;
    }
    bool hasAkuza() const {
        int countA = 0;
        int count2 = 0;
        int count3 = 0;
        for (const auto& card : hand) {
            if (card.label == "A") {
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
    bool hasNapolitana() {
        for (const auto& suit : Card().suits) {
            bool hasA = false;
            bool has2 = false;
            bool has3 = false;

            for (const auto& card : hand) {
                if (card.suit == suit) {
                    if (card.label == "A") {
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
                cout << "Greška: Špil je prazan. Nemoguće je deliti karte svakom igraču." << endl;
                return 1;
            }
        }

        for (const auto& card : players[i].hand) {
            cout << card.label << card.suit << " ";
        }
        cout << " Bodovi: " << players[i].calculatePoints();

        if (players[i].hasAkuza()) {
            cout << " | Ima Akuza!";
        }

        if (players[i].hasNapolitana()) {
            cout << " | Ima Napolitanu!";
        }
     
        cout << endl << endl; 
    }
    return 0;
}