-module ('semanticanalyzer').
-export([getfirstterm/1, optotuple/1, executiontreegenerator/1, tokenize/2, analyze/1,adder/0,subtractor/0,divider/0,multiplier/0,comparator/0,manager/2]).


analyze(String) ->
    ExecutionTree = executiontreegenerator(String),
    T1 = erlang:now(),
    sequentialprocesstree(ExecutionTree),
    T2 = erlang:now(),
    Native = timer:now_diff(T2,T1),
    Milli = Native * math:pow(10,-3),
    Second = Milli / 1000,
    io:format("Secuencial: ~p milisegundos~n", [Milli]),
    io:format("Secuencial: ~p segundos~n -------------------------~n", [Second]),
    concurrentprocesstree(ExecutionTree).



executiontreegenerator(String) ->
    {Term1, NewString} = checkifnegativeterm(String),
    Tokens = flatten(tokenize(NewString, [list_to_integer(Term1)])),
    Tree = getOrder(Tokens).

checkifnegativeterm(String) ->
    if hd(String) == hd("-") ->
            {Term, Rest} = getfirstterm(tl(String)),
            {[hd("-") | Term], Rest};
       true -> getfirstterm(String) 
end.


getfirstterm([]) -> {"",""};
getfirstterm(String) ->
    Operator = lists:member(hd(String),"+-=*/"),
    if
        Operator == true ->{"", String};
        true ->  {Term, NewString} = getfirstterm(tl(String)),
                 {[hd(String) | Term], NewString}
    end.

tokenize([], CurrentOperation) -> CurrentOperation;
tokenize(String, CurrentOperation) ->
    {Op} = optotuple(hd(String)),
    Rest = tl(String),
    {Term, NewText} = checkifnegativeterm(Rest),
    NewOperation = CurrentOperation ++ [Op,list_to_integer(Term)],
    tokenize(NewText,NewOperation).


optotuple(Op) ->
    if
        Op == hd("+") ->
            {plus}
      ;
        Op == hd("-") ->
            {minus}
      ;
        Op == hd("/") ->
            {division}
      ;
        Op == hd("*") ->
            {multiplication}
      ;
        Op == hd("=") ->
            {equals}
      ;
        true -> {term}
    end.


sequentialprocesstree({Op, Term1,Term2})->
    case Op of
        plus ->
            T1 = sequentialprocesstree(Term1),
            T2 = sequentialprocesstree(Term2),
            T1+T2;
        minus ->
            T1 = sequentialprocesstree(Term1),
            T2 = sequentialprocesstree(Term2),
            T1-T2;
        division ->
            T1 = sequentialprocesstree(Term1),
            T2 = sequentialprocesstree(Term2),
            T1/T2;
        multiplication ->
            T1 = sequentialprocesstree(Term1),
            T2 = sequentialprocesstree(Term2),
            T1*T2;
        equals ->
            T1 = sequentialprocesstree(Term1),
            T2 = sequentialprocesstree(Term2),
            Equals = T1 == T2,
            if Equals == true -> 1;
               true -> 0
            end
    end;
sequentialprocesstree(Term1) ->
    Term1.

flatten(X) -> lists:reverse(flatten(X,[])).

flatten([],Acc) -> Acc;
flatten([H|T],Acc) when is_list(H) -> flatten(T, flatten(H,Acc));
flatten([H|T],Acc) -> flatten(T,[H|Acc]).

getOrder(List) ->
    DivMult = getparameters(List,[division,multiplication]),
    AddSubt = getparameters(DivMult,[plus,minus]),
    Equals = getparameters(AddSubt,[equals]).
    

getparameters([List |[]],_) -> List;
getparameters(List, Operators) ->
    if is_tuple(List) == true -> List;
       true ->
    Term = hd(List),
    Op = hd(tl(List)),
    DivMult = lists:member(Op,Operators),
    if DivMult == true ->
            NewOperation = {Op, Term, hd(tl(tl(List)))},
             getparameters([NewOperation | tl(tl(tl(List)))],Operators);
       true -> Rest = getparameters(tl(tl(List)),Operators),
               if is_list(Rest) ->
                       [ Term | [ Op | Rest] ];
                  true ->
                       [ Term | [ Op , Rest] ]
               end
    end
    end.


concurrentprocesstree(Tree) ->
    T1 = erlang:now(),
    Adder = spawn(semanticanalyzer,adder,[]),
    Subtractor = spawn(semanticanalyzer,subtractor,[]),
    Divider = spawn(semanticanalyzer,divider,[]),
    Multiplier = spawn(semanticanalyzer,multiplier,[]),
    Comparator = spawn(semanticanalyzer,comparator,[]),
    Processes = {Adder, Subtractor, Divider, Multiplier, Comparator},
    manager(Processes,Tree),
    T2 = erlang:now(),
    Native = timer:now_diff(T2,T1),
    Milli = Native * math:pow(10,-3),
    Second = Milli / 1000,
    io:format("Concurrente: ~p milisegundos~n", [Milli]),
    io:format("Concurrente: ~p segundos~n -------------------------~n", [Second]).

manager({Adder, Subtractor, Divider, Multiplier, Comparator},{Op, P1, P2}) ->
    P1tuple = is_tuple(P1),
    P2tuple = is_tuple(P2),
    if
        P1tuple == true -> Par1 = manager({Adder, Subtractor, Divider, Multiplier, Comparator},P1);
        true -> Par1 = P1
    end,
    if
        P2tuple == true -> Par2 = manager({Adder, Subtractor, Divider, Multiplier, Comparator},P2);
        true -> Par2 = P2
    end,
    case Op of
        plus -> Adder ! {self(), Par1,Par2},
                receive {result, X} -> io:format("~p~n", [X]),X end
      ;
        minus ->Subtractor ! {self(), Par1,Par2},
                receive {result, X} -> io:format("~p~n", [X]),X end
      ;
        division ->Divider ! {self(), Par1,Par2},
                   receive {result, X} -> io:format("~p~n", [X]),X end
      ;
        multiplication ->Multiplier ! {self(), Par1,Par2},
                         receive {result, X} -> io:format("~p~n", [X]),X end
      ;
        equals ->Comparator ! {self(), Par1,Par2},
                 receive {result, X} -> io:format("~p~n", [X]),X end
    end.

adder()->
    receive
        {Pid, P1,P2} -> Pid ! {result,P1+P2}
    end,
    adder().

subtractor()->
    receive
        {Pid, P1,P2} -> Pid ! {result,P1-P2}
    end,
    subtractor().

divider()->
    receive
        {Pid, P1,P2} -> Pid ! {result,P1/P2}
    end,
    divider().

multiplier()->
    receive
        {Pid, P1,P2} -> Pid ! {result,P1*P2}
    end,
    multiplier().
comparator()->
    receive
        {Pid, P1,P2} -> 
            Equals = P1 == P2,
            if Equals == true -> Result = 1;
               true -> Result = 0
            end,
            Pid ! {result,Result}
    end,
    comparator().
