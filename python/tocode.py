import sys

def toCode(errCode: str) -> str:
    """ 
    Takes hex number (for example: 0xc46535ef) and returns int32 representation.
    """
    a = int(errCode, 16)
    b = str(bin(a))[2:]
    c = ''.join(['1' if x == '0' else '0' for x in b])
    return '-' + str(int(c, 2) + 1)

print(toCode(sys.argv[1][2:]))                               
