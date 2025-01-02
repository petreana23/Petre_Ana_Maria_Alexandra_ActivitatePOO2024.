#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Carte {
private:
    int nrPagini;
    string titlu;
    string autor;
    bool formatPDF;
    const int anPublicatie;
    string genCarte;
    static int nrTotalCarti;
    char* editura;

public:
    // Constructor fără parametri
    Carte() : anPublicatie(2010) {
        this->nrPagini = 460;
        this->titlu = "Arta Conversatiei";
        this->autor = "Ileana Vulpescu";
        this->genCarte = "roman psihologic";
        this->formatPDF = true;
        this->editura = new char[strlen("Tempus") + 1];
        strcpy(this->editura, "Tempus");
        nrTotalCarti++;
    }

    // Constructor cu parametri
    Carte(int nrPagini, string titlu, string autor, string genCarte, int an, bool formatPDF, const char* editura) : anPublicatie(an) {
        this->nrPagini = nrPagini;
        this->titlu = titlu;
        this->autor = autor;
        this->genCarte = genCarte;
        this->formatPDF = formatPDF;
        this->editura = new char[strlen(editura) + 1];
        strcpy(this->editura, editura);
        nrTotalCarti++;
    }

    // Constructor de copiere
    Carte(const Carte& c) : anPublicatie(c.anPublicatie) {
        this->nrPagini = c.nrPagini;
        this->titlu = c.titlu;
        this->autor = c.autor;
        this->genCarte = c.genCarte;
        this->formatPDF = c.formatPDF;
        this->editura = new char[strlen(c.editura) + 1];
        strcpy(this->editura, c.editura);
    }

    // Destructor
    ~Carte() {
        if (this->editura) {
            delete[] this->editura;
        }
    }

    // Getteri
    int getNrPagini() {
        return this->nrPagini;
    }
    string getTitlu() {
        return this->titlu;
    }
    string getAutor() {
        return this->autor;
    }
    bool getFormatPDF() {
        return this->formatPDF;
    }
    string getGenCarte() {
        return this->genCarte;
    }
    int getAnPublicatie() {
        return this->anPublicatie;
    }
    char* getEditura() {
        return this->editura;
    }

    // Setteri
    void setNrPagini(int nrPagini) {
        this->nrPagini = nrPagini;
    }
    void setFormatPDF(bool formatPDF) {
        this->formatPDF = formatPDF;
    }
    void setTitlu(string titlu) {
        this->titlu = titlu;
    }
    void setAutor(string autor) {
        this->autor = autor;
    }
    void setGenCarte(string genCarte) {
        this->genCarte = genCarte;
    }
    void setEditura(const char* editura) {
        if (this->editura) {
            delete[] this->editura;
        }
        this->editura = new char[strlen(editura) + 1];
        strcpy(this->editura, editura);
    }

    // Operatorul de atribuire
    Carte operator=(const Carte& c) {
        if (this != &c) {
            this->nrPagini = c.nrPagini;
            this->titlu = c.titlu;
            this->autor = c.autor;
            this->genCarte = c.genCarte;
            this->formatPDF = c.formatPDF;

            if (this->editura) {
                delete[] this->editura;
            }
            this->editura = new char[strlen(c.editura) + 1];
            strcpy(this->editura, c.editura);
        }
        return *this;
    }

    // Operator +
    Carte operator+(int paginiAdaugate) {
        Carte temp = *this;
        temp.nrPagini += paginiAdaugate;
        return temp;
    }

    // Operator ==
    bool operator==(const Carte& c) const {
        return this->titlu == c.titlu;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Carte& c) {
        out << "Titlu: " << c.titlu << ", Autor: " << c.autor
            << ", Nr. pagini: " << c.nrPagini << ", Gen: " << c.genCarte;
        return out;
    }


    // Metode statice
    static int getNrTotalCarti() { return nrTotalCarti; }

    // Metoda de afișare
    void afisare() const {
        cout << "Carte: " << titlu << ", Autor: " << autor << ", Nr pagini: " << nrPagini
            << ", Gen: " << genCarte << ", Format PDF: " << (formatPDF ? "Da" : "Nu")
            << ", Editura: " << editura << ", An publicatie: " << anPublicatie << endl;
    }
};

int Carte::nrTotalCarti = 0;

// Clasa Cititor
class Cititor {
private:
    char* adresa;
    string nume;
    int varsta;
    const string categorieCititor;
    int nrCartiImprumutate;
    string genPreferat;

public:
    // Constructor fără parametri
    Cititor() : categorieCititor("Liceeni") {
        this->nume = "AndreiIonescu";
        this->varsta = 18;
        this->nrCartiImprumutate = 0;
        this->genPreferat = "Fictiune";
        this->adresa = new char[strlen("Bucuresti") + 1];
        strcpy(this->adresa, "Bucuresti");
    }

    // Constructor cu parametri
    Cititor(string nume, int varsta, int nrCartiImprumutate, string genPreferat, const char* adresa, string categorie) : categorieCititor(categorie) {
        this->nume = nume;
        this->varsta = varsta;
        this->nrCartiImprumutate = nrCartiImprumutate;
        this->genPreferat = genPreferat;
        this->adresa = new char[strlen(adresa) + 1];
        strcpy(this->adresa, adresa);
    }

    // Constructor de copiere
    Cititor(const Cititor& c) : categorieCititor(c.categorieCititor) {
        this->nume = c.nume;
        this->varsta = c.varsta;
        this->nrCartiImprumutate = c.nrCartiImprumutate;
        this->genPreferat = c.genPreferat;
        this->adresa = new char[strlen(c.adresa) + 1];
        strcpy(this->adresa, c.adresa);
    }

    // Destructor
    ~Cititor() {
        if (this->adresa) {
            delete[] this->adresa;
        }
    }

    // Getteri
    int getVarsta() {
        return this->varsta;
    }
    string getNume() {
        return this->nume;
    }
    string getGenPreferat() {
        return this->genPreferat;
    }
    const string getCategorieCititor() {
        return this->categorieCititor;
    }
    int getNrCartiImprumutate() {
        return this->nrCartiImprumutate;
    }
    char* getAdresa() {
        return this->adresa;
    }

    // Setteri
    void setVarsta(int varsta) {
        this->varsta = varsta;
    }
    void setNume(string nume) {
        this->nume = nume;
    }
    void setGenPreferat(string genPreferat) {
        this->genPreferat = genPreferat;
    }
    void setNrCartiImprumutate(int NrCartiImprumutate) {
        this->nrCartiImprumutate = nrCartiImprumutate;
    }
    void setadresa(const char* adresa) {
        if (this->adresa) {
            delete[] this->adresa;
        }
        this->adresa = new char[strlen(adresa) + 1];
        strcpy(this->adresa, adresa);
    }

    // Operatorul de atribuire
    Cititor& operator=(const Cititor& c) {
        if (this != &c) {
            this->nume = c.nume;
            this->varsta = c.varsta;
            this->nrCartiImprumutate = c.nrCartiImprumutate;
            this->genPreferat = c.genPreferat;

            if (this->adresa) {
                delete[] this->adresa;
            }
            this->adresa = new char[strlen(c.adresa) + 1];
            strcpy(this->adresa, c.adresa);
        }
        return *this;
    }

    // Operator >
    bool operator>(const Cititor& c) const {
        return this->varsta > c.varsta;
    }

    // Operator +=
    Cititor& operator+=(int nrCarti) {
        this->nrCartiImprumutate += nrCarti;
        return *this;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Cititor& c) {
        out << "Nume: " << c.nume << ", Varsta: " << c.varsta
            << ", Nr. carti imprumutate: " << c.nrCartiImprumutate
            << ", Gen preferat: " << c.genPreferat;
        return out;
    }


    // Metoda de afișare
    void afisare() const {
        cout << "Cititor: " << nume << ", Varsta: " << varsta
            << ", Adresa: " << adresa << ", Gen preferat: " << genPreferat
            << ", Nr carti imprumutate: " << nrCartiImprumutate
            << ", Categorie: " << categorieCititor << endl;
    }
};

// Funcții globale
void imprumutaCarte(Carte& carte, Cititor& cititor) {
    cout << cititor.getNume() << " a imprumutat cartea: " << carte.getTitlu() << endl;
}

class Raft {
public:
    int capacitate;
    string material;
    int lungime; // măsurată în cm
    bool asezateGen; // indică dacă cărțile sunt așezate după gen
    string* titluriCarti;
    const int capacitateMaximaRaft; // capacitatea maximă a raftului
    static int inaltimeStandardRaft; // înălțimea standard a raftului în cm

    // Constructorul fără parametri
    Raft() : capacitateMaximaRaft(21) {
        this->capacitate = 17;
        this->lungime = 130;
        this->material = "LemnStejar";
        this->asezateGen = true;
        this->titluriCarti = NULL;
    }

    // Constructorul cu parametri
    Raft(int capacitate, string material, int lungime, bool asezateGen, int capMax) : capacitateMaximaRaft(capMax) {
        this->capacitate = capacitate;
        this->material = material;
        this->lungime = lungime;
        this->asezateGen = asezateGen;
        this->titluriCarti = new string[this->capacitate];
        for (int i = 0; i < this->capacitate; i++) {
            this->titluriCarti[i] = "CarteGenerica";
        }
    }

    // Constructorul de copiere
    Raft(const Raft& r) : capacitateMaximaRaft(r.capacitateMaximaRaft) {
        this->capacitate = r.capacitate;
        this->material = r.material;
        this->lungime = r.lungime;
        this->asezateGen = r.asezateGen;
        this->titluriCarti = new string[r.capacitate];
        for (int i = 0; i < r.capacitate; i++) {
            this->titluriCarti[i] = r.titluriCarti[i];
        }
    }

    // Destructor
    ~Raft() {
        if (this->titluriCarti) {
            delete[] this->titluriCarti;
        }
    }

    // Getteri
    int getCapacitate() {
        return this->capacitate;
    }
    string getMaterial() {
        return this->material;
    }
    int getLungime() {
        return this->lungime;
    }
    const int getCapacitateMaximaRaft() {
        return this->capacitateMaximaRaft;
    }
    bool getAsezateGen() {
        return this->asezateGen;
    }
    string* getTitluriCarti() {
        return this->titluriCarti;
    }

    // Setteri
    void setCapacitate(int capacitate) {
        this->capacitate = capacitate;
    }
    void setMaterial(string material) {
        this->material = material;
    }
    void setLungime(int lungime) {
        this->lungime = lungime;
    }
    void setAsezateGen(bool asezateGen) {
        this->asezateGen = asezateGen;
    }

    // Operatorul de atribuire
    Raft& operator=(const Raft& r) {
        if (this != &r) {
            this->capacitate = r.capacitate;
            this->material = r.material;
            this->lungime = r.lungime;
            this->asezateGen = r.asezateGen;

            if (this->titluriCarti) {
                delete[] this->titluriCarti;
            }
            this->titluriCarti = new string[r.capacitate];
            for (int i = 0; i < r.capacitate; i++) {
                this->titluriCarti[i] = r.titluriCarti[i];
            }
        }
        return *this;
    }

    // Operator []
    string& operator[](int index) {
        if (index < 0 || index >= capacitate) {
            throw out_of_range("Index invalid!");
        }
        return titluriCarti[index];
    }

    // Operator +
    Raft operator+(int nrCartiAdaugate) {
        Raft copie = *this;
        copie.capacitate += nrCartiAdaugate;
        return copie;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Raft& r) {
        out << "Material: " << r.material << ", Lungime: " << r.lungime
            << " cm, Capacitate: " << r.capacitate;
        return out;
    }


    // Metodă statică pentru înălțimea standard a raftului
    static int getInaltimeStandardRaft() {
        return Raft::inaltimeStandardRaft;
    }

    // Metodă de afișare
    void afisare() const {
        cout << "Capacitatea raftului: " << this->capacitate << endl;
        cout << "Materialul raftului: " << this->material << endl;
        cout << "Lungimea raftului: " << this->lungime << " cm" << endl;
        cout << "Cartile sunt asezate dupa gen?: " << (this->asezateGen ? "Da" : "Nu") << endl;
        cout << "Titluri de carti pe raft: ";
        if (titluriCarti != NULL) {
            for (int i = 0; i < capacitate; i++) {
                cout << titluriCarti[i] << (i < capacitate - 1 ? ", " : "\n");
            }
        }
        else {
            cout << "Nicio carte" << endl;
        }
        cout << "Capacitatea maxima a raftului: " << this->capacitateMaximaRaft << endl;
        cout << "Inaltimea standard a raftului: " << inaltimeStandardRaft << " cm" << endl;
    }
};

int Raft::inaltimeStandardRaft = 275;
bool poateImprumuta( Cititor& c,  Raft& r) {
    return c.getNrCartiImprumutate() < r.getCapacitate();
}


int main() {
    Carte c1;
    c1.afisare();
    cout << endl << endl;

    Cititor cititor1;
    cititor1.afisare();
    cout << endl << endl;

    imprumutaCarte(c1, cititor1); 
    cout << endl << endl;

    Raft raft1;
    raft1.afisare();
    cout << endl << endl;

    Raft raft2(10, "Metal", 150, false, 30);
    raft2.afisare();
    cout << endl << endl;

    Raft raft3 = raft2; // Constructor de copiere
    raft3.afisare();
    cout << endl << endl;

    cout << "Inaltimea standard a rafturilor: " << Raft::getInaltimeStandardRaft() << " cm" << endl;

    // Operatorii clasei Carte
    Carte c2(300, "Ion", "Liviu Rebreanu", "Roman", 1920, false, "Humanitas");
    c1 = c2; // Operator de atribuire
    cout << (c1 + 50) << endl;
    cout << (c1 == c2 ? "Cartile au acelasi titlu" : "Cartile au titluri diferite") << endl;
    cout << c1 << endl;
    cout << endl << endl;

    // Operatorii clasei Cititor
    cititor1 += 1; // Suprasarcină operator `+=`
    cout << (cititor1 > Cititor("Maria", 22, 1, "Drama", "Strada Libertatii", "Adulti")
        ? "Andrei este mai in varsta"
        : "Maria este mai in varsta") << endl;
    cout << cititor1 << endl;
    cout << endl << endl;

    // Operatorii clasei Raft
    raft1 = Raft(15, "Lemn", 180, true, 30);
    cout << raft1[2] << endl; 
    cout << (raft1 + 5) << endl;
    cout << raft1 << endl;
    cout << endl << endl;

    // Funcția prietenă
    cout << (poateImprumuta(cititor1, raft1) ? "Poate imprumuta" : "Nu poate imprumuta") << endl;

    return 0;
}


