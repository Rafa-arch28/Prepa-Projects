# Sistema de gestión de biblioteca

Proyecto integrador de **Programación 2** desarrollado en C++. El programa simula el registro de alumnos que visitan una biblioteca, solicitan libros y utilizan computadoras.

## ¿Qué hace el programa?

- Registra uno o varios alumnos.
- Guarda nombre, matrícula, fecha y horario de visita.
- Registra préstamos de libros.
- Registra el código del libro prestado.
- Registra el número de computadora utilizada.
- Muestra reportes de libros y computadoras.
- Guarda los registros en un archivo de texto.
- Carga automáticamente los registros cuando el programa inicia.

## Cómo clonar el proyecto

Desde una terminal, ejecuta:

```bash
git clone https://github.com/Rafa-arch28/Prepa-Projects.git
cd Prepa-Projects/PROGRAMACION/PROGRA2/PIA
```

## Requisitos

- C++20 o superior.
- Un compilador compatible con C++, como `g++`.
- Git para clonar el repositorio.

## Organización de los archivos

```text
PIA/
├── main.cpp
├── funciones.cpp
├── funciones.h
├── structs.h
└── alumnos.txt
```

### `main.cpp`

Contiene la función principal del programa. Se encarga de:

1. Crear el arreglo de alumnos.
2. Cargar los registros guardados.
3. Calcular los libros prestados y disponibles.
4. Mostrar el menú principal.
5. Guardar los datos antes de terminar.

### `structs.h`

Contiene las estructuras utilizadas por el programa:

- `Fecha`: almacena día, mes y año.
- `Alumno`: almacena la información del alumno, su visita, el libro y la computadora.

### `funciones.h`

Contiene la constante `MAXIMO` y los prototipos de las funciones.

### `funciones.cpp`

Contiene la implementación de todas las funciones del programa.

## Funciones

### `registrar`

```cpp
void registrar(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p);
```

Registra nuevos alumnos y solicita:

- Nombre.
- Matrícula.
- Hora de entrada y salida.
- Fecha de visita.
- Si desea pedir un libro.
- Si desea utilizar una computadora.

También actualiza `total`, `LIBROS` y `libros_p`.

### `cargar_alumnos`

```cpp
bool cargar_alumnos(Alumno alumnos[MAXIMO], int& total);
```

Lee los registros de `alumnos.txt` y los coloca en el arreglo `alumnos`.

Devuelve:

- `true` si los datos se cargaron correctamente.
- `false` si el archivo no existe o tiene un formato incorrecto.

### `guardar_alumnos`

```cpp
bool guardar_alumnos(const Alumno alumnos[MAXIMO], int total);
```

Guarda todos los alumnos del arreglo en `alumnos.txt`.

El parámetro `const` indica que la función solamente lee los datos del arreglo y no los modifica.

Devuelve:

- `true` si el archivo se pudo abrir y guardar.
- `false` si no se pudo abrir el archivo.

### `reporte`

```cpp
void reporte(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p);
```

Muestra:

- Cantidad de libros prestados.
- Cantidad de libros disponibles.
- Alumnos que tienen libros.
- Alumnos que utilizan computadoras.

### `mostrar_menu`

```cpp
void mostrar_menu(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p);
```

Muestra el menú principal y permite al usuario:

1. Registrar una visita a la biblioteca.
2. Mostrar el reporte.
3. Salir del programa.

## Ejemplo de ejecución

Al iniciar el programa se muestra el menú principal:

```text
Ingrese una opcion del menu:
1. Visita a la biblioteca
2. Imprimir reporte de la biblioteca
3. Salir
```

Desde este menú se pueden registrar visitas, consultar el reporte o salir guardando los datos.

## Persistencia de datos

Los registros se guardan en `alumnos.txt`. El archivo comienza con la cantidad total de alumnos y después almacena los datos de cada alumno en un orden fijo.

Formato de cada registro:

```text
cantidad total de alumnos
nombre
matrícula
hora de entrada
hora de salida
día
mes
año
código del libro
número de computadora
nombre del libro
```

Por ejemplo, un archivo con un alumno que pidió un libro puede verse así:

```text
1
Ana Lopez
123
8.3
10
7
10
2026
42
0
C++ Basico
```

En este ejemplo:

- `1` indica que hay un alumno guardado.
- `42` es el código del libro.
- `0` indica que no se utilizó una computadora.

Cuando un alumno no pide un libro, el código del libro se guarda como `0` y se conserva una línea vacía para mantener el formato.

## Notas

- El programa permite almacenar hasta `100` alumnos.
- La biblioteca inicia con `100` libros disponibles.
- Un código de libro diferente de `0` se considera un libro prestado.
- Si `alumnos.txt` no existe, el programa inicia sin registros y crea el archivo al guardar por primera vez.
- El archivo `alumnos.txt` debe conservar el formato indicado para que los datos puedan cargarse correctamente.

## Estado del proyecto

Proyecto académico funcional. Actualmente permite registrar alumnos, guardar sus datos y generar reportes de libros y computadoras.

## Limitaciones

- El programa permite registrar un máximo de `100` alumnos.
- Los datos se guardan en un archivo de texto.
- El formato de `alumnos.txt` debe conservarse para poder cargar los registros.
- Actualmente no existe una opción para devolver libros al inventario.

## Licencia

Este proyecto fue creado con fines académicos.

## Autor

**Rafa**

- GitHub: [@Rafa-arch28](https://github.com/Rafa-arch28)
- Correo: [rafael.dee@uanl.edu.mx](mailto:rafael.dee@uanl.edu.mx)
