#include<iostream>
#include "rlutil.h"
#include "PantallaPrincipal.h"
#include "Helpers/CargarProductos.h"
#include "Helpers/CargarGasto.h"
#include "Helpers/ModificarPrecio.h"
#include "Helpers/RegCompraProducto.h"

using namespace std;
using namespace rlutil;

void SubMenuPresupuesto();
void SubMenuFactura();
void SubMenuStock();
void SubmenuGasto();
void SubMenuBalance();


void PantallaPrincipal(){
    cls();
    cout << endl << endl;
    cout << "   #######  #### ########  ########   #######   ######## #### ##     ##                   " << endl;
    cout << "   ##        ##  ##     ## ##     ## ##     ##  ##        ##   ##   ##                   " << endl;
    cout << "   ##        ##  ##     ## ##     ## ##     ##  ##        ##    ## ##                    " << endl;
    cout << "   ######    ##  ########  ########  ##     ##  ######    ##     ###                     " << endl;
    cout << "   ##        ##  ##     ## ##   ##   ##     ##  ##        ##    ## ##                    " << endl;
    cout << "   ##        ##  ##     ## ##    ##  ##     ##  ##        ##   ##   ##                   " << endl;
    cout << "   ##       #### ########  ##     ##  #######   ##       #### ##     ##                  " << endl<<endl<<endl;
    cout << "                                                                TU SOLUCIÓN ANTIHUMEDAD " << endl;

    cout << endl << endl<< endl<< endl;
    cout<<"                                     PARA INICIAR PRESIONE UNA TECLA CUALQUIERA"<<endl;
    anykey();
    cls();

}

void MenuPrincipal(){
    cls();
    int opcion;
        do{
        cout<<endl;
        cout <<"                        MENU PRINCIPAL" <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl;
        cout <<"            1 - PRESUPUESTO" << endl;
        cout <<"            2 - FACTURAS" << endl;
        cout <<"            3 - STOCK DE PRODUCTOS" << endl;
        cout <<"            4 - GASTOS" << endl;
        cout <<"            5 - BALANCES" << endl;
        cout <<"------------------------------------------------------------------ "<< endl;
        cout <<"            0 - SALIR." << endl;
        cout << endl << endl << "OPCIÓN: ";
        cin >> opcion;

        cls();
        switch(opcion){
                case 0:
                    cout <<endl << endl<< endl;
                    cout << "GRACIAS POR ELEGIRNOS" << endl;
                    cout <<endl << endl<< endl;
                    anykey();
                    break;
                case 1:
                    SubMenuPresupuesto();
                    cls();
                    break;
                case 2:
                    SubMenuFactura();
                    cls();
                    break;
                case 3:
                    SubMenuStock();
                    cls();
                    break;
                case 4:
                    SubmenuGasto();
                    cls();
                    break;
                case 5:
                    SubMenuBalance();
                    cls();
                    break;
                    default:
                        cout <<endl << endl<< " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                        cout <<endl << endl<< endl;
                    break;

            }
  }
   while (opcion!=0);
}

void SubMenuPresupuesto(){
    int opcion;
    cls();
    do{
        cout <<endl;
        cout <<"                        PRESUPUESTO " <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            1 - REALIZAR NUEVO PRESUPUESTO" << endl<< endl;
        cout <<"            2 - VER PRESUPUESTOS REALIZADOS" << endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            0 - VOLVER AL MENU PRINCIPAL." << endl;
        cout << endl << endl << "OPCIÓN: ";
        cin >> opcion;

        cls();
        switch(opcion){
                case 0:
                    break;
                case 1:
                    cout <<"REALIZAR NUEVO PRESUPUESTO"<<endl;
                    anykey();
                    cls();
                    break;

                    case 2:
                        cout <<"VER PRESUPUESTOS REALIZADOS"<<endl;
                        anykey();
                        cls();
                    break;
                    default:
                        cout <<endl << endl<< " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                        cout <<endl << endl<< endl;
                    break;

            }
  }
   while (opcion!=0);


}
void SubMenuFactura(){
    int opcion;
    cls();
    do{
        cout <<endl;
        cout <<"                        FACTURA " <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            1 - REALIZAR NUEVA FACTURA" << endl<< endl;
        cout <<"            2 - VER FACTURAS EMITIDAS" << endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            0 - VOLVER AL MENU PRINCIPAL." << endl;
        cout << endl << endl << "OPCIÓN: ";
        cin >> opcion;

        cls();
        switch(opcion){
                case 0:
                    break;
                case 1:
                    cout <<"REALIZAR NUEVA FACTURA"<<endl;
                    anykey();
                    cls();
                    break;

                    case 2:
                        cout <<"VER FACTURAS EMITIDAS"<<endl;
                        anykey();
                        cls();
                    break;
                    default:
                        cout <<endl << endl<< " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                        cout <<endl << endl<< endl;
                    break;

            }
  }
   while (opcion!=0);
}

void SubMenuStock(){
    int opcion;
    cls();
    do{
        cout <<endl;
        cout <<"                        STOCK DE PRODUCTOS " <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            1 - CARGAR NUEVO PRODUCTO" << endl<< endl;
        cout <<"            2 - ACTUALIZAR PRECIO PRODUCTO" << endl<<endl;
        cout <<"            3 - REGISTRAR COMPRA DE PRODUCTO" << endl<<endl;
        cout <<"            4 - VER STOCK" << endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            0 - VOLVER AL MENU PRINCIPAL." << endl;
        cout << endl << endl << "OPCIÓN: ";
        cin >> opcion;

        cls();
        switch(opcion){
                case 0:
                    break;
                case 1:
                    cout <<"CARGAR NUEVO PRODUCTO"<<endl;
                    AgregarProducto();
                    cls();
                    break;

                    case 2:
                    cout <<"ACTUALIZAR PRECIO PRODUCTO"<<endl;
                    if(ModifPrecio()==true){
                        cout<<endl<<endl;
                        cout<<"PRECIO ACTUALIZADO";
                    }else{cout<<"PRECIO NO ACTUALIZADO";}
                    anykey();
                    cls();
                    break;
                    case 3:
                        cout <<"REGISTRAR COMPRA DE PRODUCTO"<<endl;
                        if(agregarProducto()==true){
                            cout<<endl<<endl;
                            cout<<"SE HA AGREGADO STOCK";
                        }else{cout<<"NO SE PUDO AGREGAR STOCK";}

                        anykey();
                        cls();
                    break;
                    case 4:
                        cout <<endl<<"     **********   STOCK    DISPONIBLE   **********   "<<endl<<endl;;
                        mostrarStock();
                        anykey();
                        cls();
                    break;
                    default:
                        cout <<endl << endl<< " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                        cout <<endl << endl<< endl;
                    break;

            }
  }
   while (opcion!=0);
}

void SubmenuGasto(){
    int opcion;
    cls();

    do{
        cout <<endl;
        cout <<"                        GASTOS " <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            1 - CARGAR NUEVO GASTO" << endl<< endl;
        cout <<"            2 - VER GASTO REALIZADO" << endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            0 - VOLVER AL MENU PRINCIPAL." << endl;
        cout << endl << endl << "OPCIÓN: ";
        cin >> opcion;

        cls();
        switch(opcion){
                case 0:
                    break;
                case 1:
                    cout <<"CARGAR NUEVO GASTO"<<endl;
                    AgregarGasto();
                    cls();
                    break;

                    case 2:
                        cout <<"VER GASTO REALIZADO"<<endl;
                        mostrarGasto();
                        cls();
                    break;
                    default:
                        cout <<endl << endl<< " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                        cout <<endl << endl<< endl;
                    break;

            }
  }
   while (opcion!=0);
}
void SubMenuBalance(){
    int opcion;
    cls();

        do{
        cout <<endl;
        cout <<"                        BALANCES " <<endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            1 - BALANCE ACTUAL" << endl<< endl;
        cout <<"            2 - BALANCE MENSUAL" << endl<<endl;
        cout <<"------------------------------------------------------------------ "<< endl<< endl;
        cout <<"            0 - VOLVER AL MENU PRINCIPAL." << endl;
        cout << endl << endl << "OPCIÓN: ";
        cin >> opcion;

        cls();
        switch(opcion){
                case 0:
                    break;
                case 1:
                    cout <<"BALANCE ACTUAL"<<endl;
                    anykey();
                    cls();
                    break;

                    case 2:
                        cout <<"BALANCE MENSUAL"<<endl;
                        anykey();
                        cls();
                    break;
                    default:
                        cout <<endl << endl<< " ********  OPCIÓN    INCORRECTA  ******** " << endl;
                        cout <<endl << endl<< endl;
                    break;

            }
  }
   while (opcion!=0);
}
