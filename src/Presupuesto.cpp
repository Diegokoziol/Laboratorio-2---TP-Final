#include<iostream>
#include <cstring>

using namespace std;
#include "Presupuesto.h"
#include "Fecha.h"
#include "ItemPresupuesto.h"
#include "Producto.h"


Presupuesto::Presupuesto(Fecha fecha, char *nombre, char *apellido, int DNI, int telefono){
    _fecha = fecha;
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    _DNI = DNI;
    _telefono = telefono;
}

int Presupuesto::getId(){
    return _id;
}
int Presupuesto::getDNI(){
    return _DNI;
}
const char *Presupuesto::getApellido(){
    return _apellido;
}
const char *Presupuesto::getNombre(){
    return _nombre;
}
int Presupuesto::getTelefono(){
    return _telefono;
}
Fecha Presupuesto::getFecha(){
    return _fecha;
}
void Presupuesto::setNombre(const char *nombre){
   strcpy(_nombre, nombre);
}
void Presupuesto::setApellido(const char *apellido){
    strcpy (_apellido, apellido);
}
void Presupuesto::setFecha(Fecha fecha){
    _fecha = fecha;
}
void Presupuesto::setDNI(const int DNI){
    _DNI = DNI;
}
void Presupuesto::setTelefono(const int telefono){
    _telefono = telefono;
}

bool Presupuesto::guardarEnDisco(){
    //Si el presupuesto se va a poder editar habría que validar si ya existe
    FILE *p;
    p = fopen("Presupuestos.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(Presupuesto), 1, p);
    fclose(p);
    return ok;
}
bool Presupuesto::leerDeDisco(){
    //Agregar parámetros para leer el indicado
    FILE *p;
    p = fopen("Presupuestos.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fread(this, sizeof(Presupuesto), 1, p);
    fclose(p);
    return ok;
}
//bool Presupuesto::CargarItems(){}



//------------------------------------------------------------------------------------------
//***************** Factura *********************

Factura::Factura(Presupuesto presupuesto) : Presupuesto(presupuesto){
}

int Factura::getId(){
    return _id;
}
float Factura::getMontoTotal(){
    return 0.0;
}
Fecha Factura::getFecha(){
    return _fecha;
}
const char *Factura::getApellido(){
    return _apellido;
}
const char *Factura::getNombre(){
    return _nombre;
}
int Factura::getDNI(){
    return _DNI;
}
int Factura::getTelefono(){
    return _telefono;
}
ItemFactura Factura::getItem(int pos) {
    return _itemFactura[pos];
}

bool Factura::guardarEnDisco(){
    FILE *p;
    p = fopen("Facturas.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(Factura), 1, p);
    fclose(p);
    return ok;
}
bool Factura::leerDeDisco(){
    //Agregar parámetros para leer el indicado
    FILE *p;
    p = fopen("Facturas.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fread(this, sizeof(Factura), 1, p);
    fclose(p);
    return ok;
}
