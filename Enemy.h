#include<iostream>
#include<string>

class Enemy{

public:
    Enemy(std::string n, int h, int d);
    int get_dmg();
    int get_health();
    void attack();
    void take_dmg(int dmg);
private:
    std::string name;
    int damage;
    int health;
};
Enemy::Enemy(std::string n, int h, int d){
    this->name = n;
    this->health = h;
    this->damage = d;
}
void Enemy::attack(){
    std::cout<<"Take this "<<this->damage<<std::endl;
}
void Enemy::take_dmg(int dmg){
    std::cout<<"- "<<dmg<<std::endl;
    this->health -= dmg;
}
int Enemy::get_dmg(){
    return this->damage;
}
int Enemy::get_health(){
    return this->health;
}