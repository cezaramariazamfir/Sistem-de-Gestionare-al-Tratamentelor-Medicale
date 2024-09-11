# Sistem de Gestionare al Tratamentelor Medicale

## Descriere

Acest proiect este un sistem de gestionare a tratamentelor medicale, implementat în C++ folosind Programarea Orientată pe Obiect (OOP). Sistemul permite gestionarea diferitelor tipuri de tratamente, inclusiv medicamentoase, tratamente chirurgicale și tratamente holistice. Interfața permite interacțiunea utilizatorului cu sistemul printr-un meniu simplu și intuitiv.

## Clase

- **Medicament**: Reprezintă un medicament, cu atribute și metode asociate.
- **Tratament**: Clasă de bază pentru toate tipurile de tratamente. Include atribute comune și metode pentru gestionarea tratamentului.
- **TratamentMedicamentos**: Derivată din `Tratament`, reprezintă un tratament medicamentos specific.
- **TratamentChirurgical**: Derivată din `Tratament`, reprezintă un tratament chirurgical specific.
- **TratamentHolistic**: Derivată din `TratamentMedicamentos` și `TratamentChirurgical`, utilizează moștenirea diamant pentru a reprezenta tratamentele holistice.

## Funcționalități

- **Vizualizare tratamente**: Vizualizați toate tratamentele existente.
- **Adăugare tratament**: Adăugați noi tratamente în sistem.
- **Ștergere tratament**: Ștergeți tratamente existente pe baza numelui pacientului.
- **Vizualizare diagnostic și costuri**: Vizualizați diagnosticul și costul total al tratamentelor.
- **Modificare statut asigurare**: Schimbați statutul de asigurat al pacientului și vizualizați suma totală ce trebuie decontată de CAS.

## Utilizare

1. **Pornire aplicație**: Rulați programul pentru a deschide interfața principală.

2. **Meniu principal**: Alegeți una dintre opțiunile oferite:
   - **1**: Continuați cu aplicația.
   - **2**: Ieșiți din aplicație.
     
    ![image](https://github.com/user-attachments/assets/662c6820-b249-4a09-81ef-c496f65d631c)



3. **Roluri utilizator**:
   
   - **Dacă sunteți doctor**
     - Vizualizați tratamentele existente.
     - Adăugați noi tratamente (medicamente, chirurgicale, holistice).
     - Ștergeți tratamente pe baza numelui pacientului.
       
       ![image](https://github.com/user-attachments/assets/63dc1af0-8b0d-4b5d-8884-383bcdd5afbc)

   - **Dacă sunteți pacient**
     - Vizualizați diagnosticul și tratamentele asociate.
     - Vizualizați breakdown-ul costurilor.
     - Schimbați statutul de asigurat.
       
       ![image](https://github.com/user-attachments/assets/91f2054f-3f67-418a-b411-efcb2927fdff)

   - **Dacă sunteți manager**
     - Vizualizați suma totală ce trebuie decontată de CAS.
       
       ![image](https://github.com/user-attachments/assets/7f20c80b-c077-4902-b897-62ba58464276)

   - **Înapoi la meniul anterior**



