/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemy.cpp
 * Author: alexei
 * 
 * Created on 1 de mayo de 2017, 16:55
 */

#include "Enemy.h"
#include "Personaje.hpp"

//Le pasamos el tipo de enemigo que se crea, y su posición inicial
Enemy::Enemy(int id, int inix, int iniy, float tAtaque) {
    x=inix;
    y=iniy;
    tiempoAtaque = tAtaque;
    muerte = false;
    if(id==0){
        
        int frames=6;
        std::string ruta("resources/enemyMelee_tileset.png");
        //left, top, width, height
        int coordenadas[24]={1,4,57,76, 62,3,56,77, 122,3,54,77, 180,1,53,79, 237,2,55,78, 296,5,57,75};
        idle= new Sprite(ruta, coordenadas, frames);
        idle->set_position(x, y);
        idle->set_framerate(120);
        int coordenadas2[24] = {58, 4,-57,76, 118,3,-56,77, 176,3,-54,77, 233,1,-53,79, 292,2,-55,78, 353,5,-57,75};
        idleleft = new Sprite(ruta, coordenadas2, frames);
        idleleft->set_position(x, y);
        idleleft->set_framerate(120);
        
        int coordenadas3[24]={1,86,58,76, 63,84,63,78, 130,89,55,72, 189,87,55,74, 248,84,52,76, 304,89,55,73};
        moveright=new Sprite(ruta, coordenadas3, frames);
        moveright->set_position(x, y);
        moveright->set_framerate(100);
        
        int coordenadas4[24]={59,86,-58,76, 126,84,-63,78, 185,89,-55,72, 244,87,-55,74, 300,84,-52,76, 359,89,-55,73};
        moveleft=new Sprite(ruta, coordenadas4, frames);
        moveleft->set_position(x,y);
        moveleft->set_framerate(100);
        
        
        int coordenadas5[36]={1,670,54,77, 59,668,56,79, 119,665,61,80, 184,664,65,83, 253,666,79,81, 336,673,80,74, 420,672,64,75, 488,673,58,73, 550,672,50,75};
        ataqueRight=new Sprite(ruta, coordenadas4, frames);
        ataqueRight->set_position(x,y);
        ataqueRight->set_framerate(100);
        
        int coordenadas6[36]={55,670,-54,77, 115,668,-56,79, 180,665,-61,80, 249,664,-65,83, 332,666,-79,81, 416,673,-80,74, 484,672,-64,75, 546,673,-58,73, 600,672,-50,75};
        ataqueLeft=new Sprite(ruta, coordenadas4, frames);
        ataqueLeft->set_position(x,y);
        ataqueLeft->set_framerate(100);
        
        int coordenadas7[] = {};
        
        spriteActual = idle;
    }

    sx=1.0;
    sy=1.0;
    direccion=1;
}

Enemy::Enemy(const Enemy& orig) {
}

Enemy::~Enemy() {
}

Sprite* Enemy::render(){
    int est = direccion;
    if(est>0){
        moveright->set_position(x*0.9, y*0.9);
        moveright->set_scale(sx, sy);
        spriteActual = moveright;
        return(moveright);
    }
    else if(est<0){
        moveleft->set_position(x*0.9, y*0.9);
        moveleft->set_scale(sx, sy);
        spriteActual = moveleft;
        return(moveleft);
    }
    else{
       if(direccion>0){
        idle->set_position(x*0.9, y*0.9);
        idle->set_scale(sx, sy);
        spriteActual = idle;
        return(idle);
       }else if(direccion<0){
           idleleft->set_position(x*0.9, y*0.9);
           idleleft->set_scale(sx, sy);
           spriteActual = idleleft;
           return(idleleft);
       }
    }
}

void Enemy::perseguir(Personaje* p){
    int px = p->getXCoordinate();
    int py = p->getYCoordinate();
    
    if(x <= px){
        move(1);
        direccion = 1;
    }
    if(x-100 >=px){
        move(2);
        direccion = -1;
    }
    if(y >= py){
        move(3);
    }
    if(y-70 <= py){
        move(4);
    }
}



void Enemy::move(int i){
    if(i==1){
        direccion=1;
        if(x<1153){
            x+=4;
        } 
    }
    else if(i==2){
        direccion=-1;
        if(x>20){
            x-=4;
        }
    }
    else if(i==3){
        if(y>380){
            sx-=0.002;
            sy-=0.002;
            y-=2;
        }
    }
    else if(i==4){
        if(y<570){
            sx+=0.002;
            sy+=0.002;
            y+=2;
        }
    }
}

int Enemy::getDireccion(){
    return direccion;
}

int Enemy::getXCoordinate(){
    return x;
}

int Enemy::getYCoordinate(){
    return y;
}

Sprite* Enemy::getAnimacionActiva(){
    return spriteActual;
}