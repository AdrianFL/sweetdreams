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

class Proyectil;

//Le pasamos el tipo de enemigo que se crea, y su posición inicial
Enemy::Enemy(int id, int inix, int iniy, int v, int danyo) {
    //Posiciones
    x=inix;
    y=iniy;
    lastx=x;
    lasty=y;
    
    //para cuando el borde
    movingborder= false;
    
    //danyo vida base
    vida = v;
    danyoAtaque = danyo;
    
    //si es jefe o no
    jefe = false;
    
        //Sprites de melee
    if(id==0){
        
        int frames=6;
        std::string ruta("resources/enemyMelee_tileset.png");
        //left, top, width, height
        int coordenadas[24]={1,4,57,76, 62,3,56,77, 122,3,54,77, 180,1,53,79, 237,2,55,78, 296,5,57,75};
        idle= new Sprite(ruta, coordenadas, frames);
        idle->set_position(x, y);
        idle->set_framerate(120);
        
        //Origen de coordenadas en el centro
        idle->set_origin(28,39);
        
        int coordenadas2[24] = {58, 4,-57,76, 118,3,-56,77, 176,3,-54,77, 233,1,-53,79, 292,2,-55,78, 353,5,-57,75};
        idleleft = new Sprite(ruta, coordenadas2, frames);
        idleleft->set_position(x, y);
        idleleft->set_framerate(120);
        idleleft->set_origin(28,39);
        
        
        int coordenadas3[24]={1,86,58,76, 63,84,63,78, 130,89,55,72, 189,87,55,74, 248,84,52,76, 304,89,55,73};
        moveright=new Sprite(ruta, coordenadas3, frames);
        moveright->set_position(x, y);
        moveright->set_framerate(100);
        moveright->set_origin(29,39);
        
        
        int coordenadas4[24]={59,86,-58,76, 126,84,-63,78, 185,89,-55,72, 244,87,-55,74, 300,84,-52,76, 359,89,-55,73};
        moveleft=new Sprite(ruta, coordenadas4, frames);
        moveleft->set_position(x,y);
        moveleft->set_framerate(100);
        moveleft->set_origin(28,38);
        
        frames=9;
        int coordenadas5[36]={1,670,54,77, 59,668,56,79, 119,665,61,80, 184,664,65,83, 253,666,79,81, 336,673,80,74, 420,672,64,75, 488,673,58,73, 550,672,50,75};
        ataqueRight=new Sprite(ruta, coordenadas5, frames);
        ataqueRight->set_position(x,y);
        ataqueRight->set_framerate(100);
        ataqueRight->set_origin(27,39);
        
        int coordenadas6[36]={55,670,-54,77, 115,668,-56,79, 180,665,-61,80, 249,664,-65,83, 332,666,-79,81, 416,673,-80,74, 484,672,-64,75, 546,673,-58,73, 600,672,-50,75};
        ataqueLeft=new Sprite(ruta, coordenadas6, frames);
        ataqueLeft->set_position(x,y);
        ataqueLeft->set_framerate(100);
        ataqueLeft->set_origin(27,39);
        
        frames=4;
        int coordenadas7[16] = {1440, 324, 57, 76,   1357, 330, 79, 70,  1272, 335, 81, 69,   1190, 334, 79, 97};
        muerteright=new Sprite(ruta, coordenadas7, frames);
        muerteright->set_position(x,y);
        muerteright->set_framerate(200);
        muerteright->set_origin(28,35);
        muerteright->setRepite(false);
        
        int coordenadas8[16] = {1497, 324, -57, 76,   1436, 330, -79, 70,  1353, 335, -81, 69,   1269, 334, -79, 97};
        muerteleft=new Sprite(ruta, coordenadas8, frames);
        muerteleft->set_position(x,y);
        muerteleft->set_framerate(200);
        muerteleft->set_origin(28,35);
        muerteleft->setRepite(false);
        
        spriteActual = idle;
        
        //sprites de rango
    }else if(id==1){
        int frames=6;
        std::string ruta("resources/enemyRange_tileset.png");
        //left, top, width, height
        int coordenadas[24]={1,4,57,76, 62,3,56,77, 122,3,54,77, 180,1,53,79, 237,2,55,78, 296,5,57,75};
        idle= new Sprite(ruta, coordenadas, frames);
        idle->set_position(x, y);
        idle->set_framerate(120);
        
        //Origen de coordenadas en el centro
        idle->set_origin(28,39);
        
        int coordenadas2[24] = {58, 4,-57,76, 118,3,-56,77, 176,3,-54,77, 233,1,-53,79, 292,2,-55,78, 353,5,-57,75};
        idleleft = new Sprite(ruta, coordenadas2, frames);
        idleleft->set_position(x, y);
        idleleft->set_framerate(120);
        idleleft->set_origin(28,39);
        
        
        int coordenadas3[24]={1,86,58,76, 63,84,63,78, 130,89,55,72, 189,87,55,74, 248,84,52,76, 304,89,55,73};
        moveright=new Sprite(ruta, coordenadas3, frames);
        moveright->set_position(x, y);
        moveright->set_framerate(100);
        moveright->set_origin(29,39);
        
        
        int coordenadas4[24]={59,86,-58,76, 126,84,-63,78, 185,89,-55,72, 244,87,-55,74, 300,84,-52,76, 359,89,-55,73};
        moveleft=new Sprite(ruta, coordenadas4, frames);
        moveleft->set_position(x,y);
        moveleft->set_framerate(100);
        moveleft->set_origin(28,38);
        
        frames=10;
        int coordenadas5[40]={1,755,63,83,  68,754,64,85,   136,756,65,82,  205,751,69,88,   278,764,82,74,   383,763,82,75,   1000,760,58,75,   1154,760,58,78,   1307,761,55,77,   1452,761,54,77};
        ataqueRight=new Sprite(ruta, coordenadas5, frames);
        ataqueRight->set_position(x,y);
        ataqueRight->set_framerate(100);
        ataqueRight->set_origin(32,39);
        ataqueRight->setRepite(false);
        
        int coordenadas6[40]={64,755,-63,83,  132,754,-64,85,   201,756,-65,82,  274,751,-69,88,   360,764,-82,74,   465,763,-82,75,   1058,760,-58,75,   1212,760,-58,78,   1362,761,-55,77,   1506,761,-54,77};
        ataqueLeft=new Sprite(ruta, coordenadas6, frames);
        ataqueLeft->set_position(x,y);
        ataqueLeft->set_framerate(100);
        ataqueLeft->set_origin(32,39);
        ataqueLeft->setRepite(false);
        
        frames=4;
        int coordenadas7[16]={1439, 323, 58, 78,   1356, 330, 80, 70,  1273, 334, 80, 68,   1189, 334, 80, 72};
        muerteright=new Sprite(ruta, coordenadas7, frames);
        muerteright->set_position(x,y);
        muerteright->set_framerate(200);
        muerteright->set_origin(28,35);
        muerteright->setRepite(false);
        
        int coordenadas8[16] = {1497, 323, -58, 78,   1436, 330, -80, 70,  1353, 334, -80, 68,   1269, 334, -80, 72};
        muerteleft=new Sprite(ruta, coordenadas8, frames);
        muerteleft->set_position(x,y);
        muerteleft->set_framerate(200);
        muerteleft->set_origin(29,35);
        muerteleft->setRepite(false);
        spriteActual = idle;
        
        //sprites de jefe
    }else if(id==2){
        jefe = true;
        int frames=3;
        std::string ruta("resources/badRabbit.png");
        //left, top, width, height
        int coordenadas[18]={93,0,44,83, 93,87,44,83, 93,177,44,83};
        idle= new Sprite(ruta, coordenadas, frames);
        idle->set_position(x, y);
        idle->set_framerate(120);
        idle->set_origin(22,41);
        
        int coordenadas2[18] = {93,0,44,83, 93,87,44,83, 93,177,44,83};
        idleleft = new Sprite(ruta, coordenadas2, frames);
        idleleft->set_position(x, y);
        idleleft->set_framerate(120);
        idleleft->set_origin(22,41);
        
        int coordenadas3[18]={45,0,44,83, 45,87,44,83, 45,177,44,83};
        moveright=new Sprite(ruta, coordenadas3, frames);
        moveright->set_position(x, y);
        moveright->set_framerate(120);
        moveright->set_origin(22,41);
        
        
        int coordenadas4[18]={144,0,44,83, 141,87,44,83, 141,177,44,83};
        moveleft=new Sprite(ruta, coordenadas4, frames);
        moveleft->set_position(x,y);
        moveleft->set_framerate(120);
        moveleft->set_origin(22,41);
        
        int coordenadas5[18]={188,270,-44,83, 185,357,-44,83, 185,447,-44,83};
        ataqueRight=new Sprite(ruta, coordenadas5, frames);
        ataqueRight->set_position(x,y);
        ataqueRight->set_framerate(120);
        ataqueRight->set_origin(22,41);
        
        int coordenadas6[18]={144,270,44,83, 141,357,44,83, 141,447,44,83};
        ataqueLeft=new Sprite(ruta, coordenadas6, frames);
        ataqueLeft->set_position(x,y);
        ataqueLeft->set_framerate(120);
        ataqueLeft->set_origin(22,41);
        
        int coordenadas7[48]={0,0,44,83, 0,87,44,83, 0,177,44,83, 199,0,44,83, 199,87,44,83, 199,177,44,83, 199,87,44,83, 199,177,44,83};
        specialAttack=new Sprite(ruta, coordenadas, frames);
        specialAttack->set_position(x, y);
        specialAttack->set_framerate(120);
        specialAttack->set_origin(22,41);
        
        spriteActual = idle;
    }
    //Raycast, común para todos
    std::string rutaRay("resources/amarillo.png");
    int rayCoord[4] = {0,0,1,1};
    raycast = new Sprite(rutaRay,rayCoord,1);
    raycast->set_position(x,y);
    raycast->set_framerate(100);
    raycast->set_origin(0,0);
    
    //Escalado y dirección
    sx=1.0;
    sy=1.0;
    direccion=1;
    
    //Iniciar variables de tiempo
    ataquetime = -1;
    disparotime = -1;
    cambiatime=-1;
    spattacktime=-1;
    
    //iniciar nodo objetivo
    nodoObjetivo = NULL;
}

Enemy::Enemy(const Enemy& orig) {
}

Enemy::~Enemy() {
}

Sprite* Enemy::render(int32_t tempo, float per){
    ataquetime-=tempo;
    disparotime-=tempo;
    cambiatime-=tempo;
    
    int movx = 0;
    int movy = 0;
    //--------- Añadir condición de cambio para que no sea rápida
    
    //if(cambiatime<0){
     //   cambiatime=20;
    if(!jefe){
        if(vida<=0){
            if(direccion>0){
                muerteright->set_position(x,y);
                muerteright->set_scale(sx, sy);
                spriteActual = muerteright;
                return(muerteright);
            }else{
                muerteleft->set_position(x,y);
                muerteleft->set_scale(sx, sy);
                spriteActual = muerteleft;
                return(muerteleft);
            }
        }
        if(ataquetime>=0){
            if(direccion>0){
                ataqueRight->set_position(x,y);
                ataqueRight->set_scale(sx, sy);
                spriteActual = ataqueRight;
                return(ataqueRight);
            }
            else{
                ataqueLeft->set_position(x,y);
                ataqueLeft->set_scale(sx, sy);
                spriteActual = ataqueLeft;
                return(ataqueLeft);
            }
        }
    
        if(per<1.0f && (lastx!=x||lasty!=y)){
            if(direccion>0){
                movx=(lastx*(1-per))+(x*per);
                movy=(lasty*(1-per))+(y*per);
                moveright->set_position(movx, movy);
                moveright->set_scale(sx, sy);
                spriteActual = moveright;
                return(moveright);
            }else{
                movx=(lastx*(1-per))+(x*per);
                movy=(lasty*(1-per))+(y*per);
                moveleft->set_position(movx, movy);
                moveleft->set_scale(sx, sy);
                spriteActual = moveleft;
                return(moveleft);
            }
        }
        else if(movingborder==true){
            if(direccion>0){
                moveright->set_position(x,y);
                moveright->set_scale(sx, sy);
                spriteActual = moveright;
                return(moveright);
            }
            else{
                moveleft->set_position(x,y);
                moveleft->set_scale(sx, sy);
                spriteActual = moveleft;
                return(moveleft);
            }
        }
        else{
           if(direccion>0){
               idle->set_position(x, y);
               idle->set_scale(sx, sy);
               spriteActual = idle;
               return(idle);
           }else if(direccion<0){
               idleleft->set_position(x, y);
               idleleft->set_scale(sx, sy);
               spriteActual = idleleft;
               return(idleleft);
           }
        }
    //}
    }else{
        //Si muere
        if(vida<=0){
            specialAttack->set_position(x,y);
            specialAttack->set_scale(sx, sy);
            spriteActual = specialAttack;
            return(specialAttack);
        }
        //Si lanza ataque especial
        if(spattacktime>=0){
           specialAttack->set_position(x,y);
           specialAttack->set_scale(sx, sy);
           spriteActual = specialAttack;
           return(specialAttack); 
        }
        //Si ataca normal
        if(ataquetime>=0){
            if(direccion>0){
                ataqueRight->set_position(x,y);
                ataqueRight->set_scale(sx, sy);
                spriteActual = ataqueRight;
                return(ataqueRight);
            }
            else{
                ataqueLeft->set_position(x,y);
                ataqueLeft->set_scale(sx, sy);
                spriteActual = ataqueLeft;
                return(ataqueLeft);
            }
        }
        
        //Si se mueve
        if(per<1.0f && (lastx!=x||lasty!=y)){
            if(direccion>0){
                movx=(lastx*(1-per))+(x*per);
                movy=(lasty*(1-per))+(y*per);
                moveright->set_position(movx, movy);
                moveright->set_scale(sx, sy);
                spriteActual = moveright;
                return(moveright);
            }else{
                movx=(lastx*(1-per))+(x*per);
                movy=(lasty*(1-per))+(y*per);
                moveleft->set_position(movx, movy);
                moveleft->set_scale(sx, sy);
                spriteActual = moveleft;
                return(moveleft);
            }
        }
        else if(movingborder==true){
            if(direccion>0){
                moveright->set_position(x,y);
                moveright->set_scale(sx, sy);
                spriteActual = moveright;
                return(moveright);
            }
            else{
                moveleft->set_position(x,y);
                moveleft->set_scale(sx, sy);
                spriteActual = moveleft;
                return(moveleft);
            }
        }
        else{
           if(direccion>0){
               idle->set_position(x, y);
               idle->set_scale(sx, sy);
               spriteActual = idle;
               return(idle);
           }else if(direccion<0){
               idleleft->set_position(x, y);
               idleleft->set_scale(sx, sy);
               spriteActual = idleleft;
               return(idleleft);
           }
        }
    }
    return(spriteActual);
}

void Enemy::herir(int h){
    vida-=h;
    /*if(vida<=0){
        std::cout<<"Me he muerto colegui"<<std::endl;
    }*/
}


void Enemy::move(int i){
    lastx=x;
    lasty=y;
    if(ataquetime<0){
        if(i==1){
            direccion=1;
            if(x<3200){
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

float Enemy::distanciaAEnemigo(Mapa* m, int px, int py, int ex,int ey){
    float result = -1;
    //Colocamos el escalado para darle tamaño al ray. Esto será la distancia en linea recta hasta el personaje, y la altura será la del bicho (sino 50 por defecto))
    float scalex = std::sqrt((px-ex)*(px-ex) + (py-ey)*(py-ey));
    raycast->set_scale(scalex,50.0f);
    float giro = ((std::atan2((py-ey),(px-ex)))/(2 * 3.14159)) * 360;
    
    //colocamos su posición
    raycast->set_position(ex+20*std::sin(giro*3.14159/180),ey-30*std::cos(giro*3.14159/180));
    
    //Colocamos su rotación y comprobamos colisiones en el mapa
    raycast->set_rotation(giro);
    
    if(!m->colisionaObs(raycast)){
        result = scalex;
    }
    return result;
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