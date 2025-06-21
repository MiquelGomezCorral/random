var ws 

var nombreLabel = document.getElementById('nombreLabel');
var textInput = document.getElementById('textInput');
var sendingButton = document.getElementById('sendingButton');
var textBlock = document.getElementById('textBlock');

var nickName

// =============================================================
// EVENT LISTENERS
// =============================================================

function DissabletextInput(){
    sendingButton.disabled = textInput.value.trim() == ''
}
textInput.addEventListener('input', function() {
    DissabletextInput()
});

function registerUser(){
    console.log('register user as: ' + textInput.value);
    if (textInput.value.length == 0){
        return;
    }
    initWS()

    nickName = textInput.value
    
    textInput.value = '';
    textBlock.textContent = ''
    nombreLabel.textContent  = 'Mensaje: ';
    sendingButton.textContent  = 'Enviar';
    sendingButton.classList.replace("buttonRed", "buttonGreen"); 

    sendingButton.removeEventListener('click', registerUser);
    sendingButton.addEventListener('click', sendMSG);

    DissabletextInput()
}
sendingButton.addEventListener('click', registerUser);

// =============================================================
// WEBSOCKET FUNCTIONS 
// =============================================================

function sendMSG(){
    if(!ws) {
        console.log('NO Ws')
        return
    }
    
    msg = {user: nickName, message: textInput.value}

    textInput.value = ''

    showMSG(msg)
    ws.send(JSON.stringify(msg)); // Envía el nombre de usuario al servidor

    DissabletextInput()
}

function showMSG(msg){
    textBlock.textContent += `${msg.user}> ${msg.message}\n`  
    textBlock.scrollTop = textBlock.scrollHeight
}

function initWS(){
    if(ws){
        ws.onerror = ws.onopen = ws.onclose = null
        ws.close()
    }  

    ws = new WebSocket('ws://honeycum2024.ddns.net:9001');
    ws.onopen = function () {
        ws.send(JSON.stringify({newUser: nickName}))
        console.log('Connection opened!')
    }

    ws.addEventListener('message', function(event) {
        //showMSG(JSON.parse(event.data))       
        showMSG(JSON.parse(event.data))       
    });
    ws.onclose = function () {
        console.log('Connection closed')
        ws = null; 
    }
}

