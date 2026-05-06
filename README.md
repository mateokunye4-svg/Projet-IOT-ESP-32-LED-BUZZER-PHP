Ce projet IoT utilise une carte ESP32 pour envoyer des valeurs aléatoires à un serveur PHP. Une interface web en HTML, CSS et JavaScript permet d’afficher ces valeurs et de contrôler une LED et un buzzer. Le serveur PHP stocke et renvoie les données, tandis que l'ESP32 reçoit les commandes pour activer les composants électroniques.

Fonctionnement du système:

L’ESP32 génère et envoie régulièrement une valeur aléatoire vers un serveur web. Cette valeur est enregistrée côté serveur (dans un fichier PHP) puis affichée dynamiquement sur une page web.

En parallèle, l’ESP32 est connecté à deux composants :

-une LED.

-un buzzer.

Ces composants peuvent être contrôlés directement depuis l’interface web

Interface web (HTML / CSS / JS):

Une page web a été développée pour afficher les données et interagir avec l’ESP32 :

-HTML : structure de la page (affichage de la valeur, boutons de contrôle)

-CSS : design moderne et responsive de l’interface

-JavaScript : envoi de requêtes HTTP vers l’ESP32 pour contrôler la LED et le buzzer en temps réel (via fetch)

L’interface se met à jour automatiquement toutes les quelques secondes afin d’afficher la dernière valeur reçue.

Backend PHP:

Le serveur PHP joue un rôle de pont entre l’ESP32 et la page web :

-il reçoit les valeurs envoyées par l’ESP32

-il les stocke dans un fichier texte

-il les renvoie à la page web pour affichage

Cela permet une communication simple et efficace sans base de données complexe.

ESP32 (Arduino):

Le programme Arduino de l’ESP32 permet :

-la connexion au réseau Wi-Fi

-l’envoi périodique de valeurs aléatoires vers le serveur PHP

-la réception de commandes HTTP depuis la page web

-le contrôle de la LED et du buzzer en fonction des requêtes reçues

Résultat:

Le système permet :

-d’afficher des données en temps réel sur une page web

-de contrôler des composants physiques à distance

-de comprendre les bases de l’IoT (communication ESP32 ↔ serveur ↔ interface web)

Technologies utilisées:

-ESP32 (Arduino)

-PHP (backend serveur)

-HTML / CSS / JavaScript (frontend)

-HTTP (communication réseau)

-Ubuntu (environnement de développement)
