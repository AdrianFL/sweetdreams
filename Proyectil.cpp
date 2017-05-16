/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Proyectil.cpp
 * Author: alexei
 * 
 * Created on 16 de mayo de 2017, 3:31
 */

#include "Proyectil.h"

Proyectil::Proyectil(int px, int py, int ex, int ey, int v, int d) {
    //Posiciones del proyectil
    x = px;
    y = py;
    lastx = x;
    lasty = y;
    movingborder=false;
    
    //Inicialización de los sprites
    sx=1;
    sy=1;
    int frames=4;
    std::string ruta("resources/proyectil.png");
    //Sprite derecha
    //left, top, width, height
    int coordenadas[16]={8,4,12,15, 24,5,14,13, 42,4,13,15, 61,4,13,15};
    movright= new Sprite(ruta, coordenadas, frames);
    movright->set_position(x, y);
    movright->set_framerate(100);

    //Origen de coordenadas en el centro
    movright->set_origin(6,7);
    
    //Sprite izquierda
    int coordenadas2[16]={20,4,-12,15, 38,5,-14,13, 57,4,-13,15, 72,4,-13,15};
    movleft= new Sprite(ruta, coordenadas2, frames);
    movleft->set_position(x, y);
    movleft->set_framerate(100);
    movleft->set_origin(6,7);
    
    if(px-ex<0){
        direccion=-1;
        spriteActual = movleft;
    }else{
        direccion=1;
        spriteActual = movright;
    }
    
    //Posición a la que tiene que ir
    objx = ex;
    objy = ey;
    
    //otros detalles, como vida y daño
    vida = vida;
    danyo = danyo;
}

Proyectil::Proyectil(const Proyectil& orig) {
}

Proyectil::~Proyectil() {
}

Sprite* Proyectil::render(int32_t tempo, float p){
    
    int movx=0,movy=0;
    if(p<1.0f && (lastx!=x||lasty!=y)){
        if(direccion>0){
            movx=(lastx*(1-p))+(x*p);
            movy=(lasty*(1-p))+(y*p);
            movright->set_position(movx, movy);
            movright->set_scale(sx, sy);
            spriteActual = movright;
            return(movright);
        }
        else{
            movx=(lastx*(1-p))+(x*p);
            movy=(lasty*(1-p))+(y*p);
            movleft->set_position(movx, movy);
            movleft->set_scale(sx, sy);
            spriteActual = movleft;
            return(movleft);
        }
    }
    else if(movingborder==true){
        if(direccion>0){
            spriteActual = movright;
            return(movright);
        }
        else{
            spriteActual = movleft;
            return(movleft);
        }
    }
}

void enemyRange::atacar(Personaje *p){
    if(ataquetime < 0){
        ataquetime = 1200;
        if(direccion>0){
            ataqueRight->set_position(x,y);
            ataqueRight->set_scale(sx, sy);
            ataqueLeft->reset();
            
            if(ataqueRight->comprobarColision(5, p->getAnimacionActiva())){
                p->herir(danyoAtaque);
            }
        }
        else{
            ataqueLeft->set_position(x,y);
            ataqueLeft->set_scale(sx, sy);
            ataqueLeft->reset();
            
            if(ataqueLeft->comprobarColision(5, p->getAnimacionActiva())){
               p->herir(danyoAtaque);
            }
            
        }
    }
}


void Enemy::move(int i){
    lastx=x;
    lasty=y;
    if(ataquetime<0){
        if(i==1){
            direccion=1;
            if(x<1153){
                movingborder=false;
                x+=6;
            } 
            else{
                movingborder=true;
            }
        }
        else if(i==2){
            direccion=-1;
            if(x>20){
                movingborder=false;
                x-=6;
            }
            else{
                movingborder=true;
                lastx=x;
                lasty=y;
            }
        }
        else if(i==3){
            if(y>380){
                movingborder=false;
                sx-=0.01;
                sy-=0.01;
                y-=4;
            }
            else{
                movingborder=true;
            }
        }
        else if(i==4){
            if(y<570){
                movingborder=false;
                sx+=0.01;
                sy+=0.01;
                y+=4;
            }
            else{
                movingborder=true;
            }
        }
        else if(i==0)
        {
            movingborder=false;
            lasty=y;
            lastx=x;
        }
    }
}