#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Vapor{
private: 
	static int nrVapoare;
	int capacitate;
	int nrPersoaneImbarcate;
	int* varstaPasageri;
	int nrVesteSalvare;
	int nrBarciSalvare;

public: Vapor() {
	this->capacitate = 3000;
	this->nrPersoaneImbarcate = 2900;
	this->varstaPasageri = NULL;
	this->nrVesteSalvare = 2800;
	this->nrBarciSalvare = 1500;

	
}

	  //getter -> metode de acces/ functii cu ajutorul carora putem extrage valoarea unui atribut din clasa
	  /*
	  tipDeDataAtribut getNumeAtribut(){
	  return this->numeAtribut;
	  }
	  */

	  int getnrVesteSalvare() {
		  return this->nrVesteSalvare;
	  }

	  int getnrBarciSalvare() {
		  return this->nrBarciSalvare;
	 }

	  int getcapacitate() {
		  return this->capacitate;
	  }

	  //functiile statice si friend nu primesc pointerul this 
	  static int getnrVapoare() {
		  return Vapor::nrVapoare;
	  }

	 // tipul de data la setteri este intotdeauna VOID, deoarece doar modifica valoarea, nu returneaza nimic
	  // nu putem face setteri pentru atribute constante si/sau statice
	  //la pointeri intai dezalocam in setteri si apoi alocam iar memorie

	  /*
	  void setNumeAtribut ( tipAtribut numeAtribut) {
	    this->numeAtribut = numeAtribut;
		}
	  */

	  void setnrVesteSalvare(int nrVesteSalvare) {
		  this->nrVesteSalvare = nrVesteSalvare;
	  }

	  void setnrBarciSalvare(int nrBarciSalvare) {
		  this->nrBarciSalvare = nrBarciSalvare;
	  }

	  void setcapacitate(int capacitate) {
		  this->capacitate = capacitate;
	  }

	  //Constructorul cu parametri
	  Vapor(int capacitate, int nrPersoaneImbarcate, int* varstaPasageri, int nrVesteSalvare, int nrBarciSalvare) {
		  this->capacitate = capacitate;
		  this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		  this->varstaPasageri = new int[nrPersoaneImbarcate];
		  for (int i=0; i < nrPersoaneImbarcate; i++) {
			  this->varstaPasageri[i] = varstaPasageri[i];
		  }
		  this->nrVesteSalvare = nrVesteSalvare;
		  this->nrBarciSalvare = nrBarciSalvare;
	  }

	  //constructorul de copiere 
	  // -se apeleaza atunci cand vrem sa creem un obiect nou pe baza altuia deja existent

	  Vapor(const Vapor& v) {
		  this->capacitate = v.capacitate;
		  this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
		  this->varstaPasageri = new int[nrPersoaneImbarcate];
		  for (int i = 0; i < nrPersoaneImbarcate; i++) {
			  this->varstaPasageri[i] = v.varstaPasageri[i];
		  }
		  this->nrVesteSalvare = v.nrVesteSalvare;
		  this->nrBarciSalvare = v.nrBarciSalvare;
	  }

	  //Destructor
	  ~Vapor() {
		  if (this->varstaPasageri != NULL) {
			  delete[]this->varstaPasageri;
		  }
		  cout << "S-a apelat destructorul" << endl;

	  }

	  // operatorul= -> se apeleaza intre doua obiecte deja existente
	  // operatorul = se compune din ceea ce am scris in destructor + ceea ce am scris in 
	  // constructorul de copiere + return *this
	  Vapor& operator=(const Vapor& v) {
		  if (this != &v) {
			  if (this->varstaPasageri != NULL) {
				  delete[]this->varstaPasageri;
			  }
			  this->capacitate = v.capacitate;
			  this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
			  this->varstaPasageri = new int[nrPersoaneImbarcate];
			  for (int i = 0; i < nrPersoaneImbarcate; i++) {
				  this->varstaPasageri[i] = v.varstaPasageri[i];
			  }
			  this->nrVesteSalvare = v.nrVesteSalvare;
			  this->nrBarciSalvare = v.nrBarciSalvare;
		  }
		  return *this;
	  }

	  //calculare varsta medie

	  int sumaVarstelor() {
		  int suma = 0;
		  for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
			  suma += this->varstaPasageri[i];
		  }
		  return suma;
	  }

	  int medieVarsta() {
		  return this->sumaVarstelor() / this->nrPersoaneImbarcate;
	  }
	  friend ostream& operator<<(ostream& out, const Vapor& v) {
		  out << v.capacitate << endl;
		  out << v.nrBarciSalvare << endl;
		  out << v.nrPersoaneImbarcate << endl;
		  out << v.nrVapoare << endl;
		  out << v.nrVesteSalvare << endl;
		  out << v.varstaPasageri << endl;
		  return out;
	  }
};
	int Vapor::nrVapoare = 2;
	int main() {
		Vapor v;
		cout << "Getteri" << endl;
		cout << v.getnrVesteSalvare() << endl;
		cout << v.getnrBarciSalvare() << endl;
		cout << v.getcapacitate() << endl;
		cout << v.getnrVapoare() << endl;

		v.setnrVesteSalvare(3000);
		v.setnrBarciSalvare(1600);
		v.setcapacitate(3100);
		cout << endl << endl;

		int varstaPas[] = { 26, 30, 45, 22, 29 };
		int nrPersoane = sizeof(varstaPas) / sizeof(varstaPas[0]);
		Vapor v1(3000, nrPersoane, varstaPas, 3000, 1700);
		cout << v1.getnrVesteSalvare() << endl;
		cout << v1.getnrBarciSalvare() << endl;
		cout << v1.getcapacitate() << endl;
		cout << v1.getnrVapoare() << endl;
		cout << endl << endl;

		Vapor v2 = v;
		cout << v2.getnrVesteSalvare() << endl;
		cout << v2.getnrBarciSalvare() << endl;
		cout << v2.getcapacitate() << endl;
		cout << v2.getnrVapoare() << endl;
		cout << endl << endl;

		v2 = v1;
		cout << v2.getnrVesteSalvare() << endl;
		cout << v2.getnrBarciSalvare() << endl;
		cout << v2.getcapacitate() << endl;
		cout << v2.getnrVapoare() << endl;
		cout << endl << endl << endl;

		cout << "Suma varste pasageri:" << v2.sumaVarstelor() << endl;
		cout << "Media varstelor:" << v2.medieVarsta() << endl;
		cout << v << endl;
	}