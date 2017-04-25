/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clock.hpp
 * Author: adrian
 *
 * Created on 21 de marzo de 2017, 14:43
 */

#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <SFML/System.hpp>

class Clock {
public:
    Clock();
    int32_t restart();
    int32_t getTime();
private:
    sf::Clock clock;

};

#endif /* CLOCK_HPP */
