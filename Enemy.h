/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemy.h
 * Author: alexei
 *
 * Created on 1 de mayo de 2017, 16:55
 */
#include "Sprite.hpp"
#include "Clock.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef ENEMY_H
#define ENEMY_H

class Personaje;

class Enemy {
public:
    Enemy(int id, int inix, int iniy, int tAtaque);
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    
    Sprite* render(int est, int32_t tempo);
    void move(int i);
    int perseguir(Personaje *p);
    void herir(int h);
    void atacar(Personaje *p);
    int getDireccion();
    int getXCoordinate();
    int getYCoordinate();
    Sprite* getAnimacionActiva();
private:
    Sprite *spriteActual;
    Sprite *idle;
    Sprite *idleleft;
    Sprite *moveright;
    Sprite *moveleft;
    Sprite *ataqueRight;
    Sprite *ataqueLeft;
    Sprite *muerte;
    
    int x, y;
    float sx, sy;
    
    int vida;
    int direccion;
    
    int32_t ataquetime;
    
    int  danyoAtaque;
};

#endif /* ENEMY_H */

