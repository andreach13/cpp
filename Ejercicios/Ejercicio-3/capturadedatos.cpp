#include <iostream>

using namespace std;

string alumnos[5][2];

void cargarDatos(){
    alumnos[0][0] = "Juan";
    alumnos[1][0] = "Pedro";
    alumnos[2][0] = "Pablo";
    alumnos[3][0] = "Maria";
    alumnos[4][0] = "Jose";
}

int main(int argc, char const *argv[])
{
    system("cls");
    //cargarDatos();

    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese el nombre del alumno " << i + 1 << ":";
        cin >> alumnos[i][0];
        cout << "Ingrese el apellido del alumno " << i + 1 << ":";
        cin >> alumnos[i][1];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << alumnos[i][0] << " " << alumnos[i][1] << endl;
    }
    
    return 0;
}
