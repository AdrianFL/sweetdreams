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
        
        Sprite *spritearma;
        
        Sprite *attackright;
        
        Sprite *attackleft;
        
        
    
    public:
    
        Arma(std::string t, int x, int y);
            
        int getDanyo();
        
        int getposY();
        
        int getposX();
        
        std::string getTipo();
        
        Sprite* getSprite();

        Sprite* getAttackRight();
        
        Sprite* getAttackLeft();
        
        
};

#endif