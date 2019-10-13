#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>

using namespace std;

struct Properties
{
    float health; //health
    float attack; //chance of attack
    float damage; //damage it does
};


class Game
{
private:
    int human;
    int zombie;
    
public:
    Game();
    int setHuman();
    int setZombie();
    void playgame();
    Properties Humans_Prop();
   
};

Game::Game()
{
    human=0;
    zombie=0;
}

int Game:: setHuman()
{
    int x;
    
    cout<<"Enter the number of humans: ";
    cin>>x;
    
    return x;
}

int Game:: setZombie()
{
    int y;
    
    cout<<"Enter the number of zombies: ";
    cin>>y;
    return y;
}

Properties Game:: Humans_Prop()
{
    Properties human;
    human.health=250.0f; //health
    human.attack=0.6f; //chance of attack
    human.damage=200.0f; //damage it does
    
    return human;
}


void Game:: playgame()
{
    default_random_engine randomEngine( static_cast<unsigned int> (time(NULL)));
    uniform_real_distribution<float> attack(0.0f, 1.0f);
    
    cout<<"*** Welcome to the combat simulator! *** "<<endl;
    
    human=setHuman();
    zombie=setZombie();
    
    //store initial vals
    
    const int iniH=human;
    const int iniZ=zombie;

    float current_H_health=Humans_Prop().health;
    
    //zombie properties
    float zombie_health=50.0;
    float zombie_attack=0.3f;
    float zombie_damage=40.0f;
    float current_Z_health=zombie_health;
    
    
    float attackresult;
    char turn='H';
    
    while( (human>0) && (zombie>0))
    {
         attackresult=attack(randomEngine);
        
        if(turn=='H')
        {
            
            if(attackresult<=Humans_Prop().attack)
            {
                current_Z_health-=Humans_Prop().damage;
                
                if(current_Z_health<0)
                {
                    zombie--;
                    current_Z_health=zombie_health;
                }
            }
            
            turn='Z';

        }
        else
        {
            if(attackresult<=zombie_attack)
            {
                current_H_health-=zombie_damage;
                
                if(current_H_health<0)
                {
                    human--;
                    current_H_health=Humans_Prop().health;
                }
            }
             turn='H';
        }
    }
    
    if(zombie>human)
    {
        cout<<endl;
        cout<<"*** RESULT ***"<<endl;
        cout<<endl;

        cout<<"Zombies have won!!"<<endl;
        cout<<zombie<<" zombies are alive."<<endl;
        cout<<iniZ-zombie<<" zombies were killed."<<endl;
        cout<<endl;
        cout<<iniH<<" humans were killed."<<endl;
        cout<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"*** RESULT ***"<<endl;
        cout<<endl;

        cout<<"Humans have won!!"<<endl;
        cout<<endl;

        cout<<human<<" humans are left."<<endl;
        cout<<iniH-human<<" humans were killed."<<endl;
        cout<<endl;
        cout<<iniZ<<" zombies were killed."<<endl;
        cout<<endl;
    }
    
}

int main()
{
    Game g;
    g.playgame();
    
    Game g1;
    g1.playgame();
}
