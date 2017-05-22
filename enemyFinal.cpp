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
    distDisparo = 200;
    
    //spattacktime = -1;
    //Alerta de que un ataque ha sido lanzado
    spattacklanzado = false;
    
    //Alerta de que las alertas de las tumbas han sido lanzadas
    tombalert = false;
    aparicionTumba = 1300;
    duracionTumba = 1600;
    duracionAlertaTumba = 2700;
    
    //Alerta y duraciones de las zanahorias
    zanahoriaalert = false;
    aparicionZanahoria = 2000;
    duracionZanahoria  = 1500;
    duracionAlertaZanahoria = 3400;
    
    //Daño de los hechizos
    danyotumba      = 25;
    danyoZanahoria  = 50;

}

enemyFinal::enemyFinal(const enemyFinal& orig): Enemy(orig) {
}

enemyFinal::~enemyFinal() {
}

void enemyFinal::atacar(){
    if(ataquetime < 0){
        //ataquetime = 1000;
        ataquetime = 360;
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
        //Muestra al monstruo durante 3 segundos
        spattacktime = 960*4;
    }
}

std::vector<Proyectil*> enemyFinal::huir(Personaje *p, Mapa *m, int32_t tempo){
    //Controladores de iteraciones de disparo y ataques finales
    //spattacktime-=tempo;
    //disparotime-=tempo;
    
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
    
    if(p->getVida()>0){
        //Fase 1: vida mayor a X (70% por ejemplo)
        if(vida>250){
            
            //Los ataques se hacen cada 8 segundos
            if(cambiatime<0){
                cambiatime = 6000;
            }else{
                
                //La duración del ataque es de 3 segundos
                if(cambiatime>=3000){
                    //Orientación del enemigo al atacar
                    if(px-ex>0){
                        direccion = 1;
                    }else{
                        direccion = -1;
                    }
                
                    //Añadimos raycast, que verificará si se puede ir en linea recta hasta el objetivo
                    float distRaycast = distanciaAEnemigo(m,px,py,ex,ey);;
                    if(distRaycast<= distDisparo){
                        if(disparotime<0){
                           disparotime = 300;
                           atacar();
                           Proyectil* disparo = new Proyectil(0,px,py,ex,ey,2,10.0f,10.0f, 1500);
                           conjunto.push_back(disparo);
                        }
                    }else{
                        if(disparotime<0){
                            disparotime = 1000;
                            atacar();
                            Proyectil* disparo = new Proyectil(0,px,py,ex,ey,10, 5.0f,5.0f, 2000);
                            conjunto.push_back(disparo);
                        }
                    }
                }
            }
        //Fase 2: vida menor a X (~70% por ejemplo)
        }else{
            //Fase de ataque cada 8 segundos
            if(cambiatime<0){
                cambiatime=6000;
                spattacklanzado = false;
            }else{
                //Duración de 5 segundos de la fase (8-3)
                //if(cambiatime<6000){
                    if(spattacklanzado == false){
                        //Lanza la animación de ataque
                        atacarSpecial();
                        //Ataque lanzado
                        spattacklanzado = true;
                        
                        //Elige aleatoriamente el ataque
                        int ataque = std::rand()%2;
                        if(ataque == 0){
                            tombalert = true;
                            //Limites 3160 - 2007 x; 570-380 y
                            //Sector 1-1
                            tomblastx1 = std::rand()%((1153-75)/2)+2000+34;
                            tomblasty1 = std::rand()%((190-48)/2)+380+40;

                            Proyectil* alerta = new Proyectil(2,tomblastx1,tomblasty1,ex,ey, 0, 0.0f, 0.0f, duracionAlertaTumba);
                            conjunto.push_back(alerta);


                            //Sector 1-2
                            tomblastx2 =  std::rand()%((1153-75)/2)+2007+1153/2+34;
                            tomblasty2 =  std::rand()%((190-48)/2)+380+40;
                            Proyectil* alerta2 = new Proyectil(2,tomblastx2,tomblasty2,ex,ey, 0, 0.0f, 0.0f, duracionAlertaTumba);
                            conjunto.push_back(alerta2);


                            //Sector 2-1
                            tomblastx3 =  std::rand()%((1153-75)/2)+2007+34;
                            tomblasty3 =  std::rand()%((190-48)/2)+380+190/2+40;
                            Proyectil* alerta3 = new Proyectil(2,tomblastx3,tomblasty3,ex,ey, 0, 0.0f, 0.0f, duracionAlertaTumba);
                            conjunto.push_back(alerta3);


                            //Sector 2-2
                            tomblastx4 =  std::rand()%((1153-75)/2)+2007+1153/2+34;
                            tomblasty4 =  std::rand()%((190-48)/2)+380+190/2+40;
                            Proyectil* alerta4 = new Proyectil(2,tomblastx4,tomblasty4,ex,ey, 0, 0.0f, 0.0f, duracionAlertaTumba);
                            conjunto.push_back(alerta4);
                        }
                        if(ataque == 1){
                            zanahoriaalert = true;
                            //6 y pueden aparecer en zonas variables, se pueden superponer en  valores diferentes
                            //Lado izquierda
                            int zona = std::rand()%6+1;
                            zanalastx1 = zona*(1140-80)/6+2000+40;
                            zanalasty1 = 545;

                            Proyectil* alerta = new Proyectil(2,zanalastx1,zanalasty1,ex,ey, 1, 0.0f, 0.0f, duracionAlertaZanahoria);
                            conjunto.push_back(alerta);


                            //Lado derecha
                            int zona2 = std::rand()%6+1;
                            zanalastx2 =  zona2*(1140-120)/6+2000+40;
                            zanalasty2 =  545;

                            Proyectil* alerta2 = new Proyectil(2,zanalastx2,zanalasty2,ex,ey, 1, 0.0f, 0.0f, duracionAlertaZanahoria);
                            conjunto.push_back(alerta2);
                        }
                        /*if(ataque == 2){
                            if(disparotime<0){
                                disparotime = 60;
                                atacar();
                                Proyectil* disparo = new Proyectil(0,px+200,py,ex,ey,20, 5.0f,5.0f, 2000);
                                conjunto.push_back(disparo);
                                
                                disparo = new Proyectil(0,px*std::cos(cambiatime),py*std::cos(cambiatime),ex,ey,20, 5.0f,5.0f, 2000);
                                conjunto.push_back(disparo);
                                
                                disparo = new Proyectil(0,px+200,py+200,ex,ey,20, 5.0f,5.0f, 2000);
                                conjunto.push_back(disparo);
                                
                                disparo = new Proyectil(0,px+200,py+200,ex,ey,20, 5.0f,5.0f, 2000);
                                conjunto.push_back(disparo);
                                
                                disparo = new Proyectil(0,px+200,py+200,ex,ey,20, 5.0f,5.0f, 2000);
                                conjunto.push_back(disparo);
                                
                                disparo = new Proyectil(0,px+200,py+200,ex,ey,20, 5.0f,5.0f, 2000);
                                conjunto.push_back(disparo);
                                
                                disparo = new Proyectil(0,px+200,py+200,ex,ey,20, 5.0f,5.0f, 2000);
                                conjunto.push_back(disparo);
                            }
                        }*/
                    }
                //}
                if(tombalert == true && cambiatime<6000-aparicionTumba){
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

                //Si se ha lanzado un ataque zanahoria, se controla su existencia
                if(zanahoriaalert == true && cambiatime<6000-aparicionZanahoria){
                    zanahoriaalert = false;
                    Proyectil*  disparo = new Proyectil(4,zanalastx1,zanalasty1,zanalastx1,zanalasty1, danyoZanahoria, 0.0f, 20.0f, duracionZanahoria);
                    conjunto.push_back(disparo);

                    Proyectil* disparo2 = new Proyectil(4,zanalastx2,zanalasty2,zanalastx2,zanalasty2, danyoZanahoria, 0.0f, 20.0f, duracionZanahoria);
                    conjunto.push_back(disparo2);
                }
            }
        }
    }
    return conjunto;
}
