#include<iostream>
#include <cstring>

using namespace std;
#include "ItemPresupuesto.h"
//***************** ItemPresupuesto *********************

ItemPresupuesto::ItemPresupuesto(int codigoProducto, int cantidad){
    _codigoProducto = codigoProducto;
    _cantidad = cantidad;
}

int ItemPresupuesto::getId(){
    return _id;
}

int ItemPresupuesto::getIdPresupuesto(){
    return _idPresupuesto;
}
int ItemPresupuesto::getCodigoProducto(){
    return _codigoProducto;
}

int ItemPresupuesto::getCantidad(){
    return _cantidad;
}

void ItemPresupuesto::setId(const int id){
    _id = id;
}
void ItemPresupuesto::setIdPresupuesto(const int idPresupuesto){
    _idPresupuesto = idPresupuesto;
}

bool ItemPresupuesto::guardarEnDisco(){
    //Si el presupuesto se va a poder editar habría que validar si ya existe
    FILE *p;
    p = fopen("ItemsPresupuestos.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(ItemPresupuesto), 1, p);
    fclose(p);
    return ok;
}
bool ItemPresupuesto::leerDeDisco(){ //Agregar parámetros para leer el indicado
    FILE *p;
    p = fopen("ItemsPresupuestos.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fread(this, sizeof(ItemPresupuesto), 1, p);
    fclose(p);
    return ok;
}

//------------------------------------------------------------------------------------------
//***************** ItemFactura *********************

ItemFactura::ItemFactura(ItemPresupuesto itemPresupuesto, int idFactura) : ItemPresupuesto(itemPresupuesto){
    _idFactura = idFactura;
}

int ItemFactura::getId(){
    return _id;
}

int ItemFactura::getIdFactura(){
    return _idFactura;
}

int ItemFactura::getCodigoProducto(){
    return _codigoProducto;
}

int ItemFactura::getCantidad(){
    return _cantidad;
}

bool ItemFactura::guardarEnDisco(){
    FILE *p;
    p = fopen("ItemsFacturas.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(ItemFactura), 1, p);
    fclose(p);
    return ok;
}
bool ItemFactura::leerDeDisco(){ //Agregar parámetros para leer el indicado
    FILE *p;
    p = fopen("ItemsFacturas.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fread(this, sizeof(ItemFactura), 1, p);
    fclose(p);
    return ok;
}
