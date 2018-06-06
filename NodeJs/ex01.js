var http = require('http'); //Importa o pacote http

//Cria um servidor WEB, na porta 8080
//req --> Encapsula os dados e métodos relativos da requisição feita ao servidor
//res --> Encapsula os dados e métodos relativos a resposta a ser emitida pelo servidor.
http.createServer(function (req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'}); //Define o cabeçalho a ser escrito
    res.write('<h1>Primeiro programa Node.JS - Write<h1>');//Envia o conteúdo ao cliente
    res.end(); //Encerra a resposta
}).listen(8080);
