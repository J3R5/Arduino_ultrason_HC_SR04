# Schéma Liason US arduino

  Ce markdown va traiter du schéma permettant de raccorder le capteur ultrasons HC-SR04 à l'arduino uno. Ce schéma n'est pas valable que si on change de capteur ultrason. Le code et le schéma de connection sont dépendants l'un de l'autre, mais il est possible de changer les connections en changeant deux lignes de code.

  ##### Schéma :

  ![Schema](https://github.com/J3R5/Arduino_ultrason_HC_SR04/blob/main/datasheet/Schema_US.png)

  Le schéma respecte la logique du code. En plus du Pin trig et Echo il y a les broches Vcc (+5V) et gnd (0V) à relier à la carte arduino. Les Pins Echo et trig peuvent être changés dans le code en modifiant seulement ces deux lignes de code :

  ~~~C++

//------------Define------------//
#define pinTrig 11 //Pin broche trig
#define pinEcho 12 //Pin broche echo
//-----------------------------//


  ~~~

Pour changer le schéma de connection des broches, il suffit seulement de changer le numéro de pinTrig et pinEcho en fonction du pin à l'endroit du branchement. Le reste du code se fait en fonction de pinTrig et de pinEcho et n'est pas directement lier à un numéro.

##### Epilogue :

Voici la fin sur ce court rapport montrant le schéma de connection entre le capteur US et l'arduino. Voici le markdown sur le [Code](https://github.com/J3R5/Arduino_ultrason_HC_SR04/blob/main/documentation/Documentation.md) du capteur ultrason et ici le pdf résumant [l'ensemble]().
