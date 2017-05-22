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
#include "Musica.hpp"
#include "hechizo.h"
#include "hud.h"

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
    
    int xD;
    
    void cambiaNivel();
    
    ~E1jugador();
    
    protected:
        E1jugador(Juego* context,sf::RenderWindow *w);
        E1jugador(const E1jugador &);
        E1jugador &operator = (const E1jugador &);
        
    
private:
    //Personaje
    Personaje* p1;
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
    std::vector<Pocion*> pociones;
    std::vector<Hechizo*> hechizos;
    std::vector<Arma*> armas;
    //Helpers
    Clock clock;
    Clock updateclock;
    int32_t time;
    int32_t updatetime;
    int32_t hittime;
    int32_t niveltime;
    int32_t fintime;
    int prueba;
    int option;
    
    //interfaz
    hud* interfaz;
    sf::Text* texto1;
    sf::Text* texto2;
    
    
    bool recogida;
    int movimiento;
    Musica* musica;
    bool musicaencendida;
    
    sf::RenderWindow* window;
    static E1jugador* pinstance;
    Juego* _context;
    bool salida;
    bool ataca;
    bool cambialvl;
    bool finjuego;
    bool coloca1;
    bool coloca2;
    int lvl;
};

#endif /* E1JUGADOR_H */

