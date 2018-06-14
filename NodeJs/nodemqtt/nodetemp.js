var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {

  var temperature = new five.Thermometer({
    pin: "5", freq:5000, toCelsius:function(raw){
			return (raw/sensivity)+offset;
		}
  });

  temperature.on("change", function() {
    console.log("celsius: %d", this.C);
  });
});
