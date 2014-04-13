var twilio = require('twilio'),
    SerialPort = require("serialport").SerialPort,
    express = require('express');
 
var app = express();
 
function sendMessage(res, message) {
  var resp = new twilio.TwimlResponse();
  resp.message(message);
  res.type('text/xml');
  res.send(resp.toString());
}
 
var serialPort = new SerialPort("/dev/tty.usbmodem1411", {
  baudrate: 9600
});
 
app.use(express.bodyParser());
 
app.post('/sms', twilio.webhook('your auth token', { host:'foo.herokuapp.com', protocol:'https' }), function(req, res){

 
    serialPort.once('data', function(data) {
      if (data.toString() == "left") { 
        sendMessage(res, 'Moving Left!');
      }
      else if (data.toString() == "right") {
        sendMessage(res, 'Moving Right!');
      }
      else {
        sendMessage(res, 'Moving Forward!');
      }
      console.log('data received: ' + data);
    }
  });
 
serialPort.open( function () {
  app.listen(3000);
  console.log('Listening on port 3000');
});