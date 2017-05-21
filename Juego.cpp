/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: javi
 * 
 * Created on May 20, 2017, 10:20 AM
 */

#include "Juego.h"
#include <iostream>
#include "E1jugador.h"
#include "E2jugador.h"
#include "Eintroduccion.h"
#include "Emenu.h"
#include "Eopciones.h"
#include "Epausa.h"

using namespace std;

Juego* Juego::pinstance = 0;
Juego* Juego::Instance(){
    
    if(pinstance == 0) pinstance = new Juego();

    return pinstance;
}
Juego::Juego(){
    windowWidth = 1200;
    windowHeight = 600;
    _state = 0;
    
}
void Juego::Update(){

    _state->Init();
    
}

State* Juego::currentState(){
    
    return _state;
   
}

void Juego::setState(State* state){
    _state = state;
    Update();
        
}

Juego::~Juego() {
    
  // delete EInGame::Instance(this);
  // std::cout << "Eliminamos el juego"   << std::endl;
    
}

void Juego::Init(){
    //VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings(
    window = new sf::RenderWindow(sf::VideoMode(this->windowWidth, this->windowHeight), "Ventana de juego");
    window->setFramerateLimit(60);

    //ECinematica::Instance(this)->Handle();
  //  Emenu::Instance(this,window);
    Emenu::Instance(this,window)->Handle();
    
    while(window->isOpen()){
       

        //Bucle de obtención de eventos
        while (window->pollEvent(event)){
            switch(event.type){   
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window->close();
                    break;
            }
        }
        
        if(_state!=0){ //Con el valor 0, el juego dejará de pintar  
            Update();
            //ES AQUI DONDE NO PARA DE ENTRAR
        }
        
    }
    
}
