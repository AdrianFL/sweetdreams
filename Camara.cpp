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
    kvel=despl;
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

void Camara::draw(sf::RenderWindow& window){
    window.setView(*camara);
}

void Camara::moverDer(Personaje personaje){
    if(desp==0){
        if(personaje.getXCoordinate()>=camara->getSize().x*0.5 && camara->getCenter().x <=(fondo.getGlobalBounds().width*0.79)){
            std::cout<<"ENTRO"<<std::endl;
            camara->move(kvel,0);
            desp=desp+kvel;
            
            personaje.aumentarMargenDer(kvel);
        }
    }else{
        int margen=fondo.getGlobalBounds().width-(fondo.getGlobalBounds().width*0.79);
        if(personaje.getXCoordinate()>=camara->getSize().x*0.5+desp && camara->getCenter().x<=(personaje.getXCoordinate()+margen)&& (personaje.getXCoordinate()+margen)<(mapa->_tileWidth*mapa->_width)){
            //std::cout<<"ENTRO2"<<std::endl;

            camara->move(kvel,0);
            desp=desp+kvel;
            personaje.aumentarMargenDer(kvel);
            
        }
    }
}

void Camara::moverIzq(Personaje personaje){
    if(desp!=0){
        if(personaje.getXCoordinate()<=camara->getSize().x*0.5+desp && camara->getCenter().x!=posorigen){
            camara->move(-kvel,0);
            desp=desp-kvel;
            std::cout<<"HIJOPUTA"<<std::endl;
            personaje.aumentarMargenIzq(kvel);
        }
    }
}

