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
