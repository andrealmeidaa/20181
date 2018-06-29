var express = require('express');
var router = express.Router();
var mqtt=require('mqtt');
var cliente=mqtt.connect('mqtt://broker.mqttdashboard.com');
/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index.html', { title: 'SmartHouse - Parnamirim - V2' });
});

router.get('/ligarled',function(req,res,next){
  var param=req.param("acao");
  cliente.publish("smarthouse/par/led",param,function(error){
    if(error)
      console.log(error);
    else
      console.log("Enviou corretamente LED - "+param);
  });
  res.render('index.html', { title: 'SmartHouse - Parnamirim - V2' });
});

router.get('/ligarmotor',function(req,res,next){
  var param=req.param("acao");
  cliente.publish("smarthouse/par/motor",param,function(error){
    if(error)
      console.log(error);
    else
      console.log("Enviou corretamente Motor - "+param);
  });
  res.render('index.html', { title: 'SmartHouse - Parnamirim - V2' });
});

module.exports = router;
