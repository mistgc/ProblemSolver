def check(sid):
    nid = 0
    testPaperType = sid[15]

    for i in range(1,17):
        if(int(sid[i-1]) - 0 == 1):
            nid += 2**(16-i)

    if(nid <= 1000 and nid >= 1):
        print('ID:{0}'.format(nid))
    else:
        print('Wrong ID')
        return False, testPaperType

    return True, testPaperType

s = []

def score(n):
    total = 100.00
    point = total / n
    s_score = .0

    for i in range(int(n)):
        ans = input()
        if(ans == s[i]):
            s_score += point

    return s_score

if __name__ == '__main__':
    T, n = map(int, input().split())
    s_temp = input()

    for j in range(T):
        for i in range(int(n)):
            if(s_temp[i] == 'A'):
                s.append('1000')
            elif(s_temp[i] == 'B'):
                s.append('0100')
            elif(s_temp[i] == 'C'):
                s.append('0010')
            elif(s_temp[i] == 'D'):
                s.append('0001')

        for i in range(int(n)):
            flag = True
            sid = input()
            testPaperType = input()
            flag, temp = check(sid)

            if(not flag):
                score(n)
                continue

            if(temp == testPaperType[1]):
                print('Type Correct')
            else:
                print('Type Incorrect')

            print(score(n))
            print()
