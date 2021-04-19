#include "Balle.h"
enum direction {Haut=1, Haut_D=2, Droite=3, Bas_D=4,Bas=5,Bas_G=6,Gauche=7,Haut_G=8,Stop=9} dir;
Balle::Balle(int x,int y){
        dir=Bas_G;
        x_init=x;
        y_init=y;
        x_b=x_init;
        y_b=y_init;
        vitesse=1;//Pas vraiment la vitesse(Laisser à 1 je pense)
    }
    
int Balle::collision_terrain(int x_t,int y_t)
    {
        int scenar=0;
        if(this->x_b<=1 or x_b>=x_t)
        {
            //change ball direction en fonction de la direction de la balle
            if(dir==Haut_G)
            {
                dir=Haut_D;
            }
            else if(dir==Haut_D)
            {
                dir=Haut_G;
            }
            else if(dir==Bas_G)
            {
                dir=Bas_D;
            }
            else if(dir==Bas_D)
            {
                dir=Bas_G;
            }
           scenar=0;

        }
        if(this->y_b<=0)
        {
            //player 1 perds
            scenar=1;
        }
        if(this->y_b>=y_t)
        {
            //player 2 perds
            scenar=2;
        }
        return(scenar);//Pas de collision
    }

void Balle::collision_raquette(Raquette &p1,Raquette &p2)//p1=en haut p2=en bas
    {
        int taille=p1.taille_raq; //taille centre+-taille (2 raquette meme taille)
        int nbr_elt=1+2*taille;
         //On sait que la longueur du raquette est impair (1 +2*taille) donc l'indice du millieu est entier
        int middle_ind=(nbr_elt-1)/2; 
       
        std::vector<int> v1(nbr_elt);
        std::vector<int> v2(nbr_elt);
        std::iota(v1.begin(), v1.end(), p1.x_centre-taille);//array pos x de la raquette du joueur 1
        std::iota(v2.begin(), v2.end(), p2.x_centre-taille);//array pos x de la raquette du joueur 2
        
        //On regarde si pos_balle_x est sur la raquette et pos_balle_y est sur raquette
        std::vector<int>::iterator it; 
        it = find(v1.begin(), v1.end(), x_b);
        if(it != v1.end() and y_b==p1.y_centre) 
        {
            int ind1 = it-v1.begin();
            if(ind1==middle_ind) 
            {
                dir=Haut;
            }
            else if(ind1<middle_ind)
            {
                dir=Haut_G;
            }
            else if(ind1>middle_ind)
            {
                dir=Haut_D;
            }
        }

        it = find(v2.begin(), v2.end(), x_b);
        if(it != v2.end() and y_b==p2.y_centre)
        {
             int ind2 = it-v2.begin();
            if(ind2==middle_ind) 
            {
                dir=Bas;
            }
            else if(ind2<middle_ind)
            {
                dir=Bas_G;
            }
            else if(ind2>middle_ind)
            {
                dir=Bas_D;
            }
        }
    }
    
void Balle::Set_Pos_Balle()
    {

        switch(dir)
        {
            case Haut:
                x_b=x_b;
                y_b=y_b+vitesse;
                break;
            case Haut_D:
                x_b=x_b+vitesse;
                y_b=y_b+vitesse;
                break;
            case Droite:
                x_b=x_b+vitesse;
                y_b=y_b;
                break;
            case Bas_D:
                x_b=x_b+vitesse;
                y_b=y_b-vitesse;
                break;
            case Bas:
                x_b=x_b;
                y_b=y_b-vitesse;
                break;
            case Bas_G:
                x_b=x_b-vitesse;
                y_b=y_b-vitesse;
                break;
            case Gauche:
                x_b=x_b-vitesse;
                y_b=y_b;
                break;
            case Haut_G:
                x_b=x_b-vitesse;
                y_b=y_b+vitesse;
                break;
            case Stop:
                x_b=x_b;
                y_b=y_b;
                break;
        }
    }

      