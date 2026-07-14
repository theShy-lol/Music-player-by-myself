#include<iostream>
#include<string>

class Enemy{

public:
    Enemy(std::string n, int h, int d);
    int get_dmg();
    int get_health();
    std::string get_name();
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
    std::cout<<"Take this!"<<this->damage<<" damage"<<std::endl;
}
void Enemy::take_dmg(int dmg){
    if(this->health <= 0){
        std::cout<<"Enemy dead";
    }
    std::cout<<"- "<<dmg<<std::endl;
    this->health -= dmg;
}
int Enemy::get_dmg(){
    return this->damage;
}
int Enemy::get_health(){
    return this->health;
}
std::string Enemy::get_name(){
    return this->name;
} 

