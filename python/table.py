table = [
    [],
    ["", "к", "п", "а"],
    ["", "л", "р", "б"],
    ["", "м", "с", "в"],
    ["", "н", "т", "г"],
    ["", "о", "у", "д"],
    ["", "ь", "ф", "е"],
    ["", "ъ", "х", "ё"],
    ["", "ы", "ч", "ж"],
    ["", "э", "ц", "з"],
    ["", "ю", "ш", "и"],
    ["", "я", "щ", "й"],
    ["", " ", ",", "."],
]

message = [
    (1, 1), (2, 2), (1, 3), (3, 2),
    (10, 3), (3, 3), (12, 1), (4, 2),
    (5, 1), (4, 2), (12, 2), (12, 1),
    (1, 1), (4, 2), (5, 1), (12, 1),
    (1, 1), (2, 2), (1, 3), (3, 2),
    (10, 3), (3, 3), (5, 1), (12, 1),
    (1, 2), (5, 1), (3, 2), (4, 2),
    (5, 2), (1, 2), (1, 3), (6, 3),
    (4, 2), (12, 3)
]

result = "".join([table[x[0]][x[1]] for x in message])

print(result)
