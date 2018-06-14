var five = require("johnny-five");
var board = new five.Board();
var ThingSpeakClient=require("thingspeakclient");
var clienteThingSpeak=new ThingSpeakClient();
var CHANNELID=514823;
var API_KEY="EM9X7J4XLMSFK6FM";

clienteThingSpeak.attachChannel(CHANNELID,
{writeKey:API_KEY},retornoThingSpeak);


board.on("ready", function() {
  var led = new five.Led(12);
  var sensorChama=new five.Sensor({pin:"A1",freq:5000});
  
  sensorChama.on("change",function(){
	var dado=this.scaleTo(0,100);
	if (dado!=null){
		clienteThingSpeak.updateChannel(CHANNELID,
		{field1:dado},retornoThingSpeak);
		console.log(this.scaleTo(0,100));
		if (dado<=20){
			led.on();
		}else{
			led.off();
		}
	}
	
  
  });
  
  this.on("exit",function(){
	led.off();
	sensorChama.disable();
  });
});

function retornoThingSpeak(error,response){
	if (!error && response>0){
		console.log("Conectou");
	}else{
		console.log(error);
	}
}


