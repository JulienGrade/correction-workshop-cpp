# Observateur — Comprendre les notifications entre objets

Ce programme illustre le patron de conception **Observateur**. Un objet produit un événement et prévient les objets inscrits auprès de lui. Dans notre exemple, l’objet observable prévient deux observateurs nommés Toto et Tata. Après le désabonnement de Toto, seul Tata reçoit l’événement suivant.

## Les rôles dans le programme

| Élément | Responsabilité |
| --- | --- |
| `Observer` | Définit le contrat des destinataires avec la méthode virtuelle pure `update(Observable*)`. |
| `Observable` | Conserve les adresses des observateurs et gère leur inscription, leur retrait et leur notification. |
| `ConcreteObservable` | Déclenche un événement avec `someEvent()`, qui appelle `notify()`. |
| `ConcreteObservers` | Implémente la réaction à une notification. Chaque instance affiche son nom. |
| `main.cpp` | Crée les objets, inscrit Toto et Tata, déclenche les événements et désabonne Toto. Il joue le rôle du Client du diagramme. |

## Déroulement du cas développé

1. `main` crée deux objets `ConcreteObservers`, nommés Toto et Tata, puis un objet `ConcreteObservable`.
2. `subscribe(&observateur1)` et `subscribe(&observateur2)` enregistrent leurs adresses dans la liste de l’observable.
3. Le premier appel à `someEvent()` déclenche `notify()`. Cette méthode parcourt les deux inscrits et appelle leur méthode `update(this)`.
4. Les deux observateurs affichent leur nom et la réception de la notification.
5. `unsubscribe(&observateur1)` retire l’adresse de Toto de la liste. Toto continue d’exister.
6. Le deuxième événement prévient uniquement Tata.
7. Un nouveau retrait de Toto renvoie `-1`, car son adresse est déjà absente.

```cpp
observable.subscribe(&observateur1);
observable.subscribe(&observateur2);
observable.someEvent();                 // Toto et Tata sont prévenus.

observable.unsubscribe(&observateur1);
observable.someEvent();                 // Tata est prévenu.
```

## Pourquoi ajouter Observer et Observable ?

L’observable contacte tous ses destinataires avec le même appel, `observer->update(this)`. La classe `Observer` garantit que cette méthode existe. La méthode virtuelle sélectionne ensuite la réaction de l’objet réellement inscrit. C’est le **polymorphisme**.

On peut ainsi ajouter un observateur qui actualise un écran ou écrit dans un journal. Il lui suffit d’implémenter `update()` et de s’inscrire. Le code qui envoie les notifications peut continuer à utiliser la même boucle.

`Observable` rassemble la gestion des inscriptions. Une autre classe concrète peut en hériter et appeler `notify()` lorsqu’un événement la concerne. Cette méthode est `protected`, ce qui laisse aux classes dérivées le soin de décider quand prévenir les observateurs.

## À quoi sert le paramètre observed ?

Dans `observer->update(this)`, `this` est le pointeur vers l’objet observable qui émet l’événement. Le paramètre `observed` reçu par `update()` permet donc d’identifier cet objet et, si son interface le permet, de consulter son état.

Dans ce programme, les observateurs affichent seulement un message. Ils vérifient que le pointeur reçu est valide. L’accès à des informations propres à une classe concrète demanderait une interface de lecture adaptée ou une conversion contrôlée, par exemple un `dynamic_cast` vérifié. Le passage par pointeur conserve l’identité et le type réel de l’émetteur.

## Comment les abonnements sont-ils gérés ?

| Méthode | Comportement |
| --- | --- |
| `subscribe()` | Refuse les pointeurs vides et les doublons. Renvoie le nombre d’inscrits après l’ajout, ou `-1` en cas de refus. |
| `unsubscribe()` | Retire une adresse et renvoie le nombre d’inscrits restant. Renvoie `-1` si l’objet est absent. |
| `notify()` | Parcourt les inscrits dans l’ordre et appelle leur méthode `update()`. |

Le `std::vector<Observer*>` conserve des **pointeurs non propriétaires**. Les observateurs sont créés dans `main`, où leur durée de vie est gérée automatiquement. Ils restent vivants pendant toute l’utilisation de l’observable. Dans une application plus longue, un observateur doit se désabonner avant sa destruction si l’observable continue à l’utiliser.

Les notifications sont **synchrones**. Chaque `update()` se termine avant de passer au destinataire suivant. Cette version suppose que les abonnements restent identiques pendant le parcours de `notify()`.

## Compiler et vérifier sur macOS

Depuis la racine du dépôt, avec Apple Clang et C++20.

```bash
clang++ -std=c++20 -Wall -Wextra -pedantic \
    -I workshop5/exercice1-observateur/include \
    workshop5/exercice1-observateur/src/main.cpp \
    workshop5/exercice1-observateur/src/Observable.cpp \
    workshop5/exercice1-observateur/src/ConcreteObservers.cpp \
    -o /tmp/workshop5-observateur
```

Lance ensuite le programme.

```bash
/tmp/workshop5-observateur
```

Sortie attendue.

```text
Premier evenement :
Toto a recu une notification.
Tata a recu une notification.

Deuxieme evenement :
Tata a recu une notification.

Second retrait de Toto : -1
```

Les deux premières lignes de notification valident l’inscription des deux objets. La notification unique du deuxième événement valide le retrait de Toto. Le résultat `-1` montre que le programme détecte son absence lors du second retrait.
