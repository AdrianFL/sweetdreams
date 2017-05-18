

#include "Pocion.h"
#include "Sprite.hpp"


    Pocion::Pocion(std::string t, int x, int y){
        
        if(t=="v"){
            tipo= "vida";
            tamanyo=30;
            posX=x;
            posY=y;
            
            
            int coord[4]={0, 0, 68, 56};
            int f=1;
            std::string ruta("resources/vida.png");
            spritepocion = new Sprite(ruta, coord, f);
            spritepocion->set_position(x, y);
            
        }
        else if(t=="m"){
            tipo="mana";
            tamanyo=20;
            posX=x;
            posY=y;
            
            int coord[4]={0, 0, 60, 64};
            int f=1;
            std::string ruta("resources/mana.png");
            spritepocion = new Sprite(ruta, coord, f);
            spritepocion->set_position(x, y);
            
        }

    }
 
    
    int Pocion::getTamanyo(){
        return tamanyo;
    }
    
    std::string Pocion::getTipo(){
        return tipo;
    }
    
    Sprite* Pocion::getSprite(){
        return spritepocion;
    }
    
    //Esto esta mal creo
    void Pocion::deletePocion(){     
        delete this;
    }
    
    int Pocion::getPosX(){
        return posX;
    }
    
    int Pocion::getPosY(){
        return posY;
    }
    
    int Pocion::getCantidad(std::string s){
        if(s=="vida"){
            return 30;
        }
        else if(s=="mana"){
            return 20;
        }
    }