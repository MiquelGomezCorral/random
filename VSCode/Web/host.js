const http = require('http');
const fs = require('fs');
const path = require('path');
const WebSocket = require('ws');

//
const server = http.createServer(function (req, res) {
  // Ruta del recurso solicitado
  let filePath = '.' + req.url;
  // Si la URL solicitada es '/', envía el archivo index.html
  if (filePath === './') {
    filePath = './index.html';
  }
  // Obtener la extensión del archivo solicitado
  let extname = String(path.extname(filePath)).toLowerCase();
  // Configurar el tipo de contenido según la extensión del archivo
  let contentType = 'text/html';
  switch (extname) {
    case '.js':
      contentType = 'text/javascript';
      break;
    case '.css': // Agregar caso para archivos CSS
      contentType = 'text/css';
      break;
    case '.txt': // Enviar el contenido del archivo de texto de manera diferente
      sendTextFile(filePath, res);
      return;
  }

  // Leer el archivo solicitado y enviarlo al cliente
  fs.readFile(filePath, function (err, data) {
    if (err) {
      if (err.code === 'ENOENT') {
        // Si el archivo no se encuentra, enviar una respuesta 404
        res.writeHead(404);
        res.end('404 Not Found');
      } else {
        // Si hay otros errores, enviar una respuesta 500
        res.writeHead(500);
        res.end('500 Internal Server Error: ' + err.code);
      }
    } else {
      // Si el archivo se encuentra, enviarlo al cliente con el tipo de contenido correspondiente
      res.writeHead(200, {'Content-Type': contentType});
      res.end(data, 'utf-8');
    }
  });
  logInfo('CLIENTE CONECTADO: '+filePath)
});

function sendTextFile(filePath, res) {
  // Leer el archivo de texto y enviarlo al cliente línea por línea
  fs.readFile(filePath, 'utf8', function(err, data) {
    if (err) {
      // Si hay un error al leer el archivo, enviar una respuesta 500
      res.writeHead(500);
      res.end('500 Internal Server Error: ' + err.code);
    } else {
      // Si el archivo se lee correctamente, enviar cada línea al cliente
      res.writeHead(200, {'Content-Type': 'text/plain'});
      data.split('\n').forEach(line => {
        res.write(line + '\n');
      });
      res.end();
    }
  });
}


const wss = new WebSocket.Server({ server });
let defaulConnectedUserMessage = {user: 'SERVER', message: '!NEW USER! Say hi to '}

wss.on('connection', function connection(ws) {
  ws.on('message', function incoming(message) {
    let messageJSON = JSON.parse(message)

    if(messageJSON.newUser){
      let user = messageJSON.newUser
      messageJSON = {...defaulConnectedUserMessage};
      messageJSON.message += user
    }

    logInfo(messageJSON)

    wss.clients.forEach(function each(client){
      if (client == ws || client.readyState != WebSocket.OPEN)
        return
      client.send(JSON.stringify(messageJSON));
    })
  });
});

function logInfo(info){
  let dateHour = new Date();
  dateHour = `${dateHour.getDate()}/${dateHour.getMonth() + 1}/${dateHour.getFullYear()} ${dateHour.getHours()}:${dateHour.getMinutes()}:${dateHour.getSeconds()}`
  console.log(dateHour + ": %s",info);
}

const PORT = 9001;
server.listen(PORT, () => {
  console.log(`Servidor en ejecución en el puerto ${PORT}`);
});


