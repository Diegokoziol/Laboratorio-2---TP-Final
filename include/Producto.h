#ifndef PRODUCTO_H
#define PRODUCTO_H


class Producto
{
    private:
        int _codigoProducto;
        char _descripcionProducto[30];
        float _precioProducto;
        int _stockDisponible;

    public:
        int getCodigoProducto();
        const char *getDescripcionProducto();
        float getPrecioProducto();
        int getStockDisponible();
        bool setCodigoProducto(int);
        void setDescripcionProducto(const char *);
        void setPrecioProducto(float);
        void setStockDisponible(int);
        void agregarStock(int);
        bool guardarEnDisco();
        bool leerDeDisco(int pos);//agregado for prueba
        bool actualizarEnDisco(int pos);//agregado for prueba
};

#endif // PRODUCTO_H
