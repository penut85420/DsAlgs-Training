# Exercise

## Exercise 1 - 3 Numbers Sorting
+ 試著在不使用判斷敘述下排序三個數字
+ 用計算的方式得到最大值和最小值還蠻酷的
+ [Reference](https://tinyurl.com/y2sh2r3a)
+ Min, Max 的原理是這樣
  ```
  假設最小值為 x, 最大值為 y = x + d
  x + y + abs(x - y)
    = x + x + d + abs(x - x - d)
    = 2x + d + abs(-d)
    = 2x + 2d
    = 2(x + d)
  上式除以 2 即為最大值
  
  同理
  x + y - abs(x - y)
    = x + x + d - abs(x - x + d)
    = 2x + d - d
    = 2x
  上式除以 2 即為最小值
  ```

## Exercise 2 - Sum of Divisors
+ 給一個整數 n, n > 1
+ 計算這個整數所有小於自身的除數總和
  + t 整除 n 且 0 < t < n