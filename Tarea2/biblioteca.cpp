#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

string libros [10][3];

void cargarLibros(){
    libros[0][0] = "Algoritmos"; libros[0][1] = "Algoritmos y Programacion (Guia para docentes)"; libros[0][2] = " - Juan Garcia";
	libros[1][0] = "Algoritmos"; libros[1][1] = "Estructuras de Datos Avanzada"; libros[1][2] = " - Peter Brass";
	libros[2][0] = "Algoritmos"; libros[2][1] = "Introduccion a Algoritmos"; libros[2][2] = " - Thomas H. Cormen";
	libros[3][0] = "Algoritmos"; libros[3][1] = "El Arte de la Programacion Informatica (Vol 1-4)"; libros[3][2] = " - Donald E. Knuth";
	libros[4][0] = "Algoritmos"; libros[4][1] = "El Manual de Disenio de Algortimos"; libros[4][2] = " - Steve S. Skiena";
	libros[5][0] = "Algoritmos"; libros[5][1] = "Estructura de Datos y Algoritmos"; libros[5][2] = " - Aho, Ullmany Hopcroft";
	libros[6][0] = "Base de Datos"; libros[6][1] = "Fundamentos de Base de Datos"; libros[6][2] = " - Abraham Silberschatz";
	libros[7][0] = "Base de Datos"; libros[7][1] = "Disenio de Base de Datos"; libros[7][2] = " - Rod Stephens";
	libros[8][0] = "Base de Datos"; libros[8][1] = "SQL Server 2008: Aprenda a Administrar una Base de Datos"; libros[8][2] = " - Gerome Gabillaud";
	libros[9][0] = "Programacion"; libros[9][1] = "Programacion con Visual Basic 2008"; libros[9][2] = " - Tim Patrick";
}

int main(int argc, char const *argv[])
{ 

    int opcion = 0;

    while(true)
    {
        system("cls");
        cout << "Bienvenido a Biblioteca Virtual"<< endl;
        cout << "*********************************" << endl;

        cout << "Opcion 1: Buscar libro por nombre" << endl;
        cout << "Opcion 2: Buscar libro por nombre de autor" << endl;
        cout << "Opcion 3: Salir" << endl;

        cout << "Ingrese una opcion de busqueda: ";
        cin >> opcion;

        if (opcion == 1)
        {
            
            cargarLibros();

            srand (time(NULL));

            bool salir = false;
                    
            while (salir == false)
            {
                
                string buscar = "";
                system("cls");
                cout << "Ingrese la descripcion del libro que busca: ";
                cin >> buscar;
                cout << endl;

                for (int i = 0; i < 10; i++)
                {
                    
                    string libro = libros[i][1];
                    string libroEnminuscula = libro;
                    transform(libroEnminuscula.begin(), libroEnminuscula.end(), libroEnminuscula.begin(), ::tolower);
                    transform(buscar.begin(), buscar.end(), buscar.begin(), ::tolower);
                            
                    if (libroEnminuscula.find(buscar) != string::npos)
                    {
                        
                        cout << "Libro encontrado: " << libro << endl;
                        cout << endl;

                        cout << "Tambien te sugerimos estos libros: " << endl;
                        cout << endl;

                        int sugerencia1 = rand() % 9 + 1;
                        int sugerencia2 = rand() % 9 + 1;
                        int sugerencia3 = rand() % 9 + 1;
                                

                        cout << "Sugerencia 1) " << libros[sugerencia1][1] << endl;
                        cout << "Sugerencia 2) " << libros[sugerencia2][1] << endl;
                        cout << "Sugerencia 3) " << libros[sugerencia3][1] << endl;
                        
                        system("pause");
                        salir = true;
                        break;

                        
                    }
                            
                }
                        
                    if (salir == false)
                    {
                        char continuar = 'n';
                         while (true)
                        {
                            system("cls");
                            cout << "No se encontro lo que busca. Desea continuar? s/n: ";
                            cin >> continuar;

                            if (continuar == 's' || continuar == 'S')
                            {
                                break;
                            }
                            else
                            {
                                if (continuar == 'n' || continuar == 'N')
                                {
                                    salir = true;
                                    break;
                                }
                            }                           
                        } 
                    }    
            }
        }

        if (opcion == 2)
        {
            cargarLibros();

            srand (time(NULL));

            bool salir = false;
                    
            while (salir == false)
            {
                
                string buscar = "";
                system("cls");
                cout << "Ingrese el nombre del autor que desea encontrar: ";
                cin >> buscar;
                cout << endl;

                for (int i = 0; i < 10; i++)
                {
                    string libro = libros[i][1];
                    string autor = libros[i][2];
                    string autorEnminuscula = autor;
                    transform(autorEnminuscula.begin(), autorEnminuscula.end(), autorEnminuscula.begin(), ::tolower);
                    transform(buscar.begin(), buscar.end(), buscar.begin(), ::tolower);
                            
                    if (autorEnminuscula.find(buscar) != string::npos)
                    {
                        
                        cout << "Autor encontrado: " << libro << " " << libros [i][2] << endl;
                        cout << endl;

                        cout << "Tambien te sugerimos libros de estos autores: " << endl;
                        cout << endl;

                        int sugerencia1 = rand() % 9 + 1;
                        int sugerencia2 = rand() % 9 + 1;
                        int sugerencia3 = rand() % 9 + 1;
                                

                        cout << "Sugerencia 1) " << libros[sugerencia1][1] << " " << libros[sugerencia1][2] << endl;
                        cout << "Sugerencia 2) " << libros[sugerencia2][1] << " " << libros[sugerencia2][2] << endl;
                        cout << "Sugerencia 3) " << libros[sugerencia3][1] << " " << libros[sugerencia3][2] << endl;
                        
                        system("pause");
                        salir = true;
                        break;
                        
                    }
                           
                }
                        
                    if (salir == false)
                    {
                        char continuar = 'n';
                         while (true)
                        {
                            system("cls");
                            cout << "No se encontro lo que busca. Desea continuar? s/n: ";
                            cin >> continuar;

                            if (continuar == 's' || continuar == 'S')
                            {
                                break;
                            }
                            else
                            {
                                if (continuar == 'n' || continuar == 'N')
                                {
                                    salir = true;
                                    break;
                                }                                    
                            }                                        
                        }
                    }                        
            }
        }
        
        if (opcion == 3)
        {
            break;
        }
        
    }
    
    return 0;
}

