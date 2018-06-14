var mqtt=require('mqtt');
var five=require('johnny-five');
var cliente=mqtt.connect('mqtt://broker.mqttdashboard.com',{clientId:'par-xyz-002-sub'});
var board=five.Board();
cliente.on('connect',function(){
    cliente.subscribe('experimento/par/motor');
    console.log('Conectou');
});

board.on('ready',function(){
	var servo=new five.Servo({pin:5,type:'continuous'});

cliente.on('message',function(topic,message,pacote){
    var comando=message.toString();
    console.log(comando);
    
    if(comando=='ON')
		servo.cw(0.5);
	else
		servo.ccw(0.5);
});
});




