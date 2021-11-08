:-discontiguous(likes/2).

sone(X) :- likes(X, gg), reveluv(X); blink(X).

reveluv(X) :- likes(X,rv).

blink(X) :- likes(X,bp).

likes(X,ballad) :- likes(X, rv).
likes(X,dance) :- likes(X, bp).
likes(X,djhyo) :- likes(X, electronic), sone(X).
likes(X,chungha) :- likes(X,dance), likes(X,ballad).
likes(X,seohyun) :- sone(X), likes(X,drama).
likes(X,taeyeon) :- sone(X), likes(X,ballad).
likes(X,heize) :- likes(X,drama), likes(X,ballad).


likes(p1,rv).
likes(p1,bp).
likes(p1,gg).

likes(p,rv).
likes(p,bp).
likes(p,gg).
likes(p,drama).
