#ifndef ITEMPRESUPUESTO_H
#define ITEMPRESUPUESTO_H


class ItemPresupuesto
{
    private:
        int _id;
        int _idPresupuesto;
    protected:
        int _codigoProducto;
        int _cantidad;
    public:
        ItemPresupuesto(int codigoProducto, int cantidad);
        int getId();
        int getIdPresupuesto();
        int getCodigoProducto();
        int getCantidad();
        void setId(const int);
        void setIdPresupuesto(const int);
        bool leerDeDisco();//Agregar parámetros para leer el indicado
        bool guardarEnDisco();

};

class ItemFactura  : ItemPresupuesto //Lo había pensado como que heredaba ItemPresupuesto en modo private, no public
{
    private:
        int _id;
        int _idFactura;
        float _precioProducto();

    public:
        ItemFactura(ItemPresupuesto, int);
        int getId();
        int getIdFactura();
        int getCodigoProducto();
        int getCantidad();
        int getPrecio();
        bool leerDeDisco();//Agregar parámetros para leer el indicado
        bool guardarEnDisco();


};

#endif // ITEMPRESUPUESTO_H
