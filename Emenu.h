/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Emenu.h
 * Author: javi
 *
 * Created on May 20, 2017, 10:21 AM
 */

#ifndef EMENU_H
#define EMENU_H

#define MAX_NUMBER_ITEMS 3
#define MAX_NUMBER_ITEMS_J 2
#include <iostream>
#include "State.h"
#include "Juego.h"

#include <SFML/Graphics.hpp>
class Emenu: public State {
public:
    //Emenu(float width, float height,int tipo);

    
   // void draw(sf::RenderWindow &Window);
    void moveUp();
    void moveDown();
    int selection();
    
    //nuevo
    void Handle();
    void Init();
    int CUpdate2(sf::Event event);
    void Update();
    Juego* getContext();
    static Emenu* Instance(Juego* context, sf::RenderWindow *w);

    
    void Render();  //antes tenia esto de param:sf::RenderWindow &window, sf::Event event
  //  void draw(sf::RenderWindow &window);
  //  void moveUp(std::vector<sf::Text*> menu, int &iterator);
  //  void moveDown(std::vector<sf::Text*> menu, int &iterator);
    
    int run(sf::RenderWindow &window);
    
    ~Emenu();
    
    protected:
        
    Emenu(Juego* context,sf::RenderWindow *w);
    Emenu(const Emenu &);
    Emenu &operator = (const Emenu &);
    

    
private:
    sf::RenderWindow* window;
    int selected;
    int selected2;
    int maxitems;
    sf::Font font;
    sf::Text opcion[MAX_NUMBER_ITEMS];
    sf::Text opcionj[MAX_NUMBER_ITEMS_J];
    
    

    static Emenu* pinstance;
    Juego* _context;
    bool salida;
    enum states {menu1, jugar, opciones, personaje,jugar1,jugar2};//PARA SABER QUE PINTAR
    int menustate;//para seleccionar una de las opciones anteriores
};

#endif /* EMENU_H */

