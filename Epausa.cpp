/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Epausa.cpp
 * Author: javi
 * 
 * Created on May 20, 2017, 10:20 AM
 */

#include "Epausa.h"
#include <vector>
#include <string> 
#include "Emenu.h"
#include "E2jugador.h"
#include "E1jugador.h"
#include "Eintroduccion.h"
#include "Emenu.h"
#include "Eopciones.h"

using namespace std;

Epausa* Epausa::pinstance = 0;
Epausa* Epausa::Instance(Juego* context,sf::RenderWindow *w){
    
    if(pinstance == 0) pinstance = new Epausa(context,w);

    return pinstance;
}
Epausa::Epausa(Juego* context,sf::RenderWindow *w){ //CONSTRUCTOR REAL
    window=w;
    _context = context; //En el momento en el que se crea el estado, se asigna su contexto.
    int width = Juego::Instance()->window->getSize().x;
    int height = Juego::Instance()->window->getSize().y;
    
    if(!font.loadFromFile("resources/a.ttf")){
        
    }
    //int i=0;
    
    opcionp[0].setFont(font);
    opcionp[0].setColor(sf::Color::Red);
    opcionp[0].setString("Reanudar");
    opcionp[0].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMS_P+1)*1);
    opcionp[1].setFont(font);
    opcionp[1].setColor(sf::Color::Black);
    opcionp[1].setString("Reiniciar");
    opcionp[1].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMS_P+1)*2);
    opcionp[2].setFont(font);
    opcionp[2].setColor(sf::Color::Black);
    opcionp[2].setString("Opciones");
    opcionp[2].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMS_P+1)*3);
    opcionp[3].setFont(font);
    opcionp[3].setColor(sf::Color::Black);
    opcionp[3].setString("Salir");
    opcionp[3].setPosition(2.3*width/5,height/(MAX_NUMBER_ITEMS_P+1)*4);
    
    selected=0;

}


void Epausa::Handle(bool m){
    modo=m;
 //   std::cout << "Eopciones: "  << this << std::endl;
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.
    
}
void Epausa::Handle(){
 //   std::cout << "Eopciones: "  << this << std::endl;
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.
    
}
void Epausa::Update(){
}

void Epausa::Update2(sf::Event event){

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
                                        //REANUDAR
                                        salida=true;
                                        if(modo){
                                            E1jugador::Instance(Juego::Instance(),window)->Handle();
                                        }
                                        else{
                                            E2jugador::Instance(Juego::Instance(),window)->Handle();
                                        }
                                    }
                                    else if(selected==1){
                                        //REINICIAR NIVEL
                                        salida=true;
                                        
                                        if(modo){
                                            //INICIAMOS NIVEL DE 0
                                            delete E1jugador::Instance(Juego::Instance(),window);
                                            E1jugador::Instance(Juego::Instance(),window)->Handle();
                                        }
                                        else{
                                            //INICIAMOS NIVEL DE 0
                                            delete E2jugador::Instance(Juego::Instance(),window);
                                            E2jugador::Instance(Juego::Instance(),window)->Handle();
                                        }
                                    }
                                    else if(selected==2){
                                        //OPCIONES
                                        salida=true;
                                        Eopciones::Instance(Juego::Instance(),window)->Handle(true);
                                    }
                                    else if(selected==3){
                                        //SALIMOS NIVEL
                                        salida=true;
                                        Emenu::Instance(Juego::Instance(),window)->Handle();
                                    }
                                    break;
                                case sf::Keyboard::Escape:
                                    //REANUDAR
                                    break;
                        }
                        break;   
            }

}

void Epausa::Init(){
   salida=false;
   run(*Juego::Instance()->window);
   
}

int Epausa::run(sf::RenderWindow &window){
    while(window.isOpen() && !salida){
        sf::Event event;
        while(window.pollEvent(event)){ 
            Update2( event); //llamamos a la funcion teclas /update
        }
        Render(); //llamamos a la funcion render
    }
    return 0;
    
}

void Epausa::Render(){
    
    
    //aqui mostramos en la ventana las diferentes opciones
    Juego::Instance()->window->clear();
    
    Sprite* fondo = Juego::Instance()->fondo;
    //int xD=E1jugador::Instance(Juego::Instance(),window)->xD;
    fondo->set_position(E1jugador::Instance(Juego::Instance(),window)->xD,0);
    window->draw(fondo->render(0)); 
    
    opcionp[0].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,200);
    window->draw(opcionp[0]);
    
    opcionp[1].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,300);
    window->draw(opcionp[1]);
    
    opcionp[2].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,400);
    window->draw(opcionp[2]);
    
    opcionp[3].setPosition((E1jugador::Instance(Juego::Instance(),window))->xD+500,500);
    window->draw(opcionp[3]);
          
    Juego::Instance()->window->display();

}

Juego* Epausa::getContext(){
    
    return _context;    //Para recuperar el contexto
    
}

void Epausa::moveUp(){
    if (selected -1 >=0){
        opcionp[selected].setColor(sf::Color::Black);
        selected--;
        opcionp[selected].setColor(sf::Color::Red);
    }
    else{
        opcionp[selected].setColor(sf::Color::Black);
        selected=MAX_NUMBER_ITEMS_P-1;
        opcionp[selected].setColor(sf::Color::Red);
    }
}

void Epausa::moveDown(){
    if (selected  <MAX_NUMBER_ITEMS_P-1){
        opcionp[selected].setColor(sf::Color::Black);
        selected++;
        opcionp[selected].setColor(sf::Color::Red);
    }
    else{
        opcionp[selected].setColor(sf::Color::Black);
        selected=0;
        opcionp[selected].setColor(sf::Color::Red);
    }
}
int Epausa::selection(){
   // int a=selected;
    return selected;
}
