/*
 Programa para borrar o cambiar el nombre de archivos desde consola.

 - Se comprueba la existencia del archivo antes de operar.
 - Se restringen rutas con caracteres no ASCII para evitar problemas de codificación.
 - Proyecto de aprendizaje en C++.

 ADVERTENCIA: el programa realiza operaciones destructivas.
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <limits>
using namespace std;
int main ()
{
    /**Solicitamos al usuarios la ruta del archivo a tratar**/
    char nombre[150];
    cout << "Introduzca el nombre del fichero a trabajar: ";
    cin.getline(nombre, 150);
    cout<<"\n";
    /**Comprobamos la existencia de caracteres NO ASCII en la ruta de archivo**/
    bool ascii = true;
    for (int i = 0; nombre[i] != '\0'; i++)
    {
        if ((unsigned char)nombre[i] > 127)
        {
            ascii = false;
            break;
        }
    }

    while(!ascii)
    {
        cout << "La ruta contiene caracteres no soportados (tildes o letra enie).\n";
        cout << "Use una ruta sin acentos.\n";
        cout << "Desea continuar con el programa?\n";
        char continuar[10];
        cin >> continuar;
        cout << "\n";
        /**Si existen caracteres NO ASCII se pregunta si aun así se desea continuar**/
        if (strcmp(continuar,"Si")==0 || strcmp(continuar, "si")==0)
        {
            /**Si se desea continuar se pide un nuevo nombre**/
            cout <<"Introduzca el nombre del fichero a trabajar: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.getline(nombre,150);
            cout <<"\n";
            /** Nueva validación tras entrada corregida del usuario **/

            ascii=true;
            for (int i = 0; nombre[i] != '\0'; i++)
            {
                if ((unsigned char)nombre[i] > 127)
                {
                    ascii = false;
                    break;
                }
            }
        }
        /**Si se decide NO continuar terminamos programa**/
        else
        {

            cout << "Se finaliza el programa";
            return 0;
        }
    }
    /**Al no haber caracteres problemáticos, abrimos el archivo
    para comprobar si existe**/
    FILE *f=fopen(nombre,"r");
    if (f == NULL)
    {
        cout << "El archivo dado no existe o no puede abrirse\n";
    }
    else
    {
        /**Se debe cerra el archivo para posteriormente borrarlo o
         cambiarle el nombre**/
        fclose(f);
        cout <<"\nDesea borrar o cambiar el nombre del archivo? ";
        char opcion [30];
        cin >> opcion;
        cout<< "\n";
        /**Si se elige borrar, acatamos**/
        if (strcmp(opcion,"borrar")==0 || strcmp(opcion,"Borrar")==0)
        {
            if (remove(nombre)==0)
            {
                cout << "Su archivo ha sido eliminado con exito\n";
            }
            else
            {
                cout << "Su archivo no ha podido borrarse\n";
            }
        }
        /**Si se elige cambiar, acatamos**/
        else if (strcmp(opcion,"cambiar")==0 || strcmp(opcion,"Cambiar")==0)
        {
            cout << "Seleccione un nombre nuevo:";
            char nombre2[150];
            cin >>nombre2;
            cout << "\n";
            if(rename(nombre,nombre2)==0)
            {
                cout << "El nombre del archivo se ha cambiado con exito\n";
            }
            else
            {
                cout << "Su archivo no ha podido cambiar de nombre\n";
            }
        }
        /**Si se teclea alguna opcion sin sentido, se cerrará el programa**/
        else
         {
           cout << "Opcion no valida, se finaliza el programa\n";
           return 0;
         }
        /**Despues de cambiar el nombre o borrar se pregunta si se desea continuar**/
        cout << "\nDesea continuar con el programa? : ";
        char continuar[10];
        cin >> continuar;
        cout << "\n";
        /**Mientras se teclee si se ejecutará todo el programa otra vez**/
        while (strcmp(continuar,"Si")==0 || strcmp(continuar,"si")==0)
        {
            cout << "Introduzca el nombre del fichero a trabajar: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.getline(nombre, 150);
            cout <<"\n";
            /**Nueva validación tras entrada corregida del usuario**/
            ascii = true;
            for (int i = 0; nombre[i] != '\0'; i++)
            {
                if ((unsigned char)nombre[i] > 127)
                {
                    ascii = false;
                    break;
                }
            }
            /**Si existen caracteres NO ASCII se notifica de nuevo y se pregunta si se desea continuar**/
            while(!ascii)
            {
                cout << "La ruta contiene caracteres no soportados (tildes o letra enie).\n";
                cout << "Use una ruta sin acentos.\n";
                cout << "Desea continuar con el programa?\n";
                char continuar[10];
                cin >> continuar;
                cout << "\n";
                /**Si se pone que se desea continuar se pregunta nuevo nombre**/
                if (strcmp(continuar,"Si")==0 || strcmp(continuar, "si")==0)
                {
                    cout <<"Introduzca el nombre del fichero a trabajar: ";
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cin.getline(nombre,150);
                    cout <<"\n";
                    /**Verificaremos que no contenga caracteres NO ASCII**/
                    ascii=true;
                    for (int i = 0; nombre[i] != '\0'; i++)
                    {
                        if ((unsigned char)nombre[i] > 127)
                        {
                            ascii = false;
                            break;
                        }
                    }
                }
                /** Salida controlada del programa a petición del usuario **/
                else
                {
                    cout << "Se finaliza el programa";
                    return 0;
                }
            }
            /**Abrimos el archivo para comprobar si existe**/
            FILE *f=fopen(nombre,"r");
            if (f == NULL)
            {
                cout << "El archivo dado no existe o no puede abrirse\n";
            }
            else
            {
                /**Cerramos archivo para su posterior delete or rename**/
                fclose(f);
                cout <<"\nDesea borrar o cambiar el nombre del archivo? ";
                cin >> opcion;
                /**Si se elige borrar, acatamos**/
                if (strcmp(opcion,"borrar")==0 || strcmp(opcion,"Borrar")==0)
                {
                    if (remove(nombre)==0)
                    {
                        cout << "Su archivo ha sido eliminado con exito\n";
                    }
                    else
                    {
                        cout << "Su archivo no ha podido borrarse\n";
                    }
                }
                /**Si se elige cambiar, acatamos**/
                else if (strcmp(opcion,"cambiar")==0 || strcmp(opcion,"Cambiar")==0)
                {
                    cout << "Seleccione un nombre nuevo:";
                    char nombre2[150];
                    cin >>nombre2;
                    cout << "\n";
                    if(rename(nombre,nombre2)==0)
                    {
                        cout << "El nombre del archivo se ha cambiado con exito";
                    }
                    else
                    {
                        cout << "Su archivo no ha podido cambiar de nombre";
                    }
                }
                /**Si teclea una opcion sin sentido, se notifica y terminamos programa**/
                else
                {
                    cout << "Opcion no valida, se finaliza el programa\n";
                    return 0;
                }
                /**Se pregunta si se desea continuar para volver a realizar el proceso de nuevo**/
                cout << "\nDesea continuar con el programa? : ";
                cin >>continuar;
                cout << "\n";
            }
        }
        /**Cuando salgamos de bucle se muestra un mensaje que indica que el programa finaliza y se detiene el programa**/
        cout << "Se finaliza el programa";
        return 0;
    }
}
