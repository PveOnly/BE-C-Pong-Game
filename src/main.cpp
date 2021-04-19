#include <iostream>
#include "Terrain.h"
#include "Raquette.h"
#include "Balle.h"
using namespace std;
#include <unistd.h>
int main() {
    
    Terrain Ter(2*10,2*20);
    Ter.init();
    while(1)
    {
        Ter.play();
        Ter.draw();
        usleep(1000);
    }
    
    
    return 0;
}