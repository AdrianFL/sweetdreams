/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enemyMelee.h
 * Author: alexei
 *
 * Created on 15 de mayo de 2017, 23:00
 */

#ifndef ENEMYMELEE_H
#define ENEMYMELEE_H

#include "Enemy.h"
class enemyMelee : public Enemy{
public:
    enemyMelee(int inix, int iniy, int vida, int danyo) ;
    enemyMelee(const enemyMelee& orig);
    virtual ~enemyMelee();
    
    void atacar(Personaje *p);
    int perseguir(Personaje* p,Mapa* m);
    
private:

};

#endif /* ENEMYMELEE_H */
