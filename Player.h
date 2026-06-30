#include<iostream>
#include<string.h>


class Player{

public:
    Player(std::string n, int h, int s, int d);
    int get_health();
    int get_dmg();
    void attack();
    void take_dmg(int dmg);
    void parry(int dmg);
    void heal();
private:
    std::string name;
    int health;
    int stamina;
    int damage;
};
Player::Player(std::string n, int h, int s, int d){
    this->name = n;
    this->health = h;
    this->stamina = s;
    this->damage = d;
}
void Player::attack(){
    std::cout<<"Attack"<<" "<<this->damage<<std::endl;
    this->stamina -= 5;
}
void Player::take_dmg(int dmg){
    std::cout<<"You took"<<" "<<dmg<<" damage"<<std::endl;
    this->health -= dmg;
}
void Player::parry(int dmg){
    std::cout<<"Damage deflected"<<std::endl;
    int parried = this->health - dmg * 0.5;
    std::cout<<parried<<std::endl;
    this->health - dmg * 0.5;
    this->stamina -= 3;
}
void Player::heal(){
    std::cout<<"Healing"<<std::endl;
    this->health += 25;
    this->stamina -= 5;
}
int Player::get_health(){
    return this->health;
}
int Player::get_dmg(){
    return this->damage;
}