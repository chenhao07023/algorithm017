# 学习笔记

## 字典树
即 Trie 树，又称单词查找树或键树，是一种树形结构。

### 典型应用

是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。

### 基本性质

1. 结点本身不存完整单词
2. 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的
字符串
3. 每个结点的所有子结点路径代表的字符都不相同

### 核心思想
Trie 树的核心思想是空间换时间。
利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的


## 并查集 Disjoint Set

### 基本操作

- makeSet(s)
- unionSet(x, y)
- find(x)


## 树的遍历代码模板

```
def preorder(self, root): 
    if root: 
        self.traverse_path.append(root.val) 
        self.preorder(root.left) 
        self.preorder(root.right)


def inorder(self, root):
    if root: 
        self.inorder(root.left) 
        self.traverse_path.append(root.val) 
        self.inorder(root.right)

def postorder(self, root):
    if root: 
        self.postorder(root.left) 
        self.postorder(root.right) 
        self.traverse_path.append(root.val)

```

## 二叉搜索树 Binary Search Tree

- 左子树上所有结点的值均小于它的根结点的值；
- 右子树上所有结点的值均大于它的根结点的值；
- 以此类推：左、右子树也分别为二叉查找树。 （这就是 重复性！）

### AVL 树

#### Balance Factor（平衡因子）：
是它的左子树的高度减去它的右子树的高度（有时相反）。
balance factor = {-1, 0, 1}

#### 通过旋转操作来进行平衡（四种）

- 左旋
- 右旋
- 左右旋
- 右左旋

### 红黑树

- 每个结点要么是红色，要么是黑色
- 根结点是黑色
- 每个叶结点（NIL结点，空结点）是黑色的。 
- 不能有相邻接的两个红色结点 
- 从任一结点到其每个叶子的所有路径都包含相同数目的黑色结点。

#### 关键性质

从根到叶子的最长的可能路径不多于最短的可能路径的两倍长

#### AVL VS 关键性质

- AVL trees providefaster lookups than Red Black Trees because they are more strictly 
balanced.
- Red Black Trees providefaster insertion and removal operations than AVL trees as 
fewer rotations are done due to relatively relaxed balancing.
- AVL trees storebalance factors or heightswith each node, thus requires storage for 
an integer per node whereas Red Black Tree requires only 1 bit of information per 
node.
- Red Black Trees are used in most of the language libraries 
likemap, multimap, multisetin C++whereas AVL trees are used indatabaseswhere 
faster retrievals are required.