#include <IRremote.h>
 
// irREMOTE V3.1 
// https://github.com/Arduino-IRremote/Arduino-IRremote/archive/master.zip
 

#define ONN     551489775    //код вкл выкл на LG 551489775;
#define CODELEN 32           //Кнопка 2

boolean irOk = false;

IRrecv irrecv(2); // указываем вывод, к которому подключен приемник
decode_results results;

void setup() {
  Serial.begin(9600); // выставляем скорость COM порта
  irrecv.enableIRIn(); // запускаем прием
  IrSender.begin(11, DISABLE_LED_FEEDBACK); // устанавливаем выход v3  11pin
}

void loop() {
   if (irrecv.decode()) { // если данные пришли  && !irOk
    Serial.print( "Результ минимал"); // печатаем данные
    irrecv.printIRResultMinimal(&Serial);
    unsigned long codeValue = results.value;
    Serial.println(); // печатаем данные
    Serial.print("Результ шорт"); // печатаем данные
    irrecv.printIRResultShort(&Serial);
    Serial.println( ""); // печатаем данные
    Serial.println( irrecv.decodedIRData.decodedRawData,HEX); // печатаем данные
    delay(50);
      IrSender.sendNEC(0xDF00 , 0x1C, 0);
    // irsend.sendNECRaw(0xE31CDF00, 0); //вариант 2
    //irsend.sendNECMSB(0xE31CDF00, 32, false);// вариант 3 не рабочий
    Serial.println("SEND");
    irrecv.enableIRIn();
    delay(50);
  }
      irrecv.resume(); // принимаем следующую команду
          delay(50);
}
