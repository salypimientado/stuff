-module ('hello'). 
-export([primes/1, listfromxtoy/2, divide/2, primesConcurrent/1, listfromone/1, listener/2, primesfromlist/2,compare/1, concurrente/1,secuencial/1]).


listfromone(X) -> if
    X > 1 ->  lists:append(listfromone(X-1),[X]);
    true -> []
    end.

sieve(List,Index, Max) -> if
    Index < Max -> New = lists:filter(fun(X) -> ( X rem Index /= 0 ) or ( Index == X ) end, List),
    sieve(New,Index+1,Max);
    true -> 
    List end.

primes(X) ->
    Nums = listfromone(X),
    Max = math:sqrt(length(Nums)) +1,
    io:format("Resultado suma primos no concurrente: ~p~n", [lists:sum(sieve(Nums,2,Max))]).

primesfromlist(Nums, Pid) ->
    Max = math:sqrt(lists:last(Nums)) +1,
    A = lists:sum(sieve(Nums,2,Max)),
    %io:format("num = ~p ~p~n", [Max,A]),
    Pid ! {A}.

listfromxtoy(X,Y) -> if
    Y > X-1 ->  lists:append(listfromxtoy(X,Y-1),[Y]);
    true -> []
    end.


divide(L, N) when is_integer(N), N > 0 ->
    divide(N, 0, L, []).

divide(_, _, [], Acc) ->
    [lists:reverse(Acc)];
divide(N, N, L, Acc) ->
    [lists:reverse(Acc) | divide(N, 0, L, [])];
divide(N, X, [H|T], Acc) ->
    divide(N, X+1, T, [H|Acc]).

listener(N, A) ->
    io:format("index: ~p~n", [N]),
    receive
         {Amount} when N > 1 -> 
            listener(N-1, A + Amount);
        {Amount} -> X = A + Amount,
                    io:format("Resultado suma primos concurrente: ~p~n", [X])
    end.

primesConcurrent(X) ->
    List = listfromone(X),
    Lists = divide(List,trunc(math:ceil(length(List)/20))),
    Adder = spawn(hello,listener,[20,0]),
    spawn(hello,primesfromlist,[ lists:nth(1,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(2,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(3,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(4,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(5,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(6,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(7,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(8,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(9,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(10,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(11,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(12,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(13,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(14,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(15,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(16,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(17,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(18,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(19,Lists) , Adder]),
    spawn(hello,primesfromlist,[ lists:nth(20,Lists) , Adder]).

compare(X) ->
    Seq = timer:tc(hello,primes,[X]),
    Conc = timer:tc(hello,primesConcurrent,[X]),
    io:format("Concurrente: ~p segundos~n", [element(1,Conc)/1000]),
    io:format("No concurrente: ~p segundos~n", [element(1,Seq)/1000]).


concurrente(X) ->
    Conc = timer:tc(hello,primesConcurrent,[X]),
    io:format("Concurrente: ~p segundos~n", [element(1,Conc)/1000]).

secuencial(X)->
    Seq = timer:tc(hello,primes,[X]),
    io:format("No concurrente: ~p segundos~n", [element(1,Seq)/1000]).
