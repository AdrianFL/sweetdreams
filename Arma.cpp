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
            spritearma = new Sprite(ruta, coord, f);
            spritearma->set_position(x, y);
            int coorda[32]={1456, 885, 44, 79, 1520, 884, 44, 79, 1565, 887, 44, 76, 1609, 907, 62, 60, 1674, 903, 58, 63, 1735, 916, 93, 51, 1837, 904, 70, 62, 1941, 904, 52, 62};
            coordarma=new int[32];
            for(int i=0; i<32; i++){
                coordarma[i]=coorda[i];
            }
            int coorda2[32]={1500,885,-44,79,1564,884,-44,79,1609,887,-44,76,1671,907,-62,60,1732,903,-58,63, 1828, 916, -93, 51, 1907, 904, -70, 62, 1993, 904, -52, 62};
            coordarmaleft=new int[32];
            for(int i=0; i<32; i++){
                coordarmaleft[i]=coorda2[i];
            }
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
    
    int* Arma::getCoordenadasSprite(){
        
        if(tipo=="espada"){
            return coordarma;
        }
        else if(tipo=="hacha"){
            
        }
        return NULL;
    }
    
    int* Arma::getCoordenadasSpriteLeft(){
        if(tipo=="espada"){
            return coordarmaleft;
        }
        else if(tipo=="hacha"){
            
        }
        return NULL;
    }
    
    int Arma::getFrames(){
        if(tipo=="espada"){
            return(8);
        }
        else if(tipo=="hacha"){
            return(8);
        }
    }