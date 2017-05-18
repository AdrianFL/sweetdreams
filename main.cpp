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
#include "Proyectil.h"
#include "Camara.h"

#define UPDATE_TICK_TIME 1000.0/15.0


int main()
{
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(1200, 640), "Ejecutable Hito 2");
    window.setVerticalSyncEnabled(true);
    Personaje p1(0);
    Arma hacha("h", 750, 450);
    Pocion pvida("v", 400, 450);
    Pocion pmana("m", 400, 520);
    Mapa *mapa = new Mapa();
    //1 para leer el mapa 1, 2 para leer el mapa 2
    mapa->leerMapa(1);
    
    Camara *camara=new Camara(window.getSize().x, window.getSize().y, 12, *mapa);
    
    int movimiento=0;
    
    //###################
    enemyMelee enemigoM(850,450,30,1);
    enemyRange enemigoR(100,500,30,1);
    
    std::vector<Proyectil*> proyectiles;
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
                p1.usaPocion(pvida); 
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
                p1.usaPocion(pmana);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
                p1.atacar();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
                p1.herir(25);
            }
            p1.move(option);
            if(movimiento==1){
                 camara->moverDer(p1);
            }
            if(movimiento==2){
                camara->moverIzq(p1);
            }
            option=0;
            
            //######################
            //Enemigo melee
            enemigoM.perseguir(&p1,mapa);
            
            //Enemigo de rango
            disparo = enemigoR.perseguir(&p1,mapa, time);
            
            //Control de los disparos
            if(disparo!=NULL){
                proyectiles.push_back(disparo);
            }
            int destruidos=0; //Cuenta los destruidos, por si se da más de un proyectil destruido a la vez (casi imposible pero por si acaso)
            for(int i = 0; i<proyectiles.size();i++){
                if(!proyectiles[i]->muerto){
                    proyectiles[i]->volar(&p1);
                }else{
                    //Destruir proyectiles muertos
                    proyectiles.erase(proyectiles.begin()+i-destruidos);
                    destruidos++;
                }
            }
            //######################
        }

        //coger objetos
        /*else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            p1.cogeObjeto;
        }*/
        
       
        
        //Bloque Render
        float percentTick = std::min(1.0f, static_cast<float>(updateclock.getTime())/static_cast<float>(UPDATE_TICK_TIME));
        window.clear();
        mapa->dibuja(window);
        
         //###########################################
        //mapa->dibujaNodos(window);
        mapa->dibujaObs(window);
        
        
        
        //Verifico que el camino va
        for(int i = 0; i < enemigoM.caminoActual.size();i++){
            window.draw(enemigoM.caminoActual.at(i)->getParcela()->render(time));
        }
        for(int i = 0; i < enemigoR.caminoActual.size();i++){
            window.draw(enemigoR.caminoActual.at(i)->getParcela()->render(time));
        }
        //Verifico que el raycast va
        window.draw(enemigoR.raycast->render(time));
        window.draw(enemigoM.raycast->render(time));
        //###################
        
        window.draw(hacha.getSprite()->render(time));
        window.draw(pvida.getSprite()->render(time));
        window.draw(p1.render(time, percentTick)->render(time));
        
        //###################
         window.draw(enemigoM.render(time, percentTick)->render(time));
         window.draw(enemigoR.render(time, percentTick)->render(time));
         for(int i =0; i<proyectiles.size();i++){
             window.draw(proyectiles[i]->render(time,percentTick)->render(time));
         }
        //###################
         
         
         camara->draw(window);
         
        window.display();
    }

    return 0;
}
