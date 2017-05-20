/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   E1jugador.h
 * Author: javi
 *
 * Created on May 20, 2017, 10:22 AM
 */

#ifndef E1JUGADOR_H
#define E1JUGADOR_H
#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "State.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "Clock.hpp"
#include "Mapa.h"
#include <fstream>
#include <cstring>
#include "Arma.h"
#include "Pocion.h"
#include "enemyMelee.h"
#include "enemyRange.h"
#include "enemyFinal.h"
#include "Proyectil.h"
#include "Camara.h"

class E1jugador: public State {
public:
    void Handle();
    void Init();
    void Update();
    void Render();
    Juego* getContext();
    static E1jugador* Instance(Juego* context, sf::RenderWindow *w);
    int CUpdate2(sf::Event event);
    int run(sf::RenderWindow &window);
    void reiniciar();
    
    ~E1jugador();
    
    protected:
        E1jugador(Juego* context,sf::RenderWindow *w);
        E1jugador(const E1jugador &);
        E1jugador &operator = (const E1jugador &);
        
    
private:
    
    Personaje* p1;
    Arma* hacha;
    Arma* espada;
    Pocion* pvida;
    Pocion* pmana;
    Mapa* mapa;
    Camara *camara;
    bool recogida;
    int movimiento;
    enemyMelee* enemigoM;
    enemyRange* enemigoR;
    enemyFinal* enemigoFinal;
    std::vector<Proyectil*> proyectiles;
    std::vector<Proyectil*> disparoFinal;
    Clock clock;
    Clock updateclock;
    int32_t time;
    int32_t updatetime;
    int prueba;
    int option;
    
    
    sf::RenderWindow* window;
    static E1jugador* pinstance;
    Juego* _context;
    bool salida;
};

#endif /* E1JUGADOR_H */

