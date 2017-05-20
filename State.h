/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   State.h
 * Author: javi
 *
 * Created on May 20, 2017, 10:19 AM
 */

#ifndef STATE_H
#define STATE_H

//#include "Juego.h"

class State {
public:
    State();
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Handle() = 0;
    virtual ~State();
    bool initState;
    
 //   virtual void on(Juego *m);
//    virtual void off(Juego *m);
private:

};

#endif /* STATE_H */

