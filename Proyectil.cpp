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
#include "Personaje.hpp"

Proyectil::Proyectil(int id, int px, int py, int ex, int ey, int d, float velox, float veloy, int32_t tiempoVida) {
    //Posiciones del proyectil
    x = ex;
    y = ey;
    lastx = x;
    lasty = y;
    movingborder=false;
    

   //Inicialización de los sprites
    sx=1;
    sy=1;
    
    //Proyectil enemigo rango normal
    if(id == 0){
        sx = 3;
        sy = 2;
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

        //Sprite explosion
        frames = 6;
        int coordenadas3[24]={23,25,16,13, 7,27,13,9, 80,27,10,9, 80,27,10,9, 7,27,13,9, 80,27,10,9};
        explosion= new Sprite(ruta, coordenadas3, frames);
        explosion->set_position(x, y);
        explosion->set_framerate(60);
        explosion->set_origin(6,4);
        
    //Proyectil jefe rápido
    }else if(id==1){
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

        //Sprite explosion
        frames = 6;
        int coordenadas3[24]={23,25,16,13, 7,27,13,9, 80,27,10,9, 80,27,10,9, 7,27,13,9, 80,27,10,9};
        explosion= new Sprite(ruta, coordenadas3, frames);
        explosion->set_position(x, y);
        explosion->set_framerate(100);
        explosion->set_origin(6,4);
    //Aviso de ataque de jefe
    }else if(id == 2){
        int frames= 9;
        std::string ruta("resources/aviso.png");
        int coordenadas[36]={0,0,40,60, 0,40,40,60, 0,80,40,60, 0,120,40,60, 0,160,40,60, 0,200,40,60, 0,240,40,60, 0,280,40,60, 0,320,40,60};
        explosion= new Sprite(ruta,coordenadas, frames);
        explosion->set_position(x,y);
        explosion->set_framerate(60);
        explosion->set_origin(20,30);
        
    //Ataque de jefe tumba
    }else if(id == 3){
        
    //Ataque de jefe zanahoria pocha
    }else if(id == 4){
        
    }
    if(px-ex<0){
        direccion=-1;
        spriteActual = movleft;
    }else{
        direccion=1;
        spriteActual = movright;
    }
    
    //Posición a la que tiene que ir
    objx = px;
    objy = py;
    
    //otros detalles, como vida y daño
    danyo = d;
    explotar = false;
    muerto = false;
    
    //Inicialización del tiempo de vuelo esperado y de muerte
    muertetime=600;
    vuelotime = tiempoVida;
    
    //velocidad del proyectil según tipos
    if(id == 0 || id==1){
        vx = velox*( (objx-x) / std::sqrt( (objx-x)*(objx-x) + (objy-y)*(objy-y) ));
        vy = velox*( (objy-y) / std::sqrt( (objx-x)*(objx-x) + (objy-y)*(objy-y) ));
    }else{
        vx = velox;
        vy = veloy;
    }
}

Proyectil::Proyectil(const Proyectil& orig) {
}

Proyectil::~Proyectil() {
}

Sprite* Proyectil::render(int32_t tempo, float p){
    vuelotime-=tempo;
   
    int movx=0,movy=0;
    if(explotar){
        muertetime-=tempo;
        if(muertetime>0){
            explosion->set_position(x,y);
            explosion->set_scale(sx,sy);
            spriteActual = explosion;
            return(explosion);
        }else{
            muerto = true;
            return(explosion);
        }
    }
    
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
    }else{
       if(direccion>0){
            movright->set_position(x, y);
            movright->set_scale(sx, sy);
            spriteActual = movright;
            return(movright);
       }else if(direccion<0){
           movleft->set_position(x, y);
           movleft->set_scale(sx, sy);
           spriteActual = movleft;
           return(movleft);
       }
    }
}

void Proyectil::volar(Personaje *p){
    lastx=x;
    lasty=y;
    if(vuelotime>=0 && !muerto && !explotar){
        if(spriteActual->comprobarColision(0,p->getAnimacionActiva())){
            p->herir(danyo);
            explotar = true;
        }else{
            if(objx-x>0){
                if(x<1153){
                    movingborder=false;
                    x += vx;
                }else{
                    movingborder=true;
                    lastx=x;
                    lasty=y;
                }
                
            }else if(objx-x<0){
                if(x>20){
                    movingborder=false;
                    x += vx;
                }else{
                    movingborder=true;
                    lastx=x;
                    lasty=y;
                }
            }
            
            if(objy-y<0){
                if(y>380){
                    movingborder=false;
                     y += vy;
                }else{
                    movingborder=true;
                    lastx=x;
                    lasty=y;
                }
               
            }else if(objy-y>0){
                if(y<570){
                    movingborder=false;
                     y +=  vy;
                }else{
                    movingborder=true;
                    lastx=x;
                    lasty=y;
                }
               
            }
            if(objx == x && objy == y){
                movingborder=false;
                lasty=y;
                lastx=x;
            }
        }
    }else{
        muerto = true;
    }
}