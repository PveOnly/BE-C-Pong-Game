#ifndef RAQUETTE_H
#define RAQUETTE_H
#include <vector>
#include <iostream>
#include <conio.h>
using namespace std;

class Raquette
{
    public:
    int x_init;
    int y_init;
    int taille_raq; //raquette xcentre-taille xcentre+taille;
    int x_centre;
    int y_centre;  

    //public:
    //Constructeur
    Raquette(int x,int y,int taille);
    friend class Balle;
    // Méthodes 
    void IA_Raquette(int b,int x_t);
    void Control_Raq(int x_b,int x_t);
    void test();


      
};
#endif