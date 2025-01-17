#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include <vector>
using namespace std;

// Clasă abstractă ItemBiblioteca
class ItemBiblioteca {
protected:
    string titlu;
    int anPublicatie;
    float valoare;

public:
    ItemBiblioteca(string Newtitlu = "Item Biblioteca", int anPublicatie = 2022, float Newvaloare = 50) {
        titlu = Newtitlu;
        anPublicatie = anPublicatie;
        valoare = Newvaloare;
   }

    // Funcții virtuale pure
    virtual void Afiseaza() = 0;
    virtual float CalculeazaValoare() = 0;

    virtual string getItemBiblioteca() {
        return "Item Biblioteca";
    }

    string getTitlu() {
        return titlu;
    }

    int getAnPublicatie() {
        return anPublicatie;
    }

    void setTitlu(string titluNou) {
        titlu = titluNou;
    }

    void setAnPublicatie(int anPublicatieNou) {
        anPublicatie = anPublicatieNou;
    }
};

class Carte : public ItemBiblioteca {
private:
    string autor;
    int nrPagini;

public:
    Carte() : ItemBiblioteca(), autor("Necunoscut"), nrPagini(100) {}

    Carte(string titlu, int anPublicatie, float valoare, string autor, int nrPagini)
        : ItemBiblioteca(titlu, anPublicatie, valoare), autor(autor), nrPagini(nrPagini) {}

    Carte(const Carte& carte)
        : ItemBiblioteca(carte), autor(carte.autor), nrPagini(carte.nrPagini) {}

    void Afiseaza() override {
        cout << "Carte: " << titlu << endl;
        cout << "Autor: " << autor << endl;
        cout << "An publicare: " << anPublicatie << endl;
        cout << "Valoare: " << valoare << endl;
        cout << "Nr. pagini: " << nrPagini << endl;
    }

    float CalculeazaValoare() override {
        return valoare + 0.1f * nrPagini;
    }
};

// Clasă abstractă Persoana
class Persoana {
protected:
    string nume;
    int varsta;

public:
    Persoana(string Newnume = "Persoane", int newvarsta = 40) {
        nume = Newnume;
        varsta = newvarsta;
   }

    virtual void AfiseazaDetalii() = 0;
    virtual string Persoane() {
        return "Persoane:";
    }
};

class Cititor : public Persoana {
private:
    vector<ItemBiblioteca*> imprumuturi;

public:
    Cititor() : Persoana() {}

    Cititor(string nume, int varsta) : Persoana(nume, varsta) {}

    Cititor(const Cititor& cititor) : Persoana(cititor) {
        for (auto item : cititor.imprumuturi) {
            imprumuturi.push_back(item);
        }
    }

    void imprumutaItem(ItemBiblioteca* item) {
        imprumuturi.push_back(item);
    }

    void AfiseazaDetalii() override {
        cout << "Cititor: " << nume << ", Varsta: " << varsta << endl;
        cout << "Imprumuturi:" << endl;
        for (auto item : imprumuturi) {
            item->Afiseaza();
        }
    }
};

class Biblioteca {
private:
    vector<ItemBiblioteca*> colectie;

public:
    Biblioteca() {}

    Biblioteca(const Biblioteca& biblioteca) {
        for (auto item : biblioteca.colectie) {
            colectie.push_back(item);
        }
    }

    void AdaugaItem(ItemBiblioteca* item) {
        colectie.push_back(item);
    }

    void AfiseazaColectie() {
        for (auto item : colectie) {
            item->Afiseaza();
        }
    }

    ~Biblioteca() {
        for (auto item : colectie) {
            delete item;
        }
    }
};


int main() {
    Biblioteca biblioteca;
    biblioteca.AdaugaItem(new Carte("C++ Programming", 2020, 50, "Bjarne Stroustrup", 500));
    biblioteca.AdaugaItem(new Carte("Artificial Intelligence", 2019, 60, "Stuart Russell", 400));

    Cititor cititor("Ion Popescu", 25);
    cititor.imprumutaItem(new Carte("Learn Python", 2021, 45, "Mark Lutz", 300));

    cout << "Colectia Bibliotecii:" << endl;
    biblioteca.AfiseazaColectie();

    cout << "\nDetalii Cititor:" << endl;
    cititor.AfiseazaDetalii();

    return 0;
}
