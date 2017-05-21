/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.hpp
 * Author: adrian
 *
 * Created on 17 de marzo de 2017, 17:15
 */

#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include "Sprite.hpp"
#include <SFML/Graphics.hpp>
#include "Pocion.h"
#include "Enemy.h"
#include "Arma.h"
#include "hechizo.h"
#include "Proyectil.h"

class Enemy;
class Proyectil;

class Personaje {
public:
    Personaje(int id);
    Sprite* render(int32_t tempo, float p);
    void move(int i);
    int getDireccion();
    int getXCoordinate();
    int getYCoordinate();
    int getVidaMax();
    int getManaMax();
    int getVida();
    int getMana();    
    void setMana(int i);
    void setVida(int i);
    void usaPocion(std::string s);
    int numeroPoc();
    void activaRecogida();
   // void setPociones(Pocion *pociones[5]); //para probar
    void herir(int dmg);
    void atacar();
    Sprite* getAnimacionActiva();
    void aumentaPVida();
    void aumentaPMana();
    int getNumPVida();
    int getNumPMana();
    Proyectil* lanzarHechizo();
    void recogeHechizo(Hechizo* h);
    
    void aumentarMargenDer(int i);
    void aumentarMargenIzq(int i);
    
    void cambiarAtaque(Arma* a);
    
private:
    Sprite *idle;
    Sprite *idleleft;
    Sprite *moveright;
    Sprite *moveleft;
    Sprite *attackright;
    Sprite *attackleft;
    Sprite *potivida;
    Sprite *potividaleft;
    Sprite *potimana;
    Sprite *potimanaleft;
    Sprite *muerte;
    Sprite *muerteleft;
    Sprite *recogida;
    Sprite *recogidaleft;
    Sprite *hechizo;
    Sprite *hechizoleft;
    
    int vida;
    int mana;
    int vidamax;
    int manamax;
    int numPVida;
    int numPMana;
    
    Hechizo *hactivo;
    
    int x, y;
    int lastx, lasty;
    float sx, sy;
    int activa;
    
    bool movingborder;
    
    int32_t atctime, potvidatime, potmanatime, picktime, spelltime;
    
    int direccion;
    
    int margen;
};

#endif /* PERSONAJE_HPP */
