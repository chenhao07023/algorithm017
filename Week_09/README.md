# 高级动态规划

## 复习

人肉递归低效、很累

找到最近最简方法，将其拆解成可重复解决的问题

数学归纳法思维

### 本质

寻找重复性


## 动态规划

1.问题定义
“Simplifying a complicated problem by breaking it down into 
simpler sub-problems” 
(in a recursive manner)

2.Divide & Conquer + Optimal substructure  （分支+最优子结构）

3.顺推形式： 动态递推

### 递推模板

func DP():
    dp = [][]
    for i..N:
      for j..M:
        dp[i][j] = _Function(dp[i'][j'])
    return dp[N][M]


### 关键点

动态规划 和 递归或者分治 没有根本上的区别（关键看有无最优的子结构） 

拥有共性：找到重复子问题

差异性：最优子结构，中途可以淘汰次优解



### 不同路径2 的动态递归方程

if (obstacleGrid[i][j]== 1)
    dp[i][j] = 0;
else
    dp[i][j] = dp[i-1][j] + dp[i][j-1];

## 高阶动态规划

### 复杂度

状态拥有更多维度（二维、三维、或者更多、甚至需要压缩）

状态方程更加复杂










