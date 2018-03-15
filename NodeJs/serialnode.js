var SerialPort = require('serialport');
var port = new SerialPort('/dev/ttyACM0', {
  baudRate: 9600
}, function(err){
    if (err) {
        return console.log('Erro na execução: ', err.message);
      }
      console.log('message written');
});


port.write("Vermelho ON");