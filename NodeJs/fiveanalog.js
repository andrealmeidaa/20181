var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {
  var led = new five.Led(12);
  var sensorChama=new five.Sensor({pin:"A1",freq:5000});
  
  sensorChama.on("change",function(){
	var dado=this.scaleTo(0,100);
	console.log(this.scaleTo(0,100));
	if (dado<=20){
		led.on();
	}else{
		led.off();
	}
  
  });
  
  this.on("exit",function(){
	led.off();
	sensorChama.disable();
  });
});


