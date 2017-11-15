// 按键示例
// 通过Serial输出不同的按键信息
//
// 短击                        // 长击（持续按键1s或者更长）
//        单击                 //        单击
//        双击                 //        双击
//        三击                 //        三击
//

#include <ClickButton.h>


// 按键连接管脚
const int buttonPin1 = D0;
ClickButton button1(buttonPin1, LOW, CLICKBTN_PULLUP);

// 按键输出结果标识
int function = 0;


void setup()
{
  pinMode(buttonPin1, INPUT_PULLUP);

  // 设定按钮设置时间（单位：ms）
  // (以下的设置是默认设置，为了修改方便，可以设置其他值）
  button1.debounceTime   = 20;   // 按键抖动时间（单位：ms）
  button1.multiclickTime = 250;  // 多次点击的时间限定值（单位：ms）
  button1.longClickTime  = 1000; // 上按按钮时间限定值（单位：ms）
}


void loop()
{
  // 更新按键状态
  button1.Update();

  // 保存clicks值到function变量，因为clicks将会在下一个update被重置
  if (button1.clicks != 0) function = button1.clicks;

  if(button1.clicks == 1) Serial.println("SINGLE click");

  if(function == 2) Serial.println("DOUBLE click");

  if(function == 3) Serial.println("TRIPLE click");

  if(function == -1) Serial.println("SINGLE LONG click");

  if(function == -2) Serial.println("DOUBLE LONG click");

  if(function == -3) Serial.println("TRIPLE LONG click");

  function = 0;
  delay(5);
}
