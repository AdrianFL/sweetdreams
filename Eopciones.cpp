/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Eopciones.cpp
 * Author: javi
 * 
 * Created on May 20, 2017, 10:21 AM
 */

#include "Eopciones.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <vector>
#include <string> 
#include "Emenu.h"
#include "Epausa.h"
#include "E1jugador.h"
using namespace std;

Eopciones* Eopciones::pinstance = 0;
Eopciones* Eopciones::Instance(Juego* context,sf::RenderWindow *w){
    
    if(pinstance == 0) pinstance = new Eopciones(context,w);

    return pinstance;
}
Eopciones::Eopciones(Juego* context,sf::RenderWindow *w){ //CONSTRUCTOR REAL
    window=w;
    _context = context; //En el momento en el que se crea el estado, se asigna su contexto.
    int width = Juego::Instance()->window->getSize().x;
    int height = Juego::Instance()->window->getSize().y;
    musica=true;
    sonido=true;
    if(!font.loadFromFile("resources/a.ttf")){
        
    }
    opciono[0].setFont(font);
    opciono[0].setColor(sf::Color::Red);
    opciono[0].setString("Musica On");
    opciono[0].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMSO+1)*1);
    opciono[1].setFont(font);
    opciono[1].setColor(sf::Color::Black);
    opciono[1].setString("Volver");
    opciono[1].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMSO+1)*2);
    
   
    selected=0;
    musica = true;
    musicaencendida = true;
}


void Eopciones::Handle(bool d){
    donde=d;
  //  std::cout << "Eopciones: "  << this << std::endl;
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.
    
}
void Eopciones::Handle(){
  //  std::cout << "Eopciones: "  << this << std::endl;
   // _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.
    
}
void Eopciones::Update(){
}
void Eopciones::Update2( sf::Event event){
    

        //    switch(menustate){ //para cada pantalla o estado del menu
            //    case menu1:
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
                                        if(!musica){
                                            musica=true;
                                            opciono[0].setString("Musica On");
                                        }
                                        else{
                                            musica=false;
                                            opciono[0].setString("Musica Off");
                                        }
                                    }
                                    else if(selected==1){
                                        salida=true;
                                        if(!donde){
                                            Emenu::Instance(Juego::Instance(),window)->Handle();
                                        }
                                        if(donde){
                                            Epausa::Instance(Juego::Instance(),window)->Handle();
                                        }
                                        
                                        
                                    }
                                    
                                    break;
                                case sf::Keyboard::Escape:
                                    window->close();
                                    break;
                        }
                        break;
             //       break;
             //       }
             //   case jugar:
                    }

    //    }
        
    //    Render(); //llamamos a la funcion render

   // }
  
  //  return 0;
}

void Eopciones::Init(){
   salida=false;
   run(*Juego::Instance()->window);
   
}
int Eopciones::run(sf::RenderWindow &window){
    
    while(window.isOpen() && !salida){
        //Manejador de música
        Musica* music =  Emenu::Instance(Juego::Instance(),&window)->music;
        if(musica && !musicaencendida){
            music->Play();
            musicaencendida = true;
        }
        if(!musica && musicaencendida){
            music->Stop();
            musicaencendida = false;
        }
        
        sf::Event event;
        while(window.pollEvent(event)){ 
            Update2( event); //llamamos a la funcion teclas /update
        }
        Render(); //llamamos a la funcion render
    }
    return 0;
}

void Eopciones::Render(){
    
    //aqui mostramos en la ventana las diferentes opciones
    Juego::Instance()->window->clear();
            
    Sprite* fondo = Juego::Instance()->fondo;
    //int xD=E1jugador::Instance(Juego::Instance(),window)->xD;
    fondo->set_position(E1jugador::Instance(Juego::Instance(),window)->xD,0);
    window->draw(fondo->render(0)); 
    
    opciono[0].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,200);
    window->draw(opciono[0]);
    
    opciono[1].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,350);
    window->draw(opciono[1]);
    
    opciono[2].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,500);
    window->draw(opciono[2]);
    
   
          
    Juego::Instance()->window->display();

}

Juego* Eopciones::getContext(){
    
    return _context;    //Para recuperar el contexto
    
}


void Eopciones::moveUp(){
    if (selected -1 >=0){
        opciono[selected].setColor(sf::Color::Black);
        selected--;
        opciono[selected].setColor(sf::Color::Red);
    }
    else{
        opciono[selected].setColor(sf::Color::Black);
        selected=MAX_NUMBER_ITEMSO-1;
        opciono[selected].setColor(sf::Color::Red);
    }
}

void Eopciones::moveDown(){
    if (selected  <MAX_NUMBER_ITEMSO-1){
        opciono[selected].setColor(sf::Color::Black);
        selected++;
        opciono[selected].setColor(sf::Color::Red);
    }
    else{
        opciono[selected].setColor(sf::Color::Black);
        selected=0;
        opciono[selected].setColor(sf::Color::Red);
    }
}
int Eopciones::selection(){
   // int a=selected;
    return selected;
}