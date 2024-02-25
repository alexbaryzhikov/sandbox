import Foundation

struct MissingFileName: Error, CustomStringConvertible {
    let description = "Missing file name"
}

do {
    guard CommandLine.argc > 1 else {
        throw MissingFileName()
    }
    let fileName = CommandLine.arguments[1]
    let s = try String(contentsOfFile: fileName)
    let lines = s.components(separatedBy: .newlines) 
    for l in lines {
        print(l.prefix(20))
    }
} catch {
    print(error)
}
