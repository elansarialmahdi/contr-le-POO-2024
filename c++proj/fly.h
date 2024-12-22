#include <string>
#include <iostream>
#include<vector>
using namespace std;

 //1-1 destination******************************************************************************************************************************************************************************************************************************  
   class Destination {
private:
	static int compteur_id;
    int id;
    string ville_depart;
    string ville_arrivee;
    string pays_depart;
    string pays_arrivee;

public:
    Destination(int id,string ville_depart="", string ville_arrivee="",string pays_depart="", string pays_arrivee="");
    
    int getId();
    string getVilleDepart();
    string getVilleArrivee();
    string getPaysDepart();
    string getPaysArrivee();
   
    void modification(string ville_depart,string ville_arrivee,string pays_depart,string pays_arrivee);
    void afficher() ;};
//1-2 gestions des destinations******************************************************************************************************************************************************************************************************************************
	
	class GestionDestinations {
private:
    vector<Destination> destinations;

public:
    void ajouterDestination(string ville_depart,string ville_arrivee,string pays_depart, string pays_arrivee);
    void modifierDestination(int id_dest,string ville_depart,string ville_arrivee,string pays_depart,string pays_arrivee);
    void supprimerDestination(int id_dest);
    void rechercherDestinations(string ville_depart , string ville_arrivee);
    void afficherDestinations() ;};
    //2-1 trajet******************************************************************************************************************************************************************************************************************************
	
	class Trajet {
private:
    int id; 
    string ville_depart;
    string ville_arrivee;
    string horaire;
    double prix;

public:
    
    Trajet(int id,string ville_depart,string ville_arrivee,string horaire, double prix);


    int getId();
    string getVilleDepart();
    string getVilleArrivee();
    string getHoraire();
    double getPrix();
    void afficher();
};
//2-2 gestions des trajets******************************************************************************************************************************************************************************************************************************
    
class GestionTrajets {
private:
    vector<Trajet> trajets;

public:
    void ajouterTrajet(int id,string ville_depart,string ville_arrivee,string horaire, double prix);

    void modifierTrajet(int id,string ville_depart,string ville_arrivee,string horaire, double prix);
    void supprimerTrajet(int id);
    void afficherTrajets(string ville_depart,string ville_arrivee);
    void consulterTrajet(int id) ;
};
//3-1 Reservation******************************************************************************************************************************************************************************************************************************
    
class Reservation {
private:
    int id;            
    string nom_client; 
    int id_trajet;         
    int nombre_places;     

public:
    Reservation(int id,string nom_client, int id_trajet, int nombre_places);
    int getId();
    string getNomClient();
    int getIdTrajet();
    int getNombrePlaces();
    void afficher();
};
//3-2 Reservation******************************************************************************************************************************************************************************************************************************
class GestionReservations {
private:
    vector<Reservation> reservations; 
    vector<int> places_disponibles;  

public:
    
    bool ajouterReservation(string nom_client, int id_trajet, int nombre_places);
    bool annulerReservation(int id_reservation);
    void consulterReservationsClient(string nom_client);
    void consulterPassagersTrajet(int id_trajet);
    int consulterPlacesDisponibles(int id_trajet);
};
//4-1 Passager******************************************************************************************************************************************************************************************************************************
class Passager {
private:
    int id_passager;
    string nom;
    string prenom;
    int age;

public:

    Passager(int id,string nom,string prenom, int age);
    int getId() ;
    string getNom();
    string getPrenom();
    int getAge();
    void afficher();
    void modifier(string nom,string prenom, int age);
};
//4-2 Gestion des Passagers******************************************************************************************************************************************************************************************************************************
class GestionPassagers {
private:
    vector<Passager> passagers;  

public:
    void ajouterPassager(int id,string nom, string prenom, int age);
    bool modifierPassager(int id, string nom, string prenom, int age);
    bool supprimerPassager(int id);
    Passager* rechercherPassager(int id);
    void afficherPassagers() ;
    void afficherPassagersPourTrajet(int id_trajet) ;
};
//5 Historique******************************************************************************************************************************************************************************************************************************
class Historique {
private:
    vector<string> actions;

public:
    void enregistrerAction(string action);
    void afficherHistorique(int id_trajet); 
};




















//4-2 Gestion des Passagers******************************************************************************************************************************************************************************************************************************








