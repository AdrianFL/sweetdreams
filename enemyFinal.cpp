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

enemyFinal::enemyFinal(int inix, int iniy, int v, int danyo)  : Enemy(2,inix,iniy,v,danyo) {
    distDisparo = 300;
    disparotime = -1;
    //Alerta de que un ataque final ha sido lanzado
    spattacklanzado = false;
    
    //Alerta de que las alertas de las tumbas han sido lanzadas
    tombalert = false;
    aparicionTumba = 3000;
    duracionTumba = 1500;
    
    //Daño de los hechizos
    danyotumba = 25;
}

enemyFinal::enemyFinal(const enemyFinal& orig): Enemy(orig) {
}

enemyFinal::~enemyFinal() {
}

void enemyFinal::atacar(){
    if(ataquetime < 0){
        ataquetime = 1000;
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
    if(spattacktime < 0){
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

std::vector<Proyectil*> enemyFinal::huir(Personaje *p, Mapa *m, int32_t tempo){
    //Controladores de iteraciones de disparo y ataques finales
    spattacktime-=tempo;
    disparotime-=tempo;
    
    //Array que devolverá al final
    std::vector<Proyectil*> conjunto;
    bool colisionaRaycast = false;
    
    
    //Posiciones centrales de personaje y enemigo
    int px = p->getXCoordinate();
    int py = p->getYCoordinate();
    
    int ex = x;
    int ey = y;
    
    //Posiciones a las que se dirigirá el enemigo
    float dirigex = px;
    float dirigey = py;
    
    //Ataca mientras el personaje enemigo tenga vida
    if(p->getVida()>0){
        //Fase 1: vida mayor a X (70% por ejemplo)
        /*if(vida>250){
            
            //Lanza ataques cada X segundos
            if(spattacktime>2000){
                //Añadimos raycast, que verificará si se puede ir en linea recta hasta el objetivo
                float distRaycast = distanciaAEnemigo(m,px,py,ex,ey);

                if(distRaycast<= distDisparo){
                    std::cout<<"Distancia error: "<<distRaycast<<" y el tiempo "<<disparotime<<std::endl;
                    if(disparotime<0){
                       disparotime = 50;
                       Proyectil* disparo = new Proyectil(0,px,py,ex,ey,5, 10.0f,10.0f, 1500);
                       conjunto.push_back(disparo);
                       atacar();
                    }
                }else{
                    if(disparotime<0){
                        disparotime = 600;
                        Proyectil* disparo = new Proyectil(0,px,py,ex,ey,10, 5.0f,5.0f, 1000);
                        conjunto.push_back(disparo);
                        atacar();
                    }
                }
            }
            if(spattacktime<0){
                spattacktime = 3200;
            }
        //Fase 2: vida menor a X (~70% por ejemplo)
        }else{*/
        
            //Si un ataque final no ha sido lanzado, lánzalo
            if(spattacklanzado == false){
                spattacklanzado = true;
                //int ataque = std::rand()%3;
                int ataque = 0;
                if(ataque == 0){
                    tombalert = true;
                    //Limites 3160 - 2007 x; 570-380 y
                    //Sector 1-1
                    tomblastx1 = std::rand()%(1153/2)+2007;
                    tomblasty1 = std::rand()%(190/2)+380;
                   
                    Proyectil* alerta = new Proyectil(2,tomblastx1,tomblasty1,ex,ey, 0, 0.0f, 0.0f, aparicionTumba);
                    conjunto.push_back(alerta);
                    
                    
                    //Sector 1-2
                    tomblastx2 =  std::rand()%(1153/2)+2007+1153/2;
                    tomblasty2 =  std::rand()%(190/2)+380;
                    Proyectil* alerta2 = new Proyectil(2,tomblastx2,tomblasty2,ex,ey, 0, 0.0f, 0.0f, aparicionTumba);
                    conjunto.push_back(alerta2);
                   
                    
                    //Sector 2-1
                    tomblastx3 =  std::rand()%(1153/2)+2007;
                    tomblasty3 =  std::rand()%(190/2)+380+190/2;
                    Proyectil* alerta3 = new Proyectil(2,tomblastx3,tomblasty3,ex,ey, 0, 0.0f, 0.0f, aparicionTumba);
                    conjunto.push_back(alerta3);
                    
                    
                    //Sector 2-2
                    tomblastx4 =  std::rand()%(1153/2)+2007+1153/2;
                    tomblasty4 =  std::rand()%(190/2)+380+190/2;
                    Proyectil* alerta4 = new Proyectil(2,tomblastx4,tomblasty4,ex,ey, 0, 0.0f, 0.0f, aparicionTumba);
                    conjunto.push_back(alerta4);
                    
                }
                if(ataque == 1){
                    
                }
                if(ataque == 2){
                    
                }
                
            }
            //Si se ha lanzado el ataque de la tumba, se generan los objetos
            if(tombalert == true && spattacktime<aparicionTumba-400){
                tombalert = false;
                Proyectil*  disparo = new Proyectil(3,tomblastx1,tomblasty1,ex,ey, danyotumba, 0.0f, 0.0f, duracionTumba);
                conjunto.push_back(disparo);
                
                Proyectil* disparo2 = new Proyectil(3,tomblastx2,tomblasty2,ex,ey, danyotumba, 0.0f, 0.0f, duracionTumba);
                conjunto.push_back(disparo2);
                
                Proyectil* disparo3 = new Proyectil(3,tomblastx3,tomblasty3,ex,ey, danyotumba, 0.0f, 0.0f, duracionTumba);
                conjunto.push_back(disparo3);
                
                                    
                Proyectil* disparo4 = new Proyectil(3,tomblastx4,tomblasty4,ex,ey, danyotumba, 0.0f, 0.0f, duracionTumba);
                conjunto.push_back(disparo4);
            }
            
            //Si se ha acabado el tiempo de espera del lanzamiento de ataque, reinícialo
            if(spattacktime<0){
                spattacktime = 3000;
                spattacklanzado = false;
            }
            

        //}
            
            
    }
    return conjunto;
}
