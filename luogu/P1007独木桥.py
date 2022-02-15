l = input()
n = input()

max_t, min_t = int(0), int(0)

for i in range(int(n)):
    coord = input()
    max_t = max(max_t, max(int(coord), l-int(coord)+1))
    min_t = max(min_t, min(int(coord), l-int(coord)+1))

print('{0} {1}'.format(min_t, max_t))
