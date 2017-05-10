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
#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "Clock.hpp"
#include "Mapa.h"
#include <fstream>
#include <cstring>
#include "Arma.h"
#include "Pocion.h"


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
    int32_t time;
    int direccion=0;
    
    int prueba=0;
    
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            p1.move(1);
            direccion=1;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            p1.move(2);
            direccion=-1;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            p1.move(3);
            direccion=p1.getDireccion();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            p1.move(4);
            direccion=p1.getDireccion();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
            p1.usaPocion(pvida); 
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
            p1.usaPocion(pmana);
        }
        
        //coger objetos
        /*else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            p1.cogeObjeto;
        }*/
       
        
        window.clear();
        mapa->dibuja(window);
        window.draw(hacha.getSprite()->render(time));
        window.draw(pvida.getSprite()->render(time));
        window.draw(p1.render(direccion, time)->render(time));
        window.display();
        direccion=0;
    }

    return 0;
}
