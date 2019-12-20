def solution(S):
    B= []
    N=len(S)
    if len(S) == 0:
        return -1
    for i in range(0,N):
        if S[i] == 'DUP':
           B.append(B[- 1])
        if S[i].isdigit():
           B.append(S[i])
        if i > 1 and S[i] == '-':
            if len(B) > 1 and int(B[-2])<int(B[-1]):
                sub = int(B[-1])-int(B[-2])
                B.pop()
                B.pop()
                B.append(str(sub))
            else:
                return -1
        if i > 1 and S[i] == '+':
            if len(B) > 1:
                s = int(B[-2])+int(B[-1])
                B.pop()
                B.pop()
                B.append(str(s))
            else:
                return -1
        if S[i] == 'POP':
            if len(B) != 0:
                B.pop()
            else:
                return -1

    return B[-1]


#S=['13','DUP','4','POP','5','DUP','+','DUP','+','-']
#S=['5','6','+','+']
#S=[]
#print(solution(S))


