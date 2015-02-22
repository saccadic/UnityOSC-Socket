var PORT = 8085;
var HOST = '127.0.0.1';

var dgram = require('dgram');
var server = dgram.createSocket('udp4');

server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});


var fs = require('fs');
server.on('message', function (message, remote) {
    var buf = new Buffer(message);
    console.log(message +"");
    console.log(buf);
    
    

fs.writeFile('data_o2.txt', buf);

});

server.bind(PORT, HOST);