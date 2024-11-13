s = input();
n = len(s);
k = -1;
fg = 0;
for i in range(n): 
    if s[i] == '1':
        k = i;
        break;

if (k == -1):
    print(0)
else:
    print(2*10**(n-k-1) - int(s[k:]))



