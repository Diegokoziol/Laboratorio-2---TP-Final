#include<iostream>
#include <cstring>
using namespace std;
#include "Gasto.h"
#include "Fecha.h"

Gasto::Gasto(){

}

Gasto::Gasto(float pu, const char* dg, int un){
    FILE *file = fopen("Gastos.dat","rb");

    if(file==NULL){
        if((errc)errno==errc::no_such_file_or_directory){
            _id=1;
        }
    }else{
        int idAux=0;
        Gasto aux;
        while(fread(&aux, sizeof(Gasto), 1, file)){
            if(aux.getId()>idAux)
                idAux=aux.getId();
        }
        fclose(file);

        idAux++;
        _id=idAux;
    }

    _montoUnitario=pu;
    strcpy(_descripcionGasto, dg);
    _unidades=un;
}


int Gasto::getId(){
    return _id;
}

Fecha Gasto::getFecha(){
    return _fecha;
}
float Gasto::getMontoUnitario(){
    return _montoUnitario;
}
float Gasto::getMontoTotal(){
    return _unidades * _montoUnitario;
}

int Gasto::getUnidades(){
    return _unidades;
}

const char *Gasto::getDescripcionGasto(){
    return _descripcionGasto;
}

void Gasto::setId (int id){
    _id = id;
}

void Gasto::setDescripcionGasto(const char *descripcionGasto){
    strcpy(_descripcionGasto,descripcionGasto);
}

void Gasto::setFecha(Fecha fecha){
    _fecha = fecha;
}

void Gasto::setUnidades(int unidades){
    _unidades = unidades;
}
void Gasto::setMontoUnitario(float montoUnitario){
    _montoUnitario = montoUnitario;
}

bool Gasto::guardarEnDisco(){
    FILE *pGasto;
    pGasto = fopen("Gastos.dat", "ab");
    if (pGasto == NULL){
        return false;
    }
    fwrite(this, sizeof(Gasto), 1, pGasto);
    fclose(pGasto);
    return true;
}
bool Gasto::leerDeDisco(){
    FILE *p;
    p = fopen("Gastos.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fread(this, sizeof(Gasto), 1, p);
    fclose(p);
    return ok;
}
