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
    
    Clock clock;
    Clock updateclock;
    int32_t time;
    int32_t updatetime;
    
    int prueba=0;
    int option=0;
    
    //Bucle del juego
    while (window.isOpen())
    {
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
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                option=2;
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
            option=0;
        }

        //coger objetos
        /*else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            p1.cogeObjeto;
        }*/
             
        
        //Bloque Render
        float percentTick = std::min(1.0f, static_cast<float>(updateclock.getTime())/static_cast<float>(UPDATE_TICK_TIME));
        window.clear();
        mapa->dibuja(window);
        window.draw(hacha.getSprite()->render(time));
        window.draw(pvida.getSprite()->render(time));
        window.draw(p1.render(time, percentTick)->render(time));
        window.display();
    }

    return 0;
}
