
function OFF()  {
  var x = document.getElementById('LEDState');
  x.innerHTML = "The LED is currently OFF";
}

function ON()  {
  var x = document.getElementById('LEDState');
  x.innerHTML = "The LED is currently ON";
}

function MatrixState(button) {
  if (document.getElementById(button).style.backgroundColor === "grey") {
    document.getElementById(button).style.backgroundColor = "green";
  }
}
