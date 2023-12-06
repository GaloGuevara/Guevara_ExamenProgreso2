/*Cada semestre, a la materia de Programación se inscriben una cantidad constante de 23 alumnos. El semestre está dividido en 3 progresos. Utilice los conceptos de Arreglos y Funciones para escribir un programa en lenguaje C que permita realizar los siguientes cálculos:
1- Obtener el promedio de calificaciones de cada alumno durante el semeste.
2- La nota promedio del grupo de estudiantes para cada progreso
3- El alumno que obtuvo el mayor promedio de calificación durante el semestre*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void PromedioAlumno(int Notas[3][23]);
void NotaPromedio(int Notas[3][23]);
void MayorNota(int Notas[3][23]);

int main(int argc, char const *argv[])
{
    int Notas[3][23];

    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            Notas[i][j] = rand() % 11;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            printf("%d\t", Notas[i][j]);
        }
        printf("\n");
    }
    puts("\n");


    return 0;
}
