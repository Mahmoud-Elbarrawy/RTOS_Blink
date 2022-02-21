// Use only core 1 for demo 
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif
#define LED_BUILTIN 2
// Pins 
static const int led_pin = LED_BUILTIN;

// Define the task (Blink an LED) 
void toggleLED(void *ptr) {
 while(1){ 
  digitalWrite(led_pin,HIGH);
  vTaskDelay(500/portTICK_PERIOD_MS);// vTaskDealy fun. taks ticks as an arg., portTICK_PERIOD_MS = 1ms by defualt
                                 // To get the ms of delay devid ms over portTICK_PERIOD_MS
  digitalWrite(led_pin,LOW);
  vTaskDelay(500/portTICK_PERIOD_MS);
}  
  }

// Define the task (Blink an LED) 
void toggleLED2(void *ptr) {
 while(1){ 
  digitalWrite(led_pin,HIGH);
  vTaskDelay(750/portTICK_PERIOD_MS);// vTaskDealy fun. taks ticks as an arg., portTICK_PERIOD_MS = 1ms by defualt
                                 // To get the ms of delay devid ms over portTICK_PERIOD_MS
  digitalWrite(led_pin,LOW);
  vTaskDelay(750/portTICK_PERIOD_MS);
}  
  }
void setup() {
  // Config. pin
  pinMode(led_pin,OUTPUT);
  
  // Config. Task
  xTaskCreatePinnedToCore( // Use xTaskcreate() in vanilla Free RTOS
  toggleLED,               // Fun to be called
  "Toggle LED",            // Task Name
  1024,                    // Uint16_t usStackDepth Stack size (bytes in ESP32, words in FreeRTOS)
  NULL,                    // Parameter to pass to the fun
  1,                       // Task priority 
  NULL,                    // Task handle
  app_cpu);                // Run on one core only for (ESP32)

  // Task config is done in this way because it is spesfic to esp32 on Arduino IDE

  // Config. Task
  xTaskCreatePinnedToCore( // Use xTaskcreate() in vanilla Free RTOS
  toggleLED2,               // Fun to be called
  "Toggle LED2",            // Task Name
  1024,                    // Uint16_t usStackDepth Stack size (bytes in ESP32, words in FreeRTOS)
  NULL,                    // Parameter to pass to the fun
  1,                       // Task priority 
  NULL,                    // Task handle
  app_cpu);                // Run on one core only for (ESP32)
}

void loop() {

}
