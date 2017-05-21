/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hechizo.cpp
 * Author: adrian
 * 
 * Created on 20 de mayo de 2017, 18:21
 */


#include "hechizo.h"

Hechizo::Hechizo(std::string t, int x, int y){

        if(t=="e"){
            tipo= "escupitajo";
            danyo=40;
            gastoMana=25;
            posX=x;
            posY=y;
            
            int coord[4]={0, 0, 33, 33};
            int f=1;
            std::string ruta("resources/escupitajo.png");
            spritehechizo= new Sprite(ruta, coord, f);
            spritehechizo->set_position(x, y);
            int frames=9;
            std::string ruta2("resources/Agony.png");
            int coordh[36]={385, 1554, 30, 62, 418, 1551, 42, 64, 463, 1550, 45, 65, 511, 1550, 46, 66, 561, 1550, 46, 66, 859, 1557, 83, 59, 1325, 1458, 47, 59, 1376, 1456, 38, 62, 1417, 1453, 29, 65};
            hechizoright=new Sprite(ruta2, coordh, frames);
            hechizoright->set_framerate(75);
            int coordh2[36]={415, 1554, -30, 62, 460, 1551, -42, 64, 508, 1550, -45, 65, 557, 1550, -46, 66, 607, 1550, -46, 66, 942, 1557, -83, 59, 1372, 1458, -47, 59, 1414, 1456, -38, 62, 1446, 1453, -29, 65};
            hechizoleft=new Sprite(ruta2, coordh2, frames);
            hechizoleft->set_framerate(75);
        }
        else if(t=="m"){
            tipo="meteoro";
            danyo=65;
            gastoMana=50;
            posX=x;
            posY=y;
            
            int coord[4]={0, 0, 33, 31};
            int f=1;
            std::string ruta("resources/meteoro.png");
            spritehechizo= new Sprite(ruta, coord, f);
            spritehechizo->set_position(x, y);
            int coordh[36]={675, 1455, 30, 62, 708, 1453, 42, 64, 753, 1452, 45, 65, 802, 1452, 46, 66, 852, 1452, 46, 66, 984, 1451, 80, 67, 1325, 1458, 47, 59, 1376, 1456, 38, 62, 1417, 1453, 29, 65};
            int frames=9;
            std::string ruta2("resources/Agony.png");
            hechizoright=new Sprite(ruta2, coordh, frames);
            hechizoright->set_framerate(75);
            int coordh2[36]={705, 1455, -30, 62, 750, 1453, -42, 64, 798, 1452, -45, 65, 848, 1452, -46, 66, 898, 1452, -46, 66, 1064, 1451, -80, 67, 1372, 1458, -47, 59, 1414, 1456, -38, 62, 1446, 1453, -29, 65};
            hechizoleft=new Sprite(ruta2, coordh2, frames);
            hechizoleft->set_framerate(75);
        }

    }

Hechizo::Hechizo(std::string t){
    
        if(t=="escupitajo"){
            tipo= "escupitajo";
            danyo=40;
            gastoMana=25;
            posX=0;
            posY=0;
            spritehechizo=NULL;
        }
        else if(t=="meteoro"){
            tipo="meteoro";
            danyo=65;
            gastoMana=50;
            posX=0;
            posY=0;
            spritehechizo=NULL;
        }
}

    int Hechizo::getDanyo(){
        return danyo;
    }
    
    int Hechizo::getGastoMana(){
        return gastoMana;
    }
    
    std::string Hechizo::getTipo(){
        return tipo;
    }
    
    Sprite* Hechizo::getSpriteHechizo(){
        return spritehechizo;
    }
    
    int Hechizo::getPosX(){
        return posX;
    }
    
    int Hechizo::getPosY(){
        return posY;
    }
    
    Sprite* Hechizo::getHechizoRight(){
        return hechizoright;
    }
    
    Sprite* Hechizo::getHechizoLeft(){
        return hechizoleft;
    }