/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enemyFinal.cpp
 * Author: alexei
 * 
 * Created on 18 de mayo de 2017, 15:57
 */
#include "enemyFinal.h"

enemyFinal::enemyFinal(int inix, int iniy, int vida, int danyo)  : Enemy(2,inix,iniy,vida,danyo) {
    distDisparo = 300;
}

enemyFinal::enemyFinal(const enemyFinal& orig): Enemy(orig) {
}

enemyFinal::~enemyFinal() {
}

void enemyFinal::atacar(){
    if(ataquetime < 0){
        ataquetime = 1200;
        if(direccion>0){
            ataqueRight->set_position(x,y);
            ataqueRight->set_scale(sx, sy);
            ataqueRight->reset();
        }
        else{
            ataqueLeft->set_position(x,y);
            ataqueLeft->set_scale(sx, sy);
            ataqueLeft->reset();
        }
    }
}

void enemyFinal::atacarSpecial(){
    if(ataquetime < 0){
        spattacktime = 3000;
        if(direccion>0){
            ataqueRight->set_position(x,y);
            ataqueRight->set_scale(sx, sy);
            ataqueRight->reset();
        }
        else{
            ataqueLeft->set_position(x,y);
            ataqueLeft->set_scale(sx, sy);
            ataqueLeft->reset();
        }
    }
}

Proyectil* enemyFinal::huir(Personaje *p, Mapa *m, int32_t tempo){
    spattacktime-=tempo;
    disparotime-=tempo;
    Proyectil* disparo = NULL;
    bool colisionaRaycast = false;
    
    
    //Posiciones centrales de personaje y enemigo
    int px = p->getXCoordinate();
    int py = p->getYCoordinate();
    
    int ex = x;
    int ey = y;
    
    //Posiciones a las que se dirigirá el enemigo
    float dirigex = px;
    float dirigey = py;
    
    if(p->getVida()>0){
        std::cout<<"Distancia error: "<<vida<<std::endl;
        if(vida>250){
            //Añadimos raycast, que verificará si se puede ir en linea recta hasta el objetivo
            float distRaycast = distanciaAEnemigo(m,px,py,ex,ey);
            std::cout<<"Distancia error: "<<std::endl;
            if(distRaycast<= distDisparo){
                if(disparotime<0){
                   disparotime = 200;
                   disparo = new Proyectil(0,px,py,ex,ey,5,15.0f,15.0f);
                   atacar();
                }
            }else{
                if(disparotime<0){
                    disparotime = 600;
                    disparo = new Proyectil(0,px,py,ex,ey, 10,5.0f,5.0f);
                    atacar();
                }
            }
        }else{
            
        }
    }
    return disparo;
}
