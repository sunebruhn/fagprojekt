
function OFF()  {
  var x = document.getElementById('LEDState');
  x.innerHTML = "The LED is currently OFF";
}

function ON()  {
  var x = document.getElementById('LEDState');
  x.innerHTML = "The LED is currently ON";
}

function LEDswitch(button)  {
  var x = document.getElementById(button);
  var on = 1;
  var off = 0;
  switch (x.innerHTML)  {
    case "On":
      x.innerHTML = "Off";
      document.getElementById(button).style.background = "Red";
      console.log(off);
      break;
    case "Off":
      x.innerHTML = "On";
      document.getElementById(button).style.background = "LawnGreen";
      console.log(on);
      break;
  }
}

function MatrixState(button) {
  var x = document.getElementById(button);
  switch (x.innerHTML)  {
    case " ":
      x.innerHTML = "  ";
      document.getElementById(button).style.background = "green";
      break;
    case "  ":
      x.innerHTML = " ";
      document.getElementById(button).style.background = "grey";
      break;
  }
}
