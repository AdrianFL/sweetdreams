/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enemyRange.cpp
 * Author: alexei
 * 
 * Created on 15 de mayo de 2017, 23:00
 */

#include "enemyRange.h"

enemyRange::enemyRange(int inix, int iniy, int vida, int danyo) : Enemy(1,inix,iniy,vida,danyo) {
    distDisparo = 200;
    disparotime = -1;
}

enemyRange::enemyRange(const enemyRange& orig) : Enemy(orig) {
}

enemyRange::~enemyRange() {
}

void enemyRange::atacar(){
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

Proyectil* enemyRange::perseguir(Personaje *p, Mapa *m, int32_t tempo){
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
        
        if(!spriteActual->comprobarColision(2,p->getAnimacionActiva())){
            //Añadimos raycast, que verificará si se puede ir en linea recta hasta el objetivo
            float distRaycast = distanciaAEnemigo(m,px,py,ex,ey);
                
            if(distRaycast!=-1){
                //Si está a rango de dispararle, le dispara
                if(distRaycast <= distDisparo){
                    if(disparotime<0){
                       disparotime = 600;
                       disparo = new Proyectil(0,px,py,ex,ey, 10,15.0f,15.0f);
                       atacar();
                    }
                }else{
                //Si no colisiona con el raycast, se mueve hasta la posición del personaje directamente
                    dirigex = ex;
                    dirigey = ey;

                    if(dirigex <px){
                        move(1);
                    }
                    else if(dirigex>px){
                        move(2);
                    }
                    if(dirigey>py){
                        move(3);
                    }
                    else if(dirigey<py){
                        move(4);
                    }
                    //Limpiamos el camino anteriormente recordado
                    if(caminoActual.size()>0){
                        caminoActual.clear();
                    }
                }
            }else{

                //-------Añadir previamente el cálculo del personaje más cercano si se
                //le pasa un array de personajes 
                //Discernir también por quien tiene menos vida y cosas así

                nodoObjetivo = NULL;
                //IAtime = 200;

                //Cogemos el punto del nodo en el array de nodos
                int nodoPx = px/50;
                int nodoPy = py/50;
                int nodoEx = ex/50;
                int nodoEy = ey/50;

                caminoActual =  m->CalcRoute(nodoPx,nodoPy, nodoEx, nodoEy);


                //Si el camino es mayor que 1, 
                if(caminoActual.size()>=1){
                    //El nodo siguiente es el último de esta lista, y al cogerlo lo sacamos de la misma
                    nodoObjetivo =caminoActual.at(caminoActual.size()-1);

                    //std::cout<<"nodo actual: "<<nodoObjetivo->x<<":"<<nodoObjetivo->y<< " en pos " << (nodoObjetivo->centrox) <<","<< (nodoObjetivo->centroy) << " y el enemigo "<<ex<<","<<ey<<std::endl;


                    //Si colisiona con ese nodo, se coge el siguiente
                    if(nodoObjetivo->getParcela()->comprobarColision(0,spriteActual)){
                        caminoActual.pop_back();
                        //std::cout<<"nodo entrado"<<std::endl;

                        if(caminoActual.size() == 1){
                            caminoActual.clear();
                        }
                    }

                }
                if(!nodoObjetivo){
                    nodoObjetivo = m->devuelveNodo(nodoEx,nodoEy);

                    move(0);
                }else{
                    dirigex = (float)ex / nodoObjetivo->centrox;
                    dirigey = (float)ey / nodoObjetivo->centroy;


                    //std::cout<<"magia: "<<dirigex<<","<<dirigey<<std::endl;

                    if(dirigex <1){
                        move(1);
                    }
                    else if(dirigex>1){
                        move(2);
                    }
                    if(dirigey>1){
                        move(3);
                    }
                    else if(dirigey<1){
                        move(4);
                    }
                }
            }
        }
    }
    return disparo;
}


