//------------Define------------//
#define pinTrig 11 //Pin broche trig
#define pinEcho 12 //Pin broche echo
//-----------------------------//

//-----------Variable-----------//
int distance_capteur;
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

  distance_capteur = CapteurUS();

  Serial.println(distance_capteur);

  //Attente avant nouveau cycle
  delay(2000);
}

int CapteurUS()
{
  /*
   * Cette fonction sert a déterminer la distance
   * d'un objet grace a un capteur ultrason (ici en mm)
   * si la mesure est fausse on retoune -1
   *
   * Jérémy Clémente 16/05/2023
  */

  //-----------Variable-----------//
  long temps;//cette variable gère le temps de l'allé retour du capteur ultrason
  float distance;//c'est variable sert a calculer la distance du capteur detecter par le capteur ultrason.
  //-----------------------------//

  //-----------Initialisation-----------//
  temps = 0;
  distance = 0;//on impose les variables à zéro
  //-----------------------------------//

  //Début

  //---------Activation Capteur---------//
  digitalWrite(pinTrig, HIGH);        
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  //-----------------------------------//

  //récupération valeur
  temps = pulseIn(pinEcho, HIGH);    

  //------------- Résulatat ------------//
  if (temps > 30000)//valeur du timeout donc echec de la mesure 
  {              
    distance = -1;//affichage erreur de mesure
  }
  else
  {
    //division par 2 pour aller et retour
    temps = temps/2;
    //multiplication par 340 car vitesse du son en m/s division par 10000
    //pour avoir des cm .0 sert à avoir des nombres après la virgule.
    distance = (temps*340)/10000.0;               
  }
  //-----------------------------------//

  //On retourne la valeur
  return distance;

  //Fin

}



