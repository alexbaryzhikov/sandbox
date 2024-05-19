func swap(_ a: inout Int, _ b: inout Int) {
    a += b
    b = a - b
    a -= b
}

var a = 1
var b = 2
swap(&a, &b)
print("a=\(a) b=\(b)")
