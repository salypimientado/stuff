import subprocess


def getValue(x):
    return {
        '101': "Variable",
        '102': "Asignacion",
        '103': "Suma",
        '104': "Resta",
        '105': "Division",
        '106': "Comment",
        '107': "Multiplicacion",
        '108': "Potencia",
        '109': "Par in",
        '110': "Par fin",
        '111': "Numero"
    }[x]


def getTokens():
    cmd = subprocess.Popen("tokenizer.exe " + input("introduzca el archivo a analizar: "),
                           shell=True, stdout=subprocess.PIPE)
    tokens = []
    for line in cmd.stdout:
        line = line.decode('utf-8')
        line = line.replace('\r', '')
        line = line.split(' ', 1)
        # state = re.match('^\w+', line)
        # token = re.match('(?<!(^\w+))',line)
        tokens.append((int(line[0]), line[1]))
    return tokens


def ExpList():
    global html
    if tokens:

        Expression()
        html = html + '<br>'
        ExpList()


def Expression():
    global html
    global tokens
    if(tokens and tokens[0][0] == 106):
        html = html + '<span style="background-color:#A0A0FF">' + \
            tokens[0][1] + "</span>"
        tokens.pop(0)
        html = html + '<br>'
        Expression()
    elif(tokens and tokens[0][0] == 109):
        html = html + '<span style="background-color:#A000FF">' + \
            tokens[0][1]
        tokens.pop(0)
        Expression()
        if(tokens and tokens[0][0] == 110):
            Par()
        else:
            exit()
    elif(tokens and tokens[0][0] in (101, 111, 104)):
        Termino()
    # else:
        #


def Par():
    global html
    global tokens
    Expression()
    if(tokens[0][0] == 110):
        html = html + ")</span>"
        tokens.pop(0)
        Op()


def Op():
    global html
    global tokens
    if(tokens and tokens[0][0] == 108):
        html = html + '<span style="background-color:#A0AF0F">' + \
            tokens[0][1]
        tokens.pop(0)
        Expression()

        html = html + '</span>'

    elif(tokens and tokens[0][0] == 105):
        html = html + '<span style="background-color:#FF5C5C">' + \
            tokens[0][1]
        tokens.pop(0)
        Expression()

        html = html + '</span>'

    elif(tokens and tokens[0][0] == 107):
        html = html + '<span style="background-color:#00FF00">' + \
            tokens[0][1]
        tokens.pop(0)
        Expression()

        html = html + '</span>'

    elif(tokens and tokens[0][0] == 104):
        html = html + '<span style="background-color:#10EFEF">' + \
            tokens[0][1]
        tokens.pop(0)
        Expression()

        html = html + '</span>'

    elif(tokens and tokens[0][0] == 103):
        html = html + '<span style="background-color:#B0B0FF">' + \
            tokens[0][1]
        tokens.pop(0)
        Expression()

        html = html + '</span>'

    elif(tokens and tokens[0][0] == 102):
        html = html + '<span style="background-color:#A0A0A0">' + \
            tokens[0][1]
        tokens.pop(0)
        Expression()

        html = html + '</span>'


def Termino():
    global html
    global tokens
    if(tokens and tokens[0][0] == 104):
        html = html + '<span style="background-color:#0080FF">' + \
            tokens[0][1]
        tokens.pop(0)
        Termino()
        html = html + '</span>'

    elif(tokens and tokens[0][0] == 101):
        html = html + '<span style="background-color:#FF0505">' + \
            tokens[0][1]
        tokens.pop(0)
        Op()

        html = html + '</span>'

    elif(tokens and tokens[0][0] == 111):
        html = html + '<span style="background-color:#0080FF">' + \
            tokens[0][1]
        tokens.pop(0)
        Op()

        html = html + '</span>'


if __name__ == "__main__":
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
    html = "<html><head><title>cosa</title><body>"
    f = open('highlighted-code.html', "wt")
    ExpList()
    html = html + '<br><br><span style="background-color:#A0A0FF">Comentario</span>'
    html = html + '<br><span style="background-color:#A000FF">Parentesis</span>'
    html = html + '<br><span style="background-color:#A0AF0F">Potencia/exponente</span>'
    html = html + '<br><span style="background-color:#FF5C5C">Division</span>'
    html = html + '<br><span style="background-color:#00FF00">Multiplicacion</span>'
    html = html + '<br><span style="background-color:#10EFEF">Resta</span>'
    html = html + '<br><span style="background-color:#B0B0FF">Suma</span>'
    html = html + '<br><span style="background-color:#A0A0A0">Asignacion</span>'
    html = html + '<br><span style="background-color:#0080FF">Negativo</span>'
    html = html + '<br><span style="background-color:#FF0505">Variable</span>'
    html = html + '<br><span style="background-color:#0080FF">Numero</span>'
    html = html + "</body>"
    f.write(html)
