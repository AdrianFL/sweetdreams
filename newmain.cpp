/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: javi
 *
 * 
 * Created on May 11, 2017, 7:50 AM
 */

#include <cstdlib>
#include "Eopciones.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <vector>
#include <string> 
#include "Emenu.h"
#include "Juego.h"

using namespace std;

/*
 * 
 */
int main() {

    Juego::Instance();
    Juego::Instance()->Init();
    
    return 0;
}

