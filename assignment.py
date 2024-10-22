import numpy as np

Y = 5

def distance(x1,y1,x2,y2):
    return np.sqrt((x2-x1)**2 + (y2-y1)**2)

def speed(y):
    return np.sqrt(2*10*(Y-y))

def average_speed(s1,s2):
    return (s1+s2)/2

path1 = np.array([[0, 5],
                  [0, 4],
                  [1, 3],
                  [2, 3],
                  [3, 2],
                  [4, 1],
                  [4, 0],
                  [5, 0]])

path2 = np.array([[0, 5],
                  [0, 4],
                  [1, 4],
                  [2, 3],
                  [3, 3],
                  [4, 2],
                  [4, 1],
                  [5, 0]])

t1=0;
t2=0;

for i in range(path1.shape[0]-1):
    s1=speed(path1[i][1])
    s2=speed(path1[i+1][1])
    t1+=distance(path1[i][0], path1[i][1], path1[i+1][0], path1[i+1][1])/average_speed(s1,s2)

print(t1)

for i in range(path2.shape[0]-1):
    s1=speed(path2[i][1])
    s2=speed(path2[i+1][1])
    t2+=distance(path2[i][0], path2[i][1], path2[i+1][0], path2[i+1][1])/average_speed(s1,s2)

print(t2)

W = np.array([[0,0,0,0,0,0],
              [5,3,3,5,4,1],
              [2,5,4,4,4,2],
              [5,5,2,1,3,1],
              [4,2,3,4,4,1],
              [1,5,5,5,2,3]])
print(W,'\n')
if t1 < t2:
    fast = path1.copy()
    slow = path2.copy()
else:
    fast = path2.copy()
    slow = path1.copy()


for coord in fast:
    x, y = coord
    W[x][y] += 1

for coord in slow:
    x, y = coord
    W[x][y] -= 1

print(W)