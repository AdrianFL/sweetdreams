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


int main()
{
    //Creamos una ventana 
    sf::RenderWindow window(sf::VideoMode(1200, 640), "Ejecutable Hito 1");
    window.setVerticalSyncEnabled(true);
    Personaje p1(0);
    Mapa *mapa = new Mapa();
    mapa->leerMapa();
    
    Clock clock;
    int32_t time;
    int direccion=0;
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
        
        window.clear();
        mapa->dibuja(window);
        window.draw(p1.render(direccion)->render(time));
        window.display();
        direccion=0;
    }

    return 0;
}
