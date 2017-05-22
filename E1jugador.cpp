/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   E1jugador.cpp
 * Author: javi
 * 
 * Created on May 20, 2017, 10:22 AM
 */


#include "E1jugador.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include "E2jugador.h"
#include "Eintroduccion.h"
#include "Emenu.h"
//#include "Eopciones.h"
#include "Epausa.h"
#include "Juego.h"


#define UPDATE_TICK_TIME 1000.0/15.0


E1jugador* E1jugador::pinstance = 0;
E1jugador* E1jugador::Instance(Juego* context,sf::RenderWindow *w){
    
    if(pinstance == 0) pinstance = new E1jugador(context,w);

    return pinstance;
}
E1jugador::E1jugador(Juego* context,sf::RenderWindow *w){ //CONSTRUCTOR REAL
    window=w;
    _context = context;    
    
    texto1= new sf::Text;
    texto2= new sf::Text;
    xD=0;
    
    
    //08080808080808080808080808080808080808080808080808080808080808080808080808080808080808
    //08080808080808080808080808080808080808080808080808080808080808080808080808080808080808
    window->setVerticalSyncEnabled(true);
    p1= new Personaje(0);
    mapa= new Mapa;
    
    //Música
    std::string rutamusica("resources/sweetdreams.ogg");
    Musica* musica = new Musica(rutamusica);
    
    musica->setLoop(true);
    //Comprobador de la música con el menú de opciones
    if(Eopciones::Instance(Juego::Instance(),window)->musica){
        musica->Play();
    }
    musicaencendida=true;
    
    //1 para leer el mapa 1, 2 para leer el mapa 2
    lvl = 1;
    mapa->leerMapa(lvl);
    
    camara=new Camara(window->getSize().x, window->getSize().y, 12, *mapa);
    
    recogida=true;
    movimiento=0;
    
    //Valores para el posicionamiento de enemigos y pociones
    ataca=false;
    cambialvl=false;
    finjuego=false;
    coloca1=false;
    coloca2=false;
    niveltime=-1;
    fintime=-1;
    
    //###################
    //Instanciacion enemigos
    if(lvl==1){
        enemigoM= new enemyMelee(1000, 400, 5, 10);
        enemigos.push_back(enemigoM);
        enemigoR= new enemyRange(1000, 520, 40, 5);
        enemigos.push_back(enemigoR);
        enemigoM2= new enemyMelee(1800, 400, 40, 5);
        enemigos.push_back(enemigoM2);
        enemigoM3=new enemyMelee(1800, 520, 40, 10);
        enemigos.push_back(enemigoM3);
        enemigoR2=new enemyRange(1870, 470, 60, 10);
        enemigos.push_back(enemigoR2);
        enemigoM4=new enemyMelee(3000, 400, 50, 10);
        enemigos.push_back(enemigoM4);
        enemigoM5=new enemyMelee(3000, 520, 50, 10);
        enemigos.push_back(enemigoM5);
        enemigoM6=new enemyMelee(3100, 400, 50, 10);
        enemigos.push_back(enemigoM6);
        enemigoM7=new enemyMelee(3100, 520, 50, 10);
        enemigos.push_back(enemigoM7);
        enemigoR3=new enemyRange(3150, 470, 100, 15);
        enemigos.push_back(enemigoR3);
        
        pvida=new Pocion("v", 900, -450);
        pociones.push_back(pvida);
        pmana=new Pocion("m", 400, -520);
        pociones.push_back(pmana);

        escupitajo=new Hechizo("e", 300, -500);
        hechizos.push_back(escupitajo);
    }
    //###################
    
    clock;
    updateclock;
    time;
    updatetime;
    
    hittime=-1;
    
    prueba=0;
    option=0;
    
    //08080808080808080808080808080808080808080808080808080808080808080808080808080808080808
    interfaz = new hud;
    //08080808080808080808080808080808080808080808080808080808080808080808080808080808080808
}

void E1jugador::Handle(){
    
   // std::cout << "E1JUGADOR: "  << this << std::endl;
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.
   // std::cout << _context<< std::endl;
    
    
}
Juego* E1jugador::getContext(){
    
    return _context;    //Para recuperar el contexto
    
}

void E1jugador::Init(){
   std::cout << "init E1jugador" << std::endl;
   salida=false;
   run(*Juego::Instance()->window);
   
}
int E1jugador::run(sf::RenderWindow &window){
    //buclue principal del juego  
    while(window.isOpen() && !salida){
        sf::Event event;
        //Comprobador de la música
        if(Eopciones::Instance(Juego::Instance(),&window)->musica && !musicaencendida){
            musica->Play();
            musicaencendida = true;
        }
        if(!Eopciones::Instance(Juego::Instance(),&window)->musica && musicaencendida){
            musica->Stop();
            musicaencendida = false;
        }
        
        while(window.pollEvent(event)){
            CUpdate2( event); //llamamos a la funcion teclas /update
        }
        
        //Tiempo para el render
        time=clock.restart();
        if(updateclock.getTime() > UPDATE_TICK_TIME)
        {
            Update();
        }
        Render(); //llamamos a la funcion render
    }
    return 0;
    
}
void E1jugador::Update(){
    
    if(finjuego==false && (p1->getVida()<=0 || (lvl==2 && enemigoFinal->vida<=0))){
        finjuego=true;
        fintime=1500;
    }
    
    if(finjuego==true && fintime<0){
        salida=true;
        Emenu::Instance(Juego::Instance(), window)->Handle();
    }
    
    Proyectil* disparo = NULL;
    std::vector<Proyectil*> disparoHechizo;
    
    updatetime=updateclock.restart();
    
    //Coordinación del ataque del protagonista
    if(ataca==true && hittime<0){
        ataca=false;
        for(int i=0; i<enemigos.size(); i++){
            if(golpeados[i]==true){
                enemigos[i]->herir(p1->getDanyo());
            }
        }
        
        if(lvl==1 && enemigoR3->vida<=0){
            cambialvl=true;
            niveltime=1000;
        }
        
        if(coloca1==false && lvl==1 && enemigoR->vida<=0){
            hechizos[0]->cambiarPos(1200,450);
            coloca1=true;
        }
        
        if(coloca2==false && lvl==1 && enemigoR2->vida<=0){
            pociones[0]->cambiarPos(1900,450);
            pociones[1]->cambiarPos(1800,425);
            coloca2=true;
        }
        
        if(coloca1==false &&lvl==2 && enemigoR->vida<=0 && enemigoR2->vida<=0){
            armas[0]->cambiarPos(1200,475);
            coloca1=true;
        }
        
        if(coloca2==false && lvl==2 && enemigoR3->vida<=0 && enemigoR4->vida<=0){
            pociones[2]->cambiarPos(1900,450);
            pociones[3]->cambiarPos(1800,425);
            hechizos[0]->cambiarPos(2000,500);
            coloca2=true;
        }
    }
    
    //Bloque update
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X)>50){
        option=1;
        movimiento=1;                
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X)<-50){
        option=2;
        movimiento=2;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y)<-50){
        option=3;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y)>50){
        option=4;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Joystick::isButtonPressed(0, 4)){
        p1->usaPocion("vida"); 
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Joystick::isButtonPressed(0, 5)){
        p1->usaPocion("mana");
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U) || sf::Joystick::isButtonPressed(0, 0)){
       //Falta comprobar que atctime<0
        if(ataca==false){
            p1->atacar();
            ataca=true;
            hittime=300;
            golpeados.clear();
            for(int i=0; i<enemigos.size(); i++){
                if(p1->getDireccion()>0){
                    if(enemigos[i]->vida>0 && enemigos[i]->getXCoordinate()>p1->getXCoordinate() && enemigos[i]->getXCoordinate()-p1->getXCoordinate()<150 && enemigos[i]->getYCoordinate()-p1->getYCoordinate()<100 && enemigos[i]->getYCoordinate()-p1->getYCoordinate()>-100){
                         golpeados.push_back(true);
                    }
                    else{
                        golpeados.push_back(false);
                    }
                }
                else{
                    if(enemigos[i]->vida>0 && enemigos[i]->getXCoordinate()<p1->getXCoordinate() && p1->getXCoordinate()-enemigos[i]->getXCoordinate()<150 && enemigos[i]->getYCoordinate()-p1->getYCoordinate()<100 && enemigos[i]->getYCoordinate()-p1->getYCoordinate()>-100){
                        golpeados.push_back(true);
                    }
                    else{
                        golpeados.push_back(false);
                    }
                }
            }
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) || sf::Joystick::isButtonPressed(0, 2)){
        p1->activaRecogida();
        recogida=false;
        for(int i=0; i<pociones.size()&&recogida==false; i++){
            if(recogida==false){
                if(p1->getDireccion()>0){
                    if(pociones[i]!=NULL && pociones[i]->getPosX()>p1->getXCoordinate() && pociones[i]->getPosX()-p1->getXCoordinate()<80 && pociones[i]->getPosY()-p1->getYCoordinate()<60 && pociones[i]->getPosY()-p1->getYCoordinate()>-60){
                        if(pociones[i]->getTipo()=="vida"){
                            if(p1->getNumPVida()<3){
                                recogida=true;
                                p1->aumentaPVida();
                                pociones.erase(pociones.begin()+i);
                            }
                        }
                        else if(pociones[i]->getTipo()=="mana"){
                            if(p1->getNumPMana()<3){
                                recogida=true;
                                p1->aumentaPMana();
                                pociones.erase(pociones.begin()+i);
                            }
                        }
                    }
                }
                else{
                    if(pociones[i]!=NULL && pociones[i]->getPosX()<p1->getXCoordinate() && p1->getXCoordinate()-pociones[i]->getPosX()<80 && pociones[i]->getPosY()-p1->getYCoordinate()<60 && pociones[i]->getPosY()-p1->getYCoordinate()>-60){
                        if(pociones[i]->getTipo()=="vida"){
                            if(p1->getNumPVida()<3){
                                recogida=true;
                                p1->aumentaPVida();
                                pociones.erase(pociones.begin()+i);
                            }
                        }
                        else if(pociones[i]->getTipo()=="mana"){
                            if(p1->getNumPMana()<3){
                                recogida=true;
                                p1->aumentaPMana();
                                pociones.erase(pociones.begin()+i);
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<armas.size() && recogida==false; i++){
            if(recogida==false){
                if(p1->getDireccion()>0){
                    if(armas[i]!=NULL && armas[i]->getposX()>p1->getXCoordinate() && armas[i]->getposX()-p1->getXCoordinate()<100 && armas[i]->getposY()-p1->getYCoordinate()<100 && armas[i]->getposY()-p1->getYCoordinate()>-100){
                        recogida=true;
                        p1->cambiarAtaque(armas[i]);
                        armas.erase(armas.begin()+i);
                    }
                }
                else{
                    if(armas[i]!=NULL && armas[i]->getposX()<p1->getXCoordinate() && p1->getXCoordinate()-armas[i]->getposX()<100 && armas[i]->getposY()-p1->getYCoordinate()<100 && armas[i]->getposY()-p1->getYCoordinate()>-100){
                        recogida=true;
                        p1->cambiarAtaque(armas[i]);
                        armas.erase(armas.begin()+i);
                    }
                }
            }
        }
        for(int i=0; i<hechizos.size() && recogida==false; i++){
            if(recogida==false){
                if(p1->getDireccion()>0){
                    if(hechizos[i]!=NULL && hechizos[i]->getPosX()>p1->getXCoordinate() && hechizos[i]->getPosX()-p1->getXCoordinate()<100 && hechizos[i]->getPosY()-p1->getYCoordinate()<100 && hechizos[i]->getPosY()-p1->getYCoordinate()>-100){
                        recogida=true;
                        p1->recogeHechizo(hechizos[i]);
                        hechizos.erase(hechizos.begin()+i);
                    }
                }
                else{
                    if(hechizos[i]!=NULL && hechizos[i]->getPosX()<p1->getXCoordinate() && p1->getXCoordinate()-hechizos[i]->getPosX()<100 && hechizos[i]->getPosY()-p1->getYCoordinate()<100 && hechizos[i]->getPosY()-p1->getYCoordinate()>-100){
                        recogida=true;
                        p1->recogeHechizo(hechizos[i]);
                        hechizos.erase(hechizos.begin()+i);
                    }
                }
            }
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y) || sf::Joystick::isButtonPressed(0, 3)){
        disparoHechizo = p1->lanzarHechizo();
    }
    p1->move(option);
    if(movimiento == 0){
        camara->fija();
    }
    else if(movimiento==1){
         camara->moverDer(*p1);
    }
    else if(movimiento==2){
        camara->moverIzq(*p1);
    }
    option=0;
    movimiento = 0;
    
    //######################
    //Control total de los enemigos
    int muertos=0; //Cuenta los destruidos, por si se da más de un enemigo destruido a la vez (casi imposible pero por si acaso)
    for(int i = 0; i<enemigos.size();i++){
        //Si el enemigo está vivo
        if(enemigos[i]->vida>0){
            if(dynamic_cast<enemyMelee*>(enemigos[i]) != NULL){
                dynamic_cast<enemyMelee*>(enemigos[i])->perseguir(p1,mapa);              
            }
            if(dynamic_cast<enemyRange*>(enemigos[i]) != NULL){
                disparo = dynamic_cast<enemyRange*>(enemigos[i])->perseguir(p1,mapa, time);
                
                //Control de los disparos, se pueden dar dos disparos a la vez por enemigo
                if(disparo!=NULL){
                    proyectiles.push_back(disparo);
                }
            }
            if(dynamic_cast<enemyFinal*>(enemigos[i]) != NULL){
                disparoFinal = dynamic_cast<enemyFinal*>(enemigos[i])->huir(p1,mapa,time);
            }
        }/*else{
            //Destruir enemigos muertos
            Enemy* enemigoMuerto  = enemigos.at(i-muertos);
            enemigos.erase(enemigos.begin()+i-muertos);
            muertos++;
            delete enemigoMuerto;
        }*/
    }
    //Control de los disparos
    //Enemigos

    for(int i = 0; i<disparoFinal.size();i++){
        Proyectil* aux = disparoFinal.at(i);
        proyectiles.push_back(aux);
    }
    
    //Personaje
    for(int i = 0; i<disparoHechizo.size();i++){
        Proyectil* aux = disparoHechizo.at(i);
        proyectiles.push_back(aux);
    }
    int destruidos=0; //Cuenta los destruidos, por si se da más de un proyectil destruido a la vez (casi imposible pero por si acaso)
    for(int i = 0; i<proyectiles.size();i++){
        if(!proyectiles[i]->muerto){
            if(proyectiles[i]->type<10){
                proyectiles[i]->volar(p1);
            }else{
                proyectiles[i]->volarP(enemigos);
            }
        }else{
            //Destruir proyectiles muertos
            Proyectil* proyectilMuerto  = proyectiles.at(i-destruidos);
            proyectiles.erase(proyectiles.begin()+i-destruidos);
            destruidos++;
            delete proyectilMuerto;
            
        }
        
    }
    
    //-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.INI
    int vidaDespues=p1->getVida();
    int manaDespues=p1->getMana();
    int numpv=p1->getNumPVida();
    int numpm=p1->getNumPMana();

    int entero = 10;
    std::string cadena = "";

    cadena = static_cast<std::ostringstream*>(&(std::ostringstream() << numpv))->str();
    std::string cadena2 = "";

    cadena2 = static_cast<std::ostringstream*>(&(std::ostringstream() << numpm))->str();

    //std::cout << "Esto es una cadena: " + cadena + "." << std::endl;


    texto1->setString(cadena);
    texto2->setString(cadena2);
    interfaz->actualizar(vidaDespues,manaDespues);
            
    //-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.FIN
    //######################
    //Manejador de niveles
    if(lvl==1 && cambialvl==true && niveltime<0){
        lvl=2;
        cambiaNivel();
    }
}

int E1jugador::CUpdate2(sf::Event event){
     switch(event.type){
        case sf::Event::KeyReleased:
                            
        switch(event.key.code){
            case sf::Keyboard::Escape:
                salida=true;
                Epausa::Instance(Juego::Instance(),window)->Handle(true);
                break;
            case sf::Keyboard::P:
                salida=true;
                Epausa::Instance(Juego::Instance(),window)->Handle(true);
                break;

        }
     }
     
         
    return 0;
}

void E1jugador::Render(){
    hittime-=time;
    niveltime-=time;
    fintime-=time;
    float percentTick = std::min(1.0f, static_cast<float>(updateclock.getTime())/static_cast<float>(UPDATE_TICK_TIME));
    window->clear();
    mapa->dibuja(*window);


     //###########################################
    //mapa->dibujaNodos(*window);
    //mapa->dibujaObs(*window);
    //Verifico que el camino va
    /*for(int i = 0; i<enemigos.size();i++){
        for(int j = 0;j < enemigos.at(i)->caminoActual.size();j++){
            window->draw(enemigos.at(i)->caminoActual.at(j)->getParcela()->render(time));
        }
    }*/
    //Verifico que el raycast va
    /*window->draw(enemigoR->raycast->render(time));
    window->draw(enemigoM->raycast->render(time));
    window->draw(enemigoFinal->raycast->render(time));*/
    //###################
    
    window->draw(p1->render(time, percentTick)->render(time));
    //###################
    for(int i =0; i<proyectiles.size();i++){
        if(proyectiles[i]->type==2){
            window->draw(proyectiles[i]->render(time,percentTick)->render(time));
        }
    }
    
    for (int i=0; i<pociones.size(); i++){
        window->draw(pociones[i]->getSprite()->getFotogramaActual());
    }
    
    for (int i=0; i<hechizos.size(); i++){
        window->draw(hechizos[i]->getSpriteHechizo()->getFotogramaActual());
    }
    for (int i=0; i<armas.size(); i++){
        window->draw(armas[i]->getSprite()->getFotogramaActual());
    }
    
    for(int i =0; i<enemigos.size();i++){
        window->draw(enemigos[i]->render(time,percentTick)->render(time));
    }

    window->draw(p1->render(time, percentTick)->render(time));
    
    for(int i =0; i<proyectiles.size();i++){
        if(proyectiles[i]->type!=2){
            window->draw(proyectiles[i]->render(time,percentTick)->render(time));
        }
    }
    //###################
    camara->move(percentTick);
    camara->draw(*window);
    
    //Renderizado de interfaz
    xD=camara->getDesp();
         window->draw(interfaz->renderbv(xD)->render(time));
         window->draw(interfaz->renderbm(xD)->render(time));
         window->draw(interfaz->renderv(xD)->render(time));
         window->draw(interfaz->renderm(xD)->render(time));
         window->draw(interfaz->renderra(xD)->render(time));
         window->draw(interfaz->renderrh(xD)->render(time));
         //window->draw(interfaz->rendera(xD)->render(time));
         //window->draw(interfaz->renderh(xD)->render(time));
         window->draw(interfaz->renderpv(xD)->render(time));
         window->draw(interfaz->renderpm(xD)->render(time));
         texto1=interfaz->getnpm(xD);
         texto2=interfaz->getnpv(xD);
         window->draw(*texto1);
         window->draw(*texto2);
    ////////
         
    window->display();
}

E1jugador::~E1jugador(){
    _context = 0;
    pinstance = 0;
}

void E1jugador::cambiaNivel(){
   
    
    if(lvl==2){
       delete mapa;
       
       mapa=new Mapa;
       mapa->leerMapa(lvl);
       
       delete camara;
       camara=new Camara(window->getSize().x, window->getSize().y, 12, *mapa);
       p1->cambialvl(0);
       enemigos.clear();
       delete enemigoM;
       enemigoM=new enemyMelee(100, 520, 10, 10);
       delete enemigoM2;
       enemigoM2=new enemyMelee(100, 470, 10, 10);
       delete enemigoR;
       enemigoR=new enemyRange(1000, 520, 50, 10);
       delete enemigoR2;
       enemigoR2=new enemyRange(1000, 470, 50, 10);
       delete enemigoM3;
       enemigoM3=new enemyMelee(1400, 520, 40, 10);
       delete enemigoM4;
       enemigoM4=new enemyMelee(1400, 470, 40, 10);
       delete enemigoM5;
       enemigoM5=new enemyMelee(1600, 500, 100, 10);
       delete enemigoR3;
       enemigoR3=new enemyRange(1900, 520, 40, 10);
       enemigoR4=new enemyRange(1900, 470, 40, 10);
       enemigoFinal=new enemyFinal(2700, 500, 1000, 20);
       enemigos.push_back(enemigoM);
       enemigos.push_back(enemigoM2);
       enemigos.push_back(enemigoR);
       enemigos.push_back(enemigoR2);
       enemigos.push_back(enemigoM3);
       enemigos.push_back(enemigoM4);
       enemigos.push_back(enemigoM5);
       enemigos.push_back(enemigoR3);
       enemigos.push_back(enemigoR4);
       enemigos.push_back(enemigoFinal);
       
       pociones.clear();
       delete pvida;
       delete pmana;
       pvida=new Pocion("v", 900, -450);
       pociones.push_back(pvida);
       pmana=new Pocion("m", 400, -520);
       pociones.push_back(pmana);
       pvida2=new Pocion("v",900,-900);
       pociones.push_back(pvida2);
       pmana2=new Pocion("m",400,-400);
       pociones.push_back(pmana2);
       
       hechizos.clear();
       delete escupitajo;
       meteoro=new Hechizo("m", 650, -500);
       hechizos.push_back(meteoro);
        
       espada=new Arma("e", 850, -450);
       armas.push_back(espada);
       
       coloca1=false;
       coloca2=false;
    }
}