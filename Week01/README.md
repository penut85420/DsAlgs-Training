# Week 1

## Day 1 - 選擇排序法 Selection Sort
### 簡介
+ 先拿了這個很常見、很普通，是我人生寫的第一個排序演算法來試試刀
+ 以從小排到大的例子來講，就是每一次都從剩下的數字裡面挑一個最大的放到後面
+ 簡單好上手，但複雜度在任何方面都是 n<sup>2</sup> 的演算法
+ 順便測量了一下程式實際運作的時間，從結果來看可以發現實做語言的差異還是相當的大
+ Wikipedia: [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort)

### 評估
+ C
  ```
  Run 25 Times - Array Size: 5000

  Run  1 Time Cost: 0.027476
  Run  2 Time Cost: 0.022451
  ...
  Run 24 Time Cost: 0.024214
  Run 25 Time Cost: 0.025828

  Average Time Cost: 0.027280
  ```
+ Python
  ```
  Run 25 Times - Array Size: 5000

  Run  1 Time Cost: 1.102930
  Run  2 Time Cost: 1.097699
  ...
  Run 24 Time Cost: 1.097158
  Run 25 Time Cost: 1.104857

  Average Time Cost: 1.098899
  ```
+ 效能差距約 50 倍左右

## Day 2 - 二分搜尋法 Binary Search
+ 從已經排序好的陣列中搜尋目標所在位置
+ 這是第一個複雜度為 log 等級的演算法
+ 主要是練習使用遞迴的方式

## Day 3 - 排列 Permutation
+ 產生一個陣列所有的排列可能
+ 這裡主要也是在練習遞迴的用法

## Day 4 - 組合 Combination
+ 產生一個陣列所有的組合可能
+ 寫法與排列很相似，但是元素可重複出現，長度也不一定
+ Python 嘗試了比較物件導向的寫法

## Day 5 - 矩陣相加 Matrix Addition
+ 加法算是矩陣運算中相對簡單的題目
+ 透過矩陣相加複習了一下二維陣列的動態宣告與印出矩陣
+ Python 一樣用了物件的方式，順便挑戰令人看不懂的單行寫法