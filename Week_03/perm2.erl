-module(perm2).
-export([perm2/1]).

perm([]) -> [[]];
perm(L) -> [[H|T] || H <- L, T <- perm(L--[H])].

perm2(L) ->
   S = sets:from_list(perm(L)),
   sets:to_list(S).