/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.h
 * Author: alejandro
 *
 * Created on 24 de marzo de 2017, 3:23
 */

#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics.hpp>
//######################
#include "Nodo.h"
#include "Obstaculo.h"
//######################

class Mapa {
public:
    Mapa();
    Mapa(const Mapa& orig);
    ~Mapa();
    
    void leerMapa(int mapa);
    void dibuja(sf::RenderWindow &window);
    
    sf::Sprite  fondo;
    int _width;
    int _tileWidth;
 
    //Añadido para la IA
    //#####################
    void dibujaNodos(sf::RenderWindow &window);
    void dibujaObs(sf::RenderWindow &window);
    
    int _rows;
    int _cols;
    std::vector<Nodo*> CalcRoute(int px, int py, int ex, int ey);
    void limpiaIA();
    Nodo* devuelveNodo(int x, int y);
    bool colisionaObs(Sprite *colisionador);
    //#####################
    
private:
    
    int ***_tilemap;
    int _numLayers;
    int _height;
    int _tileHeigth;
    
    sf::Sprite ****_tilemapSprite;
    sf::Sprite *_tilesetSprite;
    
    sf::Texture _tilesetTexture;
    sf::Texture texturafondo;
    
        //Añadido para la IA
    //#####################
    Nodo*** grid;
    Obstaculo** obstaculos;
     //#####################
    
};

#endif	/* CARGAR_H */