#include<iostream>
#include "Helpers/RegCompraProducto.h"
#include "Producto.h"
#include "Gasto.h"

using namespace std;

int buscarCodigoProd (int codigoProducto){
    Producto reg;

    int pos=0;
    while (reg.leerDeDisco(pos)==true){
        if(reg.getCodigoProducto()==codigoProducto){
            return pos;
        }
        pos++;
    }
    return -1;
}
bool agregarProducto(){

    int cpb; // codigo producto buscado
    int stkP; // stock producto
    float precio;
    int pos;
    cout<<"INGRESE CODIGO DE PRODUCTO A CARGAR STOCK: " ;
    cin>>cpb;
    cout << endl;

    pos = buscarCodigoProd(cpb);
    if (pos >= 0){
        Producto agregar;
        agregar.leerDeDisco(pos);

        cout << "STOCK ACTUAL:  "<<agregar.getStockDisponible()<< endl<<endl;
        cout<<"INGRESE UNIDADES COMPRADAS: " ;
        cin>>stkP;
        cout<<"INGRESE PRECIO DE CADA UNIDAD: " ;
        cin>>precio;
        cout<<endl;

        agregar.agregarStock(stkP);

        string descripcionGasto = to_string(agregar.getCodigoProducto());
        descripcionGasto += " - ";
        descripcionGasto+= agregar.getDescripcionProducto();
        Gasto gastoPorStock(precio, descripcionGasto.c_str(), stkP);

        if(agregar.actualizarEnDisco(pos)){
            if(gastoPorStock.guardarEnDisco()){
                cout<<" NUEVO STOCK: "<<agregar.getStockDisponible()<< endl<<endl;
                return true;
            }else{
                //Revertir stock agregado si falla el guardado del gasto
                agregar.agregarStock(stkP*-1);
                agregar.guardarEnDisco();
            }
        }
    }
    return false;
}








