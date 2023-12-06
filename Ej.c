/*Cada semestre, a la materia de Programación se inscriben una cantidad constante de 23 alumnos. El semestre está dividido en 3 progresos.
Utilice los conceptos de Arreglos y Funciones para escribir un programa en lenguaje C que permita realizar los siguientes cálculos:
1- Obtener el promedio de calificaciones de cada alumno durante el semeste.
2- La nota promedio del grupo de estudiantes para cada progreso
3- El alumno que obtuvo el mayor promedio de calificación durante el semestre*/
// inclusion de librerias
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// bloque de prototipado de las funciones a utilizar
void PromedioAlumno(int Notas[3][23], float promedioCurso[23]);
void NotaPromedio(int Notas[3][23], float promedioCurso[23]);
void MayorNota(int Notas[3][23], float promedioCurso[23]);

int main(int argc, char const *argv[])
{
    int Notas[3][23];        // voy a guardar las notas de cada estudiante en su respectivo progreso mediante una matriz
    float promedioCurso[23]; // tambien, como corrección durante el codificar, voy a colocar una matriz donde guardar la nota promedio de cada alumno para utilizarla en la funcion NotaMayor

    srand(time(NULL)); // generacion de numeros aleatorios

    // bloque donde relleno la matriz de notas aleatoriamente entre 0 y 10
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            Notas[i][j] = rand() % 11; // aqui selecciono que sean entre 0 y 10
        }
    }

    // muestro en pantalla la matriz que guarda las notas de todos los estudiantes
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            printf("%d\t", Notas[i][j]);
        }
        printf("\n");
    }
    puts("\n");

    // Aqui pasa la magia y llamo a todas las funciones
    PromedioAlumno(Notas, promedioCurso);
    NotaPromedio(Notas, promedioCurso);
    MayorNota(Notas, promedioCurso);

    return 0;
}

void PromedioAlumno(int Notas[3][23], float promedioCurso[23])
{
    int alumno = 0; // variable de apoyo donde pido al usuario ingresar que alumno quiere ver el promedio
    puts("Ingrese el alumno que quiere ver el promedio: ");
    scanf("%d%*c", &alumno);

    float suma = 0; // varaible de apoyo tipo flotante donde guardo la suma de las 3 notas de los progresos del alumno para sacar su promedio luego
    for (int i = 0; i < 3; i++)
    {
        suma += Notas[i][alumno - 1]; // guardo los valores en la variable suma
    }

    printf("El promedio del estudiante %d es %.2f\n", alumno, suma / 3); // muestro en pantalla el resultado
}

void NotaPromedio(int Notas[3][23], float promedioCurso[23])
{
    // variables de apoyo tipo flotante
    float sumaCurso = 0; // aqui guardo la suma de notas de todos los estudiantes del curso, tomando en cuenta solo las notas promediadas de los 3 progresos
    float promedio = 0;  // variable de apoyo donde guardo el promedio de cada alumno en el semestre y voy a ir guardando en el arreglo float promedioCurso[23]

    // podemos decir que vuelvo a reutilizar parte del codigo de PromedioAlumno para no caer en llamar una función dentro de otra función
    for (int alumno = 0; alumno < 23; alumno++)
    {
        float suma = 0;
        for (int i = 0; i < 3; i++)
        {
            suma += Notas[i][alumno];
        }
        promedio = suma / 3;
        promedioCurso[alumno] = promedio; // guardo las notas promediadas de cada estudiante para poder tener facilidad de manipular en la siguiente funcion
    }

    for (int i = 0; i < 23; i++)
    {
        sumaCurso += promedioCurso[i]; // guardo las notas de todos los promedios de los alumnos para sacar su promedio luego
    }

    // muestro en pantalla el arreglo que guarda las notas finales promediadas de cada alumno
    puts("\nEl promedio de cada estudiante es:");
    for (int i = 0; i < 23; i++)
    {
        printf("%.2f\t", promedioCurso[i]);
    }
    puts("\n");

    printf("El promedio del curso es: %.2f\n", sumaCurso / 27); // muestro el promedio del curso
}

void MayorNota(int Notas[3][23], float promedioCurso[23])
{
    float notaMax = 0; // variable de apoyo donde guardo la nota maxima del curso
    int alumnoMax;     // guardo el indice de la ubicacion del usuario con mayor nota

    // recorro todo el arreglo float promedioCurso[23] que hice, es muy util el arreglo
    for (int i = 0; i < 23; i++)
    {
        if (promedioCurso[i] >= notaMax) // con un condicional voy determinando cual es la mayor nota
        {
            notaMax = promedioCurso[i]; // cambio la variable notaMax con la encontrada
            alumnoMax = i + 1;          // guardo la ubicacion del estudiante
        }
    }

    printf("La mayor nota es %.2f correspondiente al alumno %d\n\n", notaMax, alumnoMax); // muestro en pantalla la nota maxima y el alumno que la tiene
}