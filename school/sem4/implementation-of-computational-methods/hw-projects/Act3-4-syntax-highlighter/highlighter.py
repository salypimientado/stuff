import subprocess
import re

def getValue(x):
    return {
        '101':"Variable",
        '102':"Asignacion",
        '103':"Suma",
        '104':"Resta",
        '105':"Division",
        '106':"Comment",
        '107':"Multiplicacion",
        '108':"Potencia",
        '109':"Par in",
        '110':"Par fin",
        '111':"Numero"
    }[x]

def getTokens():
    cmd = subprocess.Popen("./highlighter test.txt",shell=True,stdout=subprocess.PIPE)
    tokens = []
    for line in cmd.stdout:
        line = line.decode('ascii').replace('\n', '')
        line = line.split(' ',1)
        #state = re.match('^\w+', line)
       # token = re.match('(?<!(^\w+))',line)
       # print(state[0])
       # print(token[0])
        tokens.append((int(line[0]),line[1]))
    return tokens


def Expression():
    global html
    global tokenIndex
    global expIndex
    expIndex = tokenIndex
    global parentheses
    if(tokenIndex < len(tokens) and tokens[tokenIndex][0] == 106):
        index1 = expIndex
        html = html + '<h1 style="background-color:#A0A0FF">' + tokens[tokenIndex][1] + "</h1>"
        tokenIndex = tokenIndex + 1

        Expression()

        index2 = tokenIndex
        parentheses.append((index1,index2))

    else:
        print("ta", parentheses)


#if __name__ == "__main__":
tokens = getTokens()
tokenIndex = 0
expIndex = 0
comments = []
parentheses = []
exponents = []
division = []
addition = []
substraction = []
asignation = []
terms = []
html="<html><head><title>cosa</title><body>"
f = open('highlighted-code.html', "wt")
Expression()


html = html + "</body>"
f.write(html)
print(html)

