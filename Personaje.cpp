/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.cpp
 * Author: adrian
 * 
 * Created on 17 de marzo de 2017, 17:15
 */

#include "Personaje.hpp"
#include "Sprite.hpp"
#include <iostream>

Personaje::Personaje(int id) {
    if(id==0){
        vida=200;
        mana=100;
        vidamax=200;
        manamax=100;
        int coordenadas[24]={7,28,31,64,39,28,31,64,73,28,29,64,105,27,30,65,138,27,31,65,172,27,31,65};
        int frames=6;
        std::string ruta("resources/Agony.png");
        idle= new Sprite(ruta, coordenadas, frames);
        idle->set_position(600, 450);
        idle->set_framerate(120);
        int coordenadas2[24] = {38, 28, -31, 64, 70,28,-31,64,102,28,-29,64,135,27,-30,65,169, 27, -31, 65,203, 27, -31,65};
        idleleft = new Sprite(ruta, coordenadas2, frames);
        idleleft->set_position(600, 450);
        idleleft->set_framerate(120);
        int coordenadas3[32] = {632, 131, 47, 59, 682,125, 42,65, 727,126,47,57,777,128,45,59,825,131,46,57,874,125,40,63,917,126,46,57,966,128,44,59};
        frames=8;
        moveright=new Sprite(ruta, coordenadas3, frames);
        moveright->set_position(600, 450);
        moveright->set_framerate(100);
        int coordenadas4[32] = {679,131,-47,59, 724,125, -42, 65, 774, 126, -47, 57, 822,128,-45,59,871,131,-46,57,914,125,-40,63,963,126,-46,57,1010,128,-44,59};
        moveleft=new Sprite(ruta, coordenadas4, frames);
        moveleft->set_position(600,450);
        moveleft->set_framerate(100);
        int coordenadas5[32] = {691,1074,55,63,749,1055,36,82,788,1062,56,75,847,1058,55,79,905,1055,77,82,985,1079,69,58,1057,1076,68,61,1128,1072,52,65};
        attackright=new Sprite(ruta, coordenadas5, frames);
        attackright->set_position(600, 450);
        attackright->set_framerate(50);
        int coordenadas6[32] = {746,1074,-55,63,785,1055,-36,82,844,1062,-56,75,902,1058,-55,79,982,1055,-77,82,1054,1079,-69,58,1125,1076,-68,61,1180,1072,-52,65};
        attackleft=new Sprite(ruta,coordenadas6, frames);
        attackleft->set_position(600,450);
        attackleft->set_framerate(50);
    
    }
    else if(id==1){
        
    }
    x=600;
    y=450;
    sx=1.0;
    sy=1.0;
    direccion=1;
    activa=0;
}

Sprite* Personaje::render(int est){
    if(est>0){
        moveright->set_position(x, y);
        moveright->set_scale(sx, sy);
        activa=2;
        return(moveright);
    }
    else if(est<0){
        moveleft->set_position(x, y);
        moveleft->set_scale(sx, sy);
        activa=3;
        return(moveleft);
    }
    else{
       if(direccion>0){
        idle->set_position(x, y);
        idle->set_scale(sx, sy);
        activa=0;
        return(idle);
       }else if(direccion<0){
           idleleft->set_position(x, y);
           idleleft->set_scale(sx, sy);
           activa=1;
           return(idleleft);
       }
    }
}

void Personaje::move(int i){
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

int Personaje::getDireccion(){
    return(direccion);
}

int Personaje::getXCoordinate(){
    return(x);
}

int Personaje::getYCoordinate(){
    return(y);
}

Sprite* Personaje::getAnimacionActiva(){
    
}
