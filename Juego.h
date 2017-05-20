/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: javi
 *
 * Created on May 20, 2017, 10:20 AM
 */

#ifndef JUEGO_H
#define JUEGO_H
#include "State.h"
#include <SFML/Graphics.hpp>

class Juego {
public:
  
   // class State *current;
    
 //   void off();
 //   void on();
    
   // void setCurrent(State *s);

    static Juego* Instance();
    Juego();
    void Init();
    
    State* currentState();
    
    void setState (State* state);
    
    void Update();
    
    virtual ~Juego();
    
    sf::RenderWindow* window;
    
    sf::Event event;
    
    int windowWidth = 1080; //Width de la window
    
    int windowHeight = 800; //Height de la window
    
private:
	State* _state;
        static Juego* pinstance;
    

};

#endif /* JUEGO_H */

