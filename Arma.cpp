#include "Arma.h"
#include <iostream>
#include "Sprite.hpp"


    Arma::Arma(std::string t, int x, int y){

        if(t=="e"){
            tipo="espada";
            danyo=15;
            posx=x;
            posy=y;
            
            int coord[4]={0, 0, 49 , 92};
            int f=1;
            std::string ruta("resources/sword.png");
            std::string ruta2("resources/Agony.png");
            spritearma = new Sprite(ruta, coord, f);
            spritearma->set_position(x, y);
            int coorda[32]={1456, 885, 44, 79, 1520, 884, 44, 79, 1565, 887, 44, 76, 1609, 907, 62, 60, 1674, 903, 58, 63, 1735, 916, 93, 51, 1837, 904, 70, 62, 1941, 904, 52, 62};
            attackright=new Sprite(ruta2, coorda, 8);
            attackright->set_framerate(75);
            int coorda2[32]={1500,885,-44,79,1564,884,-44,79,1609,887,-44,76,1671,907,-62,60,1732,903,-58,63, 1828, 916, -93, 51, 1907, 904, -70, 62, 1993, 904, -52, 62};
            attackleft=new Sprite(ruta2, coorda2, 8);
            attackleft->set_framerate(75);
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
    
    Arma::Arma(std::string t){
        if(t=="espaada"){
            tipo="espada";
            danyo=15;
        }
        else if(t=="hacha"){
            tipo="hacha";
            danyo=25;
        }
    }

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
    
    Sprite* Arma::getAttackRight(){
        return attackright;
    }
    
    Sprite* Arma::getAttackLeft(){
        return attackleft;
    }