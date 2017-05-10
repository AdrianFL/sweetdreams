
#include <iostream>
#include "Sprite.hpp"


#ifndef POCION_H
#define POCION_H

class Pocion{
    
    private:
    
        std::string tipo;
        
        int tamanyo;
        
        int posY;
        
        int posX;
        
        Sprite *spritepocion;
    
        
    
    public:
    
        Pocion(std::string t, int x, int y);
        
        int getTamanyo();
        
        std::string getTipo();
         
        Sprite* getSprite();
        
        void deletePocion();
        
        sf::FloatRect getPosicion();
        
            
};

#endif
