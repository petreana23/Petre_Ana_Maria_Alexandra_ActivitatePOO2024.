#include<iostream>

using namespace std;

class Cofetarie {
private:
	string nume; //
	int nrAngajati;//
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

public:
	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Iris";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}

	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}
	Cofetarie operator=(const Cofetarie& c) {
		if (&c != this) {
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
			this->esteVegana = c.esteVegana;
			this->adaos = c.adaos;
		}
		return *this;
	}

	~Cofetarie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	explicit operator int() {
		return this->nrAngajati;
	}

	explicit operator float() {
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s += this->salarii[i];
		}
		return s;
	}

	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Numar angajati:" << this->nrAngajati << endl;
		cout << "Dispune de produse vegane:" << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "Anul deschiderii:" << this->anDeschidere << endl;
		cout << "Adaos:" << this->adaos << endl;
		cout << "TVA:" << Cofetarie::TVA << endl;
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}
	}
	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}


	bool operator<(Cofetarie c) {
		return this->nrAngajati < c.nrAngajati;
	}

	

};
int Cofetarie::TVA = 9;

int main() {
	Cofetarie c;
	c.afisare();
	cout << endl << endl;
	Cofetarie c2("Alexis", 3, false, 2020, 10);
	c2.afisare();
	cout << endl << endl;

	int nrAngajati = (int)c2;
	float salariiTotale = (float)c2;


	if (c < c2) { 
		cout << "C1 este mai mic decat c2";
	}



}

