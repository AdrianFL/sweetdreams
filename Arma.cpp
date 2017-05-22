#include "Arma.h"
#include <iostream>
#include "Sprite.hpp"


    Arma::Arma(std::string t, int x, int y){

        if(t=="e"){
            tipo="espada";
            danyo=25;
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
            
            std::string ruta3("resources/Mort.png");
            int coorda3[24]={5, 697, 72, 66, 79, 688, 66, 75, 166, 694, 93, 68, 273, 696, 76, 64, 354, 698, 65, 63};
            attackrightmort=new Sprite(ruta3, coorda3, 6);
            attackrightmort->set_framerate(75);
            int coorda4[24]={77, 697, -72, 66, 145, 688, -66, 75, 259, 694, -93, 68, 349, 696, -76, 64, 419, 698, -65, 63};
            attackleftmort=new Sprite(ruta3, coorda4, 6);
            attackleftmort->set_framerate(75);
        }
        else if(t=="h"){
            tipo="hacha";
            danyo=15;
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
        if(t=="espada"){
            tipo="espada";
            danyo=25;
        }
        else if(t=="hacha"){
            tipo="hacha";
            danyo=15;
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
    
    Sprite* Arma::getAttackRight(int id){
        if(id==0){
            return attackright;
        }
        else if(id==1){
            return attackrightmort;
        }
    }
    
    Sprite* Arma::getAttackLeft(int id){
        if(id==0){
            return attackleft;
        }
        else if(id==1){
            return attackleftmort;
        }
    }
    
    void Arma::cambiarPos(int x, int y){
        posx=x;
        posy=y;
        spritearma->set_position(posx, posy);
        
    }