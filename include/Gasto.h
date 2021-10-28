#ifndef GASTO_H
#define GASTO_H
#include"fecha.h"

class Gasto
{
    private:
        int _id;
        float _montoUnitario;
        char _descripcionGasto[40];
        int _unidades;
        Fecha _fecha;//composicion
    public:
        Gasto();
        Gasto(float, const char*, int);
        int getId();
        float getMontoUnitario();
        const char *getDescripcionGasto();
        int getUnidades();
        float getMontoTotal();
        Fecha getFecha();//composicion
        void setId(int);
        void setDescripcionGasto(const char *DescripcionGasto);
        void setFecha(Fecha fecha);
        void setUnidades(int);
        void setMontoUnitario(float);
        bool leerDeDisco();
        bool guardarEnDisco();
};

#endif // GASTO_H
