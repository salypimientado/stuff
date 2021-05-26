-module ('hello'). 
-export([primes/1, listfromxtoy/2, divide/2, listfromone/1,concurrent/2,listmanager/3, worker/0]).


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

getdivisibleby(List,Num) ->
    lists:filter(fun(X) -> (X rem  Num == 0 ) and ( X /= Num ) end,List) .

checkprimes(List,X, Pid) -> 
    Pid! {modifyList, getdivisibleby(List,X)}.

worker() ->
    receive
        {Pid, List, X} ->
                checkprimes(List,X,Pid),
                Pid ! {sendNext, self()},
            worker();
        {done} -> 0
    end.

listmanager(Original, Cur, Max)->
    receive
        {sendNext, Pid} when Max+1 > Cur-> Pid ! {self(),Original,Cur},
                           listmanager(Original,Cur+1,Max);
        {sendNext, Pid} -> Pid ! {done};

        {modifyList, NumsToRemove} when Cur == Max-1 -> io:format("final = ~p~n",[lists:sum(lists:filter(fun(X) -> not lists:member(X,NumsToRemove) end,Original))]);
        {modifyList, NumsToRemove} ->  listmanager(lists:filter(fun(X) -> not lists:member(X,NumsToRemove) end,Original),Cur, Max)

end.


workerspawner(ManagerPid,Cur)-> if
    Cur /= 0 ->
    Worker = spawn(hello,worker,[]),
    ManagerPid ! {sendNext, Worker},
    workerspawner(ManagerPid, Cur-1);
    true -> io:format("all workers spawned~n") end.


concurrent(X,Threads)->
    A = listfromone(X),
    Max = trunc(math:ceil(math:sqrt(X+2))),
    Listmanager = spawn(hello,listmanager,[A,2,Max]),
    workerspawner(Listmanager, Threads).

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
