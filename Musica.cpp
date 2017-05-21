/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Musica.cpp
 * Author: adrian
 * 
 * Created on 21 de mayo de 2017, 13:42
 */

#include "Musica.hpp"
#include <iostream>

Musica::Musica(std::string s) {
    if(!musica.openFromFile(s)){
        std::cerr << "Error al abrir la musica" << std::endl;
        exit(-1);
    }
}

void Musica::Play(){
    musica.play();
}

void Musica::setLoop(bool b){
    musica.setLoop(b);
}

