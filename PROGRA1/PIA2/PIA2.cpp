/*
PIA PROGRAMACION I 
Integrantes: 
    Gissel Azeneth Ceron Santos, Matricula: 2307
    Rafael Antonio de la Fuente Esparza, Matricula: 2307861
    Kimberly Paola Rodarte Rivera, Matricula: 2307804
*/

#include <iostream>
using namespace std;

int main() {
    
    const int MAXIMO_PACIENTES = 100;
    const int MAXIMO_REGISTROS = 100;
    const int MAXIMO_DOCTORES = 100;
    const int MAXIMO_ESPECIALIDADES = 100;
    const int MAXIMO_RESULTADOS = 100;
    const int MAXIMO_ESTUDIOS = 100;
    const int MAXIMO_DIAGNOSTICOS = 100;

    // arreglos para pacientes
    string pacientes[MAXIMO_PACIENTES];
    string contrasena_paciente[MAXIMO_PACIENTES];

    // arreglos para doctores
    string doctores[MAXIMO_DOCTORES];
    string especialidad_doctores[MAXIMO_ESPECIALIDADES];
    string tipo_estudio[MAXIMO_ESTUDIOS];
    int cantidad_doctores[MAXIMO_DOCTORES];

    // arreglos para el diagnostico, aqui se guarda el tipo de diagnostico que tiene
    string diagnostico[MAXIMO_DIAGNOSTICOS];

    string reclGlucosa[] = {
        "Todo bien, sigue con tu dieta actual",
        "Cuidado, baja el consumo de refrescos y azucares en general",
        "PELIGRO, elimina los azucares YAAAA"
    };

    string recColesterol[] = {
        "Corazon sano. Sigue haciendo ejercicio",
        "Ojo. Evita alimentos fritos y grasas saturadas",
        "ALERTA. Riesgo de infarto. Evita grasas y haz cardio"
    };

    string recNutricion[] = {
        "Peso ideal. Mantente hidratado y activo",
        "Sobrepeso. Reduce porciones y evita comida chatarra",
        "Obesidad. Inicia dieta balanceada y camina 30min"
    };

    string contrasena_admin = "ADMIN123";
    string usuario;
    string nombre_usuario;
    string contra_usuario;
    string contrasena_doc;
    int opc = 0;
    int contador = 0;
    int contador2 = 0;
    int contador3 = 0;
    int paciente_borrar = 0;
    int doctor_borrar = 0;
    int numero_registro = 0;
    char repetir_programa;

    // INICIAMOS CON LA LOGICA
    do {
        cout << "MENU PARA UNA CLINICA \n\n";
        cout << "Ingrese su tipo de usuario: \nTipos de usuario: \nUSUARIO \nDOCTOR, contra DOCTOR: ADMIN123\n";
    cin >> usuario; cout << endl;

    if (usuario == "DOCTOR") {
        cout << "Ingrese la contrasena: ";
        cin >> contrasena_doc;
        if (contrasena_doc == contrasena_admin) {
            do {

                cout << endl;
                cout << "ESTA EN EL MENU DE DOCTOR\n";
                cout << "1. Crear nuevo registro \n2. Imprimir registros \n3. Borrar registro \n4. Agregar nuevo doctor \n5. imprimir doctores \n6. Borrar Doctor\n7. Salir" << endl;
                cin >> opc;

                switch (opc) {
                    case 1:
                    {
                        cout << endl;
                        if (contador >= MAXIMO_REGISTROS) {
                            cout << "ERROR: YA NO HAY ESPACIO PARA MAS REGISTROS" << endl;
                            break;
                        }
                        
                        cin.ignore(); // esta linea es para quitar el enter imaginario que guarda el buffer

                        cout << "CREANDO NUEVO REGISTRO \n\n";

                        cout << "Ingrese el nombre del paciente: ";
                        getline(cin, pacientes[contador]);

                        cout << "Ingrese la contrasena para el paciente: ";
                        getline(cin, contrasena_paciente[contador]);

                        do {
                            cout << "Ingrese el tipo de estudio: \nDIABETOLOGIA\nCARDIOLOGIA\nNUTRICION\n";
                            getline(cin, tipo_estudio[contador]);  // uso getline para saltarme los espacios
                            if (tipo_estudio[contador] != "DIABETOLOGIA" && 
                                tipo_estudio[contador] != "CARDIOLOGIA" && 
                                tipo_estudio[contador] != "NUTRICION") {
                                cout << "OPCION INVALIDA, INTENTE DE NUEVO" << endl;
                            }
                        } while (tipo_estudio[contador] != "DIABETOLOGIA" && 
                            tipo_estudio[contador] != "CARDIOLOGIA" && 
                            tipo_estudio[contador] != "NUTRICION");

                        do {

                            cout << "Ingrese el diagnostico (BUENO, REGULAR, MALO): ";
                            getline(cin, diagnostico[contador]);

                            if (diagnostico[contador] != "BUENO" && 
                            diagnostico[contador] != "REGULAR" && 
                            diagnostico[contador] != "MALO") {

                                cout << "OPCION INVALIDA, INTENTELO DE NUEVO" << endl;

                            }

                        } while (diagnostico[contador] != "BUENO" && 
                            diagnostico[contador] != "REGULAR" && 
                            diagnostico[contador] != "MALO");

                        cout << "REGISTRO CREADO EXITOSAMENTE" << endl << endl;
                        contador++;
                        break;
                    }
                    case 2:
                    {
                        cout << endl;
                        if (contador != 0){ 
                            cout << "REPORTE DE REGISTROS" << endl;
                            cout << "Numero de registros: " << contador << "\n" << endl;
                            for (int k = 0; k < contador; k++){
                                cout << "Registro #" << k + 1 << endl;
                                cout << "Nombre del paciente: " << pacientes[k] << endl;
                                cout << "Tipo de estudio: " << tipo_estudio[k] << endl;
                                cout << "Su diagnostico es: " << diagnostico[k] << endl;
                            }
                            cout << endl;
                        } else {
                            cout << "Aun no hay registros hechos :) " << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (contador == 0) {
                            cout << "No hay pacientes para borrar" << endl;
                            break;
                        }
                        cout << "Ingrese el numero del registro que quiere borrar (1 a " << contador << "): ";
                        cin >> paciente_borrar; cout << "\n";
                        int indice = paciente_borrar - 1;

                        if (indice >= 0 and indice < contador) {

                            for (int k = indice; k < contador - 1; k++) {
                                pacientes[k] = pacientes[k + 1];
                                contrasena_paciente[k] = contrasena_paciente[k + 1];
                                tipo_estudio[k] = tipo_estudio[k + 1];
                                diagnostico[k] = diagnostico[k + 1];
                            }

                            contador--;
                            cout << "REGISTRO ELIMINADO EXITOSAMENTE" << endl;
                        } else {
                            cout << "Numero de registro invalido." << endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        cin.ignore();
                        cout << endl;
                        
                        if (contador2 >= MAXIMO_DOCTORES) {
                            cout << "ERROR: YA NO HAY ESPACIO PARA MAS DOCTORES" << endl;
                            break;
                        }
                        
                        cout << "REGISTRANDO NUEVO DOCTOR \n";

                        cout << "Ingrese el nombre del Doctor: ";
                        getline(cin, doctores[contador2]);

                        do {

                            cout << "Ingrese la especialidad (DIABETOLOGIA, CARDIOLOGIA, NUTRICION): ";
                            getline(cin, especialidad_doctores[contador2]);

                            if (especialidad_doctores[contador2] != "DIABETOLOGIA" && 
                            especialidad_doctores[contador2] != "CARDIOLOGIA" && 
                            especialidad_doctores[contador2] != "NUTRICION") {
                                cout << "OPCION INVALIDA, VUELVA A INTENTARLO" << endl;
                            }

                        } while (especialidad_doctores[contador2] != "DIABETOLOGIA" && 
                            especialidad_doctores[contador2] != "CARDIOLOGIA" && 
                            especialidad_doctores[contador2] != "NUTRICION");

                        cout << "DOCTOR REGISTRADO CORRECTAMENTE" << endl;
                        cantidad_doctores[contador2] = 1;
                        cout << endl;

                        contador2++;

                        break;
                    }
                    case 5:
                    {
                        cout << endl;
                        if (contador2 == 0) {
                            cout << "No hay doctores registrados" << endl;
                        } else {
                            cout << "IMPRIMIENDO REPORTE DE DOCTORES" << endl;
                            cout << "Cantidad de Doctores: " << contador2 << "\n" << endl;
                            for (int k = 0; k < contador2; k++){
                                cout << "Doctor #" << k + 1 << endl;
                                cout << "Nombre del doctor: " << doctores[k] << endl;
                                cout << "Especialidad del doctor: " << especialidad_doctores[k] << endl;
                            }
                        }
                        cout << endl << endl;
                        break;
                    }
                    case 6:
                    {
                        if (contador2 == 0) {
                            cout << "No hay doctores para borrar" << endl;
                            break;
                        } else {
                            cout << "Ingrese el numero del doctor a borrar (del 1 al " << contador2 << ") " << endl;
                            cin >> doctor_borrar; cout << "\n";
                            int indice2 = doctor_borrar - 1;

                            if (indice2 >= 0 and indice2 < contador2) {

                                for (int k = indice2; k < contador2 - 1; k++) {
                                    doctores[k] = doctores[k + 1];
                                    especialidad_doctores[k] = especialidad_doctores[k + 1];
                                    cantidad_doctores[k] = cantidad_doctores[k + 1];
                                }

                                contador2--;
                                cout << "DOCTOR ELIMINADO EXITOSAMENTE" << endl;
                            } else {
                                cout << "Numero de doctor invalido." << endl;
                            }
                        }
                        break;
                    }
                }
            } while (opc != 7);
            cout << "SALIENDO DEL MENU DOCTOR, GRACIAS POR ENTRAR\n";
        } else {
            cout << "CONTRASENA INCORRECTA, INTENTE DE NUEVO\n";
        }
    } else if (usuario == "USUARIO") {
        
        cin.ignore();

        cout << "Ingrese su nombre de paciente: ";
        getline(cin, nombre_usuario); 

        cout << "Ingrese su contrasena: ";
        getline(cin, contra_usuario); cout << endl;

        bool acceso_concedido = false; // es la primera bandera que usamos en el codigoo wuju

        for (int k = 0; k < contador; k++) {
            if (nombre_usuario == pacientes[k] && contra_usuario == contrasena_paciente[k]) {
                acceso_concedido = true;
                break;
            }
        }

        if (acceso_concedido == true) { // aqui se puede dejar como if (acceso_concedido) pero para que lo entiendan mejor se los deje asi
            do {
                cout << "\nBienvenido " << nombre_usuario << "!\n";
                cout << "Ingrese la opcion que desee: \n1. Buscar un registro \n2. Reporte de mis registros \n3. Salir\n";
                cin >> opc;

                switch (opc) {
                    case 1:
                    {
                        cout << "\nBUSCAR SU REGISTRO\n";
                        cout << "Ingrese su numero de registro: ";
                        cin >> numero_registro;
                        int indice = numero_registro - 1;

                        // verifico que sea valido y le pertenezca solo a este usuario
                        if (indice >= 0 && indice < contador && pacientes[indice] == nombre_usuario) {
                            
                            cout << endl;
                            cout << "Tipo de estudio: " << tipo_estudio[indice] << endl;
                            cout << "Su diagnostico es: " << diagnostico[indice] << endl;
                            cout << "Aqui tiene una recomendacion segun su diagnostico: ";

                            if (tipo_estudio[indice] == "DIABETOLOGIA"){
                                if (diagnostico[indice] == "BUENO") {
                                    cout << reclGlucosa[0] << endl;
                                } else if (diagnostico[indice] == "REGULAR") {
                                    cout << reclGlucosa[1] << endl;
                                } else {
                                    cout << reclGlucosa[2] << endl;
                                }

                            } else if (tipo_estudio[indice] == "CARDIOLOGIA") {
                                if (diagnostico[indice] == "BUENO") {
                                    cout << recColesterol[0] << endl;
                                } else if (diagnostico[indice] == "REGULAR") {
                                    cout << recColesterol[1] << endl;
                                } else {
                                    cout << recColesterol[2] << endl;
                                }

                            } else {
                                if (diagnostico[indice] == "BUENO") {
                                    cout << recNutricion[0] << endl;
                                } else if (diagnostico[indice] == "REGULAR") {
                                    cout << recNutricion[1] << endl;
                                } else {
                                    cout << recNutricion[2] << endl;
                                }
                            }

                            // LOGICA DE RECOMENDACION DE DOCTOR
                            cout << "\nDOCTORES RECOMENDADOS" << endl;
                            bool doctor_encontrado = false;
                            for (int d = 0; d < contador2; d++) {

                                if (especialidad_doctores[d] == tipo_estudio[indice]) {
                                    cout << "- Dr. " << doctores[d] << endl;
                                    doctor_encontrado = true;
                                }

                            }
                            if (!doctor_encontrado) {
                                cout << "Actualmente no tenemos especialistas " << tipo_estudio[indice] << " registrados" << endl;
                            }
                            cout << endl;

                        } else {
                            cout << "SU NUMERO DE REGISTRO NO COINCIDE O NO EXISTE" << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "\nREPORTE DE MIS REGISTROS\n";
                        bool tiene_registros = false;
                        
                        for (int k = 0; k < contador; k++) {
                            if (pacientes[k] == nombre_usuario) {
                                cout << "Registro #" << (k + 1) << endl;
                                cout << "Estudio: " << tipo_estudio[k] << endl;
                                cout << "Diagnostico: " << diagnostico[k] << endl;
                                tiene_registros = true;
                            }
                        }
                        
                        if (!tiene_registros) {
                            cout << "No tienes ningun registro medico en el sistema todavia" << endl;
                        }
                        cout << endl;
                        break;
                    }
                }
            } while (opc != 3);
            cout << "SALIENDO DEL MENU USUARIO" << endl;
        } else {
            cout << "CONTRASENA O NOMBRE INCORRECTOS, ACCESO DENEGADO.\n";
        }
    } else {
        cout << "OPCION NO VALIDA, VUELVA A INICIAR EL PROGRAMA\n";
    }

        cout << "\nDesea volver a iniciar sesion? (S/N): ";
        cin >> repetir_programa;
        cout << "\n\n";

    } while (repetir_programa == 'S' || repetir_programa == 's');

    cout << "Saliendo del programa, Gracias por ingresar :)" << endl;

    return 0;
}