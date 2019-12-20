def solution(A, K,L):
    N = len(A)
    apple_sum =[]

    for i in range(0, N-K+1):
        for j in range(0, N-L+1):
            if len(set(range(i, i+K)) & set(range(j, j+L)))==0:
                apple_sum.append(sum(A[i:i+K])+sum(A[j:j+L]))

    if len(apple_sum) == 0:
        return -1
    return max(apple_sum)




#A=[6,1,4,6,3,2,7,4]
#K=3
#L=2
#print(solution(A,K,L))