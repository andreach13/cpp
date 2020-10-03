#include <iostream>
#include "startShip.h"
#include "snake.h"
#include "ahorcado.h"

using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    int opcion = 0;

    while (true)
    {           
        system("cls");
        cout << "*********************"<< endl;
        cout << "MENU PRINCIPAL DE JUEGOS" << endl;
        cout << "*********************"<< endl;

        cout << "Seleccione un juego:" << endl << endl;

        cout << "1 - StarShip" << endl << endl;
        cout << "2 - Snake" << endl << endl;
        cout << "3 - Ahorcado" << endl << endl;
        cout << "4 - Salir del menu de juegos" << endl << endl;

        cout << "Ingrese un numero del menu para seleccionar un juego --> ";
        cin >> opcion;

      
        switch (opcion)
        {
            case 1:
            {
                system("cls");
                starShip();
                break;
            }    
            case 2:
            {
                system("cls");
                snake();
                break;
            }    
            case 3:
            {
                system("cls");
                Ahorcado();
                break;
            }
            default:
                break;
        }
        
        break;
    }

    return 0;
}
