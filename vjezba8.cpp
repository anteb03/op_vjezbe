#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class Enemy {
protected:
    string name;
    int health;
    int damage;

public:
    Enemy(const string& n, int h, int d) : name(n), health(h), damage(d) {
        if (health < 0 || damage < 0) {
            throw invalid_argument("Health or damage cannot be negative.");
        }
    }
    virtual void attack() = 0;
    virtual void displayInfo() = 0;
};

class Boss : public Enemy {
private:
    string weapon;

public:
    Boss(const string& n, int h, int d, const string& w) : Enemy(n, h, d), weapon(w) {
        if (weapon.empty()) {
            throw invalid_argument("Weapon cannot be empty.");
        }
    }
    void attack() override {
        cout << name << " attacks with " << weapon << " and deals " << damage << " damage.\n";
    }
    void displayInfo() override {
        cout << "Boss: " << name << ", Health: " << health << ", Damage: " << damage << ", Weapon: " << weapon << "\n";
    }
};

class Monster : public Enemy {
private:
    string specialAbility;

public:
    Monster(const string& n, int h, int d, const string& ability) : Enemy(n, h, d), specialAbility(ability) {
        if (specialAbility.empty()) {
            throw invalid_argument("Special ability cannot be empty.");
        }
    }
    void attack() override {
        cout << name << " attacks using " << specialAbility << " and deals " << damage << " damage.\n";
    }
    void displayInfo() override {
        cout << "Monster: " << name << ", Health: " << health << ", Damage: " << damage << ", Special Ability: " << specialAbility << "\n";
    }
};

int main() {
    vector<Enemy*> enemies;
    try {
        enemies.push_back(new Boss("Boss1", 100, 20, "Sword"));
        enemies.push_back(new Monster("Monster1", 80, 50, "Fire Breath"));
        enemies.push_back(new Boss("Boss2", 10, 30, "Axe")); 
        for (Enemy* enemy : enemies) {
            try {
                enemy->attack();
                enemy->displayInfo();
                delete enemy;
            } catch (invalid_argument& e) {
                cout << e.what() << "\n";
            }
        }
    } catch (const bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << "\n";
    }
    return 0;
}