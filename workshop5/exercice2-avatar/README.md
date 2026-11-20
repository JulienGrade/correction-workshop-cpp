# Avatar — États et transitions

L’avatar affiche successivement cinq émotions, avec une pause de cinq secondes entre deux affichages. Chaque émotion est représentée par un objet spécialisé de la classe abstraite `AvatarState`.

## Question 1 — Que se passerait-il avec un chaînage de fonctions ?

Le sujet propose d’imaginer des fonctions qui s’appellent successivement, en boucle.

```text
glad() appelle happy()
happy() appelle sad()
sad() appelle angry()
angry() appelle grumpy()
grumpy() appelle glad()
```

Chaque fonction attend que la suivante se termine pour terminer elle-même. Comme le cycle recommence indéfiniment, les appels peuvent s’accumuler dans la pile d’appels, qui mémorise notamment les informations nécessaires au retour de chaque fonction. À terme, le programme risque un débordement de pile et un arrêt anormal.

Certains compilateurs peuvent optimiser certains appels terminaux et éviter cette accumulation. Le C++ ne garantit toutefois pas cette optimisation. Une pause de cinq secondes entre les appels ne libère pas les appels précédents.

Dans notre version, `Avatar::run()` utilise une boucle. La méthode `action()` se termine, puis `next()` se termine, et la boucle poursuit son travail. Un nouveau cycle d’émotions pourrait ainsi être parcouru sans ajouter un niveau d’appel à chaque transition.

## Question 2 — Malgré les lourdeurs, quel est l’avantage de cette approche ?

Chaque état possède sa propre classe et définit son action. L’avatar utilise le contrat commun `AvatarState`, avec `action()` et `next()`. Le polymorphisme sélectionne l’affichage correspondant à l’objet courant.

| Élément | Responsabilité |
| --- | --- |
| `AvatarState` | Définit l’action attendue et conserve l’adresse de l’état suivant. |
| `Glad`, `Happy`, `Sad`, `Angry`, `Grumpy` | Fournissent chacune un affichage spécifique. |
| `Avatar` | Exécute l’état courant, attend et passe à l’état suivant. |
| `main` | Construit les objets et choisit leur enchaînement. |

Cette répartition permet de faire évoluer les comportements et le parcours séparément. Pour ajouter une émotion, on peut créer une classe dérivée et la relier aux autres états dans `main`. La boucle de l’avatar peut conserver le même fonctionnement. Pour changer l’ordre des émotions, on modifie les liens entre les objets.

L’approche utilise davantage de classes et de déclarations. Son intérêt apparaît lorsque les états ont des comportements plus riches ou lorsque leur nombre augmente. Elle illustre le principe du patron de conception **État**, avec un parcours de transitions explicitement construit dans cet exercice.

## Application dans notre programme

### Le rôle du pointeur courant

Le champ `AvatarState* state` d’`Avatar` contient l’adresse de l’émotion courante. Avec `state->action()`, l’avatar appelle la méthode virtuelle de l’objet réellement pointé, par exemple `Sad::action()`.

`state->next()` renvoie l’adresse du successeur. L’affectation `state = prochainEtat` fait ensuite travailler l’avatar avec cet autre objet.

### L’ordre des émotions

| État courant | Affichage | État suivant |
| --- | --- | --- |
| `Glad` | `Glad : heureux :-D` | `Happy` |
| `Happy` | `Happy : joyeux :-)` | `Sad` |
| `Sad` | `Sad : triste :-(` | `Angry` |
| `Angry` | `Angry : en colere >:(` | `Grumpy` |
| `Grumpy` | `Grumpy : ronchon :-/` | `nullptr` |

On construit les états depuis la fin dans `main`. Ainsi, lorsqu’on crée `Angry`, l’objet `Grumpy` existe déjà et son adresse peut être transmise au constructeur.

### Le délai et la fin du parcours

`std::this_thread::sleep_for(std::chrono::seconds{5})` suspend le thread courant avant la transition suivante. Le premier état est affiché immédiatement. Quatre pauses séparent les cinq affichages, pour une durée totale d’environ vingt secondes, éventuellement légèrement supérieure selon l’ordonnancement du système.

Nous avons choisi un passage unique, comme dans le corrigé fourni. `Grumpy` reçoit `nullptr` comme successeur. Après son action, le pointeur courant devient donc nul et la boucle s’arrête. Le sujet autorise également un fonctionnement continu. Cette variante demanderait de relier le dernier état au premier.

### La durée de vie des objets

Les états sont des objets locaux créés dans `main` avant l’avatar. Ils restent vivants pendant l’appel à `run()`, puis sont détruits automatiquement à la fin de `main`. Les pointeurs entre les états et celui de l’avatar sont non propriétaires. Ils servent à retrouver les objets existants.

## Compiler et vérifier sur macOS

Depuis la racine du dépôt, avec Apple Clang et C++20.

```bash
clang++ -std=c++20 -Wall -Wextra -pedantic -pthread \
    -I workshop5/exercice2-avatar/include \
    workshop5/exercice2-avatar/src/main.cpp \
    workshop5/exercice2-avatar/src/Avatar.cpp \
    workshop5/exercice2-avatar/src/Emotions.cpp \
    -o /tmp/workshop5-avatar
```

Puis exécuter le programme.

```bash
/tmp/workshop5-avatar
```

Les lignes suivantes apparaissent dans l’ordre, à environ cinq secondes d’intervalle.

```text
Glad : heureux :-D
Happy : joyeux :-)
Sad : triste :-(
Angry : en colere >:(
Grumpy : ronchon :-/
```
