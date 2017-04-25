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

void Sprite::set_position(int x, int y){
    for(int i=0; i<fr; i++){
        fotogramas[i].setPosition(x, y);
    }
}

void Sprite::set_scale(float x, float y){
    for(int i=0; i<fr; i++){
        fotogramas[i].setScale(x, y);
    }
}

void Sprite::move(int x, int y){
    
}

sf::Sprite Sprite::render(int32_t t){
    frames-=t;
    if(frames<0){
        frames=75;
        puntero++;
        if(puntero>=fr){
            puntero=0;
        }
    }
    return fotogramas[puntero];
}