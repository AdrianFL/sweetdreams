/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Eintroduccion.h
 * Author: javi
 *
 * Created on May 20, 2017, 10:21 AM
 */

#ifndef EINTRODUCCION_H
#define EINTRODUCCION_H

#include "Juego.h"

class Eintroduccion :public State{
public:
    //Eintroduccion();
   // Eintroduccion(const Eintroduccion& orig);
    //virtual ~Eintroduccion();
    
    
    void Handle();
    void Init();
    void Update();
    void Render();
    Juego* getContext();
    static Eintroduccion* Instance(Juego* context);
    ~Eintroduccion();
    
    
protected:
    Eintroduccion(Juego* context);
    Eintroduccion(const Eintroduccion &);
    Eintroduccion &operator = (const Eintroduccion &);

    
private:
    static Eintroduccion* pinstance;
    Juego* _context;
};

#endif /* EINTRODUCCION_H */

