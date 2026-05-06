<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

$file = __DIR__ . "/valeur.txt";

// Si c'est une requête POST, on enregistre la valeur
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_POST['valeur'])) {
        $valeur = $_POST['valeur'];
        $result = file_put_contents($file, $valeur);
        if ($result === false) {
            echo "Erreur écriture fichier";
        } else {
            echo "Valeur enregistrée : " . $valeur;
        }
    } else {
        echo "POST reçu mais pas de valeur";
    }
    exit; // On arrête ici pour ne pas afficher le GET aussi
}

// Si c'est une requête GET, on lit et affiche la dernière valeur
if (file_exists($file)) {
    $valeur = file_get_contents($file);
    echo "Dernière valeur reçue : " . htmlspecialchars($valeur);
} else {
    echo "Aucune valeur reçue pour l'instant.";
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Valeur Arduino</title>
    <!-- Rafraîchissement automatique toutes les 5 secondes -->
    <meta http-equiv="refresh" content="5">
    <link href="style.css" rel="stylesheet">
</head>
<body>
    <h1>Dernière valeur reçue de l'Arduino</h1>
    <div class="valeur"><?php echo $valeur; ?></div>
    <p>La page se rafraîchit automatiquement toutes les 5 secondes.</p>
    <button onclick="fetch('http://192.168.100.93/led')">
    Allumer Led
    </button>

    <button onclick="fetch('http://192.168.100.93/son')">
     Allumer Buzzer
    </button>

</body>
</html>