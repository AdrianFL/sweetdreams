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
        
        Sprite *attackrightmort;
        
        Sprite *attackleftmort;
        
        
    
    public:
    
        Arma(std::string t, int x, int y);
        
        Arma(std::string);
            
        int getDanyo();
        
        int getposY();
        
        int getposX();
        
        std::string getTipo();
        
        Sprite* getSprite();

        Sprite* getAttackRight(int id);
        
        Sprite* getAttackLeft(int id);
        
        void cambiarPos(int x, int y);
        
        
};

#endif