# Qt-Project1-產業機台介面

## 開發環境

- Ubuntu 14.04
- Qt Creator
- 執行於 NVIDIA Jetson TK1

## 專案介紹

•	設計一個簡易的使用者介面，可供顯示目前機台運作狀態。

• 使用LED作為實際機台的顯示介面。

• 使用者端則使用QT作為操作介面，用以機台互動。

• 在本專案中，機台分為下列幾種工作狀態：

  1. 啟動中(程式開啟)
  
   ① 三個LED同時閃爍(亮暗間距為一秒)。
   
   ② Slider及Slider Editor數值改變時，LED不受影響。
   
   ③ Start按鈕為可操作狀態(enable)。
   
   ④ Stop按鈕及Reset按鈕為無法操作狀態(disable)。
   
   ⑤ Slider初始狀況為最小值(0)，Slider Editor初始值為0。
   
  2. 開始(Start按下去之後)
  
   ① 第一個LED維持亮，不再閃爍。
   
   ② 另外兩個LED為當前Slider的數值(0為暗暗，1為暗亮，2為亮暗，3為亮亮)。
   
   ③ Slider最大值為3，最小值為0，Slider Editor需跟著Slider拉動而改變，反之Slider Editor改變Slider也會跟著改變。
   
   ④ 若Slider Editor輸入大於3則需維持3，小於0則維持0。
   
   ⑤ Slider及Slider Editor改變時，LED顯示也會跟著一起改變。
   
   ⑥ Start按鈕為不可操作狀態(disable)。
   
   ⑦ Stop按鈕及Reset按鈕為可操作狀態(enable)。
   
  3. 停止(Stop按下去之後)
  
   ① 所有LED維持暗。
   
   ② Slider及Slider Editor數值改變時，LED不受影響(保持暗)。
   
   ③ Start按鈕及Reset按鈕為可操作狀態(enable)。
   
   ④ Stop按鈕為不可操作狀態(disable)。
   
  4. 重置(Reset按下去之後)
  
   ① 系統回到啟動中(程式開啟狀態)。
   
   5. 關閉(程式結束)
   
   ① 關閉GPIO(unexport)。

## 專案成果

![image](https://cdn1-t17-techbang.pixfs.net/system/attached_images/2018/10/245247/original/30b1ef5cd893256e58a92565d284affc.png)
![image](https://cdn0-t17-techbang.pixfs.net/system/attached_images/2018/10/245246/original/c221157c19cdefc8a51271bc9d55ad69.jpg)
