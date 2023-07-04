# Capteur ultrason HC SR04

### Introduction

Ce répertoire **va traiter du fonctionnement** du capteur **HC-SR04**. Ce document va traiter du Capteur **HC-SR04** ([ici sa datasheet](https://github.com/J3R5/Arduino_ultrason_HC_SR04/blob/main/datasheet/HC-SR04.PDF)) et de son fonctionnement. Pour voir **le code du programme** test, il faut regarder [se markdown](https://github.com/J3R5/Arduino_ultrason_HC_SR04/blob/main/documentation/Documentation.md).  

Le capteur ultrason **HC-SR04** est un capteur qui est équipé d'un émetteur et d'un récepteur à ultrason. Pour utiliser le capteur, on va lui envoyer un signal sur une broche et la distance sera retournée sous forme de durée à l'état haut.

#### Capteur US Broche

Le capteur **HC-SR04** possède **4 broches Vcc, GND, Trig et Echo** :

![Pinout_HC-SR04](https://github.com/J3R5/Arduino_ultrason_HC_SR04/blob/main/datasheet/pinout%20HC-SR04.png)

* Vcc  : **Alimentation** du capteur en **+5V**.
* GND  : **Masse** du capteur **0V**.
* Trig : **Entrée du capteur** qui permet **d'activer le capteur** pour prendre **une mesure** en envoyant **une impulsion** de **10µs**.
* Echo : **Sortie du capteur** qui envoit **une impulsion** de la largeur qui **varie** en fonction de **la distance** entre le capteur et **le signal**.

#### Fonctionnement capteur

**Schéma** fonctionnement du capteur :

![logigramme_us](https://github.com/J3R5/Arduino_ultrason_HC_SR04/blob/main/datasheet/logigramme_us.PNG)

Le capteur fonctionne de la façon suivante :

* On envoit une première impulsion de 10 microsecondes sur la borne trig.
* Ensuite, une salve de 8 pulsations est envoyée via l'émetteur du module ultrason.
* Enfin, le module va envoyer un signal via la sortie Echo du capteur dont la durée dépend de la distance entre le capteur et l'objet.

Donc, pour obtenir la distance, il suffit de traiter l'information venant du echo.

Ceci est la fin de ce markdown. Pour allez voir comment utiliser le capteur US, il faut se rendre au [markdown]() il va aussi expliquer comment traiter l'information du capteur US.

