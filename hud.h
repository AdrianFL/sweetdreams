/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hud.h
 * Author: javi
 *
 * Created on May 18, 2017, 9:10 AM
 */
#include "Sprite.hpp"

#ifndef HUD_H
#define HUD_H
#include "Pocion.h"

class hud {
public:
    hud();
    hud(const hud& orig);
    virtual ~hud();
    std::vector<Sprite*> getHud();
    void actualizar(int v, int m);
    Sprite* renderv(int a);
    Sprite* renderm(int a);
    Sprite* renderbv(int a);
    Sprite* renderbm(int a);
    Sprite* rendera(int a);
    Sprite* renderh(int a);
    Sprite* renderra(int a);
    Sprite* renderrh(int a);
    Sprite* renderpv(int a);
    Sprite* renderpm(int a);
    sf::Text* getnpv(int a);
    sf::Text* getnpm(int a);
private:
    Sprite* barraVida;
    Sprite* barraMana;
    Sprite* vida;
    Sprite* mana;
    Sprite* recuadroArma;
    Sprite* recuadroHechizo;
    Sprite* espada;
    Sprite* hacha;
    Sprite* escupir;
    Sprite* meteoro;
    Sprite* pv;
    Sprite* pm;
    sf::Font font;
    sf::Text* npv;
    sf::Text* npm;
};

#endif /* HUD_H */

