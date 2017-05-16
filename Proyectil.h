/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Proyectil.h
 * Author: alexei
 *
 * Created on 16 de mayo de 2017, 3:31
 */

#ifndef PROYECTIL_H
#define PROYECTIL_H
#include "Sprite.hpp"

class Proyectil {
public:
    Proyectil(int px, int py, int ex, int ey, int v, int d);
    Proyectil(const Proyectil& orig);
    virtual ~Proyectil();
    Sprite* render(int32_t tempo, float p);
    
    
    int x, y, lastx, lasty, objx, objy;
    int vida, danyo;
    float sx,sy;
    
    bool movingborder;
    int direccion;
private:
    Sprite* movleft;
    Sprite* movright;
    Sprite* spriteActual;
};

#endif /* PROYECTIL_H */