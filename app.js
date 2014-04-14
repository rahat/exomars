
var express = require('express');
var path = require('path');
var favicon = require('static-favicon');
var logger = require('morgan');

var accountSid = 'AC94c76b0198e3919c75054a8ad7e58a1b';
var authToken = "377e4ea70d61917bb80663e2a39b92ef";

var client = require('twilio')(accountSid, authToken);

var app = express();

var server = app.listen(3000, function() {
    console.log('Listening on port %d', server.address().port);
});



app.get('/', function(req, res){
    
    var strings = {};
    var a = 0;

    client.messages.list(function(err, data){
      data.messages.forEach(function(messages){
       
        strings[a] = messages.body;
        a +=1;
        //res.send(messages.body);
    });

    //JSON.stringify(strings);
    res.send(strings);
})

});


module.exports = app;
