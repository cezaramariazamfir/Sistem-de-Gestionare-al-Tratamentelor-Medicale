#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Pentru setw()
using namespace std;

//-------------------------------------INTERFATA CITIRE/AFISARE-------------------------------------//
class IOInterface
{
public:
    virtual ostream &afisare(ostream &out) const = 0;
    virtual istream &citire(istream &in) = 0;
};

//----------------------------------------CLASA MEDICAMENT----------------------------------------//
class Medicament
{
private:
    string numeMedicament;
    float pretMedicament;
    string modDeAdministrare;

public:
    //GETTER
    string getNume() const {return this -> numeMedicament;}
    float getPret() const {return this -> pretMedicament;}
    //CONSTRUCTORUL FARA PARAM
    Medicament();
    //CONSTRUCTORUL CU TOTI PARAM
    Medicament(string numeMedicament, float pretMedicament, string modDeAdminsitrare);
    //CONSTRUCTORUL DE COPIERE
    Medicament(const Medicament &obj);
    //DESTRUCTORUL
    ~Medicament() = default;
    //OPERATORUL '='
    Medicament& operator=(const Medicament &obj);
    //OPERATORII '>>' SI '<<'
    friend istream &operator>>(istream &in, Medicament &obj);
    friend ostream &operator<<(ostream &out, Medicament &obj);
};

//CONSTRUCTORUL FARA PARAM
Medicament :: Medicament()
{
    numeMedicament ="unspecified";
    pretMedicament = 0;
    modDeAdministrare = "unspecified";
}
//CONSTRUCOTORUL CU TOTI PARAM
Medicament :: Medicament(string numeMedicament, float pretMedicament, string modDeAdminsitrare)
{
    this -> numeMedicament = numeMedicament;
    this -> pretMedicament = pretMedicament;
    this -> modDeAdministrare = modDeAdminsitrare;
}
//CONSTRUCTORUL DE COPIERE
Medicament :: Medicament(const Medicament &obj)
{
    this -> numeMedicament = obj.numeMedicament;
    this -> pretMedicament = obj.pretMedicament;
    this -> modDeAdministrare = obj.modDeAdministrare;
}
//OPERATORUL '='
Medicament& Medicament:: operator=(const Medicament &obj)
{
    if (this != &obj)
    {
        this->numeMedicament = obj.numeMedicament;
        this->pretMedicament = obj.pretMedicament;
        this -> modDeAdministrare = obj.modDeAdministrare;
    }
    return *this;
}
//OPERATORII '>>' SI '<<'
istream &operator>>(istream &in, Medicament &obj)
{
    cout << "Numele medicamentului: ";
    in >> obj.numeMedicament;
    cout << "Pretul medicamentuli: ";
    in >> obj.pretMedicament;
    cout << "Modul de administrare (oral, nazal, intravenos): ";
    in >> obj.modDeAdministrare;

    return in;
}
ostream &operator<<(ostream &out, Medicament &obj)
{
    cout << "Numele medicamentului: " << obj.numeMedicament << endl;
    cout << "Pretul medicamentului: " << obj.pretMedicament << endl;
    cout << "Modul de adminitrare: " << obj.modDeAdministrare;

    return out;
}


//----------------------------------------CLASA TRATAMENT----------------------------------------//
class Tratament : public IOInterface
{
protected:
    string numePacient;
    int varstaPacient;
    string diagnostic;
    bool asigurat;
public:
    //GETTER
    string getNume() const {return this -> numePacient;}
    string getDiagnostic() const {return this -> diagnostic;}
    bool getAsigurat() const {return this -> asigurat;}
    //SETTERS
    void setAsigurat(bool asigurat) { this -> asigurat = asigurat;}
    //CONSTRUCTORUL FARA PARAM
    Tratament();
    //CONSTRUCTORUL CU TOTI PARAM
    Tratament(string numePacient, int varstaPacient, string diagnostic, bool asigurat);
    //CONSTRUCTORUL DE COPIERE
    Tratament(const Tratament &obj);
    //OPERATORUL '='
    Tratament& operator=(const Tratament &obj);
    //DESTRUCTORUL
    ~Tratament() = default;
    //FUNCTIE CALCULARE PRET TRATAMENT
    virtual float CalcularePret() const = 0;
    //FUNCTIE AFISARE COST TRATAMENT (BREAKDOWN)
    virtual void breakdownPret() const = 0;
    //FUNCTIE TIP TRATAMENT
    virtual string tipTratament()  = 0;
    //OPERATORII '<<' SI '>>'
    friend ostream &operator<<(ostream &out, const Tratament &t);
    friend istream &operator>>(istream &in, Tratament &t);
    virtual ostream &afisare(ostream &out) const;
    virtual istream &citire(istream &in);
    //OPERATORUL '=='
    bool operator==(const Tratament &t);
};

//CONSTRUCTORUL FARA PARAM
Tratament :: Tratament()
{
    this -> numePacient = "unspecified";
    this -> varstaPacient = -1;
    this -> diagnostic = "undetermined";
    this -> asigurat = false;
}
//CONSTRUCTORUL CU TOTI PARAM
Tratament :: Tratament(string numePacient, int varstaPacient, string diagnostic, bool asigurat)
{
    this -> numePacient = numePacient;
    this -> varstaPacient = varstaPacient;
    this -> diagnostic = diagnostic;
    this -> asigurat = asigurat;
}
//CONSTRUCTORUL DE COPIERE
Tratament :: Tratament(const Tratament &obj)
{
    this -> numePacient = obj.numePacient;
    this -> varstaPacient = obj.varstaPacient;
    this -> diagnostic = obj.diagnostic;
    this -> asigurat = obj.asigurat;
}
//OPERATORUL '='
Tratament& Tratament :: operator=(const Tratament &obj)
{
    if (this != &obj)
    {
        this -> numePacient = obj.numePacient;
        this -> varstaPacient = obj.varstaPacient;
        this -> diagnostic = obj.diagnostic;
        this -> asigurat = obj.asigurat;
    }
    return *this;
}
//OPERATORII '<<' SI '>>'
ostream &operator<<(ostream &out, const Tratament &t)
{
    return t.afisare(out);
}
istream &operator>>(istream &in, Tratament &t)
{
    return t.citire(in);
}
//FUNCTIILE CITIRE SI AFISARE
ostream& Tratament :: afisare(ostream &out) const
{
    out << "Numele pacientului: " << this -> numePacient << endl;
    out << "Varsta pacientului: " << this -> varstaPacient << " ani" << endl;
    out << "Diagonsticul: " << this -> diagnostic << endl;
    out << "Asigurat: ";
    if (this->asigurat) out << "da" << endl;
    else out << "nu" << endl;

    return out;
}
istream& Tratament :: citire(istream &in)
{
    cout << "Introduceti numele pacientului: ";
    char nume[30];
    cin.get();
    cin.getline(nume, 30);
    this -> numePacient = nume;
    cout << "Introduceti varsta pacientului: ";
    in >> this -> varstaPacient;
    cout << "Introduceti diagonosticul: ";
    in >> this -> diagnostic;

    bool raspunsValid = false;
    while (raspunsValid == false)
    {
        cout << "Este pacientul asigurat? (da/nu).";
        string asigurat;
        in >> asigurat;

        if (asigurat == "da")
        {
            this->asigurat = true;
            raspunsValid = true;
            break;
        }
        else if (asigurat == "nu")
        {
            this->asigurat = false;
            raspunsValid = true;
            break;
        }
        else cout << "Va rog introduceti 'da' sau 'nu'";
    }
    return in;
}
//OPERATORUL '=='
bool Tratament :: operator==(const Tratament &t) { bool a = (this -> diagnostic == t.diagnostic); return a;}


//----------------------------------CLASA TRATAMENT MEDICAMENT0S----------------------------------//
class TratamentMedicamentos : virtual public Tratament
{
private:
    vector<Medicament> medicamente;

public:
    //CONSTRUCTORUL FARA PARAM
    TratamentMedicamentos();
    //CONSTRUCTORUL CU TOTI PARAM
    TratamentMedicamentos(string numePacient, int varstaPacient, string diagnostic, bool asigurat, vector<Medicament> medicamente);
    //CONSTRUCTORUL DE COPIERE
    TratamentMedicamentos(const TratamentMedicamentos &tm);
    //OPERATORUL '='
    TratamentMedicamentos& operator=(const TratamentMedicamentos &tm);
    //DESTRUCTORUL
    ~TratamentMedicamentos() = default;
    //FUNCTIILE CITIRE SI AFISARE
    ostream &afisare(ostream &out) const;
    istream &citire(istream &in);
    //FUNCTIE CALCULARE PRET TRATAMENT
    // asigurarea iti ofera 90% reducere la medicamente
    float CalcularePret() const;
    //FUNCTIE AFISARE BREAKDOWN COSTURI
    void breakdownPret() const;
    //FUNCTIE TIP TRATAMENT
    string tipTratament();
    //OPERATORUL '=='
    bool operator==(const TratamentMedicamentos &t);
};

//CONSTRUCTORUL FARA PARAM
TratamentMedicamentos ::  TratamentMedicamentos() : Tratament()
{
    medicamente = {};
}
//CONSTRUCTORUL CU TOTI PARAM
TratamentMedicamentos :: TratamentMedicamentos(string numePacient, int varstaPacient, string diagnostic, bool asigurat, vector<Medicament> medicamente)
                                                : Tratament(numePacient, varstaPacient, diagnostic, asigurat)
{
this -> medicamente = medicamente;
}
//CONSTRUCTORUL DE COPIERE
TratamentMedicamentos :: TratamentMedicamentos(const TratamentMedicamentos &tm) : Tratament(tm)
{
    this -> medicamente = tm.medicamente;
}
//OPERATORUL '='
TratamentMedicamentos& TratamentMedicamentos :: operator=(const TratamentMedicamentos &tm)
{
    if (this != &tm)
    {
        Tratament :: operator=(tm);
        this -> medicamente = tm.medicamente;
    }
    return *this;
}
//FUNCTIILE CITIRE SI AFISARE
ostream& TratamentMedicamentos :: afisare(ostream &out) const
{
    this -> Tratament :: afisare(out);
    cout << "Medicamentele prescrise: ";
    for (int i = 0; i < this->medicamente.size(); i++)
        out << this -> medicamente[i].getNume() << " ";
    cout << endl;
    return out;
}
istream& TratamentMedicamentos :: citire(istream &in)
{
    this -> Tratament :: citire(in);
    cout << "Introduceti medicamentele prescrise: " << endl;
    bool k = true;
    int comanda;
    while (k)
    {
        cout << endl << "Apasa 1 daca vrei sa adaugi un medicament" << endl;
        cout << "Apasa 2 daca ai terminat de adaugat medicamentele" << endl;
        in >> comanda;
        if (comanda == 1)
        {
            Medicament medicament;
            in >> medicament;
            this -> medicamente.push_back(medicament);
        }
        else
            k = false;
    }
    return in;
}
//FUNCTIE CALCULARE PRET TRATAMENT
// asigurarea iti ofera 90% reducere la medicamente
float TratamentMedicamentos :: CalcularePret() const
{
    float suma = 0;
    for (int i = 0; i < this->medicamente.size(); i++)
        suma += this->medicamente[i].getPret();

    if (this -> asigurat) return 0.1 * suma;
    else return suma;
}
//FUNCTIE AFISARE BREAKDOWN COSTURI
void TratamentMedicamentos :: breakdownPret() const
{
    cout << "MEDICAMENT          PRET" << endl;
    cout << "----------          ----" << endl;

    for (int i = 0; i < this->medicamente.size(); i++)
        cout << setw(19) << left << this->medicamente[i].getNume() << this->medicamente[i].getPret() << " RON"<< endl;
}
//FUNCTIE TIP TRATAMENT
string TratamentMedicamentos :: tipTratament()
{
    string s = "Medicamentos";
    return s;
}
//OPERATORUL '=='
bool TratamentMedicamentos :: operator==(const TratamentMedicamentos &t)
{
    bool a = Tratament ::operator==(t);
    return (a && this -> medicamente.size() == t.medicamente.size());
}


//----------------------------------CLASA TRATAMENT CHIRURGICAL----------------------------------//
class TratamentChirurgical : virtual public Tratament
{
protected:
    string nume_operatie;
    float cost_operatie;
    int nr_zile_spitalizare;
public:
    //CONSTRUCTORUL FARA PARAM
    TratamentChirurgical();
    //CONSTRUCTORUL CU TOTI PARAM
    TratamentChirurgical(string numePacient, int varstaPacient, string diagnostic, bool asigurat, string nume_operatie, float cost_operatie, int nr_zile_spitalizare);
    //CONSTRUCTORUL DE COPIERE
    TratamentChirurgical(const TratamentChirurgical &tc);
    //OPERATORUL "="
    TratamentChirurgical& operator=(const TratamentChirurgical &tc);
    //DESTRUCTORUL
    ~TratamentChirurgical() = default;
    //FUNCTIILE CITIRE SI AFISARE
    ostream &afisare(ostream &out) const;
    istream &citire(istream &in);
    //FUNCTIE CALCULARE PRET TRATAMENT
    //asigurarea iti acopera costul operatiei si iti ofera 50% reducere
    float CalcularePret() const;
    //FUNCTIE AFISARE BREAKDOWN COSTURI
    void breakdownPret() const;
    //FUNCTIE TIP TRATAMENT
    string tipTratament();
    //OPERATORUL '=='
    bool operator==(const TratamentChirurgical &t);
};
//CONSTRUCTORUL FARA PARAM
TratamentChirurgical :: TratamentChirurgical() : Tratament()
{
    this -> nume_operatie = "unspecified";
    this -> cost_operatie = 0;
    this -> nr_zile_spitalizare = 0;
}
//CONSTRUCTORUL CU TOTI PARAM
TratamentChirurgical :: TratamentChirurgical(string numePacient, int varstaPacient, string diagnostic, bool asigurat, string nume_operatie, float cost_operatie, int nr_zile_spitalizare)
                                            : Tratament(numePacient, varstaPacient, diagnostic, asigurat)
{
this -> nume_operatie = nume_operatie;
this -> cost_operatie = cost_operatie;
this -> nr_zile_spitalizare = nr_zile_spitalizare;
}
//CONSTRUCTORUL DE COPIERE
TratamentChirurgical :: TratamentChirurgical(const TratamentChirurgical &tc) : Tratament(tc)
{
    this -> nume_operatie = tc.nume_operatie;
    this -> cost_operatie = tc.cost_operatie;
    this -> nr_zile_spitalizare = tc.nr_zile_spitalizare;
}
//OPERATORUL "="
TratamentChirurgical& TratamentChirurgical :: operator=(const TratamentChirurgical &tc)
{
    if (this != &tc)
    {
        Tratament::operator=(tc);
        this->nume_operatie = tc.nume_operatie;
        this->cost_operatie = tc.cost_operatie;
        this -> nr_zile_spitalizare = tc.nr_zile_spitalizare;
    }
    return *this;
}
//FUNCTIILE CITIRE SI AFISARE
ostream& TratamentChirurgical :: afisare(ostream &out) const
{
    this -> Tratament :: afisare(out);
    cout << "Numele operatiei: " << this -> nume_operatie << endl;
    cout << "Costul operatiei: " << this -> cost_operatie << endl;
    cout << "Numarul zilelor de spitalizare: " << this -> nr_zile_spitalizare << endl;
    return out;
}
istream& TratamentChirurgical :: citire(istream &in)
{
    this -> Tratament :: citire(in);
    cout << "Introduceti numele operatiei: ";
    in >> this -> nume_operatie;
    cout << "Introduceti costul operatiei: ";
    in >> this -> cost_operatie;
    cout << "Introduceti numarul zilelor de spitalizare: ";
    in >> this -> nr_zile_spitalizare;
    return in;
}
//FUNCTIE CALCULARE PRET TRATAMENT
//asigurarea iti acopera costul operatiei si iti ofera 50% reducere
float TratamentChirurgical :: CalcularePret() const
{
    float suma = 0;
    if (this -> asigurat) suma += this -> nr_zile_spitalizare * 200 * 0.5;
    else suma += this -> nr_zile_spitalizare * 200 + this -> cost_operatie;
    return suma;
}
//FUNCTIE AFISARE BREAKDOWN COSTURI
void TratamentChirurgical :: breakdownPret() const
{
    cout << "SERVICIU          PRET" << endl;
    cout << "--------          ----" << endl;


    if (this -> asigurat)
    {
        cout << setw(19) << left << "Spitalizare" << this->nr_zile_spitalizare * 200 * 0.5 << "RON (50% reducere)" << endl;
        cout << setw(19) << left << "Operatie" << "0 RON (acoperit de asigurare)" << endl;
    }
    else
    {
        cout << setw(19) << left << "Spitalizare" << this->nr_zile_spitalizare * 200 << " RON" << endl;
        cout << setw(19) << left << "Operatie" << this -> cost_operatie << " RON" << endl ;
    }
}
//FUNCTIE TIP TRATAMENT
string TratamentChirurgical :: tipTratament()
{
    string s = "Chirurgical";
    return s;
}
//OPERATORUL '=='
bool TratamentChirurgical :: operator==(const TratamentChirurgical &t)
{
    bool a = Tratament ::operator==(t);
    return (a && this -> cost_operatie == t.cost_operatie);
}

//----------------------------------CLASA TRATAMENT HOLISTIC----------------------------------//
class TratamentHolistic : public TratamentMedicamentos, public TratamentChirurgical
{
private:
    int nr_ore_terapie;
public:
    //CONSTRUCTORUL FARA PARAM
    TratamentHolistic();
    //CONSTRUCTORUL CU TOTI PARAM
    TratamentHolistic(string numePacient, int varstaPacient, string diagnostic, bool asigurat, string nume_operatie, float cost_operatie, int nr_zile_spitalizare, vector<Medicament> medicamente, int nr_ore_terapie);
    //CONSTRUCTORUL DE COPIERE
    TratamentHolistic(const TratamentHolistic &th);
    //OPERATORUL '='
    TratamentHolistic& operator=(const TratamentHolistic &th);
    //DESTRUCTORUL
    ~TratamentHolistic() = default;
    //FUNCTIILE CITIRE SI AFISARE
    ostream &afisare(ostream &out) const;
    istream &citire(istream &in);
    //FUNCTIE CALCULARE PRET TRATAMENT
     float CalcularePret() const;
    //FUNCTIE AFISARE BREAKDOWN COSTURI
    void breakdownPret() const;
    //FUNCTIE TIP TRATAMENT
    string tipTratament();
    //OPERATORUL '=='
    bool operator==(const TratamentHolistic &t);
};

//CONSTRUCTORUL FARA PARAM
TratamentHolistic :: TratamentHolistic() : Tratament(), TratamentMedicamentos(), TratamentChirurgical()
{
    nr_ore_terapie = 0;
}


//CONSTRUCTORUL CU TOTI PARAM
TratamentHolistic :: TratamentHolistic(string numePacient, int varstaPacient, string diagnostic, bool asigurat, string nume_operatie, float cost_operatie, int nr_zile_spitalizare, vector<Medicament> medicamente, int nr_ore_terapie)
                                        :   Tratament(numePacient, varstaPacient, diagnostic, asigurat),
                                            TratamentMedicamentos(numePacient, varstaPacient, diagnostic, asigurat, medicamente),
                                            TratamentChirurgical(numePacient, varstaPacient, diagnostic, asigurat, nume_operatie, cost_operatie, nr_zile_spitalizare)
{
this -> nr_ore_terapie = nr_ore_terapie;
}
//CONSTRUCTORUL DE COPIERE
TratamentHolistic :: TratamentHolistic(const TratamentHolistic &th) : Tratament(th), TratamentMedicamentos(th), TratamentChirurgical(th)
{
    this -> nr_ore_terapie = th.nr_ore_terapie;
}
//OPERATORUL '='
TratamentHolistic& TratamentHolistic :: operator=(const TratamentHolistic &th)
{
    if (this != &th)
    {
        TratamentMedicamentos::operator=(th);
        this->nume_operatie = th.nume_operatie;
        this->cost_operatie = th.cost_operatie;
        this -> nr_zile_spitalizare = th.nr_zile_spitalizare;
        this -> nr_ore_terapie = th.nr_ore_terapie;
    }
    return *this;
}
//FUNCTIILE CITIRE SI AFISARE
ostream& TratamentHolistic :: afisare(ostream &out) const
{
    this -> TratamentMedicamentos :: afisare(out);
    cout << "Numele operatiei: " << this -> nume_operatie << endl;
    cout << "Costul operatiei: " << this -> cost_operatie << endl;
    cout << "Numarul zilelor de spitalizare: " << this -> nr_zile_spitalizare << endl;
    cout << "Numarul orelor de terapie: " << this -> nr_ore_terapie << endl;
    return out;
}
istream& TratamentHolistic :: citire(istream &in)
{
    this -> TratamentMedicamentos :: citire(in);
    cout << "Introduceti numele operatiei: ";
    in >> this -> nume_operatie;
    cout << "Introduceti costul operatiei: ";
    in >> this -> cost_operatie;
    cout << "Introduceti numarul zilelor de spitalizare: ";
    in >> this -> nr_zile_spitalizare;
    cout << "Introduceti numarul orelor de terapie: ";
    in >> this -> nr_ore_terapie;
    return in;
}
//FUNCTIE CALCULARE PRET TRATAMENT
float TratamentHolistic :: CalcularePret() const
{
    float suma = 0;
    suma += TratamentMedicamentos :: CalcularePret();
    suma += TratamentChirurgical :: CalcularePret();
    suma += this -> nr_ore_terapie * 100;
    return suma;
}
//FUNCTIE AFISARE BREAKDOWN COSTURI
void TratamentHolistic :: breakdownPret() const
{
    TratamentMedicamentos :: breakdownPret();
    cout << endl;
    TratamentChirurgical :: breakdownPret();
    cout << setw(19) << left << "Terapie" << this -> nr_ore_terapie * 100 << " RON" << endl ;
}
//FUNCTIE TIP TRATAMENT
string TratamentHolistic :: tipTratament()
{
    string s = "Holistic";
    return s;
}
//OPERATORUL '=='
bool TratamentHolistic :: operator==(const TratamentHolistic &t)
{
    bool a = TratamentMedicamentos :: operator==(t);// bool a = (*this == t)
    bool b = TratamentChirurgical ::operator==(t);
    return (a && b && this -> nr_ore_terapie == t.nr_ore_terapie);
}

//FUNCTIE AFISARE TIP TRATAMENT
void showTratament(Tratament *t)
{
    cout << "Tratamentul este: " << t -> tipTratament();
};

int main()
{
    vector<Medicament> medicamente;
    //Creez 1 obiect TratamentMedicamentos
    medicamente.push_back(Medicament("Paracetamol", 10.5, "Oral"));
    medicamente.push_back(Medicament("Oximetazolina", 15.75, "Nazal"));
    medicamente.push_back(Medicament("Amoxicilina", 30.25, "Oral"));
    TratamentMedicamentos t1 ("Ionescu Ana", 20, "Infectie respiratorie", false, medicamente);
    medicamente.pop_back();
    medicamente.pop_back();
    medicamente.pop_back();
    //Creez 1 obiect TratamentChirurgical
    TratamentChirurgical t2("Dumitran Luca", 16, "Apendicita", true, "Apendicectomie", 6500, 3);
    //Creez 1 obiect TratamentHolistic
    medicamente.push_back(Medicament("Imodium", 8.5, "Oral"));
    TratamentHolistic t3("Mocanu Vlad", 32, "Blocaj intestinal", false, "Colostomie", 7500, 7, medicamente, 14);
    medicamente.pop_back();

    //Fac un vector cu tratamentele create
    vector<Tratament *> v;
    v.push_back(&t1);
    v.push_back(&t2);
    v.push_back(&t3);


    //MENIU INTERACTIV
    int comanda;
    int k = 1;

    while (k == 1)
    {
        cout << "__________________________________________________" << endl;
        cout << "| SISTEM DE GESTIONARE AL TRATAMENTELOR MEDICALE |" << endl;
        cout << "|                                                |" << endl;
        cout << "|          APASA 1 DACA VREI SA CONTINUI.        |" << endl;
        cout << "|          APASA 2 DACA VREI SA IESI.            |" << endl;
        cout << "__________________________________________________" << endl;
        cout << endl << "Introdu comanda: ";
        cin >> comanda;
        cout << endl;

        switch(comanda)
        {
            case 1:
            {
                int l = 1;
                while(l == 1)
                {
                    cout << "__________________________________________________" << endl;
                    cout << "|          APASA 1 DACA ESTI DOCTOR.             |" << endl;
                    cout << "|          APASA 2 DACA ESTI PACIENT.            |" << endl;
                    cout << "|          APASA 3 DACA ESTI MANAGER.            |" << endl;
                    cout << "|          APASA 4 DACA VREI SA MERGI INAPOI.    |" << endl;
                    cout << "__________________________________________________" << endl;
                    int comanda2;
                    cout << endl << "Introdu comanda: ";
                    cin >> comanda2;
                    cout << endl;
                    switch(comanda2)
                    {
                        case 1:
                        {
                            int m = 1;
                            while (m == 1)
                            {
                                cout << "__________________________________________________" << endl;
                                cout << "|  APASA 1 DACA VREI SA VEZI TOATE TRATAMENTELE. |" << endl;
                                cout << "|  APASA 2 DACA VREI SA ADAUGI UN TRATAMENT.     |" << endl;
                                cout << "|  APASA 3 DACA VREI SA STERGI UN TRATAMENT.     |" << endl;
                                cout << "|  APASA 4 DACA VREI SA MERGI INAPOI.            |" << endl;
                                cout << "__________________________________________________" << endl;
                                int comanda3;
                                cout << endl << "Introdu comanda: ";
                                cin >> comanda3;
                                cout << endl;

                                switch(comanda3)
                                {
                                    case 1:
                                    {
                                        for (int i = 0; i < v.size(); i++)
                                        {
                                            cout << "TRATAMENT " << i + 1 << endl;
                                            cout << "-----------" << endl;
                                            cout << *v[i] << endl;
                                        }
                                        break;
                                    }
                                    case 2:
                                    {
                                        cout << endl << "ALEGE TIPUL TRATAMENTULUI" << endl;
                                        cout << "M - MEDICAMENTOS" << endl;
                                        cout << "C - CHIRURGICAL" << endl;
                                        cout << "H - HOLISTIC" << endl;
                                        cout << endl << "ALEGERE (M/C/H): ";
                                        char alegere;
                                        cin >> alegere;

                                        if(alegere == 'M')
                                        {
                                            TratamentMedicamentos* tm = new TratamentMedicamentos;
                                            cin >> *tm;
                                            v.push_back(tm);
                                        }
                                        else if(alegere == 'C')
                                        {
                                            TratamentChirurgical* tc = new TratamentChirurgical;
                                            cin >> *tc;
                                            v.push_back(tc);
                                        }
                                        else if(alegere == 'H')
                                        {
                                            TratamentHolistic* th = new TratamentHolistic;
                                            cin >> *th;
                                            v.push_back(th);
                                        }
                                        cout << endl << "TRATAMENT ADAUGAT CU SUCCES!" << endl;
                                        break;

                                    }
                                    case 3:
                                    {
                                        cout << endl << "Introduceti numele pacientului al carui tratament vreti sa-l stergeti: " << endl;
                                        char nume[30];
                                        bool found = false;
                                        cin.get();
                                        cin.getline(nume, 30);
                                        for (int i = 0; i < v.size(); i++)
                                        {
                                            if(nume == v[i] -> getNume())
                                            {
                                                v.erase(v.begin() + i);
                                                cout << "Tratamentul pacientului " << nume << " a fost sters cu success!" << endl;
                                                found = true;
                                             break;
                                           }
                                        }

                                        if (found == false) cout << endl << "Pacientul nu are niciun tratament asociat." << endl;
                                        break;
                                    }
                                    case 4:
                                    {
                                        m = 0;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            int n = 1;
                            cout << endl << "Introduceti numele dvs: " ;
                            char nume[30];
                            bool found = false;
                            cin.get();
                            cin.getline(nume, 30);
                            int index;
                            for (int i = 0; i < v.size(); i++)
                            {
                                if(nume == v[i] -> getNume())
                                {
                                    index = i;
                                    found = true;
                                    break;
                                }
                            }

                            if (found == false) {cout << endl << "Nu figurati in baza noastra de date." << endl << endl; break;}
                            while (n == 1)
                            {
                                cout << "__________________________________________________________" << endl;
                                cout << "| APASA 1 DACA VREI SA VEZI DIAGNOSTICUL SI TRATAMENTUL. |" << endl;
                                cout << "| APASA 2 DACA VREI SA VEZI BREAKDOWN-UL COSTURILOR.     |" << endl;
                                cout << "| APASA 3 DACA VREI SA SCHIMBI STATUSUL DE ASIGURAT.     |" << endl;
                                cout << "| APASA 4 DACA VREI SA MERGI INAPOI.                     |" << endl;
                                cout << "__________________________________________________________" << endl;
                                int comanda4;
                                cout << endl << "Introdu comanda: ";
                                cin >> comanda4;
                                cout << endl;

                                switch(comanda4)
                                {
                                    case 1:
                                    {

                                        cout << "Diagonsitcul este: " << v[index] -> getDiagnostic() << endl;
                                        showTratament(v[index]);
                                        cout << endl;
                                        break;
                                    }
                                    case 2:
                                    {
                                        v[index] -> breakdownPret();
                                        cout << endl << setw(19) << left << "PRET TOTAL" << v[index] -> CalcularePret() << " RON" << endl << endl;
                                        break;
                                    }
                                    case 3:
                                    {
                                        if (v[index] -> getAsigurat() == true) {cout << endl << "Sunteti deja asigurat." << endl; break;}
                                        else
                                        {
                                            cout << endl << "Nu sunteti asigurat. Vreti sa adaugati o asigurare? (da)" << endl;
                                            string asigurare;
                                            cin >> asigurare;
                                            if (asigurare == "da") {v[index] ->setAsigurat(true); cout << endl << "Felicitari! Sunteti asigurat!" << endl << endl;}
                                        }
                                        break;
                                    }
                                    case 4:
                                    {
                                        n = 0;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            int o = 1;
                            while (o == 1)
                            {
                                cout << "____________________________________________________" << endl;
                                cout << "| APASA 1 DACA VREI SA VEZI SUMA TOTALA CE TREBUIE |" << endl;
                                cout << "| DECONTATA DE CAS.                                |" << endl;
                                cout << "| APASA 2 DACA VREI SA MERGI INAPOI.               |" << endl;
                                cout << "____________________________________________________" << endl;
                                int comanda5;
                                cout << endl << "Introdu comanda: ";
                                cin >> comanda5;
                                cout << endl;

                                switch(comanda5)
                                {
                                    case 1:
                                    {
                                        float suma = 0;
                                        for (int i = 0; i < v.size(); i++)
                                        {
                                            if (v[i] -> getAsigurat() == true)
                                            {
                                                v[i] -> setAsigurat(false);
                                                cout<<setw(19) << left << v[i] -> getNume() << v[i] -> CalcularePret() << " RON" << endl;
                                                suma += v[i] -> CalcularePret();
                                                v[i] -> setAsigurat(true);
                                            }
                                        }
                                        cout << endl <<setw(19) << left << "SUMA: " << suma << " RON" << endl;
                                        break;
                                    }
                                    case 2:
                                    {
                                        o = 0;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4:
                        {
                            l = 0;
                            break;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                k = 0;
                break;
            }
        }
    }
}
