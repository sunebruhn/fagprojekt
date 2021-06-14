var ws = new WebSocket("ws://192.168.43.25/test");

function LEDswitch(button)  {
  var x = document.getElementById(button);
  var on = 1;
  var off = 0;
  switch (x.innerHTML)  {
    case "On":
      x.innerHTML = "Off";
      document.getElementById(button).style.background = "Red";
      ws.send(JSON.stringify({'id': 2, 'state': 0}));
      break;
    case "Off":
      x.innerHTML = "On";
      document.getElementById(button).style.background = "LawnGreen";
      ws.send(JSON.stringify({'id': 2, 'state': 1}));;
      break;
  }
}

function hexToRgb(hex) {
  var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
  var r = parseInt(result[1],16);
  var g = parseInt(result[2],16);
  var b = parseInt(result[3],16);
  ws.send(JSON.stringify({'id': 3, 'r': r, 'g' : g, 'b' : b}));
}
