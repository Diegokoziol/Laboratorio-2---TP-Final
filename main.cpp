#include <iostream>
#include "rlutil.h"
#include "PantallaPrincipal.h"
using namespace std;
using namespace rlutil;

int main()
{
    setlocale(LC_ALL, "spanish");
    setColor(WHITE);
    setBackgroundColor(BLUE);
    PantallaPrincipal();
    MenuPrincipal();
    return 0;
}
