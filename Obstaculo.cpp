/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Obstaculo.cpp
 * Author: alexei
 * 
 * Created on 10 de mayo de 2017, 17:45
 */

#include "Obstaculo.h"

Obstaculo::Obstaculo(std::string& url, int posx, int posy, int width, int height) {
    //------Reemplazar las coordenadas por las que serían de la textura
    int coordenadas[4] = {0,0,1,1};
    sprite = new Sprite(url,coordenadas,1);
    sprite->set_origin(0,0);
    sprite->set_position(posx,posy);
    sprite->set_scale(width*Nodo::width,height*Nodo::height);
}

Obstaculo::Obstaculo(const Obstaculo& orig) {
}

Obstaculo::~Obstaculo() {
}

Sprite* Obstaculo::getSprite(){
    return sprite;
}
