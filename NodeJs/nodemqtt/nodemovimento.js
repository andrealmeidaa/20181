var five = require("johnny-five");
var board = new five.Board();
var mqtt=require('mqtt');
var cliente=mqtt.connect('mqtt://broker.mqttdashboard.com',{clientId:'par-xyz-001-pub'});
board.on("ready", function() {

  var motion = new five.Motion(7);

  motion.on("calibrated", function() {
    console.log("Calibrado");
  });

  motion.on("change",function(){
	var comando;
	if (this.detectedMotion){
		console.log("Movimento");
		comando="ON";
	}else{
		console.log("Ausência Movimento");
		comando="OFF";
	}
	
	cliente.publish("experimento/par/motor",comando,function(error){
	if(error)
		console.log(error);
	else
		console.log("Enviou corretamente - "+comando);
	});
  });

  
});
