/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   E2jugador.cpp
 * Author: javi
 * 
 * Created on May 20, 2017, 10:21 AM
 */

#include "E2jugador.h"
#include "Emenu.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include "E1jugador.h"
#include "Eintroduccion.h"
#include "Eopciones.h"
#include "Epausa.h"

E2jugador* E2jugador::pinstance = 0;
E2jugador* E2jugador::Instance(Juego* context,sf::RenderWindow *w){
    
    if(pinstance == 0) pinstance = new E2jugador(context,w);

    return pinstance;
}


E2jugador::E2jugador(Juego* context,sf::RenderWindow *w){ //CONSTRUCTOR REAL
    window=w;
    _context = context;
}


void E2jugador::Handle(){
    
 //   std::cout << "E1JUGADOR: "  << this << std::endl;
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.
    std::cout << "E2JUGADOR handle!"<< std::endl;
    
}
Juego* E2jugador::getContext(){
    
    return _context;    //Para recuperar el contexto
    
}


void E2jugador::Init(){
    
  // run(*Juego::Instance()->window);
    std::cout << "init E2jugador" << std::endl;
    salida=false;
   run(*Juego::Instance()->window);
   
}
int E2jugador::run(sf::RenderWindow &window){
    //buclue principal del juego  
    while(window.isOpen() && !salida){
        sf::Event event;
        while(window.pollEvent(event)){ 
            
            CUpdate2( event); //llamamos a la funcion teclas /update
        }
        
        Render(); //llamamos a la funcion render
    }
    return 0;
    
}
int E2jugador::CUpdate2(sf::Event event){
     switch(event.type){
         case sf::Event::KeyReleased:
                            
                            switch(event.key.code){
                                case sf::Keyboard::Escape:
                                    salida=true;
                                    Emenu::Instance(Juego::Instance(),window)->Handle();
                                    break;
                                case sf::Keyboard::P:
                                    salida=true;
                                    Epausa::Instance(Juego::Instance(),window)->Handle(false);
                                    break;
                                    
                            }
     }
     
         
    return 0;
}
void E2jugador::Update(){
    
}
void E2jugador::Render(){
    
}

E2jugador::~E2jugador(){
    _context = 0;
    pinstance = 0;
}
