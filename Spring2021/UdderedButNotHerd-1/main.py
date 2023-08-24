alpha = str(input())
s = str(input())

reverse = {}

for i in range(len(alpha)):
  reverse[alpha[i]] = i

indx = -1
counter = 1

for c in s:
  if reverse[c] <= indx:
    counter+=1
  indx = reverse[c]

print(counter)
