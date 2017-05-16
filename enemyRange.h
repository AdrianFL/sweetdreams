/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enemyRange.h
 * Author: alexei
 *
 * Created on 15 de mayo de 2017, 23:00
 */

#ifndef ENEMYRANGE_H
#define ENEMYRANGE_H
#include "Enemy.h"
#include "Proyectil.h"

class enemyRange: public Enemy{
public:
    enemyRange(int inix, int iniy, int vida, int danyo);
    enemyRange(const enemyRange& orig);
    virtual ~enemyRange();
    
    void atacar(Personaje *p);
    Proyectil* perseguir(Personaje* p,Mapa* m);
    
private:
    float distDisparo;
};

#endif /* ENEMYRANGE_H */
