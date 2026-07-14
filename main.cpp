#include<iostream>
#include<string>
#include"Player.h"
#include"Enemy.h"
#include<stdlib.h>
#include<vector>


int main(){
    //Welcome
    std::cout<<"====== Welcome to a RPG like you never saw ======"<<std::endl;
    std::string name;
    std::cout<<"=====   Enter your name mate!   ======"<<std::endl;
    std::cin>>name;
    std::cout<<"======= Greetings"<<" "<<name<<" ====="<<std::endl;

    //Spawn enemy and player
    Player p{name, 100, 50, 20};
    std::vector<Enemy> enemy = {
    Enemy{"Goblin", 50, 10},
    Enemy{"Thief", 40, 20},
    Enemy{"Dragon", 100,40}
    };
    for(int i = 0; i < enemy.size(); i++){
        Enemy& current_enemy = enemy[i];
        std::cout<<"You are facing a"<<" "
        <<current_enemy.get_name()<<std::endl;

        std::cout<<"Round "<<i + 1<<std::endl;
        std::string option;

        bool isAliveEnemy = true;
        bool isAlivePlayer = true;

        while(p.get_health() > 0 && enemy[i].get_health() > 0 && option != "4"){
            std::cout<<"Choose your option: "<<std::endl;
            std::cout<<"1. Attack"<<std::endl;
            std::cout<<"2. Heal"<<std::endl;
            std::cout<<"3. Parry"<<std::endl;
            std::cout<<"4. Quit game"<<std::endl;
            std::cin>>option;
            system("clear");
            std::cout<<"Current Health: "<<p.get_health()<<std::endl;
            if (option == "1"){
                p.attack();
                current_enemy.take_dmg(p.get_dmg());
                }
            else if(option == "2"){
                p.heal();
                }
            else if(option == "3"){
                p.parry(current_enemy.get_dmg());
                }
            else{
                std::cout<<"Exiting game..."<<std::endl;
                }
            if(current_enemy.get_health() <= 0){
                std::cout<<"Enemy dead!"<<std::endl;
                }
            else{
                std::cout<<"===Enemy turn==="<<std::endl;
                std::cout<<"Enemy Health: "<<current_enemy.get_health()<<std::endl;
                current_enemy.attack();
                p.take_dmg(current_enemy.get_dmg());
            }
            if(p.get_health() < 0){
                std::cout<<"Better luck next time..."<<std::endl<<
                "You died";
            }
        }
    }
}

