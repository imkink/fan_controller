/* Samle Code */

#include <M5Atom.h>

// 硬件定义
const int FAN_PWM_PIN = 22;  // ATOM的GPIO22支持PWM
const int PWM_CHANNEL = 0;   // 使用PWM通道0
const int PWM_FREQ = 25000;  // 25kHz（适用于多数PWM风扇）
const int PWM_RESOLUTION = 8;// 8位分辨率（0-255）

void setup() {
  M5.begin(true, false, true);
  
  // 配置PWM
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(FAN_PWM_PIN, PWM_CHANNEL);
  
  Serial.println("Fan PWM Ready");
}

void loop() {
  // 示例：手动设置转速（0-255对应0-100%）
  setFanSpeed(128);  // 50%转速
  delay(3000);
  setFanSpeed(255);  // 全速
  delay(3000);
  setFanSpeed(0);    // 停转
  delay(3000);
}

// PWM调速函数
void setFanSpeed(int speed) {
  speed = constrain(speed, 0, 255);
  ledcWrite(PWM_CHANNEL, speed);
  Serial.printf("Fan Speed: %d/255\n", speed);
}
