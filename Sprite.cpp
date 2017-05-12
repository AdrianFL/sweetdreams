/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.cpp
 * Author: adrian
 * 
 * Created on 17 de marzo de 2017, 17:15
 */

#include "Sprite.hpp"
#include <iostream>

//Parametros: url de la textura, array de coordenadas para cada frame (multiplo de 4) y cantidad de frames
Sprite::Sprite(std::string& url, int coord[], int frames)
{
    if(!textura.loadFromFile(url)){
        std::cerr << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    fotogramas = new sf::Sprite[frames];
    int j=0;
    for(int i=0; i<frames; i++){
       fotogramas[i].setTexture(textura);
       fotogramas[i].setTextureRect(sf::IntRect(coord[j], coord[j+1], coord[j+2],coord[j+3]));
       fotogramas[i].setOrigin(15,32);
       j+=4;
    }
    fr=frames;
    puntero=0;
    tasa=75;
    frames=75;
}

//Coloca la coordenada origen para cada frame de la animacion
void Sprite::set_origin(int x, int y){
    for(int i=0; i<fr; i++){
        fotogramas[i].setOrigin(x, y);
    }
}

//Fija la tasa de frames de la animacion
void Sprite::set_framerate(int32_t x){
    tasa=x;
    frames=x;
}

//Coloca la animacion entera en una posicion
void Sprite::set_position(int x, int y){
    for(int i=0; i<fr; i++){
        fotogramas[i].setPosition(x, y);
    }
}

//Cambia la escala de la animacion
void Sprite::set_scale(float x, float y){
    for(int i=0; i<fr; i++){
        fotogramas[i].setScale(x, y);
    }
}

//Funcion no necesaria por el momento
void Sprite::move(int x, int y){
    
}

//Devuelve el sprite de SFML que se debe renderizar
sf::Sprite Sprite::render(int32_t t){
    frames-=t;
    if(frames<0){
        frames=tasa;
        puntero++;
        if(puntero>=fr){
            puntero=0;
        }
    }
    return fotogramas[puntero];
}


sf::Sprite Sprite::getFotogramaActual(){
    return fotogramas[puntero];
}

bool Sprite::comprobarColision(int x, Sprite *ajeno){
    if(x<0 && x>=fr){
        x=puntero;
    }
    if(fotogramas[x].getGlobalBounds().intersects(ajeno->getFotogramaActual().getGlobalBounds())){
        return true;
    }
    return false;
}

void Sprite::set_rotation(float x)
{
    for(int i=0; i<fr; i++){
        fotogramas[i].setRotation(x);
    }
}

void Sprite::rotate(float x)
{
    for(int i=0; i<fr; i++){
        fotogramas[i].rotate(x);
    }
}

void Sprite::reset()
{
    puntero=0;
}