/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Eintroduccion.cpp
 * Author: javi
 * 
 * Created on May 20, 2017, 10:21 AM
 */

#include <stdio.h>
#include <iostream>

#include "Emenu.h"
#include "Eintroduccion.h"

using namespace std;

Eintroduccion* Eintroduccion::pinstance = 0;

Eintroduccion::Eintroduccion(Juego* context){ //CONSTRUCTOR REAL
    _context = context; //En el momento en el que se crea el estado, se asigna su contexto.
    //Ahora tengo que cargar aqui las imagenes de la introduccion
}

Eintroduccion* Eintroduccion::Instance(Juego* context){
    
    if(pinstance == 0) pinstance = new Eintroduccion(context);

    return pinstance;
}

void Eintroduccion::Handle(){
  
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.
    
}
void Eintroduccion::Init(){
    
    
}


void Eintroduccion::Update(){
    
    if(!initState){
        Init();
        initState = true;
    }
    
    //ACCIONES DE UPDATE
    
    Render();

}

void Eintroduccion::Render(){
    

}

Juego* Eintroduccion::getContext(){
    
    return _context;    //Para recuperar el contexto
    
}

Eintroduccion::~Eintroduccion(){
    //Destruccion de la instancia 
    _context = 0;
    pinstance = 0;
    
}
