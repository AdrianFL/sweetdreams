/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.hpp
 * Author: adrian
 *
 * Created on 17 de marzo de 2017, 17:15
 */

#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include "Sprite.hpp"

class Personaje {
public:
    Personaje(int id);
    Sprite* render(int est);
    void move(int i);
    void atacar();
    Sprite* getAnimacionActiva();
    int getDireccion();
    int getXCoordinate();
    int getYCoordinate();
private:
    Sprite *idle;
    Sprite *idleleft;
    Sprite *moveright;
    Sprite *moveleft;
    Sprite *attackright;
    Sprite *attackleft;
    
    int x, y;
    float sx, sy;
    int vida, mana, vidamax, manamax;
    int activa;
    
    int direccion;
};

#endif /* PERSONAJE_HPP */

