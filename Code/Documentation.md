# Documentation Code

#### Introduction

Ce markdown va expliquer ligne par ligne le fonctionnement du programme du capteur ultrason. Pour savoir comment fonctionne se capteur il faut allez voir [se markdown](). Il y a deux programmes dans le dossiers code l'un permet de vérifier que le capteur ultrasons marche, quant as l'autre c'est une fonction qui se sert du capteur. Le document va présenter le premier programme puis expliquer les différences avec la fonction.

#### Programme test Capteur HC-SR04

Ce programme permet de tester si le capteur ultrasons marche en renvoyant la distance dans le moniteur série. Pour vérifier il suffit juste de mesurer la distance entre l'objet et le capteur.

##### Define : 

On commence par des Define pour définir l'entrée et sortie Trig et Echo de la carte.

~~~C++
//------------Define------------//
#define pinTrig 11 //Pin broche trig
#define pinEcho 12 //Pin broche echo
//-----------------------------//

~~~

Dans cette exemple la broche trig est connectée à la 11 quant a Echo elle est connecté à la 12. Si l'on change les borche il suffit uniquement de les changer dans le define et le programme fera le reste.

##### Variable :

Le programme possède deux variables une pour le temps de réponse du capteur ultrasons et une autre pour calculer la distance entre l'objet et la capteur.

~~~C++

//-----------Variable-----------//
long temps;//cette variable gère le temps de l'allé retour du capteur ultrason
float distance;//c'est variable sert a calculer la distance du capteur detecter par le capteur ultrason.
//-----------------------------//

~~~

Ici temps est la variable du temps de réponse et distance est la variable distance.

##### Void Setup :

Après avoir déclarer les variables et les defines on peut passer au Void Setup pour initialiser les entrées, sorties et le moniteur série.

~~~C++

void setup() {

  //-----------Initialisation-----------//
  Serial.begin(9600);
  //activation du moniteur série à 9600 bauds
  //-----------------------------------//

  //-----------Entrée/Sortie------------//
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  //-----------------------------------//
  
  //--------Initialisation-Sortie------//
  digitalWrite(pinTrig, LOW); 
  //-----------------------------------//

}

~~~

Dans cette fonction on commence par activer le moniteur série à 9600 bauds. Ensuite on déclare Trig en sortie et Echo en entrée. Après on désactive la sortie Trig pour eviter d'activer le capteur.

##### Void loop :
