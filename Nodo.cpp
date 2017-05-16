/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: alexei
 * 
 * Created on 10 de mayo de 2017, 16:11
 */

#include "Nodo.h"
#include "Sprite.hpp"

Nodo::Nodo(std::string& url, int nodox, int nodoy, float tamanyox, float tamanyoy, int e) {
    
    //posicion x, y en el array de nodos
    x = nodox;
    y = nodoy;
    
    //su tamaño
    height = tamanyox;
    width = tamanyoy;
    
    //su centro
    centrox = x*width+width/2;
    centroy = y*height+height/2;
    
    //Si se ha de pintar por si acaso
    pintable = false;
    closed = false;
    open = false;
    
    //parecela que ocupa
    int coordenadas[4] = {0,0,50,50};
    parcela = new Sprite(url, coordenadas, 1);
    parcela->set_origin(0,0);
    
    //-----Añadir método de setSize para poner sprites de tamaño adecuado en mi nodo
    parcela->set_scale(tamanyox/50,tamanyoy/50);
    parcela->set_position(x*tamanyox,y*tamanyoy);
    
    //Contadores de puntuacion para la ruta
    f=0;
    g=0;
    h=0;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
    free(parcela);
}

void Nodo::colisionaObstaculo(std::string& url, int e){
    estado = e;
    
     int coordenadas[4] = {0,0,50,50};
     
    parcela = new Sprite(url, coordenadas,1);
    parcela->set_origin(0,0);
    parcela->set_position(x*width,y*height);
}

Sprite* Nodo::getParcela(){
    return parcela;
}