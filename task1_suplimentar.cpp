#include <iostream>
using namespace std;

struct Bloc {
    string strada;
    int nrScari;
    int nrApartamente;
    int gradRisc;
    int anConstructie;
    bool areLift;
};

Bloc citireBloc() {
    Bloc b;
    cout << "Introduceti strada: ";cin >> b.strada; 
    cout << "Introduceti numarul de scari: "; cin >> b.nrScari;
    cout << "Introduceti numarul de apartamente: "; cin >> b.nrApartamente;
    cout << "Introduceti gradul de risc:"; cin >> b.gradRisc;
    cout << "Introduceti anul de constructie: "; cin >> b.anConstructie;
    cout << "Are lift (1-are; 0-nu are): "; cin >> b.areLift;
    cout << endl;
    return b;
}

void afisareBloc(Bloc b) {
    cout << "Blocul de pe strada " << b.strada << "(construit in anul " << b.anConstructie <<
        ",avand un grad de risc " << b.gradRisc << ")" <<" " << "are " << b.nrScari <<
        " scari, un numar total de " << b.nrApartamente << " apartamente" << " "<<"si" << " ";
    if (b.areLift)
        cout << "are lift.";
    else
        cout << "nu are lift.";
    cout << endl;
}

int main() {
    int nrBlocuri = 10;
    Bloc* blocuri;
    blocuri = new Bloc[nrBlocuri];

   
    for (int i = 0; i < nrBlocuri; i++) {
        cout << "Blocul " << i + 1 << ":" << endl;
        blocuri[i] = citireBloc();
        cout << endl;
    }

 
    for (int i = 0; i < nrBlocuri; i++) {
        cout << "Blocul " << i + 1 << ": ";
        afisareBloc(blocuri[i]);
        cout << endl;
    }
    delete[] blocuri;

    return 0;
}
