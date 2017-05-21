/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Mapa.h"
#include "tinystr.h"
#include "tinyxml.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

Mapa::Mapa() {
    //constructor vacio
    
}

Mapa::Mapa(const Mapa& orig) {
}

Mapa::~Mapa(){
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            delete[] _tilemap[l][y];
        }
        delete[] _tilemap[l];
    }
    delete _tilemap;
}

void Mapa::leerMapa(int mapa){
    
     //cargo la textura del fondo
    if(mapa==1){
        if(!texturafondo.loadFromFile("resources/Fondo.png")){
            std::cerr << "Error cargando la imagen de fondo";
            exit(0);
        }
    }
    if(mapa==2){
        if(!texturafondo.loadFromFile("resources/Mapa2.png")){
            std::cerr << "Error cargando la imagen de fondo";
            exit(0);
        }
    }
    fondo.setTexture(texturafondo);
    
    TiXmlDocument doc;
    
    if(mapa==1){ 
        doc.LoadFile("resources/Mapa.tmx");
    }
    
    if(mapa==2){
        doc.LoadFile("resources/Mapa2.tmx");
         
    }
    TiXmlElement* map = doc.FirstChildElement("map");

    
    
    //guardamos los datos del tmx
    map->QueryIntAttribute("width",&_width);
    map->QueryIntAttribute("height",&_height);
    map->QueryIntAttribute("tilewidth",&_tileWidth);
    map->QueryIntAttribute("tileheight",&_tileHeigth);
    
    //Leemos los tilesets
    TiXmlElement *img = map->FirstChildElement("tileset");
    int numTil=0;
    while(img){
        numTil++;
        img=img->NextSiblingElement("tileset");
    }
    
    
    string filename;

    img = map->FirstChildElement("tileset");
    //guardamos en filename el spritesheet
    while(img){
        filename=(string)img->FirstChildElement("image")->Attribute("source");
        img=img->NextSiblingElement("tileset");
    } 
    
    _tilesetTexture.loadFromFile(filename);
    
    //leemos las diferentes capas
    TiXmlElement *layer = map->FirstChildElement("layer");
    _numLayers=0;
    while(layer){
        _numLayers++;
        layer= layer->NextSiblingElement("layer");
    } 
    
    //Reserva de memoria para saber el numnero de capas y el tamaño 
    _tilemap=new int**[_numLayers];
    for(int i=0; i<_numLayers; i++){
        _tilemap[i]=new int*[_height];
    }
    
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            _tilemap[l][y]=new int[_width];
        }
    }

    TiXmlElement *data;
    //leemos el atributo imagen
    layer = map->FirstChildElement("layer");
    string *name=new string[_numLayers];
    int j=0;
    int l=0;
    //leo los tiles del xml y avanzo a la siguiente posicion
    while(layer){
        data= layer->FirstChildElement("data")->FirstChildElement("tile");
        name[j]= (string)layer->Attribute("name");
            while(data){
                for(int y=0; y<_height; y++){
                    for(int x=0; x<_width;x++){
                        data->QueryIntAttribute("gid",&_tilemap[l][y][x]);
                        data=data->NextSiblingElement("tile");
                    }
                }
            }
        l++;
        layer= layer->NextSiblingElement("layer");
        j++;
    }
      
    //Reserva de memoria para los sprites
    _tilemapSprite=new sf::Sprite***[_numLayers];
      
    for(int l=0; l<_numLayers; l++){
        _tilemapSprite[l]=new sf::Sprite**[_height];
    }
      
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            _tilemapSprite[l][y]= new sf::Sprite*[_width];
            for(int x=0; x<_width; x++){
                _tilemapSprite[l][y][x]=new sf::Sprite();
            }
        }
    } 
    
    int columns = _tilesetTexture.getSize().x / _tileWidth;
    int rows = _tilesetTexture.getSize().y / _tileHeigth;
    
    _tilesetSprite =new sf::Sprite[columns*rows];     
    int t=0;
    for(int y=0; y<rows; y++){
        for(int x=0; x<columns;x++){
              _tilesetSprite[t].setTexture(_tilesetTexture);
              //_tilesetSprite[t].setTextureRect(sf::IntRect(left,top,width,height));//ojo si hay dos imagenes
              _tilesetSprite[t].setTextureRect(sf::IntRect(x*_tileWidth,y*_tileHeigth,_tileWidth,_tileHeigth));
              t++;
        }
    }
    
    //asignacion de los diferentes sprites
      
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width;x++){
                int gid=_tilemap[l][y][x]-1;
                if(gid>=rows*columns){
                    cout<<gid<<endl;
                    cout<<rows<<endl;
                    cout<<columns<<endl;
                    cout<<"Error"<<endl;
                }
                else if(gid>0){   
                    _tilemapSprite[l][y][x]=new sf::Sprite(_tilesetTexture,_tilesetSprite[gid].getTextureRect());
                    _tilemapSprite[l][y][x]->setPosition(x*_tileWidth,y*_tileHeigth);
                }
                else{
                    _tilemapSprite[l][y][x]=NULL;
                }
            }
        }
    }
    
    //###########################################
    //Detalles extra de datos
    _cols = columns;
    _rows = rows;
    
    std::string verde("resources/verde.png");
    std::string rojo("resources/rojo.png");
    std::string amarillo("resources/amarillo.png");
    
    
    //-------Añadir el tamaño del enemigo para regular el tamaño del nodo
    //Carga de los nodos mágicos para la IA
    Nodo::height = 50.0f;
    Nodo::width = 50.0f;

    grid = new Nodo**[rows];
    for(int i = 0; i<_cols; i++){
        grid[i] = new Nodo*[_cols];
        for(int j = 0; j< _rows; j++){
            //----------El tamanyo del nodo debería de ser el tamanyo del enemigo que lo usa
            grid[i][j] = new Nodo(verde,i,j,0);
        }
    }
    
    //Carga de los obstaculos para la IA
    obstaculos = new Obstaculo*[2];
    obstaculos[0] = new Obstaculo(rojo,300,200,1,3);
    obstaculos[1] = new Obstaculo(rojo,500,500,4,1);
    
    //Pintar los nodos que coinciden con los obstáculos como bloqueados
    for(int i = 0; i<_rows; i++){
        for(int j = 0; j< _cols; j++){
            //----------El tamanyo del nodo debería de ser el tamanyo del enemigo que lo usa
            for(int k = 0; k<2;k++){
               if(grid[i][j]->getParcela()->comprobarColision(0,obstaculos[k]->getSprite())){
                   grid[i][j]->colisionaObstaculo(amarillo,1);
               } 
            }
            
        }
    }
    //###########################################
    
    cout<<endl;
    cout<<"Datos del mapa:"<<endl;
    cout<<"Heigth= "<<_height<<endl;
    cout<<"Width= "<<_width<<endl;
    cout<<"TileWidth= "<<_tileWidth<<endl;
    cout<<"TileHeigth= "<<_tileHeigth<<endl;
    cout<<"Numero de capas= "<<_numLayers<<endl;
    cout<<"Numero de tilesets= "<<numTil<<endl;
    cout<<"Nombre del tileset= "<<filename<<endl;
    cout<<endl;
}

//dibujar el mapa, primero dibujamos el fondo y a continuación las diferentes capas

void Mapa::dibuja(sf::RenderWindow& window){
    
    window.draw(fondo);

    for(int t=0; t<_numLayers; t++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[t][y][x]!=NULL){
                    window.draw(*(_tilemapSprite[t][y][x]));
                }
            }
        }
    }
    
}

//Métodos añadidos para verificar la IA
//###########################################
void Mapa::dibujaNodos(sf::RenderWindow& window){
     for(int t=0; t<_rows; t++){
        for(int y=0; y<_cols; y++){
            window.draw(grid[t][y]->getParcela()->render(0));
        }
     }
}

void Mapa::dibujaObs(sf::RenderWindow& window){
    for(int i = 0; i< 2; i++){
        window.draw(obstaculos[i]->getSprite()->render(0));
    }
}


//Métodos añadidos para usar la IA
std::vector<Nodo*> Mapa::CalcRoute(int px, int py, int ex, int ey){
    //Lista de nodos en la lista abierta, y nodos del camino final
    std::vector<Nodo*> open;
    std::vector<Nodo*> closed;
    
    //Limpiamos por si queda basurilla de la anterior ejecución
    open.clear();
    closed.clear();
    
    //Cogemos el nodo q que será con el que trabajaremos
    Nodo* q = grid[ex][ey];
    Nodo* f = NULL;
    
    //Si no nos salimos del límite
    if(px<_cols && px>=0 && ex<_cols && ex>=0 && py<_rows && py>=0 && ey< _rows && ey>=0){
        //Metemos en la lista abierta el nodo inicial
        open.push_back(grid[ex][ey]);
        
        bool reached = false;
        
        //Las variables de posicion del nodo actual en el grid
        int nodox = ex;
        int nodoy = ey;
        
        //Bucle while que solo acaba cuando no haya más elementos en la lista abierta y no alcancemos el objetivo
        while(!open.empty() && !reached){
            int tirar = 0;
            //Nuestro nodo provisional será el primero de la lista
            q = open.at(0);
            nodox = q->x;
            nodoy = q->y;
            
            //Y luego buscamos el que tenga menos valor de F para cogerlo
            for(int i = 0; i<open.size(); i++){
                if(open.at(i)->f < q->f){
                    q = open.at(i);
                    nodox = q->x;
                    nodoy = q->y;
                    tirar = i;
                }
            }
            
            // si llegamos al final, ta luego
            if(nodox == px && nodoy == py){
                reached = true;
            }else{
            
            //Metemos en la lista cerrada este nodo, y lo borramos de la abierta
            closed.push_back(open.at(tirar));
            open.erase(open.begin()+tirar);
            q->closed = true;
            
            //Nodo provisional para trabajar con él
            Nodo* x;
            if(nodox+1 < _cols){
                x = grid[nodox+1][nodoy];
                if(x->estado!=1){
                    if(!x->closed){
                        //Si no está en la lista abierta
                        if(!x->open){
                            //lo metemos dentro
                            open.push_back(x);
                            x->open = true;
                            x->padre = q;

                            //Calculo de g
                            x->g = q->g+10;

                            //calculo de H
                            int i = px - (nodox+1);
                            int j = py - nodoy;

                            if(i<0){
                                i = -i;
                            }
                            if(j<0){
                                j = -j;
                            }

                            x->h = i+j;


                            //Calculo de f
                            x->f = x->g+x->h;
                        }else{
                            //Si está ya dentro de la lista, actualizamos sus valores
                            //Si el coste es menor desde aquí, actualizamos
                            if(q->g+10 < x->g){

                                x->padre = q;
                                x->g = q->g+10;
                                x->f = x->g + x->h;
                            }
                        }

                    }
                }
            }
            if(nodox-1 >= 0){
                 x = grid[nodox-1][nodoy];
                if(x->estado!=1){
                    if(!x->closed){
                        //Si no está en la lista abierta
                        if(!x->open){
                            //lo metemos dentro
                            open.push_back(x);
                            x->open = true;
                            x->padre = q;

                            //Calculo de g
                            x->g = q->g+10;

                            //calculo de H
                            int i = px - (nodox-1);
                            int j = py - nodoy;

                            if(i<0){
                                i = -i;
                            }
                            if(j<0){
                                j = -j;
                            }

                            x->h = i+j;


                            //Calculo de f
                            x->f = x->g+x->h;
                        }else{
                            //Si está ya dentro de la lista, actualizamos sus valores
                            //Si el coste es menor desde aquí, actualizamos
                            if(q->g+10 < x->g){

                                x->padre = q;
                                x->g = q->g+10;
                                x->f = x->g + x->h;
                            }
                        }

                    }
                }
            }
            if(nodoy+1 < _rows){
                x = grid[nodox][nodoy+1];
                if(x->estado!=1){
                    if(!x->closed){
                        //Si no está en la lista abierta
                        if(!x->open){
                            //lo metemos dentro
                            open.push_back(x);
                            x->open = true;
                            x->padre = q;

                            //Calculo de g
                            x->g = q->g+10;

                            //calculo de H
                            int i = px - nodox;
                            int j = py - (nodoy+1);

                            if(i<0){
                                i = -i;
                            }
                            if(j<0){
                                j = -j;
                            }

                            x->h = i+j;


                            //Calculo de f
                            x->f = x->g+x->h;
                        }else{
                            //Si está ya dentro de la lista, actualizamos sus valores
                            //Si el coste es menor desde aquí, actualizamos
                            if(q->g+10 < x->g){

                                x->padre = q;
                                x->g = q->g+10;
                                x->f = x->g + x->h;
                            }
                        }

                    }
                }
            }
            if(nodoy-1 >= 0){
                x = grid[nodox][nodoy-1];
                if(x->estado!=1){
                    if(x->closed == false ){
                        //Si no está en la lista abierta
                        if(x->open == false){
                            //lo metemos dentro
                            open.push_back(x);
                            x->open = true;
                            x->padre = q;

                            //Calculo de g
                            x->g = q->g+10;

                            //calculo de H
                            int i = px - nodox;
                            int j = py - (nodoy-1);

                            if(i<0){
                                i = -i;
                            }
                            if(j<0){
                                j = -j;
                            }

                            x->h = i+j;


                            //Calculo de f
                            x->f = x->g+x->h;
                        }else{
                            //Si está ya dentro de la lista, actualizamos sus valores
                            //Si el coste es menor desde aquí, actualizamos
                            if(q->g+10 < x->g){

                                x->padre = q;
                                x->g = q->g+10;
                                x->f = x->g + x->h;
                            }
                        }

                    }
                }
            }
            
            }
        }
       f = grid[px][py];
    }
    
    std::vector<Nodo*> caminoProv;
    std::vector<Nodo*> caminoFinal;
    
    caminoProv.clear();
    caminoFinal.clear();
    
    
    //Si se coloca el nodo
    if(f!=NULL){
        //Por algún motivo no calcula bien condiciones dentro del while, usar siempre booleans
        bool iguales = false;
        if(f->x == ex && f->y == ey){
             iguales = true;
        }
        if(f->estado==1){
            iguales = true;
        }
        //Mientras no sean ambos puntos iguales, es decir, que se llegue al destino
        while(!iguales){
            iguales=false;
            if(f->x == ex && f->y == ey){
                iguales=true;
            }
            if(!f->padre){
                iguales = true;
            }
            if(!iguales){
                 //std::cout<<"Camino trazado: "<<f->x <<","<<f->y<<std::endl;
                caminoProv.push_back(f);
                f = f->padre;
            }
        }

        //Se reordenan dado que se almacen de delante para atrás
        for(int i = 0; i<caminoProv.size();i++){
            caminoFinal.push_back(caminoProv.at(i));
        }
    }
    limpiaIA();
    
     //---- Añadir optimización de ruta y linealizado
    
    return caminoFinal;
    //return closed;
   
}

void Mapa::limpiaIA(){
    for(int i=0;i<_rows;i++){
        for(int j=0;j<_cols;j++){
            grid[i][j]->f = 0;
            grid[i][j]->h = 0;
            grid[i][j]->g = 0;
            grid[i][j]->padre = NULL;
            grid[i][j]->closed = false;
            grid[i][j]->open = false;
        }
    }
}

Nodo* Mapa::devuelveNodo(int x, int y){
    return grid[x][y];
}

bool Mapa::colisionaObs(Sprite *colisionador){
    for(int i = 0; i< 2; i++){
        if(obstaculos[i]->getSprite()->comprobarColision(0,colisionador)){
            return true;
        }
    }
    return false;
}
//###########################################