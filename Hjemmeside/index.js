var ws = new WebSocket("ws://192.168.2.12/test");

function buttonState()  {
  ws.send("Button pressed");
}
