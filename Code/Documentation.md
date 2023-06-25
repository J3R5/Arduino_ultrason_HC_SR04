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

Le programme dans le Void loop va activer le capteur puis récuperer sa valeur pour la convertir en distance et enfin l'afficher dans le moniteur série.

~~~C++

void loop() {

  /*
   * Ce programme est un programme qui grace un capteur
   * ultrason de déterminer la distance (ici en cm)
   *
   * Jérémy Clémente 16/05/2023
  */

  //---------Activation Capteur---------//
  digitalWrite(pinTrig, HIGH);        
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  //-----------------------------------//

  //récupération valeur
  temps = pulseIn(pinEcho, HIGH);    

  //---------Affichage Résulatat--------//
  if (temps > 30000)//valeur du timeout donc echec de la mesure 
  {              
    Serial.println("Echec de la mesure");//affichage erreur de mesure
  }
  else
  {
    //division par 2 pour aller et retour
    temps = temps/2;
    //multiplication par 340 car vitesse du son en m/s division par 10000
    //pour avoir des cm .0 sert à avoir des nombres après la virgule.
    distance = (temps*340)/10000.0;
    //affichage                  
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  //-----------------------------------//

  //Attente avant nouveau cycle
  delay(2000);
}

~~~

On commence par activer le capteur pour obtenir une distance pour cela on passe brievement la borne trig a l'état haut pendant 10 micro-seconde. Ensuite on attend compte le temps a l'état du pin Echo car dans la datasheet le temps a l'état haut est proportionnel à la distance. Si le temps est suppérieur à 30 000 on considère que l'objet est trop loin donc la mesure a échouer.

Ensuite on divise le résultat par deux car la distance compte l'allez et le retour.

Pour avoir la distance on connais le temps et la vitesse du son dans l'air (340m/s pour 20°C)

On peut utiliser cette formule : 

$\v=d/t




