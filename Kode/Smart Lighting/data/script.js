var ws = new WebSocket("ws://192.168.2.13/test");

    function buttonState()  {
		ws.send("Button pressed");
	}