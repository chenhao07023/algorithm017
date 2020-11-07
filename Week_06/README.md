# 学习笔记

## 递归代码模板

void recursion(int level, int param)
{
    //recursion terminator
    if (level > MAX)
    {
        return result;
    }
    
    //process curr
    process(level, param);
    
    //next(drill down)
    recursion(level+1, param);
}

## 分治代码模板

int divide_conquer(Problem *problem, int params) {
  // recursion terminator
  if (problem == nullptr) 
  {
      return return_result;
  } 

  // process current problem
  subproblems = split_problem(problem, data)
  sub1 = divide_conquer(subproblem[0], p1)
  sub2 = divide_conquer(subproblem[1], p1)
  sub3 = divide_conquer(subproblem[2], p1)
  ...

  // merge
  result = process_result(sub1, sub2, sub3)
  // revert the current level status
 
  return 0;
}

## 感触

1.人肉递归效率低下
2.找到最近最简方法，将其拆解成可重复解决的问题
3.数学归纳法思维（抵制人肉递归的诱惑）

本质：寻找重复性

## 动态规划关键点

### 1.最优子结构
opt[n] = best_of(opt[n-1], opt[n-2], …)

### 2.存储中间状态
opt[i]

### 3.dp方程：状态转移方程
Fib: opt[i] = opt[n-1] + opt[n-2]
二维路径：opt[i,j] = opt[i+1][j] + opt[i][j+1] (且判断a[i,j]是否空地）

## 小结

1. 打破自己的思维惯性，形成机器思维
2. 理解复杂逻辑的关键
3. 也是职业进阶的要点要领






