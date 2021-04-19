#include "Terrain.h"

Terrain::Terrain(int x,int y){
    x_ter=x;
    y_ter=y;
    b=new Balle(x_ter/2,y_ter/2);//met la balle au millieu
    p1=new Raquette(x_ter/2,1,2);//crée une raquette en haut au millieu de taille 2    ------->x
    p2=new Raquette(x_ter/2,y_ter-1,2);//crée une raquette en bas au millieu de taille 2        
}
Terrain::~Terrain(){
    delete b;
    delete p1;
    delete p2;
}
void Terrain::init()
{
    test[0]=new thread(&Raquette::Control_Raq,p1,b->x_b,x_ter);
}
void Terrain::play()
{
    b->collision_terrain(x_ter,y_ter);
    b->collision_raquette(*p1,*p2);
    p2->IA_Raquette(b->x_b,x_ter);
    b->Set_Pos_Balle();
    //p1->Control_Raq(b->x_b,x_ter);
    
}
/*
void Terrain::draw()
{   
    system("CLS");
    for (int y_i=0; y_i<=y_ter;y_i++) 
    {
        for (int x_i=0; x_i<=x_ter;x_i++) 
        {
            if(y_i==0 or x_i==0 or y_i==y_ter or x_i==x_ter) //Draw terrain
            {
                cout <<"#";
            }
            else 
            {
                if(x_i==b->x_b and y_i==b->y_b) //Draw Balle
                {
                    cout<<"O";
                }
                else
                {
                    
                    if(x_i==((p1->x_centre)-p1->taille_raq) and y_i==p1->y_centre)
                    {
                        
                        for(int i=0;i<(1+2*p1->taille_raq);i++)
                        {
                            cout<<"U";
                           
                        }
                        x_i=x_i+2*p1->taille_raq;
                    }
                    else if(x_i==(p2->x_centre)-p2->taille_raq and y_i==p2->y_centre)
                    {
                        for(int i=0;i<(1+2*p2->taille_raq);i++)
                        {
                            cout<<"U";
                            
                        }
                        x_i=x_i+2*p2->taille_raq;
                    }
                    else
                    {
                         cout<<" ";
                    }
                
                }
            }

        }

        cout <<endl;
    }
}

*/
    

void Terrain::draw()
{   
    system("CLS");
    char tab[y_ter][x_ter+2]={{0}};
    /*
    char tab[2][5] = { 
  {'5','2','3','4','\n'}, //Ne pas mettre de \0 car sinon le print prendre que le premier
  {'5','6','7','8','\n'}  
};*/

    int y_i=0;
    int x_i=0;
    for (y_i=0; y_i<=y_ter;y_i++) 
    {
        for (x_i=0; x_i<=x_ter+1;x_i++) 
        {
            tab[y_i][x_i]='0';
            //cout<<tab[y_i][x_i];
        }
    }
    for (y_i=0; y_i<=y_ter;y_i++) 
    {
        for (x_i=0; x_i<=x_ter;x_i++) 
        {
            if(y_i==0 or x_i==0 or y_i==y_ter or x_i==x_ter) //Draw terrain
            {
                tab[y_i][x_i]='#';
            }
            else 
            {
                if(x_i==b->x_b and y_i==b->y_b) //Draw Balle
                {
                    tab[y_i][x_i]='O';
                }
                else
                {
                    
                    if(x_i==((p1->x_centre)-p1->taille_raq) and y_i==p1->y_centre)
                    {
                        
                        for(int i=0;i<(1+2*p1->taille_raq);i++)
                        {
                            tab[y_i][x_i]='U';
                            x_i++;
                           
                        }
                        x_i--;//il faut counter le x_i++ de fin car sinon on va sauter un indice
                      
                    }
                    else if(x_i==(p2->x_centre)-p2->taille_raq and y_i==p2->y_centre)
                    {
                        for(int i=0;i<(1+2*p2->taille_raq);i++)
                        {
                            tab[y_i][x_i]='U';
                            x_i++;
                            
                        }
                        x_i--;
                        
                    }
                    else
                    {
                         tab[y_i][x_i]=' ';
                    }
                
                }
            }

        }

        tab[y_i][x_i]='\n';
    }
    /*
    for (y_i=0; y_i<=y_ter;y_i++) 
    {
        for (x_i=0; x_i<=x_ter+1;x_i++) 
        {
            //tab[y_i][x_i]='0';
            cout<<tab[y_i][x_i];
        }
    }*/
    
    cout<<tab[0];
}