
var http = require('http'); //Importa o pacote http
var fileSystem=require('fs');
var GPIO=require('onoff').Gpio;
var LED=new GPIO(23,'out'); //Usa o modelo BCM dos pinos

http.createServer(function (request, response) {
	fileSystem.readFile('led.html',function(error,data){
	if (error) throw error;
	var dadoRequisicao=request.url;
	if (dadoRequisicao=='/on'){
		LED.writeSync(1);
	}else if(dadoRequisicao=='/off'){
		LED.writeSync(0);
	}
	response.write(data);
	response.end()
	
});
    
}).listen(8080);

process.on('SIGINT', function () { 
  LED.writeSync(0); 
  LED.unexport(); 
  process.exit(); 
});
