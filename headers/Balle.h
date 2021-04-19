#ifndef BALLE_H
#define BALLE_H
#include "Raquette.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Balle
{
    public:
    
    int vitesse;
    int x_init;
    int y_init;
    int x_b;
    int y_b;  

    //public:
    //Constructeur
    Balle(int x,int y);

    // Méthodes
    
    int collision_terrain(int x_t,int y_t);

    void collision_raquette(Raquette &p1,Raquette &p2);//p1=en haut p2=en bas
    
    void Set_Pos_Balle();

      
};
#endif