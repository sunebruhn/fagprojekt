
function OFF()  {
  var x = document.getElementById('LEDState');
  x.innerHTML = "The LED is currently OFF";
}

function ON()  {
  var x = document.getElementById('LEDState');
  x.innerHTML = "The LED is currently ON";
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
