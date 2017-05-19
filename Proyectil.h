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
#include "Personaje.hpp"

class Proyectil {
public:
    Proyectil(int id, int px, int py, int ex, int ey, int d, float velox, float veloy);
    Proyectil(const Proyectil& orig);
    virtual ~Proyectil();
    Sprite* render(int32_t tempo, float p);
    void atacar();
    void volar(Personaje* p);
    
    float x, y, lastx, lasty, objx, objy;
    int vida, danyo;
    float sx,sy;
    float vx,vy;
    
    bool movingborder;
    int direccion;
    
    bool explotar;
    
    int32_t vuelotime;
    int32_t muertetime;
    bool muerto;
private:
    Sprite* movleft;
    Sprite* movright;
    Sprite* explosion;
    
    Sprite* spriteActual;
};

#endif /* PROYECTIL_H */