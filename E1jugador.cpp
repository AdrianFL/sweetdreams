/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   E1jugador.cpp
 * Author: javi
 * 
 * Created on May 20, 2017, 10:22 AM
 */


#include "E1jugador.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include "E2jugador.h"
#include "Eintroduccion.h"
#include "Emenu.h"
//#include "Eopciones.h"
#include "Epausa.h"
#include "Juego.h"


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "Clock.hpp"
#include "Mapa.h"
#include <fstream>
#include <cstring>
#include "Arma.h"
#include "Pocion.h"
#include "enemyMelee.h"
#include "enemyRange.h"
#include "enemyFinal.h"
#include "Proyectil.h"
#include "Camara.h"

#define UPDATE_TICK_TIME 1000.0/15.0


E1jugador* E1jugador::pinstance = 0;
E1jugador* E1jugador::Instance(Juego* context,sf::RenderWindow *w){
    
    if(pinstance == 0) pinstance = new E1jugador(context,w);

    return pinstance;
}
E1jugador::E1jugador(Juego* context,sf::RenderWindow *w){ //CONSTRUCTOR REAL
    window=w;
    _context = context;
    //08080808080808080808080808080808080808080808080808080808080808080808080808080808080808
    //08080808080808080808080808080808080808080808080808080808080808080808080808080808080808
    window->setVerticalSyncEnabled(true);
    p1= new Personaje(0);
    hacha=new Arma("h", 750, 450);
    espada=new Arma("e", 850, 450);
    pvida=new Pocion("v", 400, 450);
    pmana=new Pocion("m", 400, 520);
    mapa= new Mapa;
    //1 para leer el mapa 1, 2 para leer el mapa 2
    mapa->leerMapa(1);
    
    camara=new Camara(window->getSize().x, window->getSize().y, 12, *mapa);
    
    recogida=true;
    movimiento=0;
    
    //###################
    enemigoM= new enemyMelee(850,450,30,1);
    enemigoR= new enemyRange(100,500,30,1);
    enemigoFinal= new enemyFinal(2500,500,300,5);
    std::vector<Proyectil*> proyectiles;
    std::vector<Proyectil*> disparoFinal;
    //###################
    
    clock;
    updateclock;
    time;
    updatetime;
    
    prueba=0;
    option=0;
    //08080808080808080808080808080808080808080808080808080808080808080808080808080808080808
    //08080808080808080808080808080808080808080808080808080808080808080808080808080808080808
}

void E1jugador::Handle(){
    
   // std::cout << "E1JUGADOR: "  << this << std::endl;
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.
   // std::cout << _context<< std::endl;
    std::cout << "E1JUGADOR handle!"<< std::endl;
    
    
}
Juego* E1jugador::getContext(){
    
    return _context;    //Para recuperar el contexto
    
}

void E1jugador::Init(){
    std::cout << "init E1jugador" << std::endl;
    salida=false;
   run(*Juego::Instance()->window);
   
}
int E1jugador::run(sf::RenderWindow &window){
    //buclue principal del juego  
    while(window.isOpen() && !salida){
        sf::Event event;
        while(window.pollEvent(event)){
            CUpdate2( event); //llamamos a la funcion teclas /update
        }
        
        //Tiempo para el render
        time=clock.restart();
        if(updateclock.getTime() > UPDATE_TICK_TIME)
        {
            Update();
        }
        Render(); //llamamos a la funcion render
    }
    return 0;
    
}
void E1jugador::Update(){
    Proyectil* disparo = NULL;
    updatetime=updateclock.restart();
    //Bloque update
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        option=1;
        movimiento=1;                
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        option=2;
        movimiento=2;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        option=3;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        option=4;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        p1->usaPocion("vida"); 
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        p1->usaPocion("mana");
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
        p1->atacar();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
        p1->herir(25);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
        p1->activaRecogida();
        recogida=false;
        if(recogida==false){
            if(p1->getDireccion()>0){
                if(pvida!=NULL && pvida->getPosX()>p1->getXCoordinate() && pvida->getPosX()-p1->getXCoordinate()<50 && pvida->getPosY()-p1->getYCoordinate()<30 && pvida->getPosY()-p1->getYCoordinate()>-30){
                    if(p1->getNumPVida()<3){
                        pvida->deletePocion();
                        pvida=NULL;
                        p1->aumentaPVida();
                        recogida=true;
                    }
                  }
            }
            else{
                if(pvida!=NULL && pvida->getPosX()<p1->getXCoordinate() && p1->getXCoordinate()-pvida->getPosX()<50 && pvida->getPosY()-p1->getYCoordinate()<30 && pvida->getPosY()-p1->getYCoordinate()>-30){
                    if(p1->getNumPVida()<3){
                        pvida->deletePocion();
                        pvida=NULL;
                        p1->aumentaPVida();     
                        recogida=true;
                    }
                }
            }
        }
        if(recogida==false){
            if(p1->getDireccion()>0){
                if(pmana!=NULL && pmana->getPosX()>p1->getXCoordinate() && pmana->getPosX()-p1->getXCoordinate()<50 && pmana->getPosY()-p1->getYCoordinate()<30 && pmana->getPosY()-p1->getYCoordinate()>-30){
                    if(p1->getNumPMana()<3){
                        pmana->deletePocion();
                        pmana=NULL;
                        p1->aumentaPMana();
                        recogida=true;
                    }
                }
            }
            else{
               if(pmana!=NULL && pmana->getPosX()<p1->getXCoordinate() && p1->getXCoordinate()-pmana->getPosX()<50 && pmana->getPosY()-p1->getYCoordinate()<30 && pmana->getPosY()-p1->getYCoordinate()>-30){
                    if(p1->getNumPMana()<3){
                        pmana->deletePocion();
                        pmana=NULL;
                        p1->aumentaPMana();
                        recogida=true;
                    }
                }
            }
        }
    }
    p1->move(option);
    if(movimiento==1){
         camara->moverDer(*p1);
    }
    else if(movimiento==2){
        camara->moverIzq(*p1);
    }
    option=0;

    //######################
    //Enemigo melee
    enemigoM->perseguir(p1,mapa);

    //Enemigo de rango
    disparo = enemigoR->perseguir(p1,mapa, time);

    //Enemigo Final
    disparoFinal = enemigoFinal->huir(p1,mapa,time);

    //Control de los disparos
    if(disparo!=NULL){
        proyectiles.push_back(disparo);
    }
    for(int i = 0; i<disparoFinal.size();i++){
        Proyectil* aux = disparoFinal.at(i);
        proyectiles.push_back(aux);
    }
    int destruidos=0; //Cuenta los destruidos, por si se da más de un proyectil destruido a la vez (casi imposible pero por si acaso)
    for(int i = 0; i<proyectiles.size();i++){
        if(!proyectiles[i]->muerto){
            proyectiles[i]->volar(p1);
        }else{
            //Destruir proyectiles muertos
            Proyectil* proyectilMuerto  = proyectiles.at(i-destruidos);
            proyectiles.erase(proyectiles.begin()+i-destruidos);
            destruidos++;
            delete proyectilMuerto;
        }
    }
    //######################
}

int E1jugador::CUpdate2(sf::Event event){
     switch(event.type){
        case sf::Event::KeyReleased:
                            
        switch(event.key.code){
            case sf::Keyboard::Escape:
                salida=true;
                Emenu::Instance(Juego::Instance(),window)->Handle();
                break;
            case sf::Keyboard::P:
                salida=true;
                Epausa::Instance(Juego::Instance(),window)->Handle(true);
                break;

        }
     }
     
         
    return 0;
}

void E1jugador::Render(){
    float percentTick = std::min(1.0f, static_cast<float>(updateclock.getTime())/static_cast<float>(UPDATE_TICK_TIME));
    window->clear();
    mapa->dibuja(*window);

     //###########################################
    //mapa->dibujaNodos(window);
    //mapa->dibujaObs(window);



    //Verifico que el camino va
    /*for(int i = 0; i < enemigoM.caminoActual.size();i++){
        window.draw(enemigoM.caminoActual.at(i)->getParcela()->render(time));
    }
    for(int i = 0; i < enemigoR.caminoActual.size();i++){
        window.draw(enemigoR.caminoActual.at(i)->getParcela()->render(time));
    }*/
    //Verifico que el raycast va
    window->draw(enemigoR->raycast->render(time));
    window->draw(enemigoM->raycast->render(time));
    window->draw(enemigoFinal->raycast->render(time));
    //###################

    window->draw(hacha->getSprite()->render(time));
    if(pvida!=NULL){
       window->draw(pvida->getSprite()->render(time));
    }
    if(pmana!=NULL){
        window->draw(pmana->getSprite()->render(time));
    }
    if(espada!=NULL){
        window->draw(espada->getSprite()->render(time));
    }
    window->draw(p1->render(time, percentTick)->render(time));

    //###################
    window->draw(enemigoM->render(time, percentTick)->render(time));
    window->draw(enemigoR->render(time, percentTick)->render(time));
    window->draw(enemigoFinal->render(time, percentTick)->render(time));
    for(int i =0; i<proyectiles.size();i++){
        window->draw(proyectiles[i]->render(time,percentTick)->render(time));
    }

    //###################


    camara->draw(*window);

    window->display();
}

void E1jugador::reiniciar(){
    delete p1;
    delete hacha;
    delete espada;
    delete pvida;
    delete pmana;
    delete mapa;
  //  delete recogida;
    delete camara;
  //  delete recogida;
  //  delete movimiento; 
    delete enemigoM;
    delete enemigoR;
    delete enemigoFinal;
  //  delete proyectiles; 
  //  delete disparoFinal;
  //  delete clock;
  //  delete updateclock;
  //  delete option;
  //  delete prueba;
  //  delete updatetime;
  //  delete time;
}

E1jugador::~E1jugador(){
    _context = 0;
    pinstance = 0;
}