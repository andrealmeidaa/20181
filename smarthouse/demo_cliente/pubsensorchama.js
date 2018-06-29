var mqtt=require('mqtt');
var cliente=mqtt.connect('mqtt://mqtt.thingspeak.com:1883');//Troque a numeração para igual ao do seu raspberry

cliente.on('connect',function(){
    var temp=20;
    setInterval(function(){
        cliente.publish("channels/<id_Canal>/publish/fields/field1/<chave_canal>",temp.toString(),function(error){
				if(error)
					console.log(error);
				else
					console.log("Enviou corretamente - "+temp.toString());
			});
        temp=getRandomInt(1024);
    },5000);
});

function getRandomInt(max) {
    return Math.floor(Math.random() * Math.floor(max));
  }