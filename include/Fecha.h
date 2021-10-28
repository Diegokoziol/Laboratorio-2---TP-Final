#ifndef FECHA_H
#define FECHA_H

#include <cstring>

class Fecha
{
    private:
        int _dia;
        int _mes;
        int _anio;

    public:
        Fecha();
        Fecha(int,int,int);
        int getDia();
        int getMes();
        int getAnio();
        std::string getStrFecha();
};











#endif // FECHA_H
