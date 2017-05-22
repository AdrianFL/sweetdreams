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
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Juego.h"


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
#include "Musica.hpp"
#include "hechizo.h"


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
    void reiniciar();
    
    void cambiaNivel();
    
    protected:
        E2jugador(Juego* context,sf::RenderWindow *w);
        E2jugador(const E2jugador &);
        E2jugador &operator = (const E2jugador &);
    
private:
        //Personaje
    Personaje* p1;
    Personaje* p2;
    Arma* espada;
    Pocion* pvida;
    Pocion* pvida2;
    Pocion* pmana;
    Pocion* pmana2;
    Mapa* mapa;
    Camara *camara;
    Hechizo* meteoro;
    Hechizo* escupitajo;
    
    //Enemigos
    enemyMelee* enemigoM;
    enemyMelee* enemigoM2;
    enemyMelee* enemigoM3;
    enemyMelee* enemigoM4;
    enemyMelee* enemigoM5;
    enemyMelee* enemigoM6;
    enemyMelee* enemigoM7;
    enemyRange* enemigoR;
    enemyRange* enemigoR2;
    enemyRange* enemigoR3;
    enemyRange* enemigoR4;
    enemyFinal* enemigoFinal;
    std::vector<Proyectil*> proyectiles;
    std::vector<Proyectil*> disparoFinal;
    std::vector<Enemy*> enemigos;
    std::vector<bool> golpeados;
    std::vector<bool> golpeados2;
    std::vector<Pocion*> pociones;
    std::vector<Hechizo*> hechizos;
    std::vector<Arma*> armas;
    
    //Helpers
    Clock clock;
    Clock updateclock;
    int32_t time;
    int32_t updatetime;
    int32_t hittime;
    int32_t hittime2;
    int32_t niveltime;
    int32_t fintime;
    int prueba;
    int option;
    int option2;
    bool recogida;
    int movimiento;
    int movimiento2;
    Musica* musica;
    bool musicaencendida;
    
    sf::RenderWindow* window;
    static E2jugador* pinstance;
    Juego* _context;
    bool salida;
    bool ataca;
    bool ataca2;
    bool cambialvl;
    bool finjuego;
    bool coloca1;
    bool coloca2;
    int lvl;
};


#endif /* E2JUGADOR_H */
