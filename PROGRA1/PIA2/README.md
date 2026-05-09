# Sistema de Gestion y Analisis de Resultados de Estudios con Recomendaciones

Este sistema analizara resultados de pacientes segun el area seleccionada, se simulara una visita al
medico donde el medico registre los resultados del paciente y se guarden en arreglos que simulan las bases
de datos.

# Menus
El sistema contara con varios tipos de menus

## Menu de usuario
Este menu es el que se mostrara al ingresar en consola el tipo de usuario "USUARIO", se mostrara la opcion 
de ingresar nombre y contrasena del paciente, las opciones del menu seran:

1. Buscar mis registros
    - Ingrese nombre del registro (Cuando seleccione esta opcion se mostrara el registro con las recomendaciones)
2. Reporte de registros

## Menu de doctor
Este menu se mostrara al poner en el tipo de usuario "DOCTOR", se pondra la contrasena "ADMIN123" para ingresar al panel de administrador. El panel mostrara: 

1. Crear nuevo registro de resultados
    - ingresar nombre del paciente
    - ingresar tipo de de resultado
        - Diabetologia
        - Cardiologia
        - Nutricion
    - Guardar resultados 
2. Imprimir registro de resultados (se imprime solo el nombre del paciente y su tipo de registro)
3. Borrar registro
4. Agregar nuevo doctor
    - Ingrese nombre del doctor
    - Ingrese especialidad del doctor
5. Borrar doctor
6. Salir

# Funciones necesarias
## Funcion para borrar registros
## Funcion para borrar Doctores
## Funcion para imprimir registros
## Funcion para agregar pacientes
## Funcion para agregar doctores
