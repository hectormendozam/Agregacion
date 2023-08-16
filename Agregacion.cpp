/**
PROGRAMA QUE ILUSTRA EL CONCEPTO DE "AGREGACIÓN"
*/
#include <iostream>
using namespace std;
/// Clase Estudiante
class Estudiante {
private:
	string nombre;
	int matricula;
	string facultad;
public:
	Estudiante() {
		nombre = facultad = ""; matricula = 0;
	};
	Estudiante(string nombre, int matricula, string facultad) {
		this->nombre = nombre;
		this->matricula = matricula;
		this->facultad = facultad;
	};
	string getNombre() { return nombre; };
	int getMatricula() { return matricula; };
	string getfacultad() { return facultad; };
};

/** La clase Facultad contiene una lista de objetos
de la clase Estudiante. Esta clase está "asociada"
con la clase Estudiante a través de su(s) objeto(s). **/
class Facultad {
private:
	string nombre;
	int noEstudiantes;
	Estudiante* estudiantes;
public:
	Facultad() {
		nombre = "";
		estudiantes = NULL;
	};
	Facultad(string nombre, Estudiante* estudiantes, int noEstudiantes) {
		this->nombre = nombre;
		this->noEstudiantes = noEstudiantes;
		this->estudiantes = estudiantes;
	};
	string getNombre() { return nombre; };
	int getNoEstudiantes() { return noEstudiantes; };
	Estudiante* getEstudiantes() { return estudiantes; };

};

/** La clase Universidad contiene una lista de objetos
de la clase Facultad. Esta clase está "asociada"
con la clase Facultad a través de su(s) objeto(s).*/
class Universidad {
private:
	string nombre;
	int noFacultades;
	Facultad* facultades;
public:
	Universidad() {
		nombre = "";
		facultades = NULL;
	};
	Universidad(string nombre, Facultad* facultades, int noFacultades) {
		this->nombre = nombre;
		this->noFacultades = noFacultades;
		this->facultades = facultades;
	}
	string getNombre() { return nombre; };
	int getnoFacultades() { return noFacultades; };
	Facultad* getFacultades() { return facultades; };
	int getTotalEstudiantesUniversidad();

};

/** Se cuenta el Total de estudiantes de todas las facultades
en determinada universidad */
int Universidad::getTotalEstudiantesUniversidad() {
	int noEstudiantes = 0;
	Estudiante* est;
	for (int i = 0; i < noFacultades; i++) {
		noEstudiantes += facultades[i].getNoEstudiantes();
		est = facultades[i].getEstudiantes();
		for (int j = 0; j < facultades[i].getNoEstudiantes(); j++) {
			cout << "Nombre: " << est[j].getNombre() << "\n";
			cout << "Matricula: " << est[j].getMatricula() << "\n";
			cout << "Facultad: " << est[j].getfacultad() << "\n";
		}
	}
	return noEstudiantes;
}

int main() {
	Estudiante* e1 = new Estudiante("Mia", 101, "FCC");
	Estudiante* e2 = new Estudiante("Melanie", 102, "FCC");
	Estudiante* e3 = new Estudiante("John", 103, "FCE");
	Estudiante* e4 = new Estudiante("Raul", 104, "FCE");

	/// Se crea la lista de estudiantes de la FCC
	Estudiante* fcc_students = new Estudiante[2];
	fcc_students[0] = *e1;
	fcc_students[1] = *e2;

	/// Se crea la lista de estudiantes de la FCE
	Estudiante* fce_students = new Estudiante[2];
	fce_students[0] = *e3;
	fce_students[1] = *e4;

	/// Se crean dos facultades y se les asignan sus listas de estudiantes
	Facultad* FCC = new Facultad("FCC", fcc_students, 2);
	Facultad* FCE = new Facultad("FCE", fce_students, 2);

	/// Se crea la lista de facultades para la BUAP
	Facultad* buap_facultades = new Facultad[2];
	buap_facultades[0] = *FCC;
	buap_facultades[1] = *FCE;

	/// Se crea la universidad BUAP con su lista de facultades
	Universidad* uni = new Universidad("BUAP", buap_facultades, 2);
	int Total = uni->getTotalEstudiantesUniversidad();
	cout << "\nTotal de estudiantes en la " << uni->getNombre() << ": " << Total;
	return 0;
}
