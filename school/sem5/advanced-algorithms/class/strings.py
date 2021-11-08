
def lps(patron):
    lpsv = [0 for x in range(0,len(patron))]
    length = len(patron)
    j , i = 0, 1
    while(i< length):
        if patron[i] == patron[j]:
            lpsv[i] = j+1
            j+=1
            i+=1
        elif j==0:
            lpsv[i] = 0
            i+=1
        else:
            j = lpsv[j-1]
    return lpsv

def kmp(texto, patron):
    matches = []
    lpsv = lps(patron)
    print(f"{lpsv = }")
    i, j, n, m = 0, 0, len(texto), len(patron)
    while i<n:
        if texto[i] == patron[j]:
            i+=1
            j+=1
            print(f"{i = },{ j = }")
            if j==m:
                matches.append(i-m)
                j = lpsv[j-1]
        elif j==0:
            i+=1
        else:
            j = lpsv[j-1]
    return matches

def manacher(string):
    string = ['|' + i for i in string]
    string.append('|')
    string = ''.join(string)
    print(string)

while input("input 0 to end loop") != "0":
    texto: str = input("texto:")
    manacher(texto)
    #patron = input("patron:")
    #matches = kmp(texto,patron)
    #print(f"{matches = }")
