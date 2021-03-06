/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: adrian
 *
 * Created on 28 de febrero de 2017, 13:46
 */

/*#include <iostream>
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
#include "hechizo.h"
#include "Musica.hpp"

#define UPDATE_TICK_TIME 1000.0/15.0


int main()
{
    //Tiempo aleatorio
    std::srand(std::time(0));
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(1200, 640), "Ejecutable Hito 2");
    window.setVerticalSyncEnabled(true);
    Personaje p1(0);
    Arma hacha("h", 750, 450);
    Arma* espada=new Arma("e", 850, 450);
    Hechizo* meteoro=new Hechizo("m", 650, 500);
    Hechizo* escupitajo=new Hechizo("e", 300, 500);
    Pocion* pvida=new Pocion("v", 400, 450);
    Pocion* pmana=new Pocion("m", 400, 520);
    Mapa *mapa = new Mapa();
    
    std::string rutamusica("resources/sweetdreams.ogg");
    Musica* musica = new Musica(rutamusica);
    
    musica->setLoop(true);
    musica->Play();
    
    if(sf::Joystick::isConnected(0)){
        std::cout << "mando conectado" << std::endl;
        std::cout << "Botones:" << sf::Joystick::getButtonCount(0) << std::endl;
    }
    //1 para leer el mapa 1, 2 para leer el mapa 2
    mapa->leerMapa(1);
    
    Camara *camara=new Camara(window.getSize().x, window.getSize().y, 12, *mapa);
    
    bool recogida=true;
    int movimiento=0;
    
    //###################
    enemyMelee enemigoM(850,450,30,1);
    enemyRange enemigoR(100,500,30,1);
    enemyFinal enemigoFinal(2500,500,300,5);

    std::vector<Proyectil*> proyectiles;
    std::vector<Proyectil*> disparoFinal;
    //###################
    
    Clock clock;
    Clock updateclock;
    int32_t time;
    int32_t updatetime;
    
    int prueba=0;
    int option=0;
    
    //Bucle del juego
    while (window.isOpen())
    {
        //#############
        Proyectil* disparo = NULL;
        //############
        
        //Bucle de obtención de eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            switch(event.type){
                
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;

            }
            
        }
        time=clock.restart();
        
            
        if(updateclock.getTime() > UPDATE_TICK_TIME)
        {
            updatetime=updateclock.restart();
        //Bloque update
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X)>50){
                option=1;
                movimiento=1;                
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X)<-50){
                option=2;
                movimiento=2;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y)<-50){
                option=3;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y)>50){
                option=4;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Joystick::isButtonPressed(0, 4)){
                p1.usaPocion("vida"); 
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Joystick::isButtonPressed(0, 5)){
                p1.usaPocion("mana");
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U) || sf::Joystick::isButtonPressed(0, 0)){
                p1.atacar();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
                p1.herir(25);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
 p1.activaRecogida();
                recogida=false;
                if(recogida==false){
                    if(p1.getDireccion()>0){
                        if(pvida!=NULL && pvida->getPosX()>p1.getXCoordinate() && pvida->getPosX()-p1.getXCoordinate()<50 && pvida->getPosY()-p1.getYCoordinate()<30 && pvida->getPosY()-p1.getYCoordinate()>-30){
                            if(p1.getNumPVida()<3){
                                pvida->deletePocion();
                                pvida=NULL;
                                p1.aumentaPVida();
                                recogida=true;
                            }
                          }
                    }
                    else{
                        if(pvida!=NULL && pvida->getPosX()<p1.getXCoordinate() && p1.getXCoordinate()-pvida->getPosX()<50 && pvida->getPosY()-p1.getYCoordinate()<30 && pvida->getPosY()-p1.getYCoordinate()>-30){
                            if(p1.getNumPVida()<3){
                                pvida->deletePocion();
                                pvida=NULL;
                                p1.aumentaPVida();     
                                recogida=true;
                            }
                        }
                    }
                }
                if(recogida==false){
                    if(p1.getDireccion()>0){
                        if(pmana!=NULL && pmana->getPosX()>p1.getXCoordinate() && pmana->getPosX()-p1.getXCoordinate()<50 && pmana->getPosY()-p1.getYCoordinate()<30 && pmana->getPosY()-p1.getYCoordinate()>-30){
                            if(p1.getNumPMana()<3){
                                pmana->deletePocion();
                                pmana=NULL;
                                p1.aumentaPMana();
                                recogida=true;
                            }
                        }
                    }
                    else{
                       if(pmana!=NULL && pmana->getPosX()<p1.getXCoordinate() && p1.getXCoordinate()-pmana->getPosX()<50 && pmana->getPosY()-p1.getYCoordinate()<30 && pmana->getPosY()-p1.getYCoordinate()>-30){
                            if(p1.getNumPMana()<3){
                                pmana->deletePocion();
                                pmana=NULL;
                                p1.aumentaPMana();
                                recogida=true;
                            }
                        }
                    }
                }
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y) || sf::Joystick::isButtonPressed(0, 3)){
                p1.lanzarHechizo();
            }
            p1.move(option);
            if(movimiento==1){
                 camara->moverDer(p1);
            }
            else if(movimiento==2){
                camara->moverIzq(p1);
            }
            option=0;
            
            //######################
            enemigoM.perseguir(&p1,mapa);
            
            //Enemigo de rango
            disparo = enemigoR.perseguir(&p1,mapa, time);
            disparoFinal = enemigoFinal.huir(&p1,mapa,time);
            //Control de los disparos
            if(disparo!=NULL){
                proyectiles.push_back(disparo);
            }

            if(disparoFinal.size()>0){
                for(int i = 0; i<disparoFinal.size();i++){
                    Proyectil* aux = disparoFinal.at(i);
                    proyectiles.push_back(aux);
                }
            }
            
            int destruidos=0; //Cuenta los destruidos, por si se da más de un proyectil destruido a la vez (casi imposible pero por si acaso)
            for(int i = 0; i<proyectiles.size();i++){
                if(!proyectiles[i]->muerto){
                    proyectiles[i]->volar(&p1);
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

        //coger objetos
        /*else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            p1.cogeObjeto;
        }*/
        
       
        
        //Bloque Render
 /*       float percentTick = std::min(1.0f, static_cast<float>(updateclock.getTime())/static_cast<float>(UPDATE_TICK_TIME));
        window.clear();
        mapa->dibuja(window);

 */       
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

 /*       //Verifico que el raycast va
        window.draw(enemigoR.raycast->render(time));
        window.draw(enemigoM.raycast->render(time));
        window.draw(enemigoFinal.raycast->render(time));

        //###################
        
        if(pvida!=NULL){
           window.draw(pvida->getSprite()->render(time));
        }
        if(pmana!=NULL){
            window.draw(pmana->getSprite()->render(time));
        }
        if(espada!=NULL){
            window.draw(espada->getSprite()->render(time));
        }
        if(meteoro!=NULL){
            window.draw(meteoro->getSpriteHechizo()->render(time));
        }
        if(escupitajo!=NULL){
            window.draw(escupitajo->getSpriteHechizo()->render(time));
        }
        window.draw(p1.render(time, percentTick)->render(time));
        
        //###################
         window.draw(enemigoM.render(time, percentTick)->render(time));
         window.draw(enemigoR.render(time, percentTick)->render(time));
         window.draw(enemigoFinal.render(time, percentTick)->render(time));
         for(int i =0; i<proyectiles.size();i++){
             window.draw(proyectiles[i]->render(time,percentTick)->render(time));
         }
         
        //###################
         camara->draw(window);
         
        window.display();
    }

    return 0;
}*/
