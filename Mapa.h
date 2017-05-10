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
 
private:
    
    int ***_tilemap;
    int _numLayers;
    int _height;
    int _tileHeigth;
    
    sf::Sprite ****_tilemapSprite;
    sf::Sprite *_tilesetSprite;
    
    sf::Texture _tilesetTexture;
    sf::Texture texturafondo;
    
};

#endif	/* CARGAR_H */