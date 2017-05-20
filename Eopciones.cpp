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
    opciono[1].setColor(sf::Color::White);
    opciono[1].setString("Sonido On");
    opciono[1].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMSO+1)*2);
    opciono[2].setFont(font);
    opciono[2].setColor(sf::Color::White);
    opciono[2].setString("Volver");
    opciono[2].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMSO+1)*3);
    
   
    selected=0;
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
                                        if(!sonido){
                                            sonido=true;
                                            opciono[1].setString("Sonido On");
                                        }
                                        else{
                                            sonido=false;
                                            opciono[1].setString("Sonido Off");
                                        }
                                        
                                    }
                                    else if(selected==2){
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
            for(int i=0; i<MAX_NUMBER_ITEMSO; i++){
                window->draw(opciono[i]);
            }  
          
    Juego::Instance()->window->display();

}
//void Emenu::Update(){
    
 //   if(!initState){
 //       Init();
 //       initState = true;
 //   }
    
    //ACCIONES DE UPDATE
 //   run(*Juego::Instance()->window);
 //   Render();

//}
Juego* Eopciones::getContext(){
    
    return _context;    //Para recuperar el contexto
    
}


void Eopciones::moveUp(){
    if (selected -1 >=0){
        opciono[selected].setColor(sf::Color::White);
        selected--;
        opciono[selected].setColor(sf::Color::Red);
    }
    else{
        opciono[selected].setColor(sf::Color::White);
        selected=MAX_NUMBER_ITEMSO-1;
        opciono[selected].setColor(sf::Color::Red);
    }
}

void Eopciones::moveDown(){
    if (selected  <MAX_NUMBER_ITEMSO-1){
        opciono[selected].setColor(sf::Color::White);
        selected++;
        opciono[selected].setColor(sf::Color::Red);
    }
    else{
        opciono[selected].setColor(sf::Color::White);
        selected=0;
        opciono[selected].setColor(sf::Color::Red);
    }
}
int Eopciones::selection(){
   // int a=selected;
    return selected;
}