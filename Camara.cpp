/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Camara.h"
#include "Mapa.h"
#include <iostream>
#include "Personaje.hpp"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

Camara::Camara(int width, int height,int despl,Mapa &map){
    ancho=width;
    alto=height;
    camara=new sf::View(sf::FloatRect(0,0,ancho,alto));
    desp=0;
    posorigen=camara->getCenter().x;
    posactual=0;
    kvel=despl;
    lastdesp=desp;
    mapa=new Mapa();
    
    mapa->_tileWidth=map._tileWidth;
    mapa->_width=map._width;
    mapa->fondo=map.fondo;
    fondo=mapa->fondo;
    
}

Camara::Camara(const Camara& orig){
    
}

Camara::~Camara(){
    
}

void Camara::render(sf::RenderWindow& window,float p,Personaje p1,int movimiento){
    
    int movecamara=0;
    
    if(p<1.0f && lastdesp!=kvel){
        if(movimiento==1){
            movecamara=(lastdesp*(1-p))+(desp*p);
            std::cout<<"ENTRO2";
        }
        if(movimiento==2){
            movecamara=(lastdesp*(1-p))+(desp*p);
            std::cout<<"ENTRO3";
            //moverIzq(p1,movecamara);
            
        }
    }
    
}

void Camara::move(float p){ 
    float movecamara=0;
    
    if(p<1.0f && lastdesp!=kvel){
        movecamara=(lastdesp*(1.0-p))+(desp*p); 
        camara->move(movecamara-posactual, 0);
        posactual=movecamara;
    }
    
}

void Camara::draw(sf::RenderWindow& window){
    window.setView(*camara);
}

void Camara::fija(){
    lastdesp=desp;
}

void Camara::moverDer(Personaje personaje){

    int margen=fondo.getGlobalBounds().width-(fondo.getGlobalBounds().width*0.810);

    if(personaje.getXCoordinate()>=2600){
        lastdesp=desp;
    }else if(personaje.getXCoordinate()>=camara->getSize().x*0.5+desp && camara->getCenter().x<=(personaje.getXCoordinate()+margen)&& (personaje.getXCoordinate()+margen)<(mapa->_tileWidth*mapa->_width)){
        //camara->move(kvel,0);
        lastdesp=desp;
        desp=desp+kvel;
        //personaje.aumentarMargenIzq(kvel);
    }
        
        
}

void Camara::moverIzq(Personaje personaje){
    if(desp!=0){
        if(personaje.getXCoordinate()<=camara->getSize().x*0.5+desp && camara->getCenter().x!=posorigen){
            lastdesp=desp;
            desp=desp-kvel;
        }
    }
}

int Camara::getDesp(){
    return desp;
}