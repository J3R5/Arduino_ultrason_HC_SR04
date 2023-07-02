# Schéma Liason US arduino

  Ce markdown va traiter du schéma permettant de racorder le capteur ultrasons HC-SR04 à l'arduino uno. Ce schéma n'est pas valable si l'on change de capteur ultrason. Le code et le schéma de connection sont dépendant l'un de l'autre, mais il est possible de changer les connection en changeant deux lignes de code.

  ##### Schéma :

  ![Schema](https://github.com/J3R5/Arduino_ultrason_HC_SR04/blob/main/datasheet/Schema_US.png)

  Le schéma respecte la logique du code. En plus du Pin trig et Echo il y a les broches Vcc (+5V) et gnd (0V) à relier a la carte arduino. Les Pins Echo et trig peuvent être changer dans le code en modifiant seulement ces deux lignes de code :

  ~~~C++


  ~~~
