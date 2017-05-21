/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enemyFinal.h
 * Author: alexei
 *
 * Created on 18 de mayo de 2017, 15:57
 */
#include "Sprite.hpp"
#include "Enemy.h"
#include "Proyectil.h"
#include <iostream>

#ifndef ENEMYFINAL_H
#define ENEMYFINAL_H

class enemyFinal: public Enemy {
public:
    enemyFinal(int inix, int iniy, int v, int danyo);
    enemyFinal(const enemyFinal& orig);
    virtual ~enemyFinal();
    
    void atacar();
    void atacarSpecial();
    std::vector<Proyectil*> huir(Personaje *p, Mapa *m, int32_t tempo);
    
    bool spattacklanzado;
    bool tombalert;
    bool zanahoriaalert;
private:
    float distDisparo;
    int32_t disparotime;
    
    //Atriutos de las tumbas
    int danyotumba;
    int aparicionTumba;
    int duracionTumba;
    int tomblastx1,tomblastx2,tomblastx3,tomblastx4,tomblasty1,tomblasty2,tomblasty3,tomblasty4;
    
    //Atributos zanahorias
    int danyoZanahoria;
    int aparicionZanahoria;
    int duracionZanahoria;
    int zanalastx1,zanalasty1,zanalastx2,zanalasty2;
};

#endif /* ENEMYFINAL_H */

