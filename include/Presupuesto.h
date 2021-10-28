#ifndef PRESUPUESTO_H
#define PRESUPUESTO_H
#include"Fecha.h"
#include "ItemPresupuesto.h"
#include "Producto.h"


class Presupuesto
{
    private:
        int _id;
        int _cantidadItems;
        ItemPresupuesto *_itemPresupuesto; //Cambiar por Vector<itemPresupuesto>

    protected:
        Fecha _fecha;
        char _nombre[30];
        char _apellido[30];
        int _DNI;
        int _telefono;

    public:
        Presupuesto(Fecha fecha ,char *nombre, char *apellido, int DNI, int _telefono);
        void generarFactura();
        bool leerDeDisco(); //Agregar parámetros para leer el indicado
        bool guardarEnDisco();
        bool cargarItems();
        int getId();
        bool agregarItem(ItemPresupuesto itemPresupuesto);
        Fecha getFecha();
        const char *getNombre();
        const char *getApellido();
        int getDNI();
        int getTelefono();
        void setFecha (Fecha fecha);
        void setNombre (const char *nombre);
        void setApellido (const char *apellido);
        void setDNI (const int);
        void setTelefono(const int);


};

class Factura : Presupuesto //Lo había pensado como que heredaba ItemPresupuesto en modo private, no public
{
    private:
        int _id;
        ItemFactura *_itemFactura;
    public:
        Factura(Presupuesto presupuesto);
        int getId();
        float getMontoTotal();
        Fecha getFecha();
        const char *getNombre();
        const char *getApellido();
        int getDNI();
        int getTelefono();
        ItemFactura getItem(int pos);
        bool leerDeDisco(); //Agregar parámetros para leer el indicado
        bool guardarEnDisco();

};

#endif // PRESUPUESTO_H
