#include<iostream>
#include <cstring>

using namespace std;
#include "Producto.h"

int Producto::getCodigoProducto(){
   return _codigoProducto;
}

const char *Producto::getDescripcionProducto(){
    return _descripcionProducto;
}

float Producto::getPrecioProducto(){
   return _precioProducto;
}

int Producto::getStockDisponible(){
    return _stockDisponible;
}

bool Producto::setCodigoProducto(int codigoProducto){
    if(codigoProducto<1) {
        _codigoProducto = -1;
        return false;
    }
    FILE *file = fopen("Productos.dat","rb");
    if(file==NULL) {
        _codigoProducto = codigoProducto;
        return true;
    } else {
        Producto aux;
        while (fread(&aux,sizeof (Producto),1,file)==1)
            if(aux.getCodigoProducto()==codigoProducto) {
                _codigoProducto = -1;
                return false;
            }
    }
   _codigoProducto = codigoProducto;
   return true;
}

void Producto::setDescripcionProducto(const char *descripcionProducto){
   strcpy(_descripcionProducto, descripcionProducto);
}

void Producto::setPrecioProducto (float precioProducto){
    _precioProducto = precioProducto;
}

void Producto::setStockDisponible(int stockDisponible){
    _stockDisponible = stockDisponible;
}

void Producto::agregarStock(int stockAgregado){
    _stockDisponible += stockAgregado;
}

bool Producto::guardarEnDisco(){
    FILE *pProducto;

    pProducto=fopen("Productos.dat", "ab");

    if(pProducto==NULL){

        return false;
    }

    fwrite(this,sizeof(Producto),1, pProducto);
    fclose(pProducto);
    return true;
}
///--------------------------------------------
bool Producto::leerDeDisco (int pos){
    FILE *pProducto;
    pProducto=fopen("Productos.dat", "rb");
    if(pProducto==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(pProducto,sizeof(Producto)*pos,SEEK_SET);
    bool ok=fread(this,sizeof(Producto),1, pProducto);
    fclose(pProducto);
    return ok;
}

bool Producto::actualizarEnDisco(int pos){

    FILE *pProducto;
    pProducto = fopen("Productos.dat", "rb+");
    if (pProducto == NULL){
        return false;
    }
    bool ok;
    fseek(pProducto, pos * sizeof(Producto), SEEK_SET);
    ok = fwrite(this, sizeof(Producto), 1, pProducto);
    fclose(pProducto);
    return ok;

}


