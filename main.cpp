#include<iostream>
#include<string>
#include"Player.h"
#include"Enemy.h"





int main(){
    //Welcome
    std::cout<<"====== Welcome to a RPG like you never saw ======"<<std::endl;
    std::string name;
    std::cout<<"=====   Enter your name mate!   ======"<<std::endl;
    std::cin>>name;
    std::cout<<"======= Greetings"<<" "<<name<<" ====="<<std::endl;

    //Spawn enemy and player
    Player p{name, 100, 50, 20};
    Enemy e{"Goblin", 50, 10};
    Enemy t{"Thief", 40, 20};
    std::string option;
    bool isAliveEnemy = true;
    bool isAlivePlayer = true;

    std::cout<<"Round 1"<<std::endl;
    while(p.get_health() > 0 && option != "4"){
        std::cout<<"Choose your option: "<<std::endl;
        std::cout<<"1. Attack"<<std::endl;
        std::cout<<"2. Heal"<<std::endl;
        std::cout<<"3. Parry"<<std::endl;
        std::cout<<"4. Quit game"<<std::endl;
        std::cin>>option;
        std::cout<<"Current Health: "<<p.get_health()<<std::endl;
        std::cout<<"Enemy Health: "<<e.get_health()<<std::endl;
        if (option == "1"){
            p.attack();
            e.take_dmg(p.get_dmg());
        }
        else if(option == "2"){
            p.heal();
        }
        else if(option == "3"){
            p.parry(e.get_dmg());
        }
        else{
            std::cout<<"Exiting game..."<<std::endl;
        }
        if(e.get_health() <= 0){
            isAliveEnemy = false;
            std::cout<<"Enemy dead!"<<std::endl;
        }
        else{
            std::cout<<"===Enemy turn==="<<std::endl;
            e.attack();
            p.take_dmg(e.get_dmg());
        }
        if(isAliveEnemy == false){
            std::cout<<"==== Round 2 ===="<<std::endl;
            std::cout<<"New enemy arrived "<<"Thief!"<<std::endl;
            std::cout<<"=== Enemy turn ==="<<std::endl;
        }
    }
}

