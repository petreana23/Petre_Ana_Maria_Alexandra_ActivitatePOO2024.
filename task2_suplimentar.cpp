
#include<iostream>
using namespace std;



	class Carte {
	public:
		int nrPagini;
		string titlu;
		string autor;
		bool formatPDF;
		const int anPublicatie;
		string genCarte;
		static int nrTotalCarti;
		char* editura;

		//constructor fara parametri
		Carte() :anPublicatie(2010) {
			this->nrPagini = 460;
			this->titlu = "Arta Conversatiei";
			this->autor = "Ileana Vulpescu";
			this->genCarte = "roman psihologic";
			this->nrTotalCarti = nrTotalCarti ;
			this->editura = NULL;
			this->formatPDF = false;

			cout << endl << endl << endl;
		}

		//constructor cu parametri
		Carte(int nrPagini, string titlu, string autor, string genCarte, int an, bool formatPDF) :anPublicatie(an) {
			this->titlu = titlu;
			this->genCarte = genCarte;
			this->autor = autor;
			this->nrPagini = nrPagini;
			this->formatPDF = formatPDF;
			this->editura = new char[strlen("Humanitas") + 1];
			strcpy_s(this->editura, strlen("Humanitas") + 1, "Humanitas");

		}

		//constructor de copiere
		Carte(const Carte &c):anPublicatie(c.anPublicatie) {
			this->titlu = c.titlu;
			this->genCarte = c.genCarte;
			this->autor = c.autor;
			this->nrPagini = c.nrPagini;
			this->formatPDF = c.formatPDF;
			this->editura = new char[strlen(c.editura) + 1];
			strcpy_s(this->editura, strlen(c.editura)+1, c.editura);
		}
		
		static int getnrTotalCarti() {
			return Carte::nrTotalCarti;
		}
		void afisare() {
			cout << "Carte: " << this->titlu << endl;
			cout << " Numar pagini: " << this->nrPagini << endl;
			cout << "Genul cartii: " << this->genCarte << endl;
			cout << "Autorul: " << this->autor << endl;
			cout << "Este in format PDF?" << this->formatPDF << endl;
			cout << "Editura:" << this->editura << endl;
			cout << "Numarul total de carti din biblioteca:" << this->nrTotalCarti << endl;
			cout << "Anul publicarii cartii:" << this->anPublicatie << endl;

		}

	};
	int Carte::nrTotalCarti = 2;

	class Cititor {
	public:
		char* adresa;
		string nume;
		int varsta;
		const string categorieCititor;
		int nrCartiImprumutate;
		string genPreferat;
		static int nrMaxCartiImprumutate;
		
		//constructor fara parametri
		Cititor() :categorieCititor("Liceeni") {
			this->nume = "Mihai";
			this->varsta = 15;
			this->adresa = NULL;
			this->genPreferat = "SF";
			this->nrCartiImprumutate = 2;
		}

		//constructor cu parametri
		Cititor(string nume, int varsta, int nrCartiImprumutate, string genPreferat, string categorie) :categorieCititor(categorie) {
			this->nume = nume;
			this->varsta = varsta;
			this->nrCartiImprumutate = nrCartiImprumutate;
			this->genPreferat = genPreferat;
			this->adresa = new char[strlen("Bucuresti") + 1];
			strcpy_s(this->adresa, strlen("Bucuresti") + 1, "Bucuresti");
		}

		//constructor de copiere
		Cititor(const Cititor& c1):categorieCititor(c1.categorieCititor) {
			this->nume = c1.nume;
			this->varsta = c1.varsta;
			this->nrCartiImprumutate = c1.nrCartiImprumutate;
			this->genPreferat = c1.genPreferat;
			this->adresa = new char[strlen(c1.adresa) + 1];
			strcpy_s(this->adresa, strlen(c1.adresa)+1, c1.adresa);
		}
		
		void afisare() {
			cout << "Adresa cititorului: " << this->adresa << endl;
			cout << " Numele cititorului: " << this->nume << endl;
			cout << "Varsta cititorului: " << this->varsta << endl;
			cout << "Categoria in care se incadreaza cititorul: " << this->categorieCititor << endl;
			cout << "Nr cartilor imprumutate in prezent:" << this->nrCartiImprumutate << endl;
			cout << "Genul preferat:" << this->genPreferat << endl;
			cout << "Nr maxim de carti ce pot fi imprumutate:" << this->nrMaxCartiImprumutate << endl;

		}

	};
	int Cititor::nrMaxCartiImprumutate = 5;
	

	class Raft {
	public:
		int capacitate;
		string material;
		int lungime; //masurata in cm
		bool asezateGen;
		string* titluriCarti;
		const int capacitateMaximaRaft; 
		static int inaltimeStandardRaft; //masurat in cm; inaltimea bibliotecii in care se afla raftul

		//constructorul fara parametri
		Raft() :capacitateMaximaRaft(21) {
			this->capacitate = 17;
			this->lungime = 130;
			this->material = "LemnStejar";
			this->asezateGen = true;
			this->titluriCarti = NULL;
		}

		//constructorul cu parametri
		Raft(int capacitate, string material, int lungime, bool asezateGen, int capMax) :capacitateMaximaRaft(capMax) {
			this->capacitate = capacitate;
			this->material = material;
			this->lungime = lungime;
			this->asezateGen = asezateGen;
			this->titluriCarti = new string[this->capacitate];
			for (int i = 0; i < this->capacitate; i++) {
				this->titluriCarti[i] = "Iona";
			}

		}

		//constructorul de copiere
		Raft(const Raft& r) :capacitateMaximaRaft(r.capacitateMaximaRaft) {
			this->capacitate = r.capacitate;
			this->material = r.material;
			this->lungime = r.lungime;
			this->asezateGen = r.asezateGen;
			this->titluriCarti = new string[r.capacitate];
			for (int i = 0; i < r.capacitate; i++) {
				this->titluriCarti[i]=r.capacitate;
			}
		}
		static int getinaltimeStandardRaft() {
			return Raft::inaltimeStandardRaft;
		}
		void afisare() {
			cout << "Capacitatea raftului: " << this->capacitate << endl;
			cout << " Materialul din care este creat raftul: " << this->material << endl;
			cout << "Lungimea raftului: " << this->lungime << endl;
			cout << "Cartile sunt asezate dupa gen?: " << this->asezateGen << endl;
			cout << "Titluri de carti de pe raft:" << this->titluriCarti << endl;
			cout << "Cate carti incap maxim pe raft?:" << this->capacitateMaximaRaft << endl;
			cout << "Care este inaltimea standard?:" << this->inaltimeStandardRaft << endl;

		}

	};

	int Raft::inaltimeStandardRaft = 275;

	int main() {
		cout << "Constructorii fara parametri pentru cele trei clase:" << endl;
		Carte c;
		c.afisare();
		Cititor c1;
		c1.afisare();
		Raft r;
		r.afisare();
		cout << endl << endl << endl;

		cout << "Constructorii cu parametri pentru cele trei clase:" << endl;
		Carte c2(200, "Amintiri din copilarie", "Ion Creanga", "educational", 1940, true);
		c2.afisare();
		Cititor c3("Ionescu Mihai", 15, 3, "Aventura", "liceu");
		c3.afisare();
		Raft r1(23, "Stejar", 60, true, 25);
		r1.afisare();
		
		return 0;

	}




