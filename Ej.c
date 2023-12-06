/*Cada semestre, a la materia de Programación se inscriben una cantidad constante de 23 alumnos. El semestre está dividido en 3 progresos.
Utilice los conceptos de Arreglos y Funciones para escribir un programa en lenguaje C que permita realizar los siguientes cálculos:
1- Obtener el promedio de calificaciones de cada alumno durante el semeste.
2- La nota promedio del grupo de estudiantes para cada progreso
3- El alumno que obtuvo el mayor promedio de calificación durante el semestre*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void PromedioAlumno(int Notas[3][23], float promedioCurso[23]);
void NotaPromedio(int Notas[3][23], float promedioCurso[23]);
void MayorNota(int Notas[3][23], float promedioCurso[23]);

int main(int argc, char const *argv[])
{
    int Notas[3][23];
    float promedioCurso[23];

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

    PromedioAlumno(Notas, promedioCurso);
    NotaPromedio(Notas, promedioCurso);
    MayorNota(Notas, promedioCurso);

        return 0;
}

void PromedioAlumno(int Notas[3][23], float promedioCurso[23])
{
    int alumno = 0;
    puts("Ingrese el alumno que quiere ver el promedio: ");
    scanf("%d%*c", &alumno);

    float suma = 0;
    for (int i = 0; i < 3; i++)
    {
        suma += Notas[i][alumno - 1];
    }

    printf("El promedio del estudiante %d es %.2f\n", alumno, suma / 3);
}

void NotaPromedio(int Notas[3][23], float promedioCurso[23])
{
    float sumaCurso = 0;
    float promedio = 0;

    for (int alumno = 0; alumno < 23; alumno++)
    {
        float suma = 0;
        for (int i = 0; i < 3; i++)
        {
            suma += Notas[i][alumno];
        }
        promedio = suma / 3;
        promedioCurso[alumno] = promedio;
    }

    for (int i = 0; i < 23; i++)
    {
        sumaCurso += promedioCurso[i];
    }

    puts("\nEl promedio de cada estudiante es:");
    for (int i = 0; i < 23; i++)
    {
        printf("%.2f\t", promedioCurso[i]);
    }
    puts("\n");
    printf("El promedio del curso es: %.2f\n", sumaCurso / 27);
}

void MayorNota(int Notas[3][23], float promedioCurso[23])
{
    float notaMax = 0;
    int alumnoMax;

    for (int i = 0; i < 23; i++)
    {
        if (promedioCurso[i] >= notaMax)
        {
            notaMax = promedioCurso[i];
            alumnoMax = i+1;
        }
    }

    printf("La mayor nota es %.2f correspondiente al alumno %d\n\n", notaMax, alumnoMax);
}