import sys

if len(sys.argv) < 2:
    raise Exception('Missing file name')

fileName = sys.argv[1]
with open(fileName) as f:
    for l in f:
        if len(l) > 10:
            print(l[:10])
        else:
            print(l[:-1])
