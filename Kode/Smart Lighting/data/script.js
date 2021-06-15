var ws = new WebSocket("ws://192.168.43.25/test");

var LEDSTATE;

function LEDswitch(button)  {
  var x = document.getElementById(button);
  var on = 1;
  var off = 0;
  switch (LEDSTATE)  {
    case false:
      document.getElementById(button).style.background = "Red";
      ws.send(JSON.stringify({'id': 2, 'state': 0}));
      break;
    case true:
      document.getElementById(button).style.background = "LawnGreen";
      ws.send(JSON.stringify({'id': 2, 'state': 1}));;
      break;
  }
  getstate();
}

function hexToRgb(hex) {
  var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
  var r = parseInt(result[1],16);
  var g = parseInt(result[2],16);
  var b = parseInt(result[3],16);
  ws.send(JSON.stringify({'id': 3, 'r': r, 'g' : g, 'b' : b}));
}


function preset1(button1, button2, button3, button4, button5, button6, button7)  {
  document.getElementById(button1).style.background = "LawnGreen";
  document.getElementById(button2).style.background = "#F9F6EE";
  document.getElementById(button3).style.background = "#F9F6EE";
  document.getElementById(button4).style.background = "#F9F6EE";
  document.getElementById(button5).style.background = "#F9F6EE";
  document.getElementById(button6).style.background = "#F9F6EE";
  document.getElementById(button7).style.background = "#F9F6EE";
  ws.send(JSON.stringify({'id': 4}));
}
function preset2(button1, button2, button3, button4, button5, button6, button7)  {
  document.getElementById(button2).style.background = "LawnGreen";
  document.getElementById(button1).style.background = "#F9F6EE";
  document.getElementById(button3).style.background = "#F9F6EE";
  document.getElementById(button4).style.background = "#F9F6EE";
  document.getElementById(button5).style.background = "#F9F6EE";
  document.getElementById(button6).style.background = "#F9F6EE";
  document.getElementById(button7).style.background = "#F9F6EE";
  ws.send(JSON.stringify({'id': 5}));
}
function preset3(button1, button2, button3, button4, button5, button6, button7)  {
  document.getElementById(button3).style.background = "LawnGreen";
  document.getElementById(button1).style.background = "#F9F6EE";
  document.getElementById(button2).style.background = "#F9F6EE";
  document.getElementById(button4).style.background = "#F9F6EE";
  document.getElementById(button5).style.background = "#F9F6EE";
  document.getElementById(button6).style.background = "#F9F6EE";
  document.getElementById(button7).style.background = "#F9F6EE";
  ws.send(JSON.stringify({'id': 6}));
}
function preset4(button1, button2, button3, button4, button5, button6, button7)  {
  document.getElementById(button4).style.background = "LawnGreen";
  document.getElementById(button1).style.background = "#F9F6EE";
  document.getElementById(button2).style.background = "#F9F6EE";
  document.getElementById(button3).style.background = "#F9F6EE";
  document.getElementById(button5).style.background = "#F9F6EE";
  document.getElementById(button6).style.background = "#F9F6EE";
  document.getElementById(button7).style.background = "#F9F6EE";
  ws.send(JSON.stringify({'id': 7}));
}
function preset5(button1, button2, button3, button4, button5, button6, button7)  {
  document.getElementById(button5).style.background = "LawnGreen";
  document.getElementById(button1).style.background = "#F9F6EE";
  document.getElementById(button2).style.background = "#F9F6EE";
  document.getElementById(button3).style.background = "#F9F6EE";
  document.getElementById(button4).style.background = "#F9F6EE";
  document.getElementById(button6).style.background = "#F9F6EE";
  document.getElementById(button7).style.background = "#F9F6EE";
  ws.send(JSON.stringify({'id': 8}));
}
function preset6(button1, button2, button3, button4, button5, button6, button7)  {
  document.getElementById(button6).style.background = "LawnGreen";
  document.getElementById(button1).style.background = "#F9F6EE";
  document.getElementById(button2).style.background = "#F9F6EE";
  document.getElementById(button3).style.background = "#F9F6EE";
  document.getElementById(button4).style.background = "#F9F6EE";
  document.getElementById(button5).style.background = "#F9F6EE";
  document.getElementById(button7).style.background = "#F9F6EE";
  ws.send(JSON.stringify({'id': 9}));
}
function preset7(button1, button2, button3, button4, button5, button6, button7)  {
  document.getElementById(button7).style.background = "LawnGreen";
  document.getElementById(button1).style.background = "#F9F6EE";
  document.getElementById(button2).style.background = "#F9F6EE";
  document.getElementById(button3).style.background = "#F9F6EE";
  document.getElementById(button4).style.background = "#F9F6EE";
  document.getElementById(button5).style.background = "#F9F6EE";
  document.getElementById(button6).style.background = "#F9F6EE";
  ws.send(JSON.stringify({'id': 10}));
}

function getState() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      const jsonresponse = JSON.parse(this.responseText);
      LEDSTATE = jsonresponse.state;
    }
  };
  xhttp.open("GET", "/getState", true);
  xhttp.send();
}
