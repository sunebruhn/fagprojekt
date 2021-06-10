var ws = new WebSocket("ws://192.168.2.69/test");

    function buttonState()  {
		ws.send("Button pressed");
	}