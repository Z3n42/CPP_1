function rnd_color() {
    var x = Math.floor(Math.random() * 256);
    var y = Math.floor(Math.random() * 256);
    var z = Math.floor(Math.random() * 256);
    var bgColor = "rgb(" + x + "," + y + "," + z + ")";
 console.log(bgColor);
 
	console.log(document.getElementById("tomas"));
    document.getElementById("tomas").style.background = bgColor;
    }

// rnd_color();
