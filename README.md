# Capteur ultrason HC SR04

### Introduction

Ce repertoir **va traiter du fonctionnement** du capteur **HC-SR04**. Ce document va traiter du Capteur **HC-SR04** ([ici sa datasheet]()) et de son fonctionnement. Pour voir **le code du programme** test il faut aller voir [se markdown]().  

Le capteur ultrason **HC-SR04** est un capteur qui est équiper d'un émetteur et d'un recepteur à ultrason. Pour utilisée le capteur on va lui envoyer un signal sur une broche et la distance sera retourner sous forme de durée à l'état haut.

#### Capteur US Broche

Le capteur **HC-SR04** possède **4 broches Vcc, GND, Trig et Echo** :

![Pinout_HC-SR04](https://github.com/J3R5/Arduino_ultrason_HC_SR04/blob/main/datasheet/pinout%20HC-SR04.png)

* Vcc  : **Alimentation** du capteur en **+5V**.
* GND  : **Masse** du capteur **0V**.
* Trig : **Entrée du capteur** qui permet **d'activer le capteur** pour prendre **une mesure** en envoyant **une impulsion** de **10µs**.
* Echo : **Sortie du capteur** qui envoie **une impulsion** de la largeur qui **varie** en fonction de **la distance** entre le capteur et **le signal**.

#### Fonctionnement capteur

**Schéma** fonctionnement du capteur :

![logigramme_us](https://github.com/J3R5/Arduino_ultrason_HC_SR04/blob/main/datasheet/logigramme_us.PNG)





