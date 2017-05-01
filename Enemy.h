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
#include "Personaje.hpp"
#include <SFML/Graphics.hpp>

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(int id, int inix, int iniy, float tAtaque);
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    
    Sprite* render();
    void move(int i);
    void perseguir(Personaje* p);
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
    
    
    
    int x, y;
    float sx, sy;
    bool muerte;
    
    int direccion;
    float tiempoAtaque;
};

#endif /* ENEMY_H */
