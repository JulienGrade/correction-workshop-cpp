# Workshop 1 — Programmation orientée objet en C++

Ce workshop part de structures et de fonctions libres, puis introduit les classes à travers trois programmes. Les formes montrent comment associer des opérations à un objet. Les fractions montrent comment contrôler l’accès aux données et produire de nouveaux objets. Le jeu combine ces notions pour faire évoluer plusieurs objets au fil des actions du joueur.

| Partie | Programme | Notions principales |
| --- | --- | --- |
| Formes | [`partie1-formes/main.cpp`](partie1-formes/main.cpp) | Structures, classes, constructeurs, méthodes et `const` |
| Fractions | [`partie2-fractions/main.cpp`](partie2-fractions/main.cpp) | Encapsulation, références, retour par valeur, tests et simplification |
| Jeu | [`partie3-jeu/main.cpp`](partie3-jeu/main.cpp) | Interaction entre objets, boucle de jeu, hasard, inventaire et sauvegarde |

## 1. Formes — Passer des structures aux classes

### Regrouper les données

`Circle` contient les coordonnées de son centre et son rayon. `Rectangle` contient les coordonnées de son coin supérieur gauche, sa largeur et sa hauteur. Chaque objet possède ses propres valeurs.

Dans le programme de départ, les fonctions sont définies en dehors des structures. L’appel `perimeter(c)` reçoit une copie du cercle. Pour déplacer le cercle d’origine, `set_pos(&c, 1, 1)` reçoit son adresse. Dans la fonction, `c->x` désigne le champ `x` de l’objet pointé.

### Construire un objet et lui associer des méthodes

Le passage à `class` introduit un **constructeur**. Avec `Circle c{0, 0, 1};`, le constructeur initialise les coordonnées à `0` et le rayon à `1`. Dans sa liste d’initialisation, `r{r}` utilise le paramètre de droite pour initialiser le champ de gauche.

Les champs restent publics dans cet exercice pour permettre les accès directs comme `c.x`. Une structure C++ rend ses membres publics par défaut, tandis qu’une classe les rend privés par défaut. Le bloc `public:` rend explicite l’accès retenu ici.

En transformant les fonctions libres en méthodes, on peut écrire `c.set_pos(1, 1)` et `c.perimeter()`. L’objet sur lequel la méthode agit est donné par l’appel. Dans `this->x = x;`, `this->x` désigne le champ de cet objet et `x` le paramètre reçu. Le `const` de `perimeter() const` et de `area() const` indique que ces calculs laissent l’état de l’objet intact.

**Ce qu’on a appris.** Déplacer progressivement du code vers des classes tout en vérifiant le comportement à chaque étape. Le cercle de rayon `1` conserve son périmètre d’environ `6.28319`, puis on ajoute le calcul de son aire, environ `3.14159`. Le rectangle de largeur `1` et de hauteur `2` a un périmètre de `6` et une aire de `2`.

## 2. Fractions — Encapsuler les données et renvoyer un résultat

### Définir l’interface de la classe

Une `Fraction` stocke deux entiers privés, `numerateur` et `denominateur`. Les méthodes publiques forment son interface. Les **getters** lisent les champs et les **setters** les modifient. Cette organisation donne à la classe un point de passage pour appliquer des règles si nécessaire.

La classe possède deux constructeurs. `Fraction f0;` crée `1/1` et `Fraction f1(1, 2);` crée `1/2`. C’est un exemple de **surcharge**. Les deux constructeurs ont le même nom et C++ choisit selon les arguments fournis.

### Distinguer lecture, résultat et modification

Dans `Fraction f3 = f1.add(f2);`, `f1` est l’objet courant et `f2` est l’autre opérande. Le paramètre `const Fraction& autre` permet de lire `f2` sans le copier. Le `const` placé après les parenthèses de la méthode protège l’état de `f1` pendant le calcul. Le résultat est renvoyé **par valeur** sous la forme d’une nouvelle fraction.

| Appel avec `f1 = 1/2` et `f2 = 3/4` | Résultat attendu par le sujet |
| --- | --- |
| `f1.add(f2)` | `10/8` |
| `f1.minus(f2)` | `-2/8` |
| `f1.multiply(f2)` | `3/8` |
| `f1.divide(f2)` | `4/6` |

Les tests du sujet comparent séparément le numérateur et le dénominateur. Ils attendent donc les résultats sous leur forme non simplifiée. La méthode `simplify()` est appelée à la demande. Elle calcule le **plus grand commun diviseur** (PGCD) par l’algorithme d’Euclide, puis divise les deux champs par ce nombre. Par exemple, le PGCD de `10` et `8` vaut `2`, ce qui transforme `10/8` en `5/4`.

**Ce qu’on a appris.** Une méthode peut renvoyer un nouvel objet, comme `add()`, ou modifier l’objet courant, comme `simplify()`. Les six tests d’origine vérifient les constructeurs et les opérations. Deux assertions supplémentaires vérifient la simplification de `10/8` en `5/4` et de `-2/8` en `-1/4`.

## 3. Jeu — Faire interagir des objets et conserver leur état

### Répartir les responsabilités

`Heros` et `Creature` possèdent chacun des points de vie (PV) et des points d’attaque (PA). Chaque classe sait afficher son état, calculer ses dégâts, recevoir un coup et indiquer si elle est encore vivante. Le diagramme de classes décrit ces données et opérations. Le diagramme de séquence donne l’ordre des appels pendant un échange.

Dans `main`, `heros.attaque()` renvoie des dégâts, puis `creature.subitDegat(degatsHeros)` les applique. Le menu étend cet échange à plusieurs tours. Il lit les choix avec `std::getline`, utilise `continue` pour revenir au menu et s’arrête quand un personnage est vaincu ou que le joueur quitte. La créature riposte si elle est encore vivante.

### Faire des tirages reproductibles

`std::srand(42)` fixe la graine au début de la partie. `std::rand()` effectue un tirage au moment de l’attaque. Avec `pa = 10`, l’expression `1 + std::rand() % pa` produit un nombre entre `1` et `10`. Sur le même environnement, la même graine et le même ordre d’appels reproduisent la suite des dégâts. On peut ainsi comparer deux parties pour vérifier le bonus de l’épée.

### Mémoriser l’équipement et la potion

Un `bool` indique si l’épée est équipée. Elle ajoute `3` dégâts tant que cette valeur est vraie. Un autre `bool` indique si la potion est disponible. La potion soigne jusqu’à `5` PV, dans la limite des PV maximum, et est consommée quand elle soigne effectivement le héros. Ces champs mémorisent les conséquences des choix d’un tour à l’autre.

### Sauvegarder et reprendre la partie

L’option `5` écrit les PV, l’état de l’épée et de la potion et le nombre de tours joués dans `workshop1-partie.txt` avec `std::ofstream`. Ce fichier se trouve dans le dossier depuis lequel le jeu est lancé. L’option `6` le lit avec `std::ifstream`. La lecture se fait d’abord dans des copies, puis les objets de la partie sont remplacés après validation des valeurs chargées.

Pour reprendre les tirages, le jeu réinitialise la graine puis avance de deux tirages par tour sauvegardé. Un tour sauvegardé a consommé un tirage pour l’attaque du héros et un autre pour la riposte. Sur le même environnement, le premier coup après le chargement donne les mêmes dégâts que si la partie avait continué.

**Ce qu’on a appris.** Les objets portent les données et les règles qui les concernent. `main` coordonne leurs interactions, gère les choix au clavier et déclenche la sauvegarde ou le chargement.

## Compiler et exécuter

Les trois programmes se compilent séparément en **C++20**. Lance les commandes depuis la **racine du dépôt Git**, le dossier qui contient `workshop1/`. Chaque commande compile un seul `main.cpp` et lance le programme si la compilation réussit. Les exécutables sont placés dans le dossier temporaire du système.

### macOS — Terminal avec Apple Clang

Vérifie que le compilateur est disponible avec `clang++ --version`. Si la commande est introuvable, lance `xcode-select --install` pour installer les outils en ligne de commande d’Apple, puis rouvre le Terminal.

```bash
# Formes
clang++ -std=c++20 -Wall -Wextra -pedantic workshop1/partie1-formes/main.cpp -o /tmp/workshop1-formes &&
    /tmp/workshop1-formes

# Fractions — six tests du sujet
clang++ -std=c++20 -Wall -Wextra -pedantic workshop1/partie2-fractions/main.cpp -o /tmp/workshop1-fractions &&
    /tmp/workshop1-fractions

# Jeu
clang++ -std=c++20 -Wall -Wextra -pedantic workshop1/partie3-jeu/main.cpp -o /tmp/workshop1-jeu &&
    /tmp/workshop1-jeu

# Fractions — deux tests de simplify()
clang++ -std=c++20 -Wall -Wextra -pedantic -DTEST_SIMPLIFY workshop1/partie2-fractions/main.cpp -o /tmp/workshop1-fractions-simplify &&
    /tmp/workshop1-fractions-simplify
```

### Windows 11 (x64) — PowerShell avec GCC

1. Installe [MSYS2](https://www.msys2.org/) dans le dossier proposé, généralement `C:\msys64`.
2. Ouvre **MSYS2 UCRT64** depuis le menu Démarrer et lance la commande suivante. [Installation de GCC avec MSYS2](https://www.mingw-w64.org/getting-started/msys2/)

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

3. Ouvre **PowerShell**, place-toi à la racine du dépôt et exécute les deux lignes suivantes. La première rend le compilateur et ses bibliothèques accessibles pour cette session PowerShell. Adapte le chemin si tu as installé MSYS2 ailleurs.

```powershell
$env:Path = "C:\msys64\ucrt64\bin;$env:Path"
g++ --version
```

4. Dans la même fenêtre, lance le bloc correspondant au programme souhaité. `$env:TEMP` désigne le dossier temporaire Windows. Après la compilation, `$LASTEXITCODE -eq 0` vérifie sa réussite et `&` lance le fichier `.exe`.

```powershell
# Formes
g++ -std=c++20 -Wall -Wextra -pedantic .\workshop1\partie1-formes\main.cpp -o "$env:TEMP\workshop1-formes.exe"
if ($LASTEXITCODE -eq 0) { & "$env:TEMP\workshop1-formes.exe" }

# Fractions — six tests du sujet
g++ -std=c++20 -Wall -Wextra -pedantic .\workshop1\partie2-fractions\main.cpp -o "$env:TEMP\workshop1-fractions.exe"
if ($LASTEXITCODE -eq 0) { & "$env:TEMP\workshop1-fractions.exe" }

# Jeu
g++ -std=c++20 -Wall -Wextra -pedantic .\workshop1\partie3-jeu\main.cpp -o "$env:TEMP\workshop1-jeu.exe"
if ($LASTEXITCODE -eq 0) { & "$env:TEMP\workshop1-jeu.exe" }

# Fractions — deux tests de simplify()
g++ -std=c++20 -Wall -Wextra -pedantic -DTEST_SIMPLIFY .\workshop1\partie2-fractions\main.cpp -o "$env:TEMP\workshop1-fractions-simplify.exe"
if ($LASTEXITCODE -eq 0) { & "$env:TEMP\workshop1-fractions-simplify.exe" }
```

### Vérifier le résultat

- **Formes** — Le programme affiche le périmètre, l’aire et la position de chaque forme.
- **Fractions** — La compilation standard affiche six lignes `[OK]`. Avec `-DTEST_SIMPLIFY`, le programme affiche deux lignes `[OK]` pour les cas de simplification.
- **Jeu** — Le menu s’affiche et attend un choix au clavier. Les dégâts peuvent différer entre macOS et Windows, car la suite produite par `rand()` dépend de l’implémentation. Pour tester la reprise d’une sauvegarde, effectue les deux essais dans le même environnement.


