/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Eopciones.h
 * Author: javi
 *
 * Created on May 20, 2017, 10:21 AM
 */

#ifndef EOPCIONES_H
#define EOPCIONES_H
#define MAX_NUMBER_ITEMSO 2
#include "State.h"
#include "Juego.h"
#include "Emenu.h"

class Emenu;

class Eopciones: public State {
public:
    void moveUp();
    void moveDown();
    int selection();
    
    //nuevo
    
    Eopciones(Juego* context, sf::RenderWindow *w);
    void Handle(bool d);
    void Handle();
    void Init();
    void Update();
    void Update2(sf::Event event);
    Juego* getContext();
    static Eopciones* Instance(Juego* context, sf::RenderWindow *w);

    
    void Render();
    //void draw(sf::RenderWindow &window);
    
    int run(sf::RenderWindow &window);
    
    bool musica;
    bool sonido;
    
private:
    sf::RenderWindow* window;
    int selected;
    int maxitems;

    sf::Font font;
    
    bool salida;
    bool donde;
    bool musicaencendida;
    
   // std::vector<sf::Text*> opciono;
    sf::Text opciono[MAX_NUMBER_ITEMSO];
    static Eopciones* pinstance;
    Juego* _context;

};

#endif /* EOPCIONES_H */

