#ifndef TERRAIN_H
#define TERRAIN_H
#include <stdlib.h>
#include "Balle.h"
#include "Raquette.h"
#include <iostream>
#include <thread>
using namespace std;

class Terrain
{
    private:
    int x_ter;
    int y_ter;
    thread *test[2];
    Balle *b;
    Raquette *p1;
    Raquette *p2;

    public:
    //Constructeur
    Terrain(int x,int y);
    ~Terrain();
    void draw();
    void play();
    void init();
    friend class Balle;
    // Méthodes


      
};
#endif
