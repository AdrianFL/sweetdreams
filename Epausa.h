/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Epausa.h
 * Author: javi
 *
 * Created on May 20, 2017, 10:20 AM
 */

#ifndef EPAUSA_H
#define EPAUSA_H
#define MAX_NUMBER_ITEMS_P 4

#include "Juego.h"
class Epausa: public State {
public:
    void moveUp();
    void moveDown();
    int selection();
    
    //nuevo
    Epausa(Juego* context, sf::RenderWindow *w);
    void Handle();
    void Handle(bool m);
    void Init();
    void Update();
    void Update2(sf::Event event);
    Juego* getContext();
    static Epausa* Instance(Juego* context, sf::RenderWindow *w);

    
    void Render();
    void draw(sf::RenderWindow &window);
    
    int run(sf::RenderWindow &window);
    
private:
    sf::RenderWindow* window;
    int selected;
    int maxitems;
    sf::Font font;
    
    bool salida;
    bool modo;
    
    static Epausa* pinstance;
    Juego* _context;
   // std::vector<sf::Text*> opcionp;
    sf::Text opcionp[MAX_NUMBER_ITEMS_P];
};

#endif /* EPAUSA_H */

