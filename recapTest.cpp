#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class TrotinetaElectrica {
private:	string model;
			float nivelBaterie;
			const float consumPerKm;
			float* kmPerSesiuneInchiriere;
			int nrSesiuniInchiriere;
			static int NIVEL_MAXIM_BATERIE;

			//constructorul implicit
public: TrotinetaElectrica() :consumPerKm(0) {
				this->model = "Bolt";
				this->nivelBaterie = 50;
				this->kmPerSesiuneInchiriere = NULL;
				this->nrSesiuniInchiriere = 3;
				cout << "Constructorul implicit apelat!\n";
			}

			string getmodel() {
				return this->model;
			}
			int getnrSesiuniInchiriere() {
				return this->nrSesiuniInchiriere;
			}
			float getnivelBaterie() {
				return this->nivelBaterie;
			}

			//constructor cu parametri
			TrotinetaElectrica(string model, float nivelBaterie, int nrSesiuniInchiriere, float consum) :consumPerKm(consum) {
				this->model = model;
				this->nivelBaterie = nivelBaterie;
				this->kmPerSesiuneInchiriere = new float[consumPerKm];
				for (int i = 0; i < consumPerKm; i++) {
					this->kmPerSesiuneInchiriere[i] = consumPerKm;
				}
				this->nrSesiuniInchiriere = nrSesiuniInchiriere;
			}

			//destructor
			~TrotinetaElectrica() {
				if (this->kmPerSesiuneInchiriere) {
					delete[]this->kmPerSesiuneInchiriere;
				}
			}

			//constructor de copiere 

			TrotinetaElectrica(const TrotinetaElectrica &t):consumPerKm(t.consumPerKm){
				this->model = t.model;
				this->nivelBaterie = t.nivelBaterie;
				this->kmPerSesiuneInchiriere = new float[consumPerKm];
				for (int i = 0; i < consumPerKm; i++) {
					this->kmPerSesiuneInchiriere[i] = t.consumPerKm;
				}
				this->nrSesiuniInchiriere = t.nrSesiuniInchiriere;
			}

			//operatorul = (de atribuire)
			TrotinetaElectrica operator=(const TrotinetaElectrica& t) {
				if (this != &t) {
					this->model = t.model;
					this->nivelBaterie = t.nivelBaterie;
					if (this->kmPerSesiuneInchiriere) {
						delete[]this->kmPerSesiuneInchiriere;
					}
					this->kmPerSesiuneInchiriere = new float[consumPerKm];
					for (int i = 0; i < consumPerKm; i++) {
						this->kmPerSesiuneInchiriere[i] = t.consumPerKm;
					}
					this->nrSesiuniInchiriere = t.nrSesiuniInchiriere;
				}
				return *this;
			}


			void afisare();
			

};
int TrotinetaElectrica::NIVEL_MAXIM_BATERIE = 100;

void TrotinetaElectrica::afisare() {
	cout << "Model:" << this->model << endl;
	cout << "Nivel Baterie: " << this->nivelBaterie << endl;
	cout << "Consum per Km:" << this->consumPerKm << endl;
	cout << "Km Per Sesiuni Inchiriere:" << this->kmPerSesiuneInchiriere << endl;
	cout << "Numar sesiuni inchiriere:" << this->nrSesiuniInchiriere << endl;
	cout << "Nivel maxim baterie:" << TrotinetaElectrica::NIVEL_MAXIM_BATERIE << endl;
}

int main() {
	TrotinetaElectrica t;
	t.afisare();
	cout << endl << endl;
	TrotinetaElectrica t1("Bolt", 50, 5, 7.5); // Constructorul cu parametri
	t1.afisare();
	cout << endl << endl << endl;
	TrotinetaElectrica t2 = t1;
	t2.afisare();

	cout << endl << endl << endl;
	TrotinetaElectrica t3;
	t3 = t1;
	t2.afisare();
	cout << t1.getmodel() << endl;
	cout << t1.getnrSesiuniInchiriere() << endl;
	cout << t1.getnivelBaterie() << endl;
	



}

