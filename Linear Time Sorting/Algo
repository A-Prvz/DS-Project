Algorithm for GSACA
                             
Phase 1: divide suffixes into groups
1: order all suffixes of S into groups according to their first character: Let Si and Sj be two suffixes. Then, group(i) = group(j) ⇔ S[i] = S[j].
2: order the suffix groups: Let G1 be a suffix group with group context character u, G2 be a suffix group with group context character v. Then, G1 < G2 if u < v.
3: for each group G in descending group order do
4: for each i ∈ G do
5: prev(i) ← max({ j ∈ [1 . . . i] | group(j) < group(i) } ∪ {0})
6: let P be the set of previous suffixes from G, P := { j ∈ [1 . . . n] | prev(i) = j for any i ∈ G }.
7: split P into k subsets P1, . . . ,Pk such that a subset Pl contains suffixes whose number of prev pointers from G pointing to them is equal to l, i.e. i ∈ Pl ⇔ |{ j ∈ G | prev(j) = i }| = l.
8: for l = k down to 1 do
9: split Pl into m subsets Pl1 , . . . ,Plm such that suffixes of same group are gathered in the same subset.
10: for q = 1 up to m do
11: remove suffixes of Plq from their group and put them into a new group placed as immediate successor of their old group.


Phase 2: construct suffix array from groups
12: SA[1] ← n
13: for i = 1 up to n do
14: j ← SA[i] − 1
15: while j 6= 0 do
16: let sr be the number of suffixes placed in lower groups, i.e. sr := |{ s ∈ [1 . . . n] | group(s) < group(j) }|.
17: if SA[sr + 1] 6= nil then
18: break
19: SA[sr + 1] ← j
20: remove j from its current group and put it in a new group placed as immediate predecessor of j’s old group.
21: j ← prev(j)
