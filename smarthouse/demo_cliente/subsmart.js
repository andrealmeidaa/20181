var mqtt=require('mqtt');
var cliente=mqtt.connect('mqtt://broker.mqttdashboard.com',{clientId:'par-xyz-001-sub'});

cliente.on('connect',function(){
    cliente.subscribe('smarthouse/par/motor');
    cliente.subscribe('smarthouse/par/led')
    console.log('Conectou');
});

cliente.on('message',function(topic,message,pacote){
    var comando=message.toString();
    if (topic=='smarthouse/par/motor'){
        console.log("Motor-"+comando);
    }else if(topic=='smarthouse/par/led'){
        console.log("LED-"+comando);
    }
});