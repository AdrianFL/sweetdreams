/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: alexei
 *
 * Created on 10 de mayo de 2017, 16:11
 */
#include "Sprite.hpp"

#ifndef NODO_H
#define NODO_H

class Nodo {
public:
    Nodo(std::string& url, int nodox, int nodoy, int e);
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    void colisionaObstaculo(std::string& url, int e);
    Sprite* getParcela();
    
    static int getWidth();
    static int getHeight();
    
    int estado;
    
    int f;
    int g;
    int h;
    
    bool pintable;
    bool closed;
    bool open;
    
    Nodo* padre;
    
    int x;
    int y;
    
    static float height;
    static float width;
    
    int centrox;
    int centroy;
    
private:
    Sprite* parcela;
};

#endif /* NODO_H */
