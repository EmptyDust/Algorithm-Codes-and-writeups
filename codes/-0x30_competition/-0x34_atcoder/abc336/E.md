注意到：
1.该数字最多有13位，因此数位和最大为13*9=117,遍历所有可能的数位和.
2.例如在mod 8条件下，2024（mod 8）等价于424（20%8=4）等价于24(42%8=2),显然整除，且2024数位和等于8，此时可以计算出2024符合条件。
深搜遍历所有位置可能的数。
由于递归，因此可以过程化地记录三元组 $(pos,sum,cur)$ （pos代表数位，sum代表当前数位和，cur代表当前数对mod的余数） 对应的数量 $res$ ，显然下次遍历到它时（如110024的1100%8=4）直接取出答案。
时间复杂度为 $O(81 \times length^3)$ 。