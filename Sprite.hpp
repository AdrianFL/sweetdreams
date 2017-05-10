/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.hpp
 * Author: adrian
 *
 * Created on 17 de marzo de 2017, 17:14
 */

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SFML/Graphics.hpp>

class Sprite {
public:
    /*Sprite();
    Sprite(const Sprite& orig);
    virtual ~Sprite();*/
    Sprite(std::string& url, int coord[], int frames);
    void set_origin(int x, int y);
    void set_framerate(int32_t x);
    void set_position(int x, int y);
    void set_scale(float x, float y);
    void set_rotation(float x);
    void rotate(float x);
    void move(int x, int y);
    bool comprobarColision(int x, Sprite *ajeno);
    sf::Sprite render(int32_t t);
    sf::Sprite getFotogramaActual();
private:    
    sf::Sprite *fotogramas;
    sf::Texture textura;
    int fr;
    int puntero;
    int32_t tasa;
    int32_t frames;

};

#endif /* SPRITE_HPP */

