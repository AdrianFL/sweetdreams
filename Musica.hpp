/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Musica.hpp
 * Author: adrian
 *
 * Created on 21 de mayo de 2017, 13:42
 */

#ifndef MUSICA_HPP
#define MUSICA_HPP

#include<SFML/Audio.hpp>

class Musica {
public:
    Musica(std::string s);
    void Play();
    void setLoop(bool b);
private:
    sf::Music musica;
};

#endif /* MUSICA_HPP */

