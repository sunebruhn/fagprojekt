var ws = new WebSocket("ws://192.168.43.25/test");

/*
function LEDswitch(button)  {
  var x = document.getElementById(button);
  var on = 1;
  var off = 0;
  getState();
  switch (LEDSTATE)  {
    case false:
      document.getElementById(button).style.background = "Red";
      document.getElementById(button).innerHTML = "Off";
      ws.send(JSON.stringify({'id': 2, 'state': 0}));
      break;
    case true:
      document.getElementById(button).style.background = "LawnGreen";
      document.getElementById(button).innerHTML = "On";
      ws.send(JSON.stringify({'id': 2, 'state': 1}));;
      break;
  }
  getState();
}
*/

function hexToRgb(hex) {
  var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
  var r = parseInt(result[1],16);
  var g = parseInt(result[2],16);
  var b = parseInt(result[3],16);
  ws.send(JSON.stringify({'id': 3, 'r': r, 'g' : g, 'b' : b}));
}


function preset1(button1, button2, button3, button4, button5, button6, button7)  {
  switch(document.getElementById('mode').innerHTML) {
  case "1":
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 4}));
    break;
  default:
    document.getElementById(button1).style.background = "LawnGreen";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 5}));
    break;
  }
  getState();
}

function preset2(button1, button2, button3, button4, button5, button6, button7)  {
  switch(document.getElementById('mode').innerHTML) {
  case "2":
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 4}));
    break;
  default:
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "LawnGreen";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 6}));
    break;
  }
  getState();
}

function preset3(button1, button2, button3, button4, button5, button6, button7)  {
  switch(document.getElementById('mode').innerHTML) {
  case "3":
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 4}));
    break;
  default:
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "LawnGreen";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 7}));
    break;
  }
  getState();
}

function preset4(button1, button2, button3, button4, button5, button6, button7)  {
  switch(document.getElementById('mode').innerHTML) {
  case "4":
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 4}));
    break;
  default:
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "LawnGreen";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 8}));
    break;
  }
  getState();
}

function preset5(button1, button2, button3, button4, button5, button6, button7)  {
  switch(document.getElementById('mode').innerHTML) {
  case "5":
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 4}));
    break;
  default:
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "LawnGreen";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 9}));
    break;
  }
  getState();
}

function preset6(button1, button2, button3, button4, button5, button6, button7)  {
  switch(document.getElementById('mode').innerHTML) {
  case "6":
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 4}));
    break;
  default:
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "LawnGreen";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 10}));
    break;
  }
  getState();
}

function preset7(button1, button2, button3, button4, button5, button6, button7)  {
  switch(document.getElementById('mode').innerHTML) {
  case "7":
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "#F9F6EE";
    ws.send(JSON.stringify({'id': 4}));
    break;
  default:
    document.getElementById(button1).style.background = "#F9F6EE";
    document.getElementById(button2).style.background = "#F9F6EE";
    document.getElementById(button3).style.background = "#F9F6EE";
    document.getElementById(button4).style.background = "#F9F6EE";
    document.getElementById(button5).style.background = "#F9F6EE";
    document.getElementById(button6).style.background = "#F9F6EE";
    document.getElementById(button7).style.background = "LawnGreen";
    ws.send(JSON.stringify({'id': 11}));
    break;
  }
  getState();
}

function getState(button, button1, button2, button3, button4, button5, button6, button7) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      const jsonresponse = JSON.parse(this.responseText);
      document.getElementById('LED_State').innerHTML = jsonresponse.state;
      document.getElementById('mode').innerHTML = jsonresponse.mode;

    }
  };
  xhttp.open("GET", "/getState", true);
  xhttp.send();
  LEDinit(button, button1, button2, button3, button4, button5, button6, button7);
}

function LEDswitch(button)
{
  var x = document.getElementById('LED_State').innerHTML;
  console.log(x);
  switch (x)  {
    case "true":
      document.getElementById(button).style.background = "LawnGreen";
      document.getElementById(button).innerHTML = "On";
      ws.send(JSON.stringify({'id': 2, 'state': 0}));
      console.log("is true");
      break;
    case "false":
      document.getElementById(button).style.background = "Red";
      document.getElementById(button).innerHTML = "Off";
      ws.send(JSON.stringify({'id': 2, 'state': 1}));
      console.log("is false");
      break;
  }
  getState();
}

function LEDinit(button, button1, button2, button3, button4, button5, button6, button7)
{
  var x = document.getElementById('LED_State').innerHTML;
  console.log(x);
  switch (x)  {
    case "true":
      document.getElementById(button).style.background = "LawnGreen";
      document.getElementById(button).innerHTML = "On";
      break;
    case "false":
      document.getElementById(button).style.background = "Red";
      document.getElementById(button).innerHTML = "Off";
      break;
  }
  switch(document.getElementById('mode').innerHTML) {
    case "0":
      document.getElementById(button1).style.background = "#F9F6EE";
      document.getElementById(button2).style.background = "#F9F6EE";
      document.getElementById(button3).style.background = "#F9F6EE";
      document.getElementById(button4).style.background = "#F9F6EE";
      document.getElementById(button5).style.background = "#F9F6EE";
      document.getElementById(button6).style.background = "#F9F6EE";
      document.getElementById(button7).style.background = "#F9F6EE";
      break;
    case "1":
      document.getElementById(button1).style.background = "LawnGreen";
      document.getElementById(button2).style.background = "#F9F6EE";
      document.getElementById(button3).style.background = "#F9F6EE";
      document.getElementById(button4).style.background = "#F9F6EE";
      document.getElementById(button5).style.background = "#F9F6EE";
      document.getElementById(button6).style.background = "#F9F6EE";
      document.getElementById(button7).style.background = "#F9F6EE";
      break;
    case "2":
      document.getElementById(button1).style.background = "#F9F6EE";
      document.getElementById(button2).style.background = "LawnGreen";
      document.getElementById(button3).style.background = "#F9F6EE";
      document.getElementById(button4).style.background = "#F9F6EE";
      document.getElementById(button5).style.background = "#F9F6EE";
      document.getElementById(button6).style.background = "#F9F6EE";
      document.getElementById(button7).style.background = "#F9F6EE";
      break;
    case "3":
      document.getElementById(button1).style.background = "#F9F6EE";
      document.getElementById(button2).style.background = "#F9F6EE";
      document.getElementById(button3).style.background = "LawnGreen";
      document.getElementById(button4).style.background = "#F9F6EE";
      document.getElementById(button5).style.background = "#F9F6EE";
      document.getElementById(button6).style.background = "#F9F6EE";
      document.getElementById(button7).style.background = "#F9F6EE";
      break;
    case "4":
      document.getElementById(button1).style.background = "#F9F6EE";
      document.getElementById(button2).style.background = "#F9F6EE";
      document.getElementById(button3).style.background = "#F9F6EE";
      document.getElementById(button4).style.background = "LawnGreen";
      document.getElementById(button5).style.background = "#F9F6EE";
      document.getElementById(button6).style.background = "#F9F6EE";
      document.getElementById(button7).style.background = "#F9F6EE";
      break;
    case "5":
      document.getElementById(button1).style.background = "#F9F6EE";
      document.getElementById(button2).style.background = "#F9F6EE";
      document.getElementById(button3).style.background = "#F9F6EE";
      document.getElementById(button4).style.background = "#F9F6EE";
      document.getElementById(button5).style.background = "LawnGreen";
      document.getElementById(button6).style.background = "#F9F6EE";
      document.getElementById(button7).style.background = "#F9F6EE";
      break;
    case "6":
      document.getElementById(button1).style.background = "#F9F6EE";
      document.getElementById(button2).style.background = "#F9F6EE";
      document.getElementById(button3).style.background = "#F9F6EE";
      document.getElementById(button4).style.background = "#F9F6EE";
      document.getElementById(button5).style.background = "#F9F6EE";
      document.getElementById(button6).style.background = "LawnGreen";
      document.getElementById(button7).style.background = "#F9F6EE";
      break;
    case "7":
      document.getElementById(button1).style.background = "#F9F6EE";
      document.getElementById(button2).style.background = "#F9F6EE";
      document.getElementById(button3).style.background = "#F9F6EE";
      document.getElementById(button4).style.background = "#F9F6EE";
      document.getElementById(button5).style.background = "#F9F6EE";
      document.getElementById(button6).style.background = "#F9F6EE";
      document.getElementById(button7).style.background = "LawnGreen";
      break;
  }
}

function MODEswitch(button)
{
  var x = document.getElementById('LED_State').innerHTML;
  console.log(x);
  switch (x)  {
    case "true":
      document.getElementById(button).style.background = "LawnGreen";
      document.getElementById(button).innerHTML = "On";
      ws.send(JSON.stringify({'id': 2, 'state': 0}));
      console.log("is true");
      break;
    case "false":
      document.getElementById(button).style.background = "Red";
      document.getElementById(button).innerHTML = "Off";
      ws.send(JSON.stringify({'id': 2, 'state': 1}));
      console.log("is false");
      break;
  }
  getState();
}
