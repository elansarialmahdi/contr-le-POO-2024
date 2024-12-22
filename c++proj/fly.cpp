#include"fly.h"
//1-1 destination******************************************************************************************************************************************************************************************************************************
int Destination::compteur_id = 0;

Destination::Destination(int id,string ville_depart,string ville_arrivee,string pays_depart,string pays_arrivee)
    :  ville_depart(ville_depart), ville_arrivee(ville_arrivee),pays_depart(pays_depart), pays_arrivee(pays_arrivee) 
	{
	++compteur_id;
	}

   int Destination::getId()
 { return id; }

    string Destination::getVilleDepart()
{ return ville_depart; }

string Destination::getVilleArrivee()
 { return ville_arrivee; }

string Destination::getPaysDepart()
 { return pays_depart; }

string Destination::getPaysArrivee()
 { return pays_arrivee; }

void Destination::modification(string ville_depart, string ville_arrivee, string pays_depart, string pays_arrivee) {
    if (ville_depart != "") 
        this->ville_depart = ville_depart;
    if (ville_arrivee != "") 
        this->ville_arrivee = ville_arrivee;
    if (pays_depart != "") 
        this->pays_depart = pays_depart;
    if (pays_arrivee != "") 
        this->pays_arrivee = pays_arrivee;
}
void Destination::afficher() {
    cout << "Destination " << id << ":: " << ville_depart << " ---> " << ville_arrivee<< ", " << pays_depart << " ---> " << pays_arrivee <<endl;
}
//1-2 gestion des destinations **********************************************************************************************************************************************************************************************

void GestionDestinations::ajouterDestination(string ville_depart,string ville_arrivee,string pays_depart,string pays_arrivee) {
    int id_dest = destinations.size() + 1;
    Destination nouvelle_dest(id_dest, ville_depart, ville_arrivee, pays_depart, pays_arrivee);
    destinations.push_back(nouvelle_dest);
    cout << "Destination ajoutée : " <<endl;
    nouvelle_dest.afficher();
}

void GestionDestinations::modifierDestination(int id_dest, string ville_depart,string ville_arrivee,string pays_depart,string pays_arrivee) {
    for (auto& dest : destinations) {
        if (dest.getId() == id_dest) {
            dest.modification(ville_depart, ville_arrivee, pays_depart, pays_arrivee);
            cout << "Destination mise à jour : " <<endl;
            dest.afficher();
            return;
        }
    }
    cout << "Destination non trouvée." <<endl;
}

void GestionDestinations::supprimerDestination(int id_dest) {
    bool trouve = false;
    
    
    for (int i = 0; i < destinations.size(); ++i) {
        if (destinations[i].getId() == id_dest) {
            cout << "Destination supprimée : " <<endl;
            destinations[i].afficher();
            destinations.erase(destinations.begin() + i); 
            trouve = true;
            break; 
        }
    }

    if (!trouve) {
    cout << "Destination non trouvée." <<endl;
    }
}


void GestionDestinations::rechercherDestinations(string ville_depart,string ville_arrivee) {
    bool trouve = false;
    
    for (auto& dest : destinations) {
        bool correspond_ville_depart = (ville_depart == "" || dest.getVilleDepart() == ville_depart);
        bool correspond_ville_arrivee = (ville_arrivee == "" || dest.getVilleArrivee() == ville_arrivee);
        
        if (correspond_ville_depart && correspond_ville_arrivee) {
            dest.afficher();
            trouve = true;
        }
    }

    if (trouve==false) {
    cout << "Aucune destination trouvée." <<endl;
    }
}

void GestionDestinations::afficherDestinations(){
    for ( auto& dest : destinations) {
        dest.afficher();
    }
}
//2-1 trajet ******************************************************************************************************************************************************************************************************************************


Trajet::Trajet(int id,string ville_depart,string ville_arrivee,string horaire, double prix)
: id(id), ville_depart(ville_depart), ville_arrivee(ville_arrivee), horaire(horaire), prix(prix) {}

int Trajet::getId() {
    return id;
}

string Trajet::getVilleDepart() {
    return ville_depart;
}

string Trajet::getVilleArrivee(){
    return ville_arrivee;
}

string Trajet::getHoraire(){
    return horaire;
}

double Trajet::getPrix(){
    return prix;
}

void Trajet::afficher() {
    cout << "ID: " << id << ", Départ: " << ville_depart << ", Arrivée: " << ville_arrivee << ", Horaire: " << horaire << ", Prix: " << prix << "DH" << std::endl;
}
//2-2 gestions des trajets ******************************************************************************************************************************************************************************************************************************
void GestionTrajets::ajouterTrajet(int id,string ville_depart,string ville_arrivee,string horaire, double prix) {
    trajets.push_back(Trajet(id, ville_depart, ville_arrivee, horaire, prix));
}

void GestionTrajets::modifierTrajet(int id,string ville_depart,string ville_arrivee,string horaire, double prix) {
    for (auto& trajet : trajets) {
        if (trajet.getId() == id) {
            trajet = Trajet(id, ville_depart, ville_arrivee, horaire, prix);
            cout << "Trajet modifié : " <<endl;
            trajet.afficher();
            return;
        }
    }
    cout << "Trajet non trouvé." <<endl;
}

void GestionTrajets::supprimerTrajet(int id) {
    bool trouve = false;
    for (size_t i = 0; i < trajets.size(); ++i) {
        if (trajets[i].getId() == id) {
            trajets.erase(trajets.begin() + i);
            cout << "Trajet supprimé." <<endl;
            trouve = true;
            break;
        }
    }

    if (!trouve) {
        cout << "Trajet non trouvé." <<endl;
    }
}

void GestionTrajets::afficherTrajets(string ville_depart,string ville_arrivee){
    bool trouve = false;
    for ( auto& trajet : trajets) {
        if (trajet.getVilleDepart() == ville_depart && trajet.getVilleArrivee() == ville_arrivee) {
            trajet.afficher();
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucun trajet trouvé pour cette destination." <<endl;
    }
}

void GestionTrajets::consulterTrajet(int id){
    for (auto& trajet : trajets) {
        if (trajet.getId() == id) {
            trajet.afficher();
            return;
        }
    }
    cout << "Trajet non trouvé." <<endl;
}
//3-1 reservation*************************************************************************************************************************************************************************************************************************************************
Reservation::Reservation(int id,string nom_client, int id_trajet, int nombre_places)
    : id(id), nom_client(nom_client), id_trajet(id_trajet), nombre_places(nombre_places) {}

int Reservation::getId() {
    return id;
}

string Reservation::getNomClient() {
    return nom_client;
}

int Reservation::getIdTrajet()  {
    return id_trajet;
}

int Reservation::getNombrePlaces()  {
    return nombre_places;
}

void Reservation::afficher()  {
   cout << "Réservation ID: " << id << ", Client: " << nom_client << ", Trajet ID: " << id_trajet<< ", Places réservées: " << nombre_places <<endl;
}
//3-2 gestion des reservations*************************************************************************************************************************************************************************************************************************************************

bool GestionReservations::ajouterReservation(string nom_client, int id_trajet, int nombre_places) {
    int places_disponibles = consulterPlacesDisponibles(id_trajet);
    if (places_disponibles >= nombre_places) {
        int id_reservation = reservations.size() + 1;  
        reservations.push_back(Reservation(id_reservation, nom_client, id_trajet, nombre_places));
        places_disponibles -= nombre_places;
      this->places_disponibles[id_trajet]=places_disponibles;
        cout << "Réservation ajoutée avec succès !" << endl;
        return true;
    } else {
        cout << "Pas assez de places disponibles." <<endl;
        return false;
    }
}


bool GestionReservations::annulerReservation(int id_reservation) {
    bool trouve = false;
    for ( int i = 0; i < reservations.size(); ++i) {
        if (reservations[i].getId() == id_reservation) {
           
            int id_trajet = reservations[i].getIdTrajet();
            int nombre_places = reservations[i].getNombrePlaces();

            reservations.erase(reservations.begin() + i);

            places_disponibles[id_trajet] += nombre_places;
            
            cout << "Réservation annulée." << endl;
            trouve = true;
            break;  
        }
    }
    
    if (!trouve) {
        cout << "Réservation non trouvée." <<endl;
        return false;
    }

    return true;
}


void GestionReservations::consulterReservationsClient(string nom_client) {
    bool trouve = false;
    for ( auto& res : reservations) {
        if (res.getNomClient() == nom_client) {
            res.afficher();
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucune réservation trouvée pour ce client." <<endl;
    }
}

void GestionReservations::consulterPassagersTrajet(int id_trajet){
    bool trouve = false;
    for (auto& res : reservations) {
        if (res.getIdTrajet() == id_trajet) {
            res.afficher();
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucun passager trouvé pour ce trajet." << endl;
    }
}

int GestionReservations::consulterPlacesDisponibles(int id_trajet)  {
    return places_disponibles[id_trajet];
}
//4-1 Passager*************************************************************************************************************************************************************************************************************************************************


Passager::Passager(int id,string nom,string prenom, int age): id_passager(id), nom(nom), prenom(prenom), age(age) {}

int Passager::getId(){
    return id_passager;
}

string Passager::getNom()  {
    return nom;
}

string Passager::getPrenom(){
    return prenom;
}

int Passager::getAge(){
    return age;
}

void Passager::afficher()  {
    cout << "ID: " << id_passager << ", Nom: " << nom << ", Prenom: " << prenom << ", Age: " << age <<endl;
}

void Passager::modifier(string nom, string prenom, int age) {
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
}
//4-2 Gestion des Passagers*************************************************************************************************************************************************************************************************************************************************

void GestionPassagers::ajouterPassager(int id, string nom, string prenom, int age) {
    passagers.push_back(Passager(id, nom, prenom, age));
}

bool GestionPassagers::modifierPassager(int id, string nom, string prenom, int age) {
    for (auto& passager : passagers) {
        if (passager.getId() == id) {
            passager.modifier(nom, prenom, age);
            return true;
        }
    }
    std::cout << "Passager non trouvé." << std::endl;
    return false;
}

bool GestionPassagers::supprimerPassager(int id) {
    for (size_t i = 0; i < passagers.size(); ++i) {
        if (passagers[i].getId() == id) {
            passagers.erase(passagers.begin() + i);
            cout << "Passager supprimé." << endl;
            return true;
        }
    }
    cout << "Passager non trouvé." <<endl;
    return false;
}
Passager* GestionPassagers::rechercherPassager(int id) {
    for (auto& passager : passagers) {
        if (passager.getId() == id) {
            return &passager;
        }
    }
    return nullptr;
}

void GestionPassagers::afficherPassagers() {
    for ( auto& passager : passagers) {
        passager.afficher();
    }
}

void GestionPassagers::afficherPassagersPourTrajet(int id_trajet) {
    cout << "Affichage des passagers pour le trajet " << id_trajet << " : " <<endl;
    afficherPassagers(); 
}
//5 Historique*************************************************************************************************************************************************************************************************************************************************
void Historique::enregistrerAction(string action) {
    actions.push_back(action); 
}

void Historique::afficherHistorique(int id_trajet) {
    cout << "Historique des actions pour le trajet " << id_trajet <<endl;
    for ( auto& action : actions) {
        cout << action <<endl; 
    }
}

















