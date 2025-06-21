var textoDinamico = document.getElementById('dinamycText');
var counter = document.getElementById('Counter');
var heartSwitch = document.getElementById("heartSwitch");

var permanentHears = false;
var size = 52;
var delay = 1000/15; // ms
var amount = 16 //84
var heartSpawnTime = 250
var heartLifeTime = 750
var hearts = []

//----------------------------------------------------------------

function permanentHearsSwitched(){
    permanentHears = !permanentHears;
    if(permanentHears) {
        heartSpawnTime = 75
        heartSwitch.textContent = "¡CORAZONES!";
        heartSwitch.classList.replace("buttonRed", "buttonPink"); // Reemplazar una clase existente con otra nueva
    }else {
        heartSpawnTime = 250
        heartSwitch.textContent = "¿Corazones?";
        heartSwitch.classList.replace("buttonPink", "buttonRed");
    }
    for (var h of hearts){
        h.remove();
    }
    hearts = [];
}
heartSwitch.addEventListener("click", permanentHearsSwitched);

// HEART ANIMATION
let allowHeartCreation = true;

document.addEventListener("mousemove", function(event) {
    if (!allowHeartCreation) return;
    allowHeartCreation = false;

    var heart = document.createElement("div");
    heart.classList.add("heart");
    heart.style.left = event.pageX + "px";
    heart.style.top = event.pageY + "px";
    document.getElementById("heart-container").appendChild(heart);

    setTimeout(() => {
        allowHeartCreation = true;
    }, heartSpawnTime);
    setTimeout(() => {
        if(!permanentHears){heart.remove();}
        else {hearts.push(heart);}
    }, heartLifeTime); // Permitir la creación de corazones nuevamente después de medio segundo
});

// Función para leer el archivo de texto y mostrar líneas progresivamente
function startAnimation() {
    // Leer el archivo de texto línea por línea
    fetch('honeyFrames.txt') //.txt
    .then(response => response.text())
    .then(texto => {
        // Dividir el texto en líneas
        var lineas = texto.split('\n');
        var line = 0;
        for(let k = 0; k < 1000; k++) {
            for (let i = 0; i < lineas.length-size; i += size) {
                let bloqueDeLineas = lineas.slice(i, i + size);
                let textoBloque = bloqueDeLineas.join("\n"); // Convertir el bloque de líneas en una sola cadena de texto con saltos de línea
                setTimeout(() => {
                    textoDinamico.textContent = textoBloque; // Mostrar el bloque completo de líneas
                    line++;
                }, ((i / size) * delay) + k*amount*delay);
            }
        }
    });
}

startAnimation();
//setInterval(startAnimation, )