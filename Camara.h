/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camara.h
 * Author: alejandro
 *
 * Created on 25 de abril de 2017, 7:59
 */

#ifndef CAMARA_H
#define CAMARA_H
#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Personaje.hpp"
#include "Sprite.hpp"

class Camara{
public:
    Camara(int width, int height,int desplazamiento, Mapa &mapa);
    Camara(const Camara& orig);
    ~Camara();
    
    void draw(sf::RenderWindow &window);
    void render(sf::RenderWindow &window, float p, Personaje personaje,int movimiento);
    void move(float p);
    void moverDer(Personaje personaje);
    void moverIzq(Personaje personaje);
    void fija();
    
    
    
private:
    sf::Clock updateClock;
    sf::Vector2i lastPos;
    sf::Vector2i newPos;
    sf::Vector2i vel;
    float percentTick;
    int aceleracion;
    
    sf::Sprite fondo;
    
    int ancho;
    int alto;
    float desp;
    int posorigen;
    float kvel;
    
    float lastdesp;
    
    float posactual;
    
    sf::View *camara;
    

    Mapa *mapa;

};



#endif /* CAMARA_H */

