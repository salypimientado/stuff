-module ('hello').
-export([primes/1, checkifprime/2,concurrent/3, manager/4, worker/0, concurrente/2, secuencial/1,concurrentTimer/0]).



primes(X) ->
    Result = recursePrime(X,0),
    io:format("Resultado suma primos no concurrente: ~p~n", [Result]).

recursePrime(X,Sum) ->
    if
        X == 1 ->
            Sum;
        true ->
            New = checkifprime(X,2) + Sum,
            recursePrime(X-1,New)
    end.

checkifprime(X,Y) ->
    Overroot = Y > math:sqrt(X),
    if
        Overroot == true -> X;
        Overroot == false ->
            case (X rem Y) of
                0 ->
                    0;
                _ ->
                    checkifprime(X, Y+1)
            end
    end.









worker()->
    receive
        {number,Pid, X} ->
            Value = checkifprime(X,2),
            if Value /= 0 -> Pid ! {add, Value};
               true -> Pid ! {zero}
            end,
            Pid ! {sendNext , self()},
            worker()


end.


manager(X,Active,Value,Timer) ->
    case X == 1 of
        false ->
            receive
                {sendNext,Worker} ->
                                                %io:format("index #~p~n", [X]),
                    Worker ! {number,self(), X},
                    manager(X-1, Active+1,Value,Timer);
                {zero} -> manager(X, Active-1,Value,Timer);

                {add, Amount} -> manager(X, Active-1,Value+Amount,Timer)
            end;

        true -> receive
                    {zero} -> manager(X, Active-1,Value,Timer);
                    {add, Amount} ->
                        if
                            Active == 1 ->
                                Timer ! finish,
                                io:format("Valor calculado concurrente = ~p~n", [Value + Amount]);
                            true -> manager(X, Active-1,Value+Amount,Timer)
                        end
                end
    end.

workerspawner(ManagerPid,Cur)-> if
    Cur /= 0 ->
    Worker = spawn(hello,worker,[]),
    ManagerPid ! {sendNext, Worker},
    workerspawner(ManagerPid, Cur-1);
    true -> io:format("all workers spawned~n") end.

concurrentTimer()->
    T1 = erlang:now(),
    receive
        finish ->
            T2 = erlang:now(),
            Native = timer:now_diff(T2,T1),
            Milli = Native * math:pow(10,-3),
            Second = Milli / 1000,
            io:format("Concurrente: ~p milisegundos~n", [Milli]),
            io:format("Concurrente: ~p segundos~n -------------------------~n", [Second])
end.

concurrent(X,Threads,Timer)->
    Listmanager = spawn(hello,manager,[X,0,0,Timer]),
    workerspawner(Listmanager, Threads).

concurrente(X,Threads) ->
    Timer = spawn(hello,concurrentTimer,[]),
    concurrent(X,Threads,Timer).

supercworker(MessageProcessor) ->
    receive
        {process, X} -> 
            Value = checkifprime(X,2),
            if Value /= 0 -> MessageProcessor ! {add, Value};
               true -> Pid ! {zero}
            end,
            MessageProcessor ! {sendNext , self()},
            worker(MessageProcessor)

    end.

messageprocessor(X, Adders, Active) ->

    case X == 1 of
        false ->
            receive
                {sendNext, Pid} -> 
                    Pid ! {process, X},
                    messageprocessor(X-1, Adders, Active+1);
                {add, Number} -> 
                    hd(Adders) ! {add, Number},
                    messageprocessor(X-1, tl(Adders), Active-1)
              ;
                {available, Pid} ->
            end;

        true ->
            receive
                end
    end.




secuencial(X)->
    T1 = erlang:now(),
    primes(X),
    T2 = erlang:now(),
    Native = timer:now_diff(T2,T1),
    Milli = Native * math:pow(10,-3),
    Second = Milli / 1000,
    io:format("No concurrente: ~p milisegundos~n", [Milli]),
    io:format("No concurrente: ~p segundos~n", [Second]).
    
