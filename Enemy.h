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
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Nodo.h"
#include "Personaje.hpp"
#include "Mapa.h"

#ifndef ENEMY_H
#define ENEMY_H

class Personaje;
class Mapa;

class Enemy {
public:
    Enemy(int id, int inix, int iniy, int vida, int danyo);
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    
    Sprite* render(int32_t tempo, float per);
    void move(int i);
    void herir(int h);
    float distanciaAEnemigo(Mapa *m, int px,int py, int ex,int ey);
    int getDireccion();
    int getXCoordinate();
    int getYCoordinate();
    Sprite* getAnimacionActiva();
    
    std::vector<Nodo*> caminoActual;
    Nodo* nodoObjetivo;
    
    //Sprite de raycast
    Sprite *raycast;
protected:
    //Sprites de movimiento
    Sprite *spriteActual;
    Sprite *idle;
    Sprite *idleleft;
    Sprite *moveright;
    Sprite *moveleft;
    
    //Sprites relacionados con ataque
    Sprite *ataqueRight;
    Sprite *ataqueLeft;
    Sprite *muerte;
    
    
    
    int x, y, lastx, lasty;
    float sx, sy;
    
    int vida;
    int direccion;
    
    int32_t ataquetime;
    int32_t IAtime;
    int32_t cambiatime;
    
    
    int  danyoAtaque;
    
    bool movingborder;
};

#endif /* ENEMY_H */