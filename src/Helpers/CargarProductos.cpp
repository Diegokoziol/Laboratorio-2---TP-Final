#include<iostream>
#include <cstring>
#include <iomanip>

#include"Helpers/CargarProductos.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;


Producto CargarProducto(){ // funcion que devuelve un producto
    Producto nuevoProducto;
    int cp;
    float pp;
    char dp[30];
    bool codigoValido;

    cout<<"INGRESE CODIGO DEL PRODUCTO: "<<endl;
    cin>>cp;
    codigoValido = nuevoProducto.setCodigoProducto(cp);
    cout<<endl;

    while (!codigoValido){
        cout<<"CODIGO INVALIDO O REPETIDO, INGRESE OTRO CODIGO O (-1) PARA CANCELAR "<<endl;
        cin>>cp;
        codigoValido = nuevoProducto.setCodigoProducto(cp);
        if(cp==-1){return nuevoProducto;}
    }

    cout<<"INGRESE DESCRIPCIÓN DEL PRODUCTO: "<<endl;
    cin.ignore();
    cin.getline(dp,30);
    nuevoProducto.setDescripcionProducto(dp);

    cout<<endl;
    cout<<"INGRESE PRECIO DEL PRODUCTO: $"<<endl;
    cin>>pp;
    nuevoProducto.setPrecioProducto(pp);

    nuevoProducto.setStockDisponible(0);
    return nuevoProducto;
}

void AgregarProducto(){
    Producto reg = CargarProducto();
    if(reg.getCodigoProducto()==-1){return;}
    if(reg.guardarEnDisco()){
        cout <<"PRODUCTO AGREGADO";
    }
    else{
    cout <<"ERROR AL GRABAR";
    }
    cout<<endl;
    anykey();
}


void mostrarStock(){
    setlocale(LC_ALL, "spanish");
    cout << left;
    cout<<"______________________________________________________________________"<<endl;
    cout << setw(10) << "CÓDIGO";
    cout << setw(31) << "DESCRIPCIÓN";
    cout << setw(10) << "PRECIO";
    cout << setw(20) << "STOCK DISPONIBLE" << endl;
    cout<<"______________________________________________________________________"<<endl;
    cout<<endl;




    FILE *file;
    Producto obj;
    file=fopen("Productos.dat", "rb");

    if(file==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;

        return;
    }
    while (fread(&obj,sizeof (obj),1,file)==1){

        cout << left;
        cout<<setw(10)<<obj.getCodigoProducto();
        cout<<setw(31)<<obj.getDescripcionProducto();
        cout<<"$"<< fixed << setprecision(2)<<setw(10)<<obj.getPrecioProducto();
        cout<<setw(4)<<obj.getStockDisponible()<<endl;
        cout<<"---------------------------------------------------------------------"<<endl;

    }

}




