#include<iostream>
#include <ctime>
#include <cstring>


using namespace std;
#include "Fecha.h"

Fecha::Fecha(){
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon+1;
    _anio = f->tm_year+1900;
}

Fecha::Fecha(int dia, int mes, int anio){

    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}
string Fecha::getStrFecha(){
    string strFecha;
    strFecha += to_string(_dia)+'/';
    strFecha += to_string(_mes)+'/';
    strFecha += to_string(_anio%100);
    return strFecha;
}
