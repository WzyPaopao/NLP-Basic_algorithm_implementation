# 《自然语言处理入门》学习笔记

## 第二章

### 2.4 字典树

- **Trie** 

  通过树的形式，讲整个预料进行表示。这样的好处是只需要遍历一次预料，就能生成Trie，之后的任何查询都不再需要源语料，并且查找速度较快，如果每个节点都进行字符的 **全散列** ，则时间复杂度为 **O(log *n*)** 。

- **BinTrie** 

  在 **Trie** 的基础上，只对根节点进行全散列，这样的好处是能够保证时间复杂度的情况下，对空间复杂度进行压缩。BinTrie只有根节点进行了全散列，其余节点的散列是动态增加的，并且对整个散列进行排序，查找的时候，通过散列值进行 **二分查找**。（这里的二分查找，比较的是字符的散列值）

  ```python
  def binarySearch(char_array: list, goal: char):
      start = 0
      end = len - 1
      while start < end:
          mid = (start + end) / 2
          if hash( char_array[mid] ) > hash( goal ):
              mid = end
          elif hash( char_array[mid] ) < hash( goal ):
              mid = start
      return char_array[mid]
  ```

  

- **DoubleArrayTrie** 

  BinTrie只有根节点进行了全散列，所以只有在根节点的状态转移时间复杂度为 **O(1)** ，其余节点使用二分查找，当存在 *c* 个子节点的时候，状态转移的时间复杂度为 **O(log *c*)** 。DAT通过维护两个数组（Base和Check），只需要通过两次数组查询就能完成状态转移，将状态转移的时间复杂度降低为 **O(*c*)** 。