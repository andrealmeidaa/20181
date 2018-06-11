var mqtt=require('mqtt');
var cliente=mqtt.connect('mqtt://broker.mqttdashboard.com',{clientId:'par-xyz-001-pub'});

cliente.on('connect',function(){
    var temp=20;
    setInterval(function(){
        cliente.publish("pariot/temperature",temp.toString());
        temp++;
    },5000);
});



