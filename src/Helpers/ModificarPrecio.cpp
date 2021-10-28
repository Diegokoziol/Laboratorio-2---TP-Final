#include<iostream>
#include "Helpers/ModificarPrecio.h"
#include "Producto.h"
using namespace std;

int buscarCodigoProducto (int codigoProducto){
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


bool  ModifPrecio(){

    int cpb; // codigo producto buscado
    int mpb; // modifica precio buscado
    int pos;
    cout<<"INGRESE CODIGO DE PRODUCTO A MODIFICAR: " ;
    cin>>cpb;
    pos = buscarCodigoProducto(cpb);
    if (pos >= 0){
        Producto mod;
        mod.leerDeDisco(pos);
        cout << endl;
        cout << "PRECIO A MODIFICAR:  $"<<mod.getPrecioProducto()<< endl<<endl;
        cout<<"INGRESE NUEVO PRECIO DEL PRODUCTO: $" ;
        cin>>mpb;
        mod.setPrecioProducto(mpb);
        mod.actualizarEnDisco(pos);//<---------------
        return true;
    }
    return false;
}
