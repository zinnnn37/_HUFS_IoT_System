// 이제 센서 연결하면 됨

var http = require("http").createServer(handler);
var fs = require("fs");
var io = require("socket.io")(http);
var LED_GREEN = new Gpio(4, "out");
var LED_RED = new Gpio(5, "out");
var LED_YELLOW = new Gpio(6, "out");

http.listen(8080, function () {
    console.log("NodeJs Server is running...");
});

function handler(req, res) {
    fs.readFile(__dirname + "/public/index.html", function (err, data) {
        if (err) {
            res.writeHead(404, { "Content-Type": "text/html" });
            return res.end("404 Not Found");
        }
        res.writeHead(200, { "Content-Type": "text/html" });
        res.write(data);
        return res.end();
    });
}

var pir_value = 0;
var sock;
var data = [];
var i = 0;

function update_sensors() {
    pir_value = Math.floor(Math.random() * (10 - 1) + 1);
    if (pir_value >= 5) {
        sock.emit("pir", "PIR Detected");
        // pir GPIO on
        console.log("PIR Detected");
        pir_value = 0;
    } else {
        sock.emit("pir", "PIR NOT Detected");
        console.log("PIR NOT Detected");
        pir_value = 1;
    }
    data[0] = 50.0 + i;
    data[1] = 25.0 + i++;

    var temp = {
        humi: data[0],
        temp: data[1],
    };
    console.log(temp);
    sock.emit("temp", temp);
}

io.on("connection", function (socket) {
    var lightvalue = 0;
    sock = socket;
    setInterval(update_sensors, 3000);
    socket.on("light", function (data) {
        lightvalue = data;
        if (lightvalue == 1) {
            LED_GREEN.writeSync(green);
            console.log("Green LED is Turned On");
        } else if (lightvalue == 2) {
            LED_GREEN.writeSync(green);
            console.log("Green LED is Turned Off");
        } else if (lightvalue == 3) {
            LED_RED.writeSync(red);
            console.log("Red LED is Turned On");
        } else if (lightvalue == 4) {
            LED_RED.writeSync(red);
            console.log("Red LED is Turned Off");
        } else if (lightvalue == 5) {
            LED_YELLOW.writeSync(yellow);
            console.log("Yellow LED is Turned On");
        } else if (lightvalue == 6) {
            LED_YELLOW.writeSync(yellow);
            console.log("Yellow LED is Turned Off");
        }
    });
});
