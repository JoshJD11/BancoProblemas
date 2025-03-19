chain = str(input())



def quicksort(L):
    if(L == ""): return ""
    less = ""
    greater = ""
    pivot = L[0]
    for c in L[1:]:
        if(ord(c) <= ord(pivot)):
            greater += c
        else:
            less += c
    less = quicksort(less)
    greater = quicksort(greater)
    return less + pivot + greater




def creatingStrings(chain):
    stack = [[chain, ""]]
    ans = []
    while(stack):
        characters, combination = stack.pop()
        if not(characters): ans.append(combination)
        else:
            visited = [0] * 26
            for c in range(len(characters)):
                if not(visited[ord(characters[c])%97]):
                    visited[ord(characters[c])%97] = 1
                    newCharacters = characters[:c] + characters[c+1:]
                    stack.append([newCharacters, combination + characters[c]])
    
    print(len(ans))
    for combination in ans:
        print(combination)


creatingStrings(quicksort(chain))
