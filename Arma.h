#ifndef ARMA_H
#define ARMA_H

//#include "pj.h"
#include <iostream>
#include "Sprite.hpp"


class Arma{
    
    private:
    
        std::string tipo;
    
        int danyo;
        
        int posx;
        
        int posy;
        
        int* coordarma;
        
        int* coordarmaleft;
        
        Sprite *spritearma;
        
    
    public:
    
        Arma(std::string t, int x, int y);
    
       // void quitaVida(Pj& p);
        
        int getDanyo();
        
        int getposY();
        
        int getposX();
        
        std::string getTipo();
        
        Sprite* getSprite();
        
        int* getCoordenadasSprite();
        
        int* getCoordenadasSpriteLeft();
        
        int getFrames();
        
        
};

#endif