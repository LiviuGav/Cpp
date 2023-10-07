#pragma once
class Character
{
private:
    std::string name;
    int health;
    int mana;
    int attack;
    int defense;

public:
    // Constructor
    Character(std::string n, int h, int m, int a, int d)
        : name(n), health(h), mana(m), attack(a), defense(d) {}

    // Getter methods
    std::string getName()
    {
        return name;
    }
    int getHealth()
    {
        return health;
    }
    int getMana()
    {
        return mana;
    }
    int getAttack()
    {
        return attack;
    }
    int getDefense()
    {
        return defense;
    }

    // Setter methods
    void setName(std::string n)
    {
        name = n;
    }
    void setHealth(int h)
    {
        health = h;
        if (health < 0)
            health = 0;
    }
    void setMana(int m)
    {
        mana = m;
    }
    void setAttack(int a)
    {
        attack = a;
    }
    void setDefense(int d)
    {
        defense = d;
    }

    // Additional methods (e.g., attack, useItem, etc.)
    void Attack(Character& target)
    {
        int damage = attack - target.getDefense();
        if (damage > 0)
        {
            target.setHealth(target.getHealth() - damage);
            std::cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
            std::cout << target.getName() << "'s health: " << target.getHealth() << std::endl;
        }
        else
        {
            std::cout << name << " attacks " << target.getName() << " but it has no effect!\n";
            std::cout << target.getName() << "'s health: " << target.getHealth() << std::endl;
        }
    }
};