/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hechizo.h
 * Author: adrian
 *
 * Created on 20 de mayo de 2017, 18:21
 */

#ifndef HECHIZO_H
#define HECHIZO_H


#include <iostream>
#include "Sprite.hpp"

class Hechizo{
     
    private:
    
        std::string tipo;
        
        int danyo;
        
        int gastoMana;
        
        int posX;
        
        int posY;
        
        Sprite *spritehechizo;
        
        Sprite *hechizoright;
        
        Sprite *hechizoleft;

        Sprite *hechizorightmort;
        
        Sprite *hechizoleftmort;
    public:
    
        Hechizo(std::string t, int x, int y);
        
        Hechizo(std::string t);
 
        int getDanyo();
        
        int getGastoMana();
        
        int getPosX();
        
        int getPosY();
        
        std::string getTipo();
        
        Sprite* getSpriteHechizo();
        
        Sprite* getHechizoRight(int id);
        
        Sprite* getHechizoLeft(int id);
        
        void cambiarPos(int x,int y);
};


#endif

