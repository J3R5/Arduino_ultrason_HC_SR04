//------------Define------------//
#define pinTrig 11 //Pin broche trig
#define pinEcho 12 //Pin broche echo
//-----------------------------//

//-----------Variable-----------//
long temps;//cette variable gère le temps de l'allé retour du capteur ultrason
float distance;//c'est variable sert a calculer la distance du capteur detecter par le capteur ultrason.
//-----------------------------//



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
//----------Affichage Résultat---------//
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  //-----------------------------------//

  //Attente avant nouveau cycle
  delay(2000);
}
