#include "Arma.h"
#include <iostream>
#include "Sprite.hpp"


    Arma::Arma(std::string t, int x, int y){

        if(t=="e"){
            tipo="espada";
            danyo=15;
            
            /*
            int coord[4]={0, 0, , };
            int f=1;
            std::string ruta("resources/espada.png");
            spritearma = new Sprite(ruta, coord, f);
            spritearma->set_position(x, y);
             */
        }
        else if(t=="h"){
            tipo="hacha";
            danyo=25;
            posx=x;
            posy=y;
            
            int coord[4]={0, 0, 68, 57};
            int f=1;
            std::string ruta("resources/hacha.png");
            spritearma = new Sprite(ruta, coord, f);
            spritearma->set_position(x, y);
            
        }

    }

    /*void Arma::quitaVida(Pj& p){
       
            if(p.vida>this->getDanyo()){
                p.vida=p.vida-this->getDanyo();
            }
            else{
                p.vida=0;
            }
            
    }*/
    

    int Arma::getDanyo(){
        return danyo;
    }
    
    std::string Arma::getTipo(){
        return tipo;
    }
    
    int Arma::getposY(){
        return posy;
    }
    
    int Arma::getposX(){
        return posx;
    }
    
    Sprite* Arma::getSprite(){
        return(spritearma);
    }