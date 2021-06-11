var ws = new WebSocket("ws://192.168.1.69/test");

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
      ws.send(JSON.stringify({'id': 1, 'state': 1}));;
      break;
  }
}
