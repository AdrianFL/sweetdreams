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
    //id del proyectil
    type = id;
    //Posiciones del proyectil
    x = ex;
    y = ey;
    lastx = x;
    lasty = y;
    movingborder=false;
    

   //Inicialización de los sprites
    sx=1;
    sy=1;
   
    //Posición a la que tiene que ir
    objx = px;
    objy = py;
    
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

        explosion->set_origin(8,6);
        
        if(px-ex<0){
            direccion=-1;
            spriteActual = movleft;
        }else{
            direccion=1;
            spriteActual = movright;
        }

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
        
        if(px-ex<0){
            direccion=-1;
            spriteActual = movleft;
        }else{
            direccion=1;
            spriteActual = movright;
        }
    //Aviso de ataque de jefe
    }else if(id == 2){
        //Uso el valor del daño para indicar si es de tumba, o de zanahoria (no debería)
        if(d == 0){
            sx = 1.2;
            sy = 1.2;
        }else{
            sx = 2;
            sy = 5;
        }

        int frames= 9;
        std::string ruta("resources/aviso.png");
        int coordenadas[36]={0,0,60,40, 0,40,60,40, 0,80,60,40, 0,120,60,40, 0,160,60,40, 0,200,60,40, 0,240,60,40, 0,280,60,40, 0,320,60,40};
        explosion= new Sprite(ruta,coordenadas, frames);
        explosion->set_position(x,y);
        explosion->set_framerate(100);
        explosion->set_origin(20,30);
        
        spriteActual = explosion;
    //Ataque de jefe tumba
    }else if(id == 3){
        //Asignamos un tamaño pequeño para dar efecto de "salir del suelo"
        sx = 1;
        sy = 0.01;
        
        //Un solo frame, animamos el tamaño
        int frames= 1;
        std::string ruta("resources/graves.png");
        
        //El tipo de tumba será aleatorio

        int tipoTumba = std::rand()%4;
        
        if(tipoTumba == 0){
            int coordenadas[4]={0,0,75,107};
            explosion= new Sprite(ruta,coordenadas, frames);
            explosion->set_position(x,y);
            explosion->set_framerate(100);
            explosion->set_origin(33,107);

            spriteActual = explosion;
        }
        else if(tipoTumba == 1){
            int coordenadas[4]={90,0,70,107};
            explosion= new Sprite(ruta,coordenadas, frames);
            explosion->set_position(x,y);
            explosion->set_framerate(100);
            explosion->set_origin(33,107);

            spriteActual = explosion;
        }
        else if(tipoTumba == 2){
            int coordenadas[4]={0,122,75,108};
            explosion= new Sprite(ruta,coordenadas, frames);
            explosion->set_position(x,y);
            explosion->set_framerate(100);
            explosion->set_origin(33,108);

            spriteActual = explosion;
        }
        else if(tipoTumba == 3){
            int coordenadas[4]={85,122,75,113};
            explosion= new Sprite(ruta,coordenadas, frames);
            explosion->set_position(x,y);
            explosion->set_framerate(100);
            explosion->set_origin(33,113);

            spriteActual = explosion;
        }
        
    //Ataque de jefe zanahoria pocha
    }else if(id == 4){
        sx = 0.9;
        sy = 0.6;
        
        x +=20;
        y -=50;
        objx = x;
        objy = y;
        y = y - 100;
        
        //Un solo frame, animamos su direccion luego
        int frames= 1;
        std::string ruta("resources/zanahoria.png");
        int coordenadas[4] = {3,6,94,324};
        explosion = new Sprite(ruta, coordenadas, frames);
        explosion->set_position(x,y);
        explosion->set_framerate(100);
        explosion->set_origin(47,162);
        explosion->set_scale(sx,sy);
        spriteActual = explosion;
        
    }else if(type == 10){
        
        sx = 1;
        sy = 1;
        int frames=5;
        std::string ruta("resources/AnimaMeteoro.png");
        //Sprite derecha
        //left, top, width, height
        int coordenadas[20]={1, 4, 38, 25,   43, 4, 38, 25,   87, 4, 38, 25,   130, 4, 38, 5,   169, 4, 38, 25};
        movright= new Sprite(ruta, coordenadas, frames);
        movright->set_position(x, y);
        movright->set_framerate(100);

        //Origen de coordenadas en el centro
        movright->set_origin(19,7);

        //Sprite izquierda
        int coordenadas2[20]={39, 4, -38, 25,    81, 4, -38, 25,    125, 4, -38, 25,    168, 4, -38, 5,   206, 4, -38, 25};
        movleft= new Sprite(ruta, coordenadas2, frames);
        movleft->set_position(x, y);
        movleft->set_framerate(100);
        movleft->set_origin(6,7);

        //Sprite explosion
        frames = 6;
        std::string rutaExplosion("resources/proyectil.png");
        int coordenadas3[24]={23,25,16,13, 7,27,13,9, 80,27,10,9, 80,27,10,9, 7,27,13,9, 80,27,10,9};
        explosion= new Sprite(rutaExplosion, coordenadas3, frames);
        explosion->set_position(x, y);
        explosion->set_framerate(60);
        explosion->set_origin(8,6);
        
        if(px-ex<0){
            direccion=-1;
            spriteActual = movleft;
        }else{
            direccion=1;
            spriteActual = movright;
        }
        
    }else if(type == 11){
        sx = 1;
        sy = 1;
        int frames=4;
        std::string ruta("resources/escupitajoProyectil.png");
        //Sprite derecha
        //left, top, width, height
        int coordenadas[20]={5, 1, 30, 32, 47, 2, 38, 30, 92, 3, 32, 29, 127, 2, 41, 30, 170, 1, 28, 32};
        movright= new Sprite(ruta, coordenadas, frames);
        movright->set_position(x, y);
        movright->set_framerate(100);

        //Origen de coordenadas en el centro
        movright->set_origin(6,7);

        //Sprite izquierda
        int coordenadas2[20]={5, 1, 30, 32, 47, 2, 38, 30, 92, 3, 32, 29, 127, 2, 41, 30, 170, 1, 28, 32};
        movleft= new Sprite(ruta, coordenadas2, frames);
        movleft->set_position(x, y);
        movleft->set_framerate(100);
        movleft->set_origin(6,7);

        //Sprite explosion
        frames = 6;
        std::string rutaExplosion("resources/proyectil.png");
        int coordenadas3[24]={24,151,16,13, 8,153,13,9, 81,153,10,9, 81,153,10,9, 8,153,13,9, 81,153,10,9};
        explosion= new Sprite(rutaExplosion, coordenadas3, frames);
        explosion->set_position(x, y);
        explosion->set_framerate(60);
        explosion->set_origin(8,6);
        
        if(px-ex<0){
            direccion=-1;
            spriteActual = movleft;
        }else{
            direccion=1;
            spriteActual = movright;
        }
        
    }
    
    
    //otros detalles, como vida y daño
    danyo = d;
    explotar = false;
    muerto = false;
    
    //Inicialización del tiempo de vuelo esperado y de muerte
    muertetime = 600;
    vuelotime  = tiempoVida;
    
    //velocidad del proyectil según tipos
    if(id == 0 || id==1 || id == 10 || id == 11){
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
    //Si es de tipo 1, es una bala normal
    if(type == 0 || type == 1 || type == 10 || type == 11){
        //Si ha explotado, mostramos la animación de explosión
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
        //Si no ha explotado, movimiento interpolado
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
        
    //Si es de tipo 2, solamente mostramos el objeto apareciendo
    }else if(type == 2){
        if(vuelotime>0){
            explosion->set_position(x,y);
            explosion->set_scale(sx,sy);
            spriteActual = explosion;
            return(explosion);
        }else{
            muerto = true;
            return(explosion);
        }
        
    //Si es de tipo tumba, también crece de tamaño hasta llegar a 1
    }else if(type == 3){
        if(vuelotime>0){
            if(sy<1){
                sy +=0.16;
            }else{
                sy = 1;
            }
            if(vuelotime<200){
                sy -=0.5;
                if(sy<0){
                    sy = 0;
                }
            }
            explosion->set_position(x,y);
            explosion->set_scale(sx,sy);
            spriteActual = explosion;
            return(explosion);
        }else{
            muerto = true;
            return(explosion);
        }
    }else if(type == 4){
        if(vuelotime>0){
            if(p<1.0f && (lastx!=x||lasty!=y)){
                movx=(lastx*(1-p))+(x*p);
                movy=(lasty*(1-p))+(y*p);
                explosion->set_position(movx, movy);
                explosion->set_scale(sx, sy);
                spriteActual = explosion;
                return(explosion);
            }else{
                explosion->set_position(x, y);
                explosion->set_scale(sx, sy);
                spriteActual = explosion;
                return(explosion);
            }
        }else{
            muerto = true;
            return(explosion);
        }
     //Si no ha explotado, movimiento interpolado
    }
}

void Proyectil::volar(Personaje *p){
    lastx=x;
    lasty=y;
    //Si la bala es de tipo 1, se mueve y comprueba colisiones con el personaje
    if(type == 0 || type == 1){
        //Si no se le ha acabado el tiempo, o ha muerto o explotado
        if(vuelotime>=0 && !muerto && !explotar){
            //Comprobamos colision con el personaje
            if(spriteActual->comprobarColision(0,p->getAnimacionActiva())){
                p->herir(danyo);
                explotar = true;
            }else{
                if(objx-x>0){
                    if(x<3200){
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
    //Si es de tipo alerta solo aparece
    }else if(type == 2){
        x = objx;
        y = objy;
        lastx = objx;
        lasty = objy;
    }else if(type == 3){
        x = objx;
        y = objy;
        lastx = objx;
        lasty = objy;
        if(!explotar && !muerto){
            if(spriteActual->comprobarColision(0,p->getAnimacionActiva())){
                p->herir(danyo);
                explotar = true;
            } 
        }
        //Si el Sprite de tumba colisiona una base, provoca 1 daño
    }else if(type == 4){
        if(objy-y<0){
           y = objy;
           lastx=x;
           lasty=y;
        }else if(objy-y>0){
            if(objy-y>30){
                vy = 50.0f;
            }
            y += vy;
            lastx=x;
            lasty=y;
        }
        if(objx == x && objy == y){
            lasty=y;
            lastx=x;
        }
        if(!explotar && !muerto){
            if(spriteActual->comprobarColision(0,p->getAnimacionActiva())){
                p->herir(danyo);
                explotar = true;
            } 
        }
    }
}

void Proyectil::volarP(std::vector<Enemy*> enemigos){
    lastx=x;
    lasty=y;
    //Si la bala es de tipo 1, se mueve y comprueba colisiones con el personaje
    if(type == 10){
        
    }
    else if(type == 11){
        //Si no se le ha acabado el tiempo, o ha muerto o explotado
        if(vuelotime>=0 && !muerto && !explotar){
            //Comprobamos colision con el personaje
            for(int i = 0 ; i< enemigos.size() ; i++){
                if(spriteActual->comprobarColision(0,enemigos.at(i)->getAnimacionActiva())){
                    enemigos.at(i)->herir(danyo);
                    explotar = true;
                }
            }
            if(!explotar){
                if(objx-x>0){
                    if(x<3200){
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
}