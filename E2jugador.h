/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   E2jugador.h
 * Author: javi
 *
 * Created on May 20, 2017, 10:21 AM
 */

#ifndef E2JUGADOR_H
#define E2JUGADOR_H
#include "State.h"
#include "Juego.h"

class E2jugador: public State {
public:
    void Handle();
    void Init();
    void Update();
    void Render();
    Juego* getContext();
    static E2jugador* Instance(Juego* context,sf::RenderWindow *w);
    ~E2jugador();
    int CUpdate2(sf::Event event);
    int run(sf::RenderWindow &window);
    
    protected:
        E2jugador(Juego* context,sf::RenderWindow *w);
        E2jugador(const E2jugador &);
        E2jugador &operator = (const E2jugador &);
    
private:
    sf::RenderWindow* window;
    static E2jugador* pinstance;
    Juego* _context;
    bool salida;
};


#endif /* E2JUGADOR_H */

