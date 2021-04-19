#include "Raquette.h"
#include <iostream>
#include <mutex>
//Constructeur
Raquette::Raquette(int x,int y,int taille){
    x_init=x;
    y_init=y;
    x_centre=x_init;
    y_centre=y_init;
    taille_raq=taille;
}
void Raquette::IA_Raquette(int x_b,int x_t)
    {
        if(x_b>this->taille_raq and x_b<x_t-this->taille_raq)
        {
            this->x_centre=x_b-1;
        }
        if (this->x_centre<=this->taille_raq)
        {
            this->x_centre=this->taille_raq+1;
        }
        if (this->x_centre>=x_t-this->taille_raq)
        {
            this->x_centre=x_t-this->taille_raq-1;
        }
    }
void Raquette::test()
{
    cout<<"zal";
}
void Raquette::Control_Raq(int x_b,int x_t)
{
    while(1)
    {
    char input=' ';
    input=_getch();
    if(input=='q')
    {
        this->x_centre--;
    }
    else if(input=='d')
    {
        this->x_centre++;
    }
    if (this->x_centre<=this->taille_raq)
        {
            this->x_centre=this->taille_raq+1;
        }
    if (this->x_centre>=x_t-this->taille_raq)
        {
            this->x_centre=x_t-this->taille_raq-1;
        }
    }
}