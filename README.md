# Sample GitLab Project

> Dokumentácia k zadaniu je napísaná v k_means.docx

Uvod 
Dokumentacia popisuje algoritm klasifikacie metodov k-means. Zadanie je vypracovane v jazyku C, v programovom prostredi Dev-C++.

Je to najobľúbenejšia klasifikačná metóda.
Činnosť algoritmu je taká, že sa snaží minimalizovať celkovú štvorcovú odchýlku bodov klastra od stredov týchto klastrov. 

Popis algoritmu:
1. Vopred musíme vedieť, koľko klasterov potrebujeme na distribúciu údajov.
2. Musíme si zvoliť náhodné začiatočné centrá našich klasterov.
3. Vypočítajme vzdialenosť od každého stredu ku každému bodu. Táto vzdialenosť sa považuje za euklidovskú vzdialenosť medzi bodmi v priestore.
4. Po prepočítaní všetkých stredov sme body rozdelili do zhlukov a porovnali sme vzdialenosť od každého bodu zo stredom. Body je umiestnený v zhluku, do stredu ktorého je umiestnený bližšie ako do zvyšku centrov.

Programovy modul
Obmedzujúce podmienky - pre fungovanie programu je potrebne zadať na začatku počet bodov.
Riešenie obsahuje  dve funkcie:

_сompute_ – spočíta euklidovskú vzdialenosť medzi bodmi v priestore.
 
_compute_s_ – spočíta novy stred
 
Program funguje, kým sa centrá novej iterácie sa líši od starej, alebo kým nie je prekročený limit v 30 (dasa zmenit) iterácií. 

 
