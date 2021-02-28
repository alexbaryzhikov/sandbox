function sayHello() {
    document.write("Hello!")
}

function getValue() {
    var retVal = prompt("Enter your name: ", "your name here");
    document.write("You have entered: " + retVal);
}

function getVoid() {
    var a, b, c;

    a = void (b = 5, c = 7);
    document.write('a = ' + a + ' b = ' + b + ' c = ' + c);
}

sayHello()
