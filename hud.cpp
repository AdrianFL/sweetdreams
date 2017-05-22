/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hud.cpp
 * Author: javi
 * 
 * Created on May 18, 2017, 9:10 AM
 */

#include "hud.h"
#include "Sprite.hpp"

hud::hud() {
    std::string url("resources/a.png");
    std::string url2("resources/vida.png");
    std::string url3("resources/mana.png");
    
    int frames=1;
    int coordenadas[4]={0,0,467,44};
    barraVida = new Sprite(url,coordenadas,frames);
    barraMana = new Sprite(url,coordenadas,frames);
    
    int coordenadas2[4]={16,56,32,32};
    vida = new Sprite(url,coordenadas2,frames);
    
    int coordenadas3[4]={90,56,32,32};
    mana = new Sprite(url,coordenadas3,frames);
    
    int coordenadas4[4]={152,54,58,58};
    recuadroArma= new Sprite(url,coordenadas4, frames);
    recuadroHechizo= new Sprite(url,coordenadas4, frames);
    
    int coordenadas6[4]={0, 0, 68, 56};
    int coordenadas5[4]={0, 0, 60, 64};
    pv=new Sprite(url2, coordenadas6, frames);
    pm= new Sprite(url3, coordenadas5, frames);
    
    barraVida->set_origin(0,0);
    barraMana->set_origin(0,0);
    vida->set_origin(0,0);
    mana->set_origin(0,0);
    recuadroArma->set_origin(0,0);
    recuadroHechizo->set_origin(0,0);
    pv->set_origin(0,0);
    pm->set_origin(0,0);
    
    barraVida->set_position(20,50);
    barraMana->set_position(20,100);
    vida->set_position(23,54);
    mana->set_position(23,104);
    recuadroArma->set_position(20,200);
    recuadroHechizo->set_position(20,160);
    pv->set_position(20,260);
    pm->set_position(20,300);
    pv->set_scale(1.52,1.52);
    pm->set_scale(1.52,1.52);
    
    barraVida->set_scale(0.65,0.75);
    barraMana->set_scale(0.65,0.75);
    if(!font.loadFromFile("resources/b.TTF")){
        
    }
    npv= new sf::Text;
    npv->setFont(font);
    npv->setColor(sf::Color::White);
    npv->setString("0");
    npv->setPosition(250,300);
    
    npm= new sf::Text;
    npm->setFont(font);
    npm->setColor(sf::Color::White);
    npm->setString("0");
    npm->setPosition(250,330);
    
    
    int coord[4]={0, 0, 49 , 92};
    int f=1;
    std::string ruta("resources/sword.png");
    espada = new Sprite(ruta, coord, f);
    
}

void hud::actualizar(int v, int m){
    float escala=(float)v/200;
    float escala2=(float)m/100;
    if(v<=0){
        escala=0;
    }
    if(m<=0){
        escala2=0;
    }
    vida->set_scale(96*escala,0.8);
    mana->set_scale(96*escala2,0.8);
    //v2 y m2 son la vida y el mana actuales, para saber en que relacion aumentar/disminuir la barra
}

Sprite* hud::renderv(int a){
    vida->set_position(23+a,54);
    return vida;
}
Sprite* hud::renderm(int a){
    mana->set_position(23+a,104);
    return mana;
}
Sprite* hud::renderbv(int a){
    barraVida->set_position(20+a,50);
    return barraVida;
}
Sprite* hud::renderbm(int a){
    barraMana->set_position(20+a,100);
    return barraMana;
}
/*
Sprite* hud::rendera(int a){
    arma->set_position(20+a,160);
    return arma;
}
Sprite* hud::renderh(int a){
    hechizo->set_position(105+a,160);
    return hechizo;
}*/
Sprite* hud::renderra(int a){
    recuadroArma->set_position(20+a,160);
    return recuadroArma;
}
Sprite* hud::renderrh(int a){
    recuadroHechizo->set_position(105+a,160);
    return recuadroHechizo;
}
Sprite* hud::renderpv(int a){
    pv->set_position(180+a,140);
    return pv;
}
Sprite* hud::renderpm(int a){
    pm->set_position(240+a,137);
    return pm;
}

sf::Text* hud::getnpv(int a){
    npv->setPosition(a+202,184);
    return npv;
}
sf::Text* hud::getnpm(int a){
    npm->setPosition(a+289,186);
    return npm;
}

hud::hud(const hud& orig) {
}

hud::~hud() {
}

