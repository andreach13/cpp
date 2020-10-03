//
//  main.cpp
//  HelloWorld
//
//  Created by nicoli on 6/10/2562 BE.
//  Copyright © 2562 BE Irving Nicoli. All rights reserved.
//

// Esta es una prueba de GitHub
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <random>
#include <math.h>

using namespace std;

bool
compara_palabra(vector <char> vec_carac, string palabra);

bool
Exe_Game
(
 string&         palabra,
 vector<char>&   letras_usadas,
 vector<char>&   letras_en_palabra
 );

void
Init_Game
(
vector<char>&   letras_usadas,
vector<char>&   letras_en_palabra,
string&         palabra
);

void
PrintVector(vector<char> vec);

bool
compara_letra
(
char            letra,
vector<char>    letras_usadas
);

bool
comparacion
(
 string             palabra,
 vector<char> &     letras_usadas,
 vector<char>&      letras_en_palabra,
 char               letra
);

/**
 * Hace un random donde elije una palabra del vector palabras, limpia los vectores, sustituye las letras en palabras por guiones y la imprime.
 *
 * @param [Referencia] el vector de letras que el usuario ingresa.
 * @param [Referencia] el vector que guarda las letras que hay en la palabra que se eligio de manera aleatoria
 * @param [Referencia] Donde se guarda la palabra aleatoria.
 *
 */

void
Init_Game(vector<char>& letras_usadas, vector<char>& letras_en_palabra, string& palabra)
{
    vector<string>  palabras =
    {
        "lapicero", "mariposa", "sobrino", "dinosaurio", "tostadora",
        "iguana", "tortugas", "computadora", "elevador", "estudiante",
        "carretera", "tocadiscos", "hoteles", "jaguar", "colegio", "ecosistema",
        "sobredosis", "amanecer", "bicicleta", "moto", "telefono", "postura", "ave","xilofono"
    };
    
    // Obtener el Id de la palabra random.
    
    srand(time(0));
    int id_palabra = rand() % palabras.size();
    palabra = palabras[id_palabra];
    
    // borrar contenido de los vectors
    letras_usadas.clear();
    letras_en_palabra.clear();
    
    for (int i=0; i < palabra.size(); i++)
    {
        letras_en_palabra.push_back('-');
    }
    
    // Mensaje de Bienvenida.
    system("cls");
    cout << ("*********************************\n");
    cout << ("Bienvenido al Juego del ahorcado.\n");
    cout << ("Adivina cual es la palabra.\n");
    
    // Imprimir las letras en palabra "-------"
    PrintVector(letras_en_palabra);
}

/**
 * Comienza la interaccion con el usuario y checa los aciertos que tiene, si falla se disminuye las oportunidades tambien indica si el jugador gano o perdio.
 *
 * @param [Referencia] La palabra que se escogio aleatoriamente y la cual se debe adivinar
 * @param [Referencia] Aqui estan guardados los caracteres que el usuario ingreso.
 * @param [Referencia] Donde se encuentran las letras que contiene la palabra oculta.
 *
 * @return Me regresa que el usuario quiere volver a jugar.2
 */

bool
Exe_Game
(
 string&         palabra,
 vector<char>&   letras_usadas,
 vector<char>&   letras_en_palabra
 )
{
    int oportunidades = 5;
    char letra;
    char respuesta;
    while (oportunidades > 0)
    {
        cout << "\n*****************************************\n" << endl;
        cout << "Te quedan " << oportunidades << " oportunidades restantes para adivinar una palabra con " << palabra.length() << " letras" << "\n";
        
        cout << ("Ingresa la letra: ");
        cin >> letra;
        
        // checar que la letra que se ingreso no sea la misma
        if (compara_letra(letra, letras_usadas) == true)
        {
            oportunidades--;
        }
        
        // TODO: Ejecutar la logica.
        
        bool acerto  = comparacion(palabra, letras_usadas, letras_en_palabra, letra);
        if (acerto == false)
        {
            oportunidades--;
        }
        
        if (oportunidades == 4)
        {
            cout << " |                 \n";
            cout << " |                 \n";
            cout << " |                 \n";
            cout << " |                 \n";
            cout << " |                 \n";
            cout << " |                 \n";
        }
        
        if (oportunidades == 3)
        {
            cout << " |----------       \n";
            cout << " |                 \n";
            cout << " |                 \n";
            cout << " |                 \n";
            cout << " |                 \n";
            cout << " |                 \n";
        }
        
        if (oportunidades == 2)
        {
            cout << " |----------|      \n";
            cout << " |          |      \n";
            cout << " |                 \n";
            cout << " |                 \n";
            cout << " |                 \n";
            cout << " |                 \n";
        }
        
        if (oportunidades == 1)
        {
            cout << " |----------|      \n";
            cout << " |          |      \n";
            cout << " |          O      \n";
            cout << " |          |      \n";
            cout << " |         / |    \n";
            cout << " |                 \n";
        }
        
        if (oportunidades <= 0)
        {
            cout << " |----------|      \n";
            cout << " |          |      \n";
            cout << " |          O      \n";
            cout << " |         /||    \n";
            cout << " |         / |    \n";
            cout << " |                 \n";
            cout << endl;
            cout << "El juego termino, no conseguiste adivinar la palabra\n";
            cout << "La palabra era: " << palabra << endl;
            cout << "Si deseas seguir jugando presiona Y/N: ";
            cin >> respuesta;
            if (respuesta == 'Y' || respuesta == 'y' || respuesta == 's' || respuesta == 'S')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
        PrintVector(letras_en_palabra);
        
        if (compara_palabra(letras_en_palabra, palabra) == true)
        {
            cout << "Ganaste\n";
            cout << "Si deseas seguir jugando presiona Y/N: ";
            cin >> respuesta;
            if (respuesta == 'Y' || respuesta == 'y')
            {
                return true;
            }
            else
            {
                return false;
            }
            
            break;
        }
    }
    return true;
}

/**
 * Descripcion Compara un vector de caracteres con un string
 *
 * @param [Copia] Son las letras en palabra donde se almacenan las letras apartir de lo que ongresa el usuario
 * @param [Copia] La palabra oculta
 *
 * @return Que si el contenido del vector de caracteres es igual al string de caracteres retorna un true sino un false.
 */
 
bool
compara_palabra(vector <char> vec_carac, string palabra)
{
    if (vec_carac.size() == palabra.size())
    {
        for (int i = 0; i < palabra.size(); ++i)
        {
            if (vec_carac[i] != palabra[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    else
    {
        return false;
    }
}

/**
 * Funcion que imprime cualquier Vector de caracteres.
 *
 * @param [Copia] Cualquier vector con caracteres
 */

void
PrintVector(vector<char> vec)
{
    for (int i=0; i < vec.size(); i++)
    {
        cout << (vec[i]);
    }
    cout << "\n";
    return;
}

/**
 * Compara si la letra escrita por el usuario existe dentro de las letras de la palabra oculta y  modifica las letras en las palabras por las escritas.
 *
 * @param [Copia] Es la palabra elegida por el random para adivinar.
 * @param [Referencia] Son las letras en palabra donde se almacenan las letras apartir de lo que ongresa el usuario.
 * @param [Referencia] La palabra oculta.
 * @param [Copia] La letra ingresada por el usuario.
 *
 * @return Me retorna si el usuario tuvo aciertos o no.
 */

bool
comparacion
(
 string         palabra,
 vector<char>&  letras_usadas,
 vector<char>&  letras_en_palabra,
 char           letra
)
{
    bool aciertos = false;
    
    for (int i=0; i<palabra.size(); i++)
    {
        if (letra == palabra[i])
        {
            letras_en_palabra[i]=letra;
            aciertos = true;
        }
    }
    
    letras_usadas.push_back(letra);
    // Checar si ya esta en la lista.
    
    return aciertos;
}

bool
compara_letra
(
char            letra,
vector<char>    letras_usadas
)
{
    bool es_la_misma_letra = false;
    for (int i = 0; i < letras_usadas.size(); ++i)
    {
        if (letras_usadas[i] == letra)
        {
            cout << "Ya ingresaste esa letra. Intenta ingresar otra." << endl << endl;
            es_la_misma_letra = true;
        }
    }
    return es_la_misma_letra;
}


int Ahorcado()
{
    vector<char>    letras_usadas;
    vector<char>    letras_en_palabra;
    string          palabra;
    
    // Game Loop
    
    bool in_Game = true;
    while (in_Game)
    {
        // Prepara mis variables
        
        Init_Game(letras_usadas, letras_en_palabra, palabra);
        
        // Ejecuta el juego. Si "in_Game" es "False", ya no quiere jugar.
        
        in_Game = Exe_Game(palabra, letras_usadas, letras_en_palabra);
    }
    
    return 0;
}