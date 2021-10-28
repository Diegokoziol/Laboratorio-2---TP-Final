#include <iostream>
#include <cstring>
#include <iomanip>
#include "Helpers/CargarGasto.h"
#include "rlutil.h"
#include "Gasto.h"

using namespace std;
using namespace rlutil;


void AgregarGasto(){
    Gasto reg = CargarGasto();

    bool reintentar = true;
    while(reintentar){
        reintentar = GuardarGasto(reg);
    }

    anykey();
}

bool GuardarGasto(Gasto &reg){
    if (reg.guardarEnDisco()){
        cout <<"GASTO GRABADO";
    }
    else {
        cout <<"ERROR AL GRABAR"<< endl;
        cout << "Reintentar? [S/N]" << endl;
        char opc;
        cin >> opc;
        if(opc=='S')
            return true;
    }
    return false;
}

Gasto CargarGasto(){
    char dg[40];
    float mu;
    int un;

    cout<<"INGRESE DESCRIPCIÓN DEL GASTO: "<<endl;
    cin.ignore();
    cin.getline(dg,35);

    cout<<"INGRESE PRECIO DEL GASTO: "<<endl;
    cin>>mu;

    cout<<"INGRESE CANTIDAD DE UNIDADES: "<<endl;
    cin>>un;

    Gasto nuevoGasto(mu, dg, un);
    return nuevoGasto;

}

void mostrarGasto(){
    cout << left;
    cout<<"_______________________________________________________________________________"<<endl;
    cout << setw(5) << "ID";
    cout << setw(10) << "FECHA";
    cout << setw(31) << "DESCRIPCIÓN";
    cout << setw(10) << "PRECIO";
    cout << setw(10) << "UNIDADES" ;
    cout << setw(20) << "PRECIO TOTAL" <<endl;
    cout<<"_______________________________________________________________________________"<<endl;
    cout<<endl;

    FILE *file;
    Gasto obj;
    file=fopen("Gastos.dat", "rb");

    if(file==NULL){

        cout<<endl<<endl;
        cout<<"ERROR DE ARCHIVO"<<endl;

        anykey();

        return;

    }
    while (fread(&obj,sizeof (obj),1,file)==1){
        cout << left;
        cout<<setw(5)<<obj.getId();
        cout<<setw(10)<<obj.getFecha().getStrFecha();
        cout<<setw(31)<<obj.getDescripcionGasto();
        cout<<"$"<< fixed << setprecision(2)<<setw(10)<<obj.getMontoUnitario();
        cout<<setw(10)<<obj.getUnidades();
        cout<<"$"<< fixed << setprecision(2)<<setw(10)<<obj.getMontoTotal()<<endl;
        cout<<"-----------------------------------------------------------------------------"<<endl;
    }

    anykey();
}






