/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Obstaculo.h
 * Author: alexei
 *
 * Created on 10 de mayo de 2017, 17:45
 */
#include "Sprite.hpp"
#include "Nodo.h"

#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo {
public:
    Obstaculo(std::string& url, int posx, int posy, float width, float height);
    Obstaculo(const Obstaculo& orig);
    virtual ~Obstaculo();
    
    Sprite* getSprite();
private:
    Sprite* sprite;
};

#endif /* OBSTACULO_H */
