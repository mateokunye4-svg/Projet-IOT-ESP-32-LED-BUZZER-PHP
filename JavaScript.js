const ESP32 = "http://192.168.100.93";

//  LED
function sendLed() {
    fetch(ESP32 + "/led")
    .then(() => {
        showStatus("LED activée ", "#22c55e");
    })
    .catch(() => {
        showStatus("Erreur LED ", "#ef4444");
    });
}

//  BUZZER
function sendBuzz() {
    fetch(ESP32 + "/son")
    .then(() => {
        showStatus("Buzzer activé ", "#ef4444");
    })
    .catch(() => {
        showStatus("Erreur Buzzer ", "#ef4444");
    });
}

//  status dynamique
function showStatus(text, color) {
    let el = document.getElementById("etat");
    el.innerText = text;
    el.style.color = color;

    setTimeout(() => {
        el.innerText = "Prêt";
        el.style.color = "white";
    }, 2000);
}

//  refresh valeur ESP32
setInterval(() => {
    fetch("valeur.txt")
    .then(res => res.text())
    .then(data => {
        document.querySelector(".value").innerText = data;
    });
}, 2000);