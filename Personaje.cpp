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
#include "Enemy.h"
#include "Arma.h"
#include <iostream>




Personaje::Personaje(int id) {
    if(id==0){
        //idles
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
        //movimientos
        int coordenadas3[32] = {632, 131, 47, 59, 682,125, 42,65, 727,126,47,57,777,128,45,59,825,131,46,57,874,125,40,63,917,126,46,57,966,128,44,59};
        frames=8;
        moveright=new Sprite(ruta, coordenadas3, frames);
        moveright->set_position(600, 450);
        moveright->set_framerate(100);
        int coordenadas4[32] = {679,131,-47,59, 724,125, -42, 65, 774, 126, -47, 57, 822,128,-45,59,871,131,-46,57,914,125,-40,63,963,126,-46,57,1010,128,-44,59};
        moveleft=new Sprite(ruta, coordenadas4, frames);
        moveleft->set_position(600,450);
        moveleft->set_framerate(100);
        //Ataques hacha
        int coordenadas5[32]={691, 1068, 55, 68, 749, 1047, 38, 89, 799, 1060, 64, 77, 872, 1055, 63, 82, 940, 1078, 75, 63, 1015, 1079, 71, 59, 1087, 1076, 71, 59, 1159, 1072, 65, 64};
        attackright=new Sprite(ruta, coordenadas5, frames);
        attackright->set_position(600, 450);
        attackright->set_framerate(75);
        int coordenadas6[32] = {746,1074,-55,63,785,1055,-36,82,844,1062,-56,75,902,1058,-55,79,982,1055,-77,82,1054,1079,-69,58,1125,1076,-68,61,1180,1072,-52,65};
        attackleft=new Sprite(ruta,coordenadas6, frames);
        attackleft->set_position(600,450);
        attackleft->set_framerate(75);
        //pocionesvida
        frames=8;
        int coordenadas7[32]={699, 865, 33, 65, 734, 866, 33, 63, 769, 864, 32, 66, 804, 864, 32, 66, 836, 863, 42, 67, 836, 863, 42, 67, 904, 865, 41, 65, 904, 865, 41, 65};
        potivida=new Sprite(ruta, coordenadas7, frames);
        potivida->set_position(600, 450);
        potivida->set_framerate(100);
        int coordenadas8[32]={732,865,-33,65,767,866,-33,63,801,864,-32,66,836,864,-32,66,878,863,-42,67, 878,863,-42,67, 945,865,-41,65, 945,865,-41,65};
        potividaleft=new Sprite(ruta, coordenadas8, frames);
        potividaleft->set_position(600, 450);
        potividaleft->set_framerate(100);
        //pocionesmana
        int coordenadas9[32]={699, 865, 33, 65, 734, 866, 33, 63, 769, 864, 32, 66, 804, 864, 32, 66, 731, 966, 42, 67, 731, 966, 42, 67, 799, 966, 41, 65, 799, 966, 41, 65};
        potimana=new Sprite(ruta, coordenadas9, frames);
        potimana->set_position(600,450);
        potimana->set_framerate(100);
        int coordenadas10[32]={732,865,-33,65,767,866,-33,63,801,864,-32,66,836,864,-32,66,773,966,-42,67, 773,966,-42,67, 840,966,-41,65, 840,966,-41,65};
        potimanaleft=new Sprite(ruta, coordenadas10, frames);
        potimanaleft->set_position(600, 450);
        potimanaleft->set_framerate(100);
        //muerte
        frames=10;
        int coordenadas11[40]={1259, 1552, 40, 62, 1302, 1548, 49, 56, 1355, 1545, 71, 44, 1429, 1539, 66, 36, 1499, 1535, 67, 44, 1570, 1541, 59, 54, 1633, 1575, 45, 38, 1682, 1580, 66, 30, 1751, 1581, 65, 30, 1820, 1587, 68, 28};
        muerte=new Sprite(ruta, coordenadas11, frames);
        muerte->set_framerate(125);
        muerte->setRepite(false);
        int coordenadas12[40]={1299,1552,-40,62,1351,1548,-49,56,1426,1545,-71,44,1495,1539,-66,36,1566,1535,-67,44,1629,1541,-59,54,1678,1575,-45,38,1748,1580,-66,30,1816,1581,-65,30,1888,1587,-68,28};
        muerteleft=new Sprite(ruta, coordenadas12, frames);
        muerteleft->set_framerate(125);
        muerteleft->setRepite(false);
        //recogida
        frames=3;
        int coordenadas13[12]={488, 347, 33, 53, 527, 351, 47, 49, 579, 348, 41, 52};
        recogida=new Sprite(ruta, coordenadas13, frames);
        recogida->set_framerate(100);
        int coordenadas14[12]={521,347,-33,53,574,351,-47,49,620,348,-41,52};
        recogidaleft=new Sprite(ruta, coordenadas14, frames);
        recogidaleft->set_framerate(100);
    }
    else if(id==1){
        
    }
    x=600;
    y=450;
    lastx=600;
    lasty=450;
    sx=1.0;
    sy=1.0;
    direccion=1;
    activa=0;
    atctime=-1;
    potvidatime=-1;
    potmanatime=-1;
    picktime=-1;
    vidamax=200;
    manamax=100;
    vida=20;
    mana=10;
    numPVida=3;
    numPMana=2;
    movingborder=false;
    
    margen=0;
}

Sprite* Personaje::render(int32_t tempo, float p){
    atctime-=tempo;
    potvidatime-=tempo;
    potmanatime-=tempo;
    picktime-=tempo;
    int movx=0, movy=0;
    if(vida<1){
        if(direccion>0){
            return(muerte);
        }
        else{
            return(muerteleft);
        }
    }
    if(atctime>=0){
        if(direccion>0){
            //attackright->set_position(x,y);
            //attackright->set_scale(sx, sy);
            activa=4;
            return(attackright);
        }
        else{
            //attackleft->set_position(x,y);
            //attackleft->set_scale(sx, sy);
            activa=5;
            return(attackleft);
        }
    }
    else if(potvidatime>=0){
        if(direccion>0){
            return(potivida);
        }
        else{
            return(potividaleft);
        }
    }
    else if(potmanatime>=0){
        if(direccion>0){
            return(potimana);
        }
        else{
            return(potimanaleft);
        }
    }
    else if(picktime>=0){
        if(direccion>0){
            return(recogida);
        }
        else{
            return(recogidaleft);
        }
    }
    if(p<1.0f && (lastx!=x||lasty!=y)){
        if(direccion>0){
        movx=(lastx*(1-p))+(x*p);
        movy=(lasty*(1-p))+(y*p);
        moveright->set_position(movx, movy);
        moveright->set_scale(sx, sy);
        activa=2;
        return(moveright);
        }
        else{
        movx=(lastx*(1-p))+(x*p);
        movy=(lasty*(1-p))+(y*p);
        moveleft->set_position(movx, movy);
        moveleft->set_scale(sx, sy);
        activa=3;
        return(moveleft);
        }
    }
    else if(movingborder==true){
        if(direccion>0){
            activa=2;
            return(moveright);
        }
        else{
            activa=3;
            return(moveleft);
        }
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
    if(atctime<0){
        if(i==1){
            direccion=1;
            if(x<3160){
                movingborder=false;
                lastx=x;
                lasty=y;
                x+=12;
            } 
            else{
                movingborder=true;
                lastx=x;
                lasty=y;
            }
        }
        else if(i==2){
            direccion=-1;
            if(x>20){
                movingborder=false;
                lastx=x;
                lasty=y;
                x-=12;
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
                lasty=y;
                lastx=x;
                y-=6;
            }
            else{
                movingborder=true;
                lastx=x;
                lasty=y;
            }
        }
        else if(i==4){
            if(y<570){
                movingborder=false;
                sx+=0.01;
                sy+=0.01;
                lasty=y;
                lastx=x;
                y+=6;
            }
            else{
                movingborder=true;
                lastx=x;
                lasty=y;
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

void Personaje::usaPocion(std::string s){
       
       int sumvida=0;
       int summana=0;
    
    bool stop=false;
    
    //Falta comprobar que tiene pociones al hacer la animacion
    //Y alargar los ultimos fotogramas repitiendolos
    if(potvidatime<0 && s=="vida" && numPVida>0){
        numPVida--;
        vida+=Pocion::getCantidad(s);
        if(direccion>0){
            potivida->reset();
            potivida->set_position(x, y);
            potivida->set_scale(sx, sy);
        }
        else{
            potividaleft->reset();
            potividaleft->set_position(x, y);
            potividaleft->set_scale(sx, sy);
        }
        potvidatime=800;
    }
    else if(potmanatime<0 && s=="mana" && numPMana>0){
        numPMana--;
        mana+=Pocion::getCantidad(s);
        if(direccion>0){
            potimana->reset();
            potimana->set_position(x, y);
            potimana->set_scale(sx, sy);
        }
        else{
            potimanaleft->reset();
            potimanaleft->set_position(x, y);
            potimanaleft->set_scale(sx, sy);
        }
        potmanatime=800;
    }
}

void Personaje::activaRecogida(){
    if(picktime<0){
        picktime=300;
        if(direccion>0){
            recogida->set_position(x, y);
            recogida->set_scale(sx, sy);
        }
        else{
            recogidaleft->set_position(x, y);
            recogidaleft->set_scale(sx, sy);
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

int Personaje::getManaMax(){
    return manamax;
}

int Personaje::getVidaMax(){
    return vidamax;
}

void Personaje::setMana(int i){
    mana=i;
}

void Personaje::setVida(int i){
    vida=i;
}

int Personaje::getMana(){
    return mana;
}

int Personaje::getVida(){
    return vida;
}

/*void Personaje::setPociones(Pocion *pociones[]){
    
    for(int i=0; i<5; i++){
        for(int j=0; i<5; i++){
            bolsilloP[i]=pociones[j];
        }
    }
}*/

Sprite* Personaje::getAnimacionActiva(){
    switch(activa){
        case 0: return(idle);
        break;
        case 1: return(idleleft);
        break;
        case 2: return(moveright);
        break;
        case 3: return(moveleft);
        break;
        case 4: return(attackright);
        break;
        case 5: return(attackleft);
        break;
        default: return(idle);
        break;
    }
}

void Personaje::atacar(){
    if(atctime<0){
        atctime=600;
        if(direccion>0){
            attackright->set_position(x,y);
            attackright->set_scale(sx, sy);
            attackright->reset();
        }
        else{
            attackleft->set_position(x,y);
            attackleft->set_scale(sx, sy);
            attackleft->reset();
        }
    }
}

void Personaje::herir(int dmg){
    vida-=dmg;
    if(vida<1){
        if(direccion>0){
            muerte->set_position(x, y);
            muerte->set_scale(sx, sy);
        }
        else{
            muerteleft->set_position(x, y);
            muerteleft->set_scale(sx, sy);
        }
    }
}

void Personaje::aumentarMargenDer(int i){
    margen=margen+i;
}

void Personaje::aumentarMargenIzq(int i){
    margen=margen-i;
}

void Personaje::aumentaPVida(){
    if(numPVida<2){
        numPVida++;
    }
}

void Personaje::aumentaPMana(){
    if(numPMana<2){
        numPMana++;
    }
}

int Personaje::getNumPVida(){
    return numPVida;
}

int Personaje::getNumPMana(){
    return numPMana;
}

void Personaje::cambiarAtaque(Arma* a){
    if(a!=NULL){
        delete attackright;
        std::string ruta("resources/Agony.png");
        int fr=a->getFrames();
        attackright=new Sprite(ruta, a->getCoordenadasSprite(), fr);
        delete attackleft;
        attackleft=new Sprite(ruta, a->getCoordenadasSpriteLeft(), fr);
    }
}