import Foundation

func intToRoman(_ num: Int) -> String {
    let romanValues = [
        (value: 1000, symbol: "M"),
        (value: 900, symbol: "CM"),
        (value: 500, symbol: "D"),
        (value: 400, symbol: "CD"),
        (value: 100, symbol: "C"),
        (value: 90, symbol: "XC"),
        (value: 50, symbol: "L"),
        (value: 40, symbol: "XL"),
        (value: 10, symbol: "X"),
        (value: 9, symbol: "IX"),
        (value: 5, symbol: "V"),
        (value: 4, symbol: "IV"),
        (value: 1, symbol: "I")
    ]
    
    var num = num
    var result = ""
    
    for roman in romanValues {
        while num >= roman.value {
            result += roman.symbol
            num -= roman.value
        }
    }
    
    return result
}

let number = 2024
let romanNumeral = intToRoman(number)
print("\(number) in Roman numerals is \(romanNumeral)")
