#include<iostream>

using namespace std;
struct Masina {
	int nrUsi;
	bool esteElectrica;
	float capacitateMotor;
	string Model;
};

void afisareMasina(Masina masina) {
	cout << "Model:" << masina.Model << endl;
	cout << "Nr usi:" << masina.nrUsi << endl;
	cout << "Capacitate motor:" << masina.capacitateMotor << endl;
	cout << "Este electrica?" << (masina.esteElectrica == true ? "DA" : "NU") << endl;

}
void modificaNumarUsi(Masina* masina, int nrUsi) {
	masina->nrUsi = nrUsi;
 }

void modificaNrUsiRef(Masina& masina, int nrUsi) {
	masina.nrUsi = nrUsi;
}
 int main() {
	Masina masina;
	masina.nrUsi = 5;
	masina.esteElectrica = false;
	masina.capacitateMotor = 1.5;
	masina.Model = "Audi Q5";
	afisareMasina(masina);

	cout << "Model:" << masina.Model << endl;
	cout << "Nr usi:" << masina.nrUsi << endl;
	cout << "Este electrica?" << (masina.esteElectrica == true ? "Da" : "Nu") << endl;
	cout << "Capacitate motor" << masina.capacitateMotor << endl;

	Masina masina2;
	cout << "Introduceti modelul:";
	cin >> masina2.Model;

	cout << "Introduceti capacitatea motorului:";
	cin >> masina2.capacitateMotor;
	cout << "Introduceti nr de usi:";
	cin >> masina2.nrUsi;
	cout << "Masina este electrica?(1-DA;0-NU)";
	cin >> masina2.esteElectrica;
	afisareMasina(masina2);
	modificaNumarUsi(&masina2, 6);
	afisareMasina(masina2);
	modificaNrUsiRef(masina2, 8);

	return 0;
}