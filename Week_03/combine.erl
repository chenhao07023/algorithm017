-module(combine).
-export([comb/2]).

comb(N, K) -> combl(lists:seq(1,N), K).

combl(_, 0) -> [[]];
combl([], _) -> [];
combl([H|T], K) -> combl(T, K)++[[H] ++ L || L <- combl(T, K-1)].