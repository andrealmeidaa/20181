var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {
  var led = new five.Led(12);
  led.blink(1000);
  
  this.on("exit",function(){
	led.off();
  });
});


