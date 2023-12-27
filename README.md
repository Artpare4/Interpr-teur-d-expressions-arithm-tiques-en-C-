# Interpréteur d’expressions arithmétiques
## Arthur Parent 
**Attention, ce programme est conçu pour fonctionner dans un environement UNIX. Notamment pour la compilation et l'exécution.**

## Sommaire
1. [Entités](#Entités)
2. [Mode d'emploi](#emploi)
3. [Choix de programmation](#programmation)
### Entités <a name="Entités"></a>

#### Piles : 
Toutes les piles sont des piles chaînées.

- PileReel : Pile contenant des réels
  - NoeudReel : Noeud contenant un réel
- PilesChar : Pile contenant des caractères
  - Noeud: Noeud contenant un charactère
#### Files :
Les files sont des files chaînées.

- FileExpression : File contenant des Expressions
  - NoeudExpression : Noeud contentant un Expression

#### Autres : 
- Expression : Une expression se caractérise par un nom (var) et une expression arithmétique (exp)

### Mode d'emploi <a name="emploi"></a>
#### Installation requises:
- Installer ```g++```
- Installer ```make```

**Attention, programme exécuté sour c++11 car il permet la gestion des exception avec 'stdexcept'**

#### Pour compiler le programme
Entrez la commande dans le répertoire du projet pour pouvoir compiler le programme

```
make 
```
**Attention : Après avoir dézipé le fichier, si l'exécution du programme ne fonctionne pas directement, pensez à compiler le programme.** 

#### Pour exécuter le programme

Entrez dans le terminal la commande
```
./a.out
```
#### Exemple d'exécution du programme

##### Exemple de variable à rentrer dans le programme
```
a=((2*59)+(3-(5*97)))
b=((66*0)%3)
e=699
k=((a+9)*(686/8))
d=((k*k)-(5*b))
z=((b-(d/e))+8)
```
**Attention, pas d'espace entre la variable et le symbole égal et entre le symbole égal et l'expression**

##### Trace d'exécution du programme
###### Exemple réussite
```
Entrez votre expression (Ex: a=1+1)
a=2
Voulez vous obtenir le résultat de votre expression ? (Insérez "oui" pour avoir le résultat sinon insérez "non")
non
Voulez-vous continuer à rentre une expression ? (Insérez "stop" pour arrêter le programme sinon insérez "continue" )
continue
Entrez votre expression (Ex: a=1+1)
b=3+3            
Voulez vous obtenir le résultat de votre expression ? (Insérez "oui" pour avoir le résultat sinon insérez "non")
oui
Résultat:
6
Voulez-vous continuer à rentre une expression ? (Insérez "stop" pour arrêter le programme sinon insérez "continue" )
continue
Entrez votre expression (Ex: a=1+1)
c=a+b
Voulez vous obtenir le résultat de votre expression ? (Insérez "oui" pour avoir le résultat sinon insérez "non")
oui
Résultat:
8
Voulez-vous continuer à rentre une expression ? (Insérez "stop" pour arrêter le programme sinon insérez "continue" )
stop
```

###### Exemple mauvais parenthésage d'expression
```
Entrez votre expression (Ex: a=1+1)
a=(2+2(
                      
Votre expression est mal parenthésée
Veuillez re-retrer votre expression correctement
Entrez votre expression (Ex: a=1+1)

```

###### Exemple définition d'une expression contenant des variables non définie précédement
```
Entrez votre expression (Ex: a=1+1)
a=b+1
                      
La variable b n'a pas été défini précédement
Veuillez re-retrer votre expression correctement
Entrez votre expression (Ex: a=1+1)

```

#### Résumé
- Pas d'espace entre la variable et le symbole égal et entre le symbole égal et l'expression
- Si il y a un mauvais parenthésage, le programme vous demandera de réécrire votre expression
- Si il y a dans votre expression une variable non définie précédement, le programme vous demandera de réécrire votre expression
- Si vous voulez obtenir le résultat de votre expression, entrez **oui** à la question ``Voulez vous obtenir le résultat de votre expression ?``
- Si vous voulez stoper le programme , entrez **stop** à la question ``Voulez-vous continuer à rentre une expression ?``

### Choix de programmation <a name="programmation"></a>
<ins>Utilisation des pile/file chaînée:</ins>

Vu que nous ne savons pas combien d'expression l'utilisateur veut insérer, la taille de ces expression. J'ai donc utilisé les file et les pile chaînées
pour me soustraire de la contrainte de définir la taille des pile/file par tableaux.

<ins>Définition de la fonction de l'évaluation d'une expression dans le fichier **main.cpp** :</ins>

J'ai défini la fonction ``evaluer`` dans le fichier main.cpp car cette méthode prend en paramètre une file d'expression et si j'avais voulu définir cette même méthode avec la file en paramtère,
cela aurait créer un problème dans les dépendance et pour créer le makefile.

(FileExpression->NoeudExpression->Expression->FileExpression).
 
Une file d'expression utilise un Noeud contenant une expression. Et si la classe Expression avait besoin de la classe FileExpression pour la méthode ``evaluer``, cela un problème à la compilation et dans l'ordre de compilation.



