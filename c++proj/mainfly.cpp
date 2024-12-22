#include"fly.h"
int main() {
	
	 int choix;
    do {
    
        cout << "\n**===== Menu Principal =====**\n";
        cout << "1. Gestion des Destinations\n";
        cout << "2. Gestion des Trajets\n";
        cout << "3. Gestion des Réservations\n";
        cout << "4. Gestion des Passagers\n";
        cout << "5. Historique\n";
        cout << "6. Quitter\n";
        cout << "Veuillez entrer votre choix (1-6): ";
        cin >> choix;

        switch (choix) {
            case 1: {
///1-menu de la gestion des destinations****************************************************************************************************************************************************************************************************************************
    GestionDestinations gestionDestinations;
    
    int choix1;
    do {
        cout << "\n===== Menu Gestion des Destinations =====\n";
        cout << "1. Ajouter une destination\n";
        cout << "2. Modifier une destination\n";
        cout << "3. Supprimer une destination\n";
        cout << "4. Rechercher des destinations\n";
        cout << "5. Afficher toutes les destinations\n";
        cout << "6. Quitter\n";
        cout << "Veuillez entrer votre choix (1-6): ";
        cin >> choix1;

        switch (choix1) {
            case 1: {
                string ville_depart, ville_arrivee, pays_depart, pays_arrivee;
                cout << "Entrez la ville de départ : ";
                cin.ignore();
                cin>> ville_depart;
                cout << "Entrez la ville d'arrivée : ";
                cin>> ville_arrivee;
                cout << "Entrez le pays de départ : ";
                cin>> pays_depart;
                cout << "Entrez le pays d'arrivée : ";
                cin>> pays_arrivee;

                gestionDestinations.ajouterDestination(ville_depart, ville_arrivee, pays_depart, pays_arrivee);
                break;
            }
            case 2: {
                int id_dest;
                cout << "Entrez l'ID de la destination à modifier : ";
                cin >> id_dest;

                string ville_depart, ville_arrivee, pays_depart, pays_arrivee;
                cout << "Entrez la nouvelle ville de départ (laisser vide pour ne pas modifier) : ";
                cin.ignore();
                cin>> ville_depart;
                cout << "Entrez la nouvelle ville d'arrivée (laisser vide pour ne pas modifier) : ";
                cin>> ville_arrivee;
                cout << "Entrez le nouveau pays de départ (laisser vide pour ne pas modifier) : ";
                cin>> pays_depart;
                cout << "Entrez le nouveau pays d'arrivée (laisser vide pour ne pas modifier) : ";
                cin>> pays_arrivee;

                gestionDestinations.modifierDestination(id_dest, ville_depart, ville_arrivee, pays_depart, pays_arrivee);
                break;
            }
            case 3: {
                int id_dest;
                cout << "Entrez l'ID de la destination à supprimer : ";
                cin >> id_dest;

                gestionDestinations.supprimerDestination(id_dest);
                break;
            }
            case 4: {
                string ville_depart, ville_arrivee;
                cout << "Entrez la ville de départ (laisser vide pour ne pas filtrer) : ";
                cin.ignore();
                cin>> ville_depart;
                cout << "Entrez la ville d'arrivée (laisser vide pour ne pas filtrer) : ";
                cin>> ville_arrivee;

                gestionDestinations.rechercherDestinations(ville_depart, ville_arrivee);
                break;
            }
            case 5: {
                gestionDestinations.afficherDestinations();
                break;
            }
            case 6:
                cout << "Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while (choix1 != 6);
	break;
	}
    case 2: {
///2-menu de gestions des trajets *********************************************************************************************************************************************************************************************************************************
 GestionTrajets gestionTrajets;
    
    int choix2;
    do {
      
        cout << "\n===== Menu Gestion des Trajets =====\n";
        cout << "1. Ajouter un trajet\n";
        cout << "2. Modifier un trajet\n";
        cout << "3. Supprimer un trajet\n";
        cout << "4. Afficher les trajets d'une destination\n";
        cout << "5. Consulter un trajet\n";
        cout << "6. Quitter\n";
        cout << "Veuillez entrer votre choix (1-6): ";
        cin >> choix2;

        switch (choix2) {
            case 1: {
              
                int id;
                string ville_depart, ville_arrivee, horaire;
                double prix;

                cout << "Entrez l'ID du trajet : ";
                cin >> id;
                cin.ignore();
                cout << "Entrez la ville de départ : ";
                cin>> ville_depart;
                cout << "Entrez la ville d'arrivée : ";
                cin>> ville_arrivee;
                cout << "Entrez l'horaire du trajet : ";
                cin>> horaire;
                cout << "Entrez le prix du trajet : ";
                cin >> prix;

                gestionTrajets.ajouterTrajet(id, ville_depart, ville_arrivee, horaire, prix);
                break;
            }
            case 2: {
               
                int id;
                string ville_depart, ville_arrivee, horaire;
                double prix;

                cout << "Entrez l'ID du trajet à modifier : ";
                cin >> id;
                cin.ignore();
                cout << "Entrez la nouvelle ville de départ : ";
                cin>> ville_depart;
                cout << "Entrez la nouvelle ville d'arrivée : ";
                cin>> ville_arrivee;
                cout << "Entrez le nouvel horaire : ";
                cin>> horaire;
                cout << "Entrez le nouveau prix : ";
                cin >> prix;

                gestionTrajets.modifierTrajet(id, ville_depart, ville_arrivee, horaire, prix);
                break;
            }
            case 3: {
               
                int id;
                cout << "Entrez l'ID du trajet à supprimer : ";
                cin >> id;

                gestionTrajets.supprimerTrajet(id);
                break;
            }
            case 4: {
              
                string ville_depart, ville_arrivee;
                cout << "Entrez la ville de départ : ";
                cin.ignore();
                cin>> ville_depart;
                cout << "Entrez la ville d'arrivée : ";
                cin>> ville_arrivee;

                gestionTrajets.afficherTrajets(ville_depart, ville_arrivee);
                break;
            }
            case 5: {
               
                int id;
                cout << "Entrez l'ID du trajet à consulter : ";
                cin >> id;

                gestionTrajets.consulterTrajet(id);
                break;
            }
            case 6:
                cout << "Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while (choix2 != 6);
	break;
	}
    case 3: {
///3-gestions des reservations ***************************************************************************************************************************************************************************************************************************************************
GestionReservations gestionReservations;
    
    int choix3;
    do {

        cout << "\n===== Menu Gestion des Réservations =====\n";
        cout << "1. Ajouter une réservation\n";
        cout << "2. Annuler une réservation\n";
        cout << "3. Consulter les réservations d'un client\n";
        cout << "4. Consulter les passagers d'un trajet\n";
        cout << "5. Consulter les places disponibles pour un trajet\n";
        cout << "6. Quitter\n";
        cout << "Veuillez entrer votre choix (1-6): ";
        cin >> choix3;

        switch (choix3) {
            case 1: {
              
                string nom_client;
                int id_trajet, nombre_places;

                cout << "Entrez le nom du client : ";
                cin.ignore();  
                cin>> nom_client;
                cout << "Entrez l'ID du trajet : ";
                cin >> id_trajet;
                cout << "Entrez le nombre de places réservées : ";
                cin >> nombre_places;

                gestionReservations.ajouterReservation(nom_client, id_trajet, nombre_places);
                break;
            }
            case 2: {
              
                int id_reservation;
                cout << "Entrez l'ID de la réservation à annuler : ";
                cin >> id_reservation;

                gestionReservations.annulerReservation(id_reservation);
                break;
            }
            case 3: {
                
                string nom_client;
                cout << "Entrez le nom du client : ";
                cin.ignore();
                cin>> nom_client;

                gestionReservations.consulterReservationsClient(nom_client);
                break;
            }
            case 4: {
               
                int id_trajet;
                cout << "Entrez l'ID du trajet : ";
                cin >> id_trajet;

                gestionReservations.consulterPassagersTrajet(id_trajet);
                break;
            }
            case 5: {
               
                int id_trajet;
                cout << "Entrez l'ID du trajet : ";
                cin >> id_trajet;

                int places_disponibles = gestionReservations.consulterPlacesDisponibles(id_trajet);
                cout << "Places disponibles pour le trajet ID " << id_trajet << " : " << places_disponibles << endl;
                break;
            }
            case 6:
                cout << "Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while (choix3 != 6);
	break;
	}
    case 4: {
///4-gestions des passagers *****************************************************************************************************************************************************************************************************************************************
 GestionPassagers gestionPassagers;
    
    int choix4;
    do {
      
        cout << "\n===== Menu Gestion des Passagers =====\n";
        cout << "1. Ajouter un passager\n";
        cout << "2. Modifier un passager\n";
        cout << "3. Supprimer un passager\n";
        cout << "4. Rechercher un passager\n";
        cout << "5. Afficher tous les passagers\n";
        cout << "6. Afficher les passagers pour un trajet\n";
        cout << "7. Quitter\n";
        cout << "Veuillez entrer votre choix (1-7): ";
        cin >> choix4;

        switch (choix4) {
            case 1: {
              
                int id, age;
                string nom, prenom;

                cout << "Entrez l'ID du passager : ";
                cin >> id;
                cout << "Entrez le nom du passager : ";
                cin.ignore();  
                cin>> nom;
                cout << "Entrez le prénom du passager : ";
                cin>> prenom;
                cout << "Entrez l'âge du passager : ";
                cin >> age;

                gestionPassagers.ajouterPassager(id, nom, prenom, age);
                break;
            }
            case 2: {
               
                int id, age;
                string nom, prenom;

                cout << "Entrez l'ID du passager à modifier : ";
                cin >> id;
                cout << "Entrez le nouveau nom du passager : ";
                cin.ignore();  
                cin>> nom;
                cout << "Entrez le nouveau prénom du passager : ";
                cin>> prenom;
                cout << "Entrez le nouvel âge du passager : ";
                cin >> age;

                if (!gestionPassagers.modifierPassager(id, nom, prenom, age)) {
                    cout << "Erreur : Passager non trouvé.\n";
                }
                break;
            }
            case 3: {
                
                int id;
                cout << "Entrez l'ID du passager à supprimer : ";
                cin >> id;

                if (!gestionPassagers.supprimerPassager(id)) {
                    cout << "Erreur : Passager non trouvé.\n";
                }
                break;
            }
            case 4: {
            
                int id;
                cout << "Entrez l'ID du passager à rechercher : ";
                cin >> id;

                Passager* passager = gestionPassagers.rechercherPassager(id);
                if (passager) {
                    cout << "Passager trouvé : \n";
                    passager->afficher();
                } else {
                    cout << "Passager non trouvé.\n";
                }
                break;
            }
            case 5: {
                
                cout << "Liste des passagers : \n";
                gestionPassagers.afficherPassagers();
                break;
            }
            case 6: {
               
                int id_trajet;
                cout << "Entrez l'ID du trajet pour afficher les passagers : ";
                cin >> id_trajet;

                gestionPassagers.afficherPassagersPourTrajet(id_trajet);
                break;
            }
            case 7:
                cout << "Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while (choix4 != 7);
	break;}
    case 5: {
    //5-historique *************************************************************************************************************************************************************************************************************************************************************************
Historique historique;
    
    int choix5;
    do {
        cout << "\n===== Menu Historique =====\n";
        cout << "1. Enregistrer une action\n";
        cout << "2. Afficher l'historique des actions pour un trajet\n";
        cout << "3. Quitter\n";
        cout << "Veuillez entrer votre choix (1-3): ";
        cin >> choix5;

        switch (choix5) {
            case 1: {
                string action;
                cout << "Entrez l'action à enregistrer : ";
                cin.ignore();  
                cin>> action;
                historique.enregistrerAction(action);
                cout << "Action enregistrée avec succès.\n";
                break;
            }
            case 2: {
               
                int id_trajet;
                cout << "Entrez l'ID du trajet pour afficher l'historique : ";
                cin >> id_trajet;
                historique.afficherHistorique(id_trajet);
                break;
            }
            case 3:
                cout << "Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while (choix5 != 3);
	break;
	}
    case 6:
                cout << "Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while (choix != 6);
	
	
	
	
	
	
	











































    return 0;
}

































