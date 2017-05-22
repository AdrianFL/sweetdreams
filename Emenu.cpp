/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Emenu.cpp
 * Author: javi
 * 
 * Created on May 20, 2017, 10:21 AM
 */


#include "Emenu.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include "E1jugador.h"
#include "E2jugador.h"
#include "Eintroduccion.h"
#include "Eopciones.h"
#include "Epausa.h"
#include <vector>
#include <string> 

using namespace std;

Emenu* Emenu::pinstance = 0;
Emenu* Emenu::Instance(Juego* context,sf::RenderWindow *w){
    
    if(pinstance == 0) pinstance = new Emenu(context,w);

    return pinstance;
}

Emenu::Emenu(Juego* context,sf::RenderWindow *w){ //CONSTRUCTOR REAL
    
    window=w;
    _context = context; //En el momento en el que se crea el estado, se asigna su contexto.
    int width = Juego::Instance()->window->getSize().x;
    int height = Juego::Instance()->window->getSize().y;
    
    
    if(!font.loadFromFile("resources/a.ttf")){
        
    }
    int i=0;
    
    opcion[0].setFont(font);
    opcion[0].setColor(sf::Color::Red);
    opcion[0].setString("Nueva Partida");
    opcion[0].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMS+1)*1);
   // opcion[0].setPosition(2,2);
    opcion[1].setFont(font);
    opcion[1].setColor(sf::Color::Black);
    opcion[1].setString("Opciones");
    opcion[1].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMS+1)*2);
    opcion[2].setFont(font);
    opcion[2].setColor(sf::Color::Black);
    opcion[2].setString("Salir");
    opcion[2].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMS+1)*3);
    
    
    opcionj[0].setFont(font);
    opcionj[0].setColor(sf::Color::Red);
    opcionj[0].setString("Un Jugador");
    opcionj[0].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMS+1)*1);
    opcionj[1].setFont(font);
    opcionj[1].setColor(sf::Color::Black);
    opcionj[1].setString("Dos Jugadores");
    opcionj[1].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMS+1)*2);
    selected=0;
    selected2=0;

    string ruta("resources/menu.ogg");
    
    music=new Musica(ruta);
    music->setLoop(true);
    music->Play();
    musicaencendida = true;
}
void Emenu::Handle(){
    
    std::cout << _context<< std::endl;
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.
    std::cout << _context<< std::endl;
    
}
void Emenu::Update(){
    _context=_context;
}
int Emenu::CUpdate2(sf::Event event){
            
            switch(menustate){ //para cada pantalla o estado del menu
                case menu1:
                    switch(event.type){
                        case sf::Event::KeyReleased:
                            
                            switch(event.key.code){
                                case sf::Keyboard::Up:
                                    
                                    moveUp();
                                    break;
                                case sf::Keyboard::Down:
                                    
                                    moveDown();
                                    break;
                                case sf::Keyboard::Return:
                                    selected=selection();
                                    if(selected==0){
                                        menustate=jugar; //entramos a seleccion de personaje
                                    }
                                    else if(selected==1){
                                        //CAMBIAMOS A ESTADO DE OPCIONES
                                        salida=true;
                                        Eopciones::Instance(Juego::Instance(),window)->Handle(false);
                                        
                                    }
                                    else if(selected==2){
                                        window->close();
                                    }
                                    break;
                                case sf::Keyboard::Escape:
                                    window->close();
                                    break;
                        }
                        break;
                    break;
                    }
                    break;
                case jugar:
                    switch(event.type){
                        case sf::Event::KeyReleased:
                            switch(event.key.code){
                                case sf::Keyboard::Up:
                                    
                                    moveUp();
                                    break;
                                case sf::Keyboard::Down:
                                    moveDown(); //menu2.movedown
                                    break;
                                case sf::Keyboard::Return:
                                    
                                    if(selected2==0){
                                        //LANZAMOS STATE E1JUGADOR
                                        music->Stop();
                                        salida=true;
                                        menustate=menu1;
                                        E1jugador::Instance(Juego::Instance(),window)->Handle();
                                        //E1jugador::Instance(Juego::Instance())->Handle();
                                        
                                        
                                    }
                                    else if(selected2==1){
                                        music->Stop();
                                        salida=true;
                                        menustate=menu1;
                                        //LANZAMOS STATE E2JUGADOR
                                        E2jugador::Instance(Juego::Instance(),window)->Handle();
                                    }
                                    break;
                                case sf::Keyboard::Escape:
                                    menustate=menu1;
                                    break;
                        }
                        break;
                    }
                    break;   
            }
  
    return 0;
}

void Emenu::Init(){
   salida=false;
   run(*Juego::Instance()->window);
}

Juego* Emenu::getContext(){
    
    return _context;    //Para recuperar el contexto
    
}
int Emenu::run(sf::RenderWindow &window){
    //buclue principal del juego 
    bool musica = Eopciones::Instance(Juego::Instance(),&window)->musica;
    while(window.isOpen() && !salida){
        //Manejador música
        if(Eopciones::Instance(Juego::Instance(),&window)->musica && !musicaencendida){
            music->Play();
            musicaencendida = true;
        }
        if(!Eopciones::Instance(Juego::Instance(),&window)->musica && musicaencendida){
            music->Stop();
            musicaencendida = false;
        }
        sf::Event event;
        while(window.pollEvent(event)){ 
            
            CUpdate2( event); //llamamos a la funcion teclas /update
        }
        
        Render(); //llamamos a la funcion render
    }
    return 0;
    
}


void Emenu::Render(){
    
    
    //aqui mostramos en la ventana las diferentes opciones
    window->clear();
    Sprite* fondo = Juego::Instance()->fondo;
    window->draw(fondo->render(0));
    switch(menustate){ //menu solo tiene la pantalla principal y la de selccion de personaje
        case menu1:
            
            opcion[0].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,200);
            window->draw(opcion[0]);
    
            opcion[1].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,350);
            window->draw(opcion[1]);
    
            opcion[2].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,500);
            window->draw(opcion[2]);
            break;
            
        case jugar:
            
            opcionj[0].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,250);
            window->draw(opcionj[0]);
    
            opcionj[1].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,400);
            window->draw(opcionj[1]);
            break;
         
    }
    //Juego::Instance()->window->display();
    window->display();

}

//void Emenu::draw(sf::RenderWindow &window){
 //   for(int i=0; i<MAX_NUMBER_ITEMS; i++){
 //       window.draw(opcion[i]);
 //   }
//}

void Emenu::moveUp(){
    switch(menustate){ //menu solo tiene la pantalla principal y la de selccion de personaje
        case menu1:
            
            if (selected -1 >=0){
                
                opcion[selected].setColor(sf::Color::Black);
                selected--;
                
                opcion[selected].setColor(sf::Color::Red);
            }
            else{
                
                opcion[selected].setColor(sf::Color::Black);
                selected=MAX_NUMBER_ITEMS-1;
                
                opcion[selected].setColor(sf::Color::Red);
            }
            break;
            
        case jugar:
            
            if (selected2 -1 >=0){
                //std::cout << "selected2>=1"  << std::endl;
                opcionj[selected2].setColor(sf::Color::Black);
                selected2--;
                opcionj[selected2].setColor(sf::Color::Red);
            }
            else{
                
                opcionj[selected2].setColor(sf::Color::Black);
                selected2=MAX_NUMBER_ITEMS_J-1;
                opcionj[selected2].setColor(sf::Color::Red);
            }
            break;
         
    }
    
}

void Emenu::moveDown(){
    switch(menustate){ //menu solo tiene la pantalla principal y la de selccion de personaje
        case menu1:
            if (selected  <MAX_NUMBER_ITEMS-1){
                opcion[selected].setColor(sf::Color::Black);
                selected++;
                opcion[selected].setColor(sf::Color::Red);
            }
          else{
                opcion[selected].setColor(sf::Color::Black);
                selected=0;
                opcion[selected].setColor(sf::Color::Red);
            }
            break;
            
        case jugar:
            if (selected2  <MAX_NUMBER_ITEMS_J-1){
                opcionj[selected2].setColor(sf::Color::Black);
                selected2++;
                opcionj[selected2].setColor(sf::Color::Red);
            }
          else{
                opcionj[selected2].setColor(sf::Color::Black);
                selected2=0;
                opcionj[selected2].setColor(sf::Color::Red);
            }
            break;
         
    }
}
int Emenu::selection(){
   // int a=selected;
    return selected;
}

Emenu::~Emenu(){
                            //Destruccion de la instancia 
   // std::cout << "Emenu ha sido eliminado "  << std::endl;
    _context = 0;
    pinstance = 0;
    
}
