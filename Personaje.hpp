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
#include <SFML/Graphics.hpp>
#include "Pocion.h"
#include "Enemy.h"
class Enemy;

class Personaje {
public:
    Personaje(int id);
    Sprite* render(int est, int32_t tempo);
    void move(int i);
    int getDireccion();
    int getXCoordinate();
    int getYCoordinate();
    int getVidaMax();
    int getManaMax();
    int getVida();
    int getMana();    
    void setMana(int i);
    void setVida(int i);
    void usaPocion(Pocion pocion);
    //bool cogeObjeto();
    int numeroPoc();
   // void setPociones(Pocion *pociones[5]); //para probar
    void herir(int dmg);
    void atacar(Enemy *e);
    Sprite* getAnimacionActiva();
    
private:
    Sprite *idle;
    Sprite *idleleft;
    Sprite *moveright;
    Sprite *moveleft;
    Sprite *attackright;
    Sprite *attackleft;
    
    int vida;
    int mana;
    int vidamax;
    int manamax;
    int numPVida;
    int numPMana;
    
    Pocion *bolsilloP[5];
    int x, y;
    float sx, sy;
    int activa;
    
    int32_t atctime;
    
    int direccion;
};

#endif /* PERSONAJE_HPP */

