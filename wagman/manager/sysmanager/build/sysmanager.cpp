#line 1 "sysmanager.ino"
                                                                               
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/eeprom.h>
#include <Wire.h>
#include <HTU21D.h>
#include <Time.h>
#include <MCP79412RTC.h>
#include <SoftReset.h>



                                                                               
                   

                        
#define PIN_RELAY_NC 4
#define PIN_HEARTBEAT_NC 5
                       
#define PIN_RELAY_SWITCH 6
#define PIN_HEARTBEAT_SWITCH 7
                     
#define PIN_RELAY_GN1 8
#define PIN_HEARTBEAT_GN1 9
                     
#define PIN_RELAY_GN2 10
#define PIN_HEARTBEAT_GN2 11
                     
#define PIN_RELAY_GN3 12
#define PIN_HEARTBEAT_GN3 13
                     
#define PIN_THERMISTOR_NC A0
#define PIN_THERMISTOR_SWITCH A1
#define PIN_THERMISTOR_GN1 A2
#define PIN_THERMISTOR_GN2 A3
#define PIN_THERMISTOR_GN3 A4
                 
#define PIN_PHOTOCELL A5

                                       
                                            
#define HEARTBEAT_PERIOD_ODROID 40

                                                 
#define POWER_CYCLE_DELAY 2000

                                                            
#define BOOT_BAD_ENVIRON_WAIT_TIME 5
                                                      
#define BOOT_BAD_POWER_WAIT_TIME 1

                                    
#define ADDR_CURRENT_SENSOR_SYSMON 0x60
#define ADDR_CURRENT_SENSOR_NC 0x62
#define ADDR_CURRENT_SENSOR_SWITCH 0x63
#define ADDR_CURRENT_SENSOR_GN1 0x68
#define ADDR_CURRENT_SENSOR_GN2 0x6A
#define ADDR_CURRENT_SENSOR_GN3 0x6B

                                                     
#define MILLIAMPS_PER_STEP 16

                                                                  
#define NC_MESSAGE_DELAY 10
                                                            
#define NC_SHUTDOWN_DELAY 5000
                                                                          
#define NC_TIME_ACQUIRE_DELAY 20000

                                                       
#define TIME_UPDATE_REQUEST_PERIOD 3600

                                                              
#define NC_NOTIFIER_STATUS '@'
#define NC_NOTIFIER_PROBLEM '#'
#define NC_NOTIFIER_PARAMS_CORE '$'
#define NC_NOTIFIER_PARAMS_GN '^'
#define NC_NOTIFIER_TIME_REQUEST '*'
#define NC_NOTIFIER_TIME_SEND '('
#define NC_NOTIFIER_CONFIG_DONE "="
#define NC_NOTIFIER_SHUTDOWN '?'
#define NC_DELIMITER ','
#define NC_TERMINATOR '!'

                                      
#define PROBLEM_SYSMON_ENVIRON "SM,e"
#define PROBLEM_SYSMON_POWER "SM,p"
#define PROBLEM_NC_TEMP "NC,t"
#define PROBLEM_NC_ENVIRON "NC,e"
#define PROBLEM_NC_POWER "NC,p"
#define PROBLEM_NC_HEARTBEAT "NC,h"
#define PROBLEM_SWITCH_TEMP "SW,t"
#define PROBLEM_SWITCH_POWER "SW,p"
                                                       
                                                                          
                                                
#define PROBLEM_SWITCH_HEARTBEAT "SW,h"
#define PROBLEM_GN1_TEMP "GN1,t"
#define PROBLEM_GN1_POWER "GN1,p"
#define PROBLEM_GN1_HEARTBEAT "GN1,h"
#define PROBLEM_GN2_TEMP "GN2,t"
#define PROBLEM_GN2_POWER "GN2,p"
#define PROBLEM_GN2_HEARTBEAT "GN2,h"
#define PROBLEM_GN3_TEMP "GN3,t"
#define PROBLEM_GN3_POWER "GN3,p"
#define PROBLEM_GN3_HEARTBEAT "GN3,h"

                                                       
#define REQUEST_TIME '1'
#define REQUEST_STATUS '2'
#define REQUEST_REBOOT_NC '3'
#define REQUEST_REBOOT_SWITCH '4'
#define REQUEST_REBOOT_GN1 '5'
#define REQUEST_REBOOT_GN2 '6'
#define REQUEST_REBOOT_GN3 '7'



                                                                               
#include "Arduino.h"
void setup();
void loop();
boolean check_environ_NC();
boolean check_environ_SysMon();
boolean check_heartbeat_odroid(byte device);
boolean check_power_GN(byte gn);
boolean check_power_NC();
boolean check_power_switch();
boolean check_power_SysMon();
boolean check_temp_GN(byte gn);
boolean check_temp_NC();
boolean check_temp_switch();
void get_time_NC();
void power_cycle(byte device);
void send_problem(String problem);
void send_status();
void send_time();
void sleep_SysMon();
boolean POST();
boolean gprf_test();
boolean stack_pointer_test();
boolean status_register_test();
boolean sram_test();
boolean watchdog_test(byte reason);
boolean ADC_test();
boolean timer1_test();
boolean interrupt_test();
byte find_reset_reason();
void test_failure(byte reason, boolean fatal);
void sleep();
void boot_SOS();
void init_SOS();
void report_failure_POST();
void boot_GN(byte gn);
boolean boot_primary();
boolean boot_NC();
void boot_switch();
boolean boot_SysMon();
void get_params_core();
void get_params_GNs();
void init_primary();
void set_default_eeprom();
#line 122
volatile byte _timer1_cycle = false;

HTU21D SysMon_HTU21D;

boolean _NC_running = false;
boolean _switch_running = false;
boolean _GN1_running = false;
boolean _GN2_running = false;
boolean _GN3_running = false;

byte count_status_report = 0;
long count_time_update_request = 0;
byte count_timeout_heartbeat_NC = 0;
byte count_timeout_heartbeat_switch = 0;
byte count_timeout_heartbeat_GN1 = 0;
byte count_timeout_heartbeat_GN2 = 0;
byte count_timeout_heartbeat_GN3 = 0;
byte count_timeout_power_SysMon = 0;
byte count_timeout_power_NC = 0;
byte count_timeout_power_switch = 0;
byte count_timeout_power_GN1 = 0;
byte count_timeout_power_GN2 = 0;
byte count_timeout_power_GN3 = 0;
byte count_timeout_environ_SysMon = 0;
byte count_timeout_environ_NC = 0;
byte count_timeout_temp_processor_NC = 0;
byte count_timeout_temp_switch = 0;
byte count_timeout_temp_GN1 = 0;
byte count_timeout_temp_GN2 = 0;
byte count_timeout_temp_GN3 = 0;
unsigned int count_device_reboot = 0;

unsigned int latest_power_SysMon;
int latest_environ_temp_SysMon_NC;
byte latest_environ_hum_SysMon_NC;
unsigned int latest_power_NC;
unsigned int latest_temp_NC;
unsigned int latest_power_switch;
unsigned int latest_temp_switch;
unsigned int latest_power_GN1;
unsigned int latest_temp_GN1;
unsigned int latest_power_GN2;
unsigned int latest_temp_GN2;
unsigned int latest_power_GN3;
unsigned int latest_temp_GN3;

                                                            
uint32_t EEMEM E_USART_BAUD;
uint16_t EEMEM E_USART_RX_BUFFER_SIZE;
uint8_t EEMEM E_STATUS_REPORT_PERIOD;
uint8_t EEMEM E_MAX_NUM_SOS_BOOT_ATTEMPTS;
uint8_t EEMEM E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS;
uint8_t EEMEM E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS;
uint16_t EEMEM E_DEVICE_REBOOT_PERIOD;
uint8_t EEMEM E_PRESENT_SWITCH;
uint16_t EEMEM E_BOOT_TIME_NC;
uint16_t EEMEM E_CONFIG_TIME_NC;
uint8_t EEMEM E_BOOT_TIME_SWITCH;
uint16_t EEMEM E_BOOT_TIME_GN1;
uint16_t EEMEM E_BOOT_TIME_GN2;
uint16_t EEMEM E_BOOT_TIME_GN3;
uint8_t EEMEM E_PRESENT_GN1;
uint8_t EEMEM E_PRESENT_GN2;
uint8_t EEMEM E_PRESENT_GN3;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_NC;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_SWITCH;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN1;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN2;
uint8_t EEMEM E_HEARTBEAT_TIMEOUT_GN3;
uint8_t EEMEM E_ENVIRON_TIMEOUT_SYSMON;
uint8_t EEMEM E_ENVIRON_TIMEOUT_NC;
uint8_t EEMEM E_TEMP_PROCESSOR_TIMEOUT_NC;
uint8_t EEMEM E_TEMP_TIMEOUT_SWITCH;
uint8_t EEMEM E_TEMP_TIMEOUT_GN1;
uint8_t EEMEM E_TEMP_TIMEOUT_GN2;
uint8_t EEMEM E_TEMP_TIMEOUT_GN3;
uint8_t EEMEM E_POWER_TIMEOUT_SYSMON;
uint8_t EEMEM E_POWER_TIMEOUT_NC;
uint8_t EEMEM E_POWER_TIMEOUT_SWITCH;
uint8_t EEMEM E_POWER_TIMEOUT_GN1;
uint8_t EEMEM E_POWER_TIMEOUT_GN2;
uint8_t EEMEM E_POWER_TIMEOUT_GN3;
uint16_t EEMEM E_TEMP_MIN_SYSMON;
uint16_t EEMEM E_TEMP_MAX_SYSMON;
uint16_t EEMEM E_TEMP_MIN_NC;
uint16_t EEMEM E_TEMP_MAX_NC;
uint16_t EEMEM E_TEMP_MIN_PROCESSOR_NC;
uint16_t EEMEM E_TEMP_MAX_PROCESSOR_NC;
uint16_t EEMEM E_TEMP_MIN_SWITCH;
uint16_t EEMEM E_TEMP_MAX_SWITCH;
uint16_t EEMEM E_TEMP_MIN_GN1;
uint16_t EEMEM E_TEMP_MAX_GN1;
uint16_t EEMEM E_TEMP_MIN_GN2;
uint16_t EEMEM E_TEMP_MAX_GN2;
uint16_t EEMEM E_TEMP_MIN_GN3;
uint16_t EEMEM E_TEMP_MAX_GN3;
uint8_t EEMEM E_HUMIDITY_MIN_SYSMON;
uint8_t EEMEM E_HUMIDITY_MAX_SYSMON;
uint8_t EEMEM E_HUMIDITY_MIN_NC;
uint8_t EEMEM E_HUMIDITY_MAX_NC;
uint16_t EEMEM E_MILLIAMP_MAX_SYSMON;
uint16_t EEMEM E_MILLIAMP_MAX_NC;
uint16_t EEMEM E_MILLIAMP_MAX_SWITCH;
uint16_t EEMEM E_MILLIAMP_MAX_GN1;
uint16_t EEMEM E_MILLIAMP_MAX_GN2;
uint16_t EEMEM E_MILLIAMP_MAX_GN3;
                                                                
uint8_t EEMEM E_NC_ENABLED;
uint8_t EEMEM E_SWITCH_ENABLED;
uint8_t EEMEM E_GN1_ENABLED;
uint8_t EEMEM E_GN2_ENABLED;
uint8_t EEMEM E_GN3_ENABLED;
uint8_t EEMEM E_POST_RESULT;
uint8_t EEMEM E_TIMER_TEST_INCOMPLETE;
uint8_t EEMEM E_NUM_SOS_BOOT_ATTEMPTS;
uint8_t EEMEM E_NUM_PRIMARY_BOOT_ATTEMPTS;
uint8_t EEMEM E_FIRST_BOOT;



                                                                               
  
                                                                           
           

               
  
void setup() 
{
                                           
  wdt_disable();

                     
  #ifdef BOOT_POST
                                                  
    if(POST())
    {
                                                                             
      if(boot_primary())
      {
                               
        boot_GN(1);
        boot_GN(2);
        boot_GN(3);
      }
      else
      {
                                                                          
        byte num_attempts = eeprom_read_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS) + 1;

                                                 
        eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, num_attempts);

                                                                   
        if(num_attempts < eeprom_read_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS))
          soft_restart();
        else
        {
                                                                   
                                                             
          eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);

                                                             
          delay(10);

                                              
          sleep_SysMon();
        }
      }
    }
                                          
    else
                                    
      boot_SOS();
  #else
                                                                           
    if(boot_primary())
    {
                             
      boot_GN(1);
      boot_GN(2);
      boot_GN(3);
    }
    else
    {
                                                                        
      byte num_attempts = eeprom_read_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS) + 1;

                                               
      eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, num_attempts);

                                                                 
      if(num_attempts < eeprom_read_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS))
        soft_restart();
      else
      {
                                                                 
                                                           
        eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);

                                                           
        delay(10);

                                            
        sleep_SysMon();
      }
    }
  #endif
}



                                                                               
  
                                                                        
                                                                              
                                                                 

               
  
void loop() 
{
                                    
  if(_timer1_cycle)
  {
                                      
    count_status_report++;

                                     
    count_time_update_request++;

          
                                  
          

                                            
    if(!check_environ_SysMon())
                          
      count_timeout_environ_SysMon++;
    else
                                                                     
      count_timeout_environ_SysMon = 0;

                                           
    if(!check_power_SysMon())
      count_timeout_power_SysMon++;
    else
      count_timeout_power_SysMon = 0;


                                    
    if(_NC_running)
    {
                                                           
      if(!check_environ_NC())
        count_timeout_environ_NC++;
      else
        count_timeout_environ_NC = 0;

                                                                     
      if(!check_temp_NC())
        count_timeout_temp_processor_NC++;
      else
        count_timeout_temp_processor_NC = 0;

                                                          
      if(!check_power_NC())
        count_timeout_power_NC++;
      else
        count_timeout_power_NC = 0;

                                                         
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_NC))
        count_timeout_heartbeat_NC++;
      else
        count_timeout_heartbeat_NC = 0;
    }


                                    
    if(_switch_running)
    {
                                                           
      if(!check_temp_switch())
        count_timeout_temp_switch++;
      else
        count_timeout_temp_switch = 0;

                                                          
      if(!check_power_switch())
        count_timeout_power_switch++;
      else
        count_timeout_power_switch = 0;
    }


                                 
    if(_GN1_running)
    {
                                                      
      if(!check_temp_GN(1))
        count_timeout_temp_GN1++;
      else
        count_timeout_temp_GN1 = 0;

                                                     
      if(!check_power_GN(1))
        count_timeout_power_GN1++;
      else
        count_timeout_power_GN1 = 0;

                                                    
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN1))
        count_timeout_heartbeat_GN1++;
      else
        count_timeout_heartbeat_GN1 = 0;
    }


                                 
    if(_GN2_running)
    {
                                                      
      if(!check_temp_GN(2))
        count_timeout_temp_GN2++;
      else
        count_timeout_temp_GN2 = 0;

                                                     
      if(!check_power_GN(2))
        count_timeout_power_GN2++;
      else
        count_timeout_power_GN2 = 0;

                                                    
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN2))
        count_timeout_heartbeat_GN2++;
      else
        count_timeout_heartbeat_GN2 = 0;
    }


                                 
    if(_GN3_running)
    {
                                                      
      if(!check_temp_GN(3))
        count_timeout_temp_GN3++;
      else
        count_timeout_temp_GN3 = 0;

                                                     
      if(!check_power_GN(3))
        count_timeout_power_GN3++;
      else
        count_timeout_power_GN3 = 0;

                                                    
      if(!check_heartbeat_odroid(PIN_HEARTBEAT_GN3))
        count_timeout_heartbeat_GN3++;
      else
        count_timeout_heartbeat_GN3 = 0;
    }


                                                                  
    count_device_reboot++;


          
                           
          

                                    
    if(count_timeout_power_SysMon >= eeprom_read_byte(&E_POWER_TIMEOUT_SYSMON))
    {
                                              
      send_problem(PROBLEM_SYSMON_POWER);

                                               
      count_timeout_power_SysMon = 0;
      count_timeout_environ_SysMon = 0;

                      
      soft_restart();
    }
                                          
    else if(count_timeout_environ_SysMon >= eeprom_read_byte(&E_ENVIRON_TIMEOUT_SYSMON))
    {
                                              
      send_problem(PROBLEM_SYSMON_ENVIRON);

                                               
      count_timeout_power_SysMon = 0;
      count_timeout_environ_SysMon = 0;

                      
      soft_restart();
    }


                                    
    if(_NC_running)
    {
                                      
      if(count_timeout_heartbeat_NC >= eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_NC))
      {
                                                
        send_problem(PROBLEM_NC_HEARTBEAT);

                                             
        count_timeout_power_NC = 0;
        count_timeout_temp_processor_NC = 0;
        count_timeout_environ_NC = 0;
        count_timeout_heartbeat_NC = 0;

                                     
        boot_NC();
      }
                                  
      else if(count_timeout_power_NC >= eeprom_read_byte(&E_POWER_TIMEOUT_NC))
      {
                                                
        send_problem(PROBLEM_NC_POWER);

                                             
        count_timeout_power_NC = 0;
        count_timeout_temp_processor_NC = 0;
        count_timeout_environ_NC = 0;
        count_timeout_heartbeat_NC = 0;

                                     
        boot_NC();
      }
                                        
      else if(count_timeout_environ_NC >= eeprom_read_byte(&E_ENVIRON_TIMEOUT_NC))
      {
                                                
        send_problem(PROBLEM_NC_ENVIRON);

                                             
        count_timeout_power_NC = 0;
        count_timeout_temp_processor_NC = 0;
        count_timeout_environ_NC = 0;
        count_timeout_heartbeat_NC = 0;

                                     
        boot_NC();
      }
                                                  
      else if(count_timeout_temp_processor_NC >= eeprom_read_byte(&E_TEMP_PROCESSOR_TIMEOUT_NC))
      {
                                                
        send_problem(PROBLEM_NC_TEMP);

                                             
        count_timeout_power_NC = 0;
        count_timeout_temp_processor_NC = 0;
        count_timeout_environ_NC = 0;
        count_timeout_heartbeat_NC = 0;

                                     
        boot_NC();
      }
    }


                                    
    if(_switch_running)
    {
                                               
      if(count_timeout_power_switch >= eeprom_read_byte(&E_POWER_TIMEOUT_SWITCH))
      {
                                                
        send_problem(PROBLEM_SWITCH_POWER);

                                                 
        count_timeout_power_switch = 0;
        count_timeout_temp_switch = 0;

                            
        boot_switch();
      }
                                                     
      else if(count_timeout_temp_switch >= eeprom_read_byte(&E_TEMP_TIMEOUT_SWITCH))
      {
                                                
        send_problem(PROBLEM_SWITCH_TEMP);

                                                 
        count_timeout_power_switch = 0;
        count_timeout_temp_switch = 0;

                            
        boot_switch();

                                                                    
                                                                       
                           
        latest_power_switch = 0;
        latest_temp_switch = 0;
      }
    }


                                 
    if(_GN1_running)
    {
                                            
      if(count_timeout_power_GN1 >= eeprom_read_byte(&E_POWER_TIMEOUT_GN1))
      {
                                                
        send_problem(PROBLEM_GN1_POWER);

                                                     
        count_timeout_power_GN1 = 0;
        count_timeout_temp_GN1 = 0;
        count_timeout_heartbeat_GN1 = 0;

                            
        boot_GN(1);

                                                                    
                                                                       
                           
        latest_power_GN1 = 0;
        latest_temp_GN1 = 0;
      }
                                                  
      else if(count_timeout_temp_GN1 >= eeprom_read_byte(&E_TEMP_TIMEOUT_GN1))
      {
                                                
        send_problem(PROBLEM_GN1_TEMP);

                                                     
        count_timeout_power_GN1 = 0;
        count_timeout_temp_GN1 = 0;
        count_timeout_heartbeat_GN1 = 0;

                            
        boot_GN(1);

                                                                    
                                                                       
                           
        latest_power_GN1 = 0;
        latest_temp_GN1 = 0;
      }
                                                
      else if(count_timeout_heartbeat_GN1 >= eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_GN1))
      {
                                                
        send_problem(PROBLEM_GN1_HEARTBEAT);

                                                     
        count_timeout_power_GN1 = 0;
        count_timeout_temp_GN1 = 0;
        count_timeout_heartbeat_GN1 = 0;

                            
        boot_GN(1);

                                                                    
                                                                       
                           
        latest_power_GN1 = 0;
        latest_temp_GN1 = 0;
      }
    }


                                 
    if(_GN2_running)
    {
                                            
      if(count_timeout_power_GN2 >= eeprom_read_byte(&E_POWER_TIMEOUT_GN2))
      {
                                                
        send_problem(PROBLEM_GN2_POWER);

                                                     
        count_timeout_power_GN2 = 0;
        count_timeout_temp_GN2 = 0;
        count_timeout_heartbeat_GN2 = 0;

                            
        boot_GN(2);

                                                                    
                                                                       
                           
        latest_power_GN2 = 0;
        latest_temp_GN2 = 0;
      }
                                                  
      else if(count_timeout_temp_GN2 >= eeprom_read_byte(&E_TEMP_TIMEOUT_GN2))
      {
                                                
        send_problem(PROBLEM_GN2_TEMP);

                                                     
        count_timeout_power_GN2 = 0;
        count_timeout_temp_GN2 = 0;
        count_timeout_heartbeat_GN2 = 0;

                            
        boot_GN(2);

                                                                    
                                                                       
                           
        latest_power_GN2 = 0;
        latest_temp_GN2 = 0;
      }
                                                
      else if(count_timeout_heartbeat_GN2 >= eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_GN2))
      {
                                                
        send_problem(PROBLEM_GN2_HEARTBEAT);

                                                     
        count_timeout_power_GN2 = 0;
        count_timeout_temp_GN2 = 0;
        count_timeout_heartbeat_GN2 = 0;

                            
        boot_GN(2);

                                                                    
                                                                       
                           
        latest_power_GN2 = 0;
        latest_temp_GN2 = 0;
      }
    }


                                 
    if(_GN3_running)
    {
                                            
      if(count_timeout_power_GN3 >= eeprom_read_byte(&E_POWER_TIMEOUT_GN3))
      {
                                                
        send_problem(PROBLEM_GN3_POWER);

                                                     
        count_timeout_power_GN3 = 0;
        count_timeout_temp_GN3 = 0;
        count_timeout_heartbeat_GN3 = 0;

                            
        boot_GN(3);

                                                                    
                                                                       
                           
        latest_power_GN3 = 0;
        latest_temp_GN3 = 0;
      }
                                                  
      else if(count_timeout_temp_GN3 >= eeprom_read_byte(&E_TEMP_TIMEOUT_GN3))
      {
                                                
        send_problem(PROBLEM_GN3_TEMP);

                                                     
        count_timeout_power_GN3 = 0;
        count_timeout_temp_GN3 = 0;
        count_timeout_heartbeat_GN3 = 0;

                            
        boot_GN(3);

                                                                    
                                                                       
                           
        latest_power_GN3 = 0;
        latest_temp_GN3 = 0;
      }
                                                
      else if(count_timeout_heartbeat_GN3 >= eeprom_read_byte(&E_HEARTBEAT_TIMEOUT_GN3))
      {
                                                
        send_problem(PROBLEM_GN3_HEARTBEAT);

                                                     
        count_timeout_power_GN3 = 0;
        count_timeout_temp_GN3 = 0;
        count_timeout_heartbeat_GN3 = 0;

                            
        boot_GN(3);

                                                                    
                                                                       
                           
        latest_power_GN3 = 0;
        latest_temp_GN3 = 0;
      }
    }


                                    
    if(count_status_report >= eeprom_read_byte(&E_STATUS_REPORT_PERIOD))
    {
                          
      count_status_report = 0;

                
      send_status();
    }


                                            
    if(count_time_update_request >= TIME_UPDATE_REQUEST_PERIOD)
    {
                          
      count_time_update_request = 0;

                     
      get_time_NC();
    }

                                       
    if(Serial.available() > 0)
    {
      char incoming = Serial.read();

                                    
      if(incoming == REQUEST_TIME)
        send_time();
      else if(incoming == REQUEST_STATUS)
        send_status();
      else if(incoming == REQUEST_REBOOT_NC)
        boot_NC();
      else if(incoming == REQUEST_REBOOT_SWITCH)
        boot_switch();
      else if(incoming == REQUEST_REBOOT_GN1)
        boot_GN(1);
      else if(incoming == REQUEST_REBOOT_GN2)
        boot_GN(2);
      else if(incoming == REQUEST_REBOOT_GN3)
        boot_GN(3);
    }


                                                             
    if(count_device_reboot >= eeprom_read_word(&E_DEVICE_REBOOT_PERIOD))
    {
                          
      count_device_reboot = 0;

                                                        
      if((! _NC_running) && eeprom_read_byte(&E_NC_ENABLED))
                                          
        boot_NC();

                                                        
      if((! _switch_running) && eeprom_read_byte(&E_SWITCH_ENABLED)
        && eeprom_read_byte(&E_PRESENT_SWITCH))
                                 
        boot_switch();

                                                             
      if((! _GN1_running) && eeprom_read_byte(&E_GN1_ENABLED)
        && eeprom_read_byte(&E_PRESENT_GN1))
                                     
        boot_GN(1);

                                                             
      if((! _GN2_running) && eeprom_read_byte(&E_GN2_ENABLED)
        && eeprom_read_byte(&E_PRESENT_GN2))
                                     
        boot_GN(2);

                                                             
      if((! _GN3_running) && eeprom_read_byte(&E_GN3_ENABLED)
        && eeprom_read_byte(&E_PRESENT_GN3))
                                     
        boot_GN(3);
    }


                                              
    _timer1_cycle = false;
  }
}



                                                                               
  
                           

                                          
                                             

                  
  
boolean check_environ_NC()
{
                                                                    
  latest_environ_temp_SysMon_NC = (int)SysMon_HTU21D.readTemperature();

                                                                 
  latest_environ_hum_SysMon_NC = (byte)SysMon_HTU21D.readHumidity();

                                        
  if(((int)eeprom_read_word(&E_TEMP_MIN_NC) < latest_environ_temp_SysMon_NC)
    && (latest_environ_temp_SysMon_NC < (int)eeprom_read_word(&E_TEMP_MAX_NC))
    && (eeprom_read_byte(&E_HUMIDITY_MIN_NC) < latest_environ_hum_SysMon_NC)
    && (latest_environ_hum_SysMon_NC < eeprom_read_byte(&E_HUMIDITY_MAX_NC)))
  {
                        
    return true;
  }

                      
  return false;
}



                                                                               
  
                           

                                          
                                             

                  
  
boolean check_environ_SysMon()
{
                                                                    
  latest_environ_temp_SysMon_NC = (int)SysMon_HTU21D.readTemperature();

                                                                 
  latest_environ_hum_SysMon_NC = (byte)SysMon_HTU21D.readHumidity();

                                        
  if(((int)eeprom_read_word(&E_TEMP_MIN_SYSMON) < latest_environ_temp_SysMon_NC)
    && (latest_environ_temp_SysMon_NC < (int)eeprom_read_word(&E_TEMP_MAX_SYSMON))
    && (eeprom_read_byte(&E_HUMIDITY_MIN_SYSMON) < latest_environ_hum_SysMon_NC)
    && (latest_environ_hum_SysMon_NC < eeprom_read_byte(&E_HUMIDITY_MAX_SYSMON)))
  {
                        
    return true;
  }

                      
  return false;
}



                                                                               
  
                                                           

                                  
                                       

                                                                 

                  
  
boolean check_heartbeat_odroid(byte device)
{
   boolean result = false;

                                
   byte sample1 = digitalRead(device);

                                        
   delay(HEARTBEAT_PERIOD_ODROID / 2);

                                 
   byte sample2 = digitalRead(device);

                                                                       
   if(sample1 != sample2)
                 
      result = true;
   else
   {
                                                              

                                                    
      delay(2);

                                   
      sample1 = digitalRead(device);

                                           
      delay(HEARTBEAT_PERIOD_ODROID / 2);

                                    
      sample2 = digitalRead(device);

                                                                          
      if(sample1 != sample2)
                    
         result = true;
   }

   delay(2000);

   return result;
}



                                                                               
  
                                                   

                                                       
                                                           

                                                                     

                  
  
boolean check_power_GN(byte gn)
{
  byte msb, csb, lsb;
  int addr;

                                       
  switch (gn) {
    case 1:
                                       
      addr = ADDR_CURRENT_SENSOR_GN1;
      break;

    case 2:
                                       
      addr = ADDR_CURRENT_SENSOR_GN2;
      break;

    case 3:
                                       
      addr = ADDR_CURRENT_SENSOR_GN3;
      break;

    default:
                                                 
      return false;
  }

                                              
  Wire.beginTransmission(addr);
                                                
  Wire.write(0);
                                                                           
  Wire.endTransmission(0);
                        
  Wire.requestFrom(addr, 3);

                                             
  if(Wire.available())
  {
    msb = Wire.read();
                                                                   
    csb = Wire.read() & 0x01;
    lsb = Wire.read();
  }
  else
                        
    return false;

                                        
  Wire.endTransmission(1);

                                             
  unsigned int milliamps = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

                                       
  switch (gn) {
    case 1:
                                               
      latest_power_GN1 = milliamps;

                                                   
      if(latest_power_GN1 < eeprom_read_word(&E_MILLIAMP_MAX_GN1))
                            
        return true;

      break;

    case 2:
                                               
      latest_power_GN2 = milliamps;

                                                   
      if(latest_power_GN2 < eeprom_read_word(&E_MILLIAMP_MAX_GN2))
                            
        return true;

      break;

    case 3:
                                               
      latest_power_GN3 = milliamps;

                                                   
      if(latest_power_GN3 < eeprom_read_word(&E_MILLIAMP_MAX_GN3))
                            
        return true;

      break;

    default:
                                                 
      return false;
  }

                      
  return false;
}



                                                                               
  
                                              

                                                            
                                                                

                  
  
boolean check_power_NC()
{
  byte msb, csb, lsb;

                                              
  Wire.beginTransmission(ADDR_CURRENT_SENSOR_NC);
                                                
  Wire.write(0);
                                                                           
  Wire.endTransmission(0);
                        
  Wire.requestFrom(ADDR_CURRENT_SENSOR_NC, 3);

                                             
  if(Wire.available())
  {
    msb = Wire.read();
                                                                   
    csb = Wire.read() & 0x01;
    lsb = Wire.read();
  }
  else
                        
    return false;

                                        
  Wire.endTransmission(1);

                                             
  latest_power_NC = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

                                               
  if(latest_power_NC < eeprom_read_word(&E_MILLIAMP_MAX_NC))
                        
    return true;

                      
  return false;
}



                                                                               
  
                                             

                                                   
                                                       

                  
  
boolean check_power_switch()
{
  byte msb, csb, lsb;

                                              
  Wire.beginTransmission(ADDR_CURRENT_SENSOR_SWITCH);
                                                
  Wire.write(0);
                                                                           
  Wire.endTransmission(0);
                        
  Wire.requestFrom(ADDR_CURRENT_SENSOR_SWITCH, 3);

                                             
  if(Wire.available())
  {
    msb = Wire.read();
                                                                   
    csb = Wire.read() & 0x01;
    lsb = Wire.read();
  }
  else
                        
    return false;

                                        
  Wire.endTransmission(1);

                                             
  latest_power_switch = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

                                               
  if(latest_power_switch < eeprom_read_word(&E_MILLIAMP_MAX_SWITCH))
                        
    return true;

                      
  return false;
}



                                                                               
  
                                     

                                                   
                                                    

                  
  
boolean check_power_SysMon()
{
  byte msb, csb, lsb;
   
                                              
  Wire.beginTransmission(ADDR_CURRENT_SENSOR_SYSMON);
                                                
  Wire.write(0);
                                                                           
  Wire.endTransmission(0);
                        
  Wire.requestFrom(ADDR_CURRENT_SENSOR_SYSMON, 3);

                                             
  if(Wire.available())
  {
    msb = Wire.read();
                                                                   
    csb = Wire.read() & 0x01;
    lsb = Wire.read();
  }
  else
                        
    return false;

                                        
  Wire.endTransmission(1);

                                             
  latest_power_SysMon = ((csb << 8) | lsb) * MILLIAMPS_PER_STEP;

                                               
  if(latest_power_SysMon < eeprom_read_word(&E_MILLIAMP_MAX_SYSMON))
                        
    return true;

                      
  return false;
}



                                                                               
  
                                                     

                                          
                                             

                                                                      

                  
  
boolean check_temp_GN(byte gn)
{
                                       
  switch (gn) {
    case 1:
                                       
      latest_temp_GN1 = analogRead(PIN_THERMISTOR_GN1);

                                            
      if((eeprom_read_word(&E_TEMP_MIN_GN1) < latest_temp_GN1)
          && (latest_temp_GN1 < eeprom_read_word(&E_TEMP_MAX_GN1)))
      {
                            
        return true;
      }
      else
                            
        return false;

    case 2:
                                       
      latest_temp_GN2 = analogRead(PIN_THERMISTOR_GN2);

                                            
      if((eeprom_read_word(&E_TEMP_MIN_GN2) < latest_temp_GN2)
          && (latest_temp_GN2 < eeprom_read_word(&E_TEMP_MAX_GN2)))
      {
                            
        return true;
      }
      else
                            
        return false;

    case 3:
                                       
      latest_temp_GN3 = analogRead(PIN_THERMISTOR_GN3);

                                            
      if((eeprom_read_word(&E_TEMP_MIN_GN3) < latest_temp_GN3)
          && (latest_temp_GN3 < eeprom_read_word(&E_TEMP_MAX_GN3)))
      {
                            
        return true;
      }
      else
                            
        return false;

    default:
                                                 
      return false;
  }
}



                                                                               
  
                                                                         
                                                       

                                    
                                       

                  
  
boolean check_temp_NC()
{
                    
  latest_temp_NC = analogRead(PIN_THERMISTOR_NC);

                                        
  if((eeprom_read_word(&E_TEMP_MIN_PROCESSOR_NC) < latest_temp_NC)
    && (latest_temp_NC < eeprom_read_word(&E_TEMP_MAX_PROCESSOR_NC)))
  {
                        
    return true;
  }

                      
  return false;
}



                                                                               
  
                                                                          
                                 

                                    
                                       

                  
  
boolean check_temp_switch()
{
                    
  latest_temp_switch = analogRead(PIN_THERMISTOR_SWITCH);

                                        
  if((eeprom_read_word(&E_TEMP_MIN_SWITCH) < latest_temp_switch)
    && (latest_temp_switch < eeprom_read_word(&E_TEMP_MAX_SWITCH)))
  {
                        
    return true;
  }

                      
  return false;
}



                                                                               
  
                                                                              
                                  

               
  
void get_time_NC()
{
                  
   Serial.println(NC_NOTIFIER_TIME_REQUEST);

                                                        
                                       
   String received_time = "";
   received_time = Serial.readStringUntil(NC_TERMINATOR);

                        
   if(received_time.length() > 0)
   {
                                                   
      unsigned long seconds_since_epoch = received_time.toInt();

                     
      RTC.set(seconds_since_epoch);
   }
}



                                                                               
  
                                                    

                                                             

               
  
void power_cycle(byte device)
{
                         
   digitalWrite(device, LOW);
                    
   delay(POWER_CYCLE_DELAY);
                        
   digitalWrite(device, HIGH);
}



                                                                               
  
                                                 

                                                    

               
  
void send_problem(String problem)
{
                                                             
  Serial.println(NC_NOTIFIER_PROBLEM);

                              
  delay(NC_MESSAGE_DELAY);

                          
  problem = String(RTC.get()) + NC_DELIMITER + problem;

                        
  Serial.println(problem);

                                                                      
                     
  delay(NC_MESSAGE_DELAY);
}



                                                                               
  
                                                                      

                     
                                  
                           
                              
                                                   
                                       
                          
                                             
                             
                                
                              
                                    
                           
                              
                            
                                  
                           
                              
                            
                                  
                           
                              
                            
                                 

               
  
void send_status()
{
  String message = "";

                                                            
  Serial.println(NC_NOTIFIER_STATUS);

                              
  delay(NC_MESSAGE_DELAY);

                         
  message += String(RTC.get()) + NC_DELIMITER;
  message += String(analogRead(PIN_PHOTOCELL)) + NC_DELIMITER;
  message += String(latest_power_SysMon) + NC_DELIMITER;
  message += String(latest_environ_temp_SysMon_NC) + NC_DELIMITER;
  message += String(latest_environ_hum_SysMon_NC) + NC_DELIMITER;
  message += String(latest_power_NC) + NC_DELIMITER;
  message += String(latest_temp_NC) + NC_DELIMITER;
  if(eeprom_read_byte(&E_SWITCH_ENABLED))
    message += String(1) + NC_DELIMITER;
  else
    message += String(0) + NC_DELIMITER;
  message += String(_switch_running) + NC_DELIMITER;
  message += String(latest_power_switch) + NC_DELIMITER;
  message += String(latest_temp_switch) + NC_DELIMITER;
  if(eeprom_read_byte(&E_GN1_ENABLED))
    message += String(1) + NC_DELIMITER;
  else
    message += String(0) + NC_DELIMITER;
  message += String(_GN1_running) + NC_DELIMITER;
  message += String(latest_power_GN1) + NC_DELIMITER;
  message += String(latest_temp_GN1) + NC_DELIMITER;
  if(eeprom_read_byte(&E_GN2_ENABLED))
    message += String(1) + NC_DELIMITER;
  else
    message += String(0) + NC_DELIMITER;
  message += String(_GN2_running) + NC_DELIMITER;
  message += String(latest_power_GN2) + NC_DELIMITER;
  message += String(latest_temp_GN2) + NC_DELIMITER;
  if(eeprom_read_byte(&E_GN3_ENABLED))
    message += String(1) + NC_DELIMITER;
  else
    message += String(0) + NC_DELIMITER;
  message += String(_GN3_running) + NC_DELIMITER;
  message += String(latest_power_GN3) + NC_DELIMITER;
  message += String(latest_temp_GN3);

            
  Serial.println(message);
}



                                                                               
  
                                             

               
  
void send_time()
{
                                                          
  Serial.println(NC_NOTIFIER_TIME_SEND);

                              
  delay(NC_MESSAGE_DELAY);

                                                         
  Serial.println(RTC.get());
}



                                                                               
  
                               

               
  
void sleep_SysMon()
{
                                                            
                    

                
                  

  

                                            
                                              
                             
                                               
                              
  digitalWrite(PIN_RELAY_NC, LOW);
  digitalWrite(PIN_RELAY_SWITCH, LOW);
  digitalWrite(PIN_RELAY_GN1, LOW);
  digitalWrite(PIN_RELAY_GN2, LOW);
  digitalWrite(PIN_RELAY_GN3, LOW);
  while(1);
}



                                                                               
  
                                                                         
                                                              

               
  
 ISR(TIMER1_OVF_vect)
{
                   
  wdt_reset();

                                                    
  _timer1_cycle = true;
}
#line 1 "POST.ino"
                                                                               
const byte RESET_POWER_ON = 0;
const byte RESET_EXTERNAL = 1;
const byte RESET_BROWN_OUT = 2;
const byte RESET_WATCHDOG = 3;
const byte RESET_JTAG = 4;
const byte RESET_USB = 5;

const byte FAIL_GPRF = 1;
const byte FAIL_STACK = 2;
const byte FAIL_SREG = 3;
const byte FAIL_SRAM = 4;
const byte FAIL_FLASH = 5;
const byte FAIL_WATCHDOG = 6;
const byte FAIL_ADC = 7;
const byte FAIL_TIMER1 = 8;
const byte FAIL_INTERRUPT = 9;

const boolean FATAL_GPRF = true;
const boolean FATAL_STACK = true;
const boolean FATAL_SREG = true;
const boolean FATAL_SRAM = true;
const boolean FATAL_FLASH = true;
const boolean FATAL_WATCHDOG = false;
const boolean FATAL_ADC = false;
const boolean FATAL_TIMER1 = false;
const boolean FATAL_INTERRUPT = false;

const int ADC_TEST_THRESHOLD = 512;



                                                                               
boolean _SOS_boot_mode = false;
boolean _watchdog_good = false;
volatile boolean _external_interrupt = false;



                                                                               
  
                                                                         
                                                                     

                                                                      
                                                                             
                                                                              
                                                                          

                                                                      
                                                                           
                

                                                             

                  
  
boolean POST() 
{
                          
  byte reason = find_reset_reason();

                                                                     
  wdt_disable();

  Serial.begin(57600);

  delay(1000);

                                          
	if(!gprf_test())
		test_failure(FAIL_GPRF, FATAL_GPRF);

  Serial.println("GPRF");
  delay(5);

	                        
	if(!stack_pointer_test())
		test_failure(FAIL_STACK, FATAL_STACK);

  Serial.println("stack");
  delay(5);

	                                      
	if(!status_register_test())
		test_failure(FAIL_SREG, FATAL_SREG);

  Serial.println("SREG");
  delay(5);

	                    
	if(!sram_test())
		test_failure(FAIL_SRAM, FATAL_SRAM);

  Serial.println("SRAM");
  delay(5);

	                     
	                   
		                                        

	                        
	if(!watchdog_test(reason))
		test_failure(FAIL_WATCHDOG, FATAL_WATCHDOG);
  else
                                                           
    _watchdog_good = true;

  Serial.println("watchdog");
  delay(5);

                     
  if(!ADC_test())
    test_failure(FAIL_ADC, FATAL_ADC);

  Serial.println("ADC");
  delay(5);

                        
  if(!timer1_test())
    test_failure(FAIL_TIMER1, FATAL_TIMER1);

  Serial.println("Timer");
  delay(5);

                                      
  if(!interrupt_test())
    test_failure(FAIL_INTERRUPT, FATAL_INTERRUPT);

  Serial.println("interrupt");
  delay(5);

                                 
  if(_SOS_boot_mode)
  {
    Serial.println("SOS");
    delay(10);
                             
    return false;
  }

                           
  return true;
}



                                                                               
  
                                                                     
                                          
                                           

                                                                       
                                                                           
                                                                         
                                                                           
                                                           

                 
  
__attribute__((optimize(0))) boolean gprf_test()
{
	boolean result;

	                                                                     
	                                                                           
	                                              
	asm volatile(
		              
		"R31_0x55_TST:                             \n\t"
    "							ldi   R31, 0x55              \n\t"
    "             cpi   R31, 0x55              \n\t"
    "             breq  R31_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R31_0xAA_TST:  													 \n\t"
    "							ldi   R31, 0xAA              \n\t"
    "             cpi   R31, 0xAA              \n\t"
    "             breq  R30_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
                  
    "R30_0x55_TST:                             \n\t"
    "							ldi   R30, 0x55              \n\t"
    "             cpi   R30, 0x55              \n\t"
    "             breq  R30_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R30_0xAA_TST:  													 \n\t"
    "							ldi   R30, 0xAA              \n\t"
    "             cpi   R30, 0xAA              \n\t"
    "             breq  R29_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    
                  
    "R29_0x55_TST:                             \n\t"
    "							mov   R31, R29     ; save R29\n\t"
    "							ldi   R29, 0x55              \n\t"
    "             cpi   R29, 0x55              \n\t"
    "             breq  R29_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R29_0xAA_TST:  													 \n\t"
    "							ldi   R29, 0xAA              \n\t"
    "             cpi   R29, 0xAA              \n\t"
    "             breq  R29_END_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R29_END_TST: 														 \n\t"
    "							mov   R29, R31  ; restore R29\n\t"
                  
    "R28_0x55_TST:                             \n\t"
    "							mov   R31, R28     ; save R28\n\t"
    "							ldi   R28, 0x55              \n\t"
    "             cpi   R28, 0x55              \n\t"
    "             breq  R28_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R28_0xAA_TST:  													 \n\t"
    "							ldi   R28, 0xAA              \n\t"
    "             cpi   R28, 0xAA              \n\t"
    "             breq  R28_END_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R28_END_TST: 														 \n\t"
    "							mov   R28, R31  ; restore R28\n\t"
    
                  
    "R27_0x55_TST:                             \n\t"
    "							ldi   R27, 0x55              \n\t"
    "             cpi   R27, 0x55              \n\t"
    "             breq  R27_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R27_0xAA_TST:  													 \n\t"
    "							ldi   R27, 0xAA              \n\t"
    "             cpi   R27, 0xAA              \n\t"
    "             breq  R26_0x55_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
                  
    "R26_0x55_TST:                             \n\t"
    "							ldi   R26, 0x55              \n\t"
    "             cpi   R26, 0x55              \n\t"
    "             breq  R26_0xAA_TST           \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "R26_0xAA_TST:  													 \n\t"
    "							ldi   R26, 0xAA              \n\t"
    "             cpi   R26, 0xAA              \n\t"
    "             breq  RX_TST                 \n\t"
    "							jmp   Fail_GPRF              \n\t"

               
    "RX_TST:     															 \n\t"   
    "							ldi   R30, 0x00    ; clear ZL\n\t"
    "             ldi   R31, 0x00    ; clear ZH\n\t"
    "RX_0x55_TST:   													 \n\t"
    "							ldi   R25, 0x55              \n\t"
    "             st    Z, R25                 \n\t"
    "             ldi   R25, 0x00              \n\t"
    "             ld    R25, Z                 \n\t"
    "             cpi   R25, 0x55              \n\t"
    "             breq  RX_0xAA_TST            \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "RX_0xAA_TST:   													 \n\t"
    "							ldi   R25, 0xAA              \n\t"
    "             ST    Z, R25                 \n\t"
    "             ldi   R25, 0x00              \n\t"
    "             ld    R25, Z+                \n\t"
    "             cpi   R25, 0xAA              \n\t"
    "             breq  RX_TST_2               \n\t"
    "             jmp   Fail_GPRF              \n\t"
    "RX_TST_2:      													 \n\t"
    "							cpi   r30, 25; test until R25\n\t"
    "             brne  RX_0x55_TST            \n\t"
    "							clr   r1 ; R1 must be cleared\n\t"
    "							jmp   Pass_GPRF 						 \n\t"
  );

	               
  asm volatile(
    "Fail_GPRF:																 \n\t"
  );
  result = false;

                 
  asm volatile(
    "Pass_GPRF:                                \n\t"
	);
	result = true;

                        
	if(result)
                             
    return true;
  else
                             
    return false;
}



                                                                               
  
                                          
                                          
                                           

                                                                       
                                                                            
                                                                          
                                                                           
                                                           

                 
  
__attribute__((optimize(0))) boolean stack_pointer_test()
{
	boolean result;

	                                                                     
	                                                                           
	                                              
	asm volatile(
		"SP_TST:																	 \n\t"
			                        
			"						in    R23, 0x3E              \n\t"
      "           in    R22, 0x3D              \n\t"

                     
      "SPL_0x55_TST:  												 \n\t"
      "						ldi   R24, 0x55              \n\t"
      "           out   0x3D, R24              \n\t"
      "           in    R24, 0x3D              \n\t"
      "           cpi   R24, 0x55              \n\t"
      "           breq  SPL_0xAA_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      "SPL_0xAA_TST:  												 \n\t"
      "						ldi   R24, 0xAA              \n\t"
      "           out   0x3D, R24              \n\t"
      "           in    R24, 0x3D              \n\t"
      "           cpi   R24, 0xAA              \n\t"
      "           breq  SPH_0x55_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
                     
      "SPH_0x55_TST:  												 \n\t"
      "						ldi   R25, 0x07			         \n\t"
      "           andi  R25, 0x55              \n\t"
      "           out   0x3E, R25              \n\t"
      "           in    R24, 0x3E              \n\t"
      "           cp    R24, R25               \n\t"
      "           breq  SPH_0xAA_TST           \n\t"
      "           jmp   Fail_SP                \n\t"
      "SPH_0xAA_TST:  												 \n\t"
      "						ldi   R25, 0x07              \n\t"
      "           andi  R25, 0xAA              \n\t"
      "           out   0x3E, R25              \n\t"
      "           in    R24, 0x3E              \n\t"
      "           cp    R24, R25               \n\t"
      "           breq  RESTORE_SP             \n\t"
      "           jmp   Fail_SP                \n\t"

                              
      "RESTORE_SP:    												 \n\t"
      "						out   0x3E, R23              \n\t"
      "           out   0x3D, R22              \n\t"
      "           jmp   Pass_SP                \n\t"
  );

	               
  asm volatile(
    "Fail_SP:																   \n\t"
  );
  result = false;

                 
  asm volatile(
    "Pass_SP:																   \n\t"
	);
	result = true;

	                      
  if(result)
                             
    return true;
  else
                             
    return false;
}



                                                                               
  
                                                    
                                           
                                           

                                                                       
                                                                            
                                                                          
                                                                           
                                                           

                  
  
__attribute__((optimize(0))) boolean status_register_test() 
{
	byte read_sreg, save_sreg;

	                             
	save_sreg = SREG;

	                      
	SREG = 0x55;

	                     
	read_sreg = SREG;

	                                 
	SREG = save_sreg;

	                                                      
	if(read_sreg != 0x55)
		                         
		return false;
	else
	{
		                             
		save_sreg = SREG;

		                      
		SREG = 0xAA;

		                     
		read_sreg = SREG;

		                                 
		SREG = save_sreg;

		                                                  
		if(read_sreg == 0xAA)
			                         
			return true;
		else
			                         
			return false;
	}
}



                                                                               
  
                                  
                                           
                                           

                                                                       
                                                                            
                                                                          
                                                                           
                                                           

                  
  
__attribute__((optimize(0))) boolean sram_test()
{
  boolean result;
  
                                                                       
                                                                                       
                                                
  asm volatile(
    "LD_INITS:                                 \n\t"
    "             ldi   R31, 0x01              \n\t"
    "             ldi   R30, 0x00              \n\t"
    "             ldi   R28, 0x55              \n\t"
    "             ldi   R29, 0xAA              \n\t"
    "CHECK_DONE:                               \n\t"
                                       
    "             cpi   R31, 0x0A              \n\t"
    "             brne  LOOP                   \n\t"
                                       
    "             cpi   R30, 0xFF              \n\t"
                                                 
    "             breq  Pass_RAM               \n\t"
    "LOOP:                                     \n\t"
                                               
    "             ld    R26, Z                 \n\t"
                                               
    "             st    Z, R28                 \n\t"
                                         
    "             ld    R27, Z                 \n\t"
    "             cpi   R27, 0x55              \n\t" 
                                                    
    "             brne  Fail_RAM               \n\t"
                                               
    "             st    Z, R29                 \n\t"
                                         
    "             ld    R27, Z                 \n\t"
                                                               
    "             st    Z+, R26                \n\t"
    "             cpi   R27, 0xAA              \n\t" 
    "             brne  Fail_RAM               \n\t"
                                                         
    "             jmp   CHECK_DONE             \n\t"
  );

                 
  asm volatile(
    "Fail_RAM:                                 \n\t"
  );
  result = false;

                 
  asm volatile(
    "Pass_RAM:                                 \n\t"
  );
  result = true;

                        
  if(result)
                             
    return true;
  else
                             
    return false;
}



                                                                               
  
                                                                       
                                             
                                          
                                           

                                                                       
                                                                            
                                                                          
                                                                           
                                                           

                  
  
__attribute__((optimize(0))) boolean watchdog_test(byte reason)
{
  Serial.println(reason);
  delay(100);

                                   
                                                   
  if(reason != RESET_WATCHDOG)
  {
    Serial.println("not watchdog reset");
    wdt_enable(WDTO_8S);
    Serial.println("enabled");
    delay(9000);
    Serial.println("watchdog did not reset");
    return false;
  }

                                                   
  if(reason == RESET_WATCHDOG)
  {
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);
  }
  return true;
}



                                                                               
  
                                                
                                           
                                            

                                                                        
                                                                            
                                                                          
                                                                           
                                                           

                  
  
__attribute__((optimize(0))) boolean ADC_test()
{
                                                
  analogReference(INTERNAL);

                                                               
                                          
  delay(50);
  analogRead(INTERNAL);
  analogRead(INTERNAL);
  analogRead(INTERNAL);

                                    
  int value = analogRead(INTERNAL);

                                            
                                                                
  if(value > ADC_TEST_THRESHOLD)
                             
    return true;
  else
                             
    return false;
}



                                                                               
  
                                                                         
                                                                           
                                           
                                            

                                                                        
                                                                            
                                                                          
                                                                           
                                                           

                  
  
__attribute__((optimize(0))) boolean timer1_test()
{
                                                                      
  noInterrupts();

                                                                   
                          
  TCCR1A = 0x55;
                                                
                                  
  if((TCCR1A & 0x55) != 0x55)
                             
    return false;
                           
  TCCR1A = 0xAA;
                                                
                                  
  if((TCCR1A & 0xAA) != 0xAA)
                             
    return false;
                       
  TCCR1A = 0;

  TCCR1B = 0x55;
  if((TCCR1B & 0x55) != 0x55)
    return false;
  TCCR1B = 0xAA;
  if((TCCR1B & 0xAA) != 0x8A)
    return false;
  TCCR1B = 0;

  TCNT1 = 0x5555;
  if((TCNT1 & 0x5555) != 0x5555)
    return false;
  TCNT1 = 0xAAAA;
  if((TCNT1 & 0xAAAA) != 0xAAAA)
    return false;
  TCNT1 = 0;

  OCR1A = 0x5555;
  if((OCR1A & 0x5555) != 0x5555)
    return false;
  OCR1A = 0xAAAA;
  if((OCR1A & 0xAAAA) != 0xAAAA)
    return false;
  OCR1A = 0;

  TIMSK1 = 0x55;
  if((TIMSK1 & 0x55) != 0x05)
    return false;
  TIMSK1 = 0xAA;
  if((TIMSK1 & 0xAA) != 0x2A)
    return false;
  TIMSK1 = 0;

                      
  interrupts();

                                                                  
  if(eeprom_read_byte(&E_TIMER_TEST_INCOMPLETE))
                             
    return false;

                                
                                                                             
                                                                      
                                                                           
                                                                    
  if(_watchdog_good)
  {
                                    
    eeprom_update_byte(&E_TIMER_TEST_INCOMPLETE, 1);

                      
    wdt_enable(WDTO_60MS);

                                            
    TCCR1B = (1 << CS11);

                                   
    while(! (TIFR1 & _BV(TOV1)));

                       
    wdt_disable();

                                                            
    TCCR1B = 0;
                                
    TCNT1 = 0;
                              
    TIFR1 = _BV(TOV1);

                                  
    eeprom_update_byte(&E_TIMER_TEST_INCOMPLETE, 0);
  }

                           
  return true;
}



                                                                               
  
                                                                            
                                           
                                            

                                                                        
                                                                            
                                                                          
                                                                           
                                                           

                  
  
__attribute__((optimize(0))) boolean interrupt_test()
{
                                                                     
  pinMode(INT0, OUTPUT);

                                                                           
                                                        
  EIMSK |= _BV(INT0);

                          
  digitalWrite(INT0, LOW);

                                                     
  delay(1);

                            
  if(_external_interrupt)
                        
    return true;
  else
                        
    return false;
}



                                                                               
  
                                         

               
  
ISR(INT0_vect)
{
                           
  EIMSK = 0;

                                               
  _external_interrupt = true;
}



                                                                               
  
                                                            

               
  
byte find_reset_reason()
{
	byte i;
	byte mask = 0x01;

	                          
	for(i = 0; i < 6; i++)
	{
                              
		if(MCUSR & mask)
			                                         
			break;

		                           
		mask <<= 1;
	}

                
  MCUSR = 0;

	                          
	return i;	
}



                                                                               
  
                                                                            

                                             
                                                 
  
void test_failure(byte reason, boolean fatal)
{
	                              
	eeprom_update_byte(&E_POST_RESULT, reason);

	                                          
	delay(5);

	                         
	if(fatal)
		              
		sleep();
	else
		                             
    _SOS_boot_mode = true;
}



                                                                               
  
                                             
  
void sleep()
{
	                                              
	noInterrupts();

	                                                                 
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);

	               
	sleep_enable();

	              
	sleep_mode();

	                                           
	while(1);
}
#line 1 "boot_SOS.ino"
                                                                               
const byte NO_WATCHDOG = 1;
const byte NO_TIMER = 2;
const byte NO_ADC = 3;
const byte NO_INTERRUPT = 4;



                                                                               
byte SOS_mode;



                                                                               
  
                                                                         
                                                                            
                

               
  
void boot_SOS()
{
	                                          
	              

	                                                              
	                      

	                                                      
	                                                                
	                        

	                                                                  
	                                                               

	                                             
	                                                                  
	                                              
	            

	                                             
	                                                             

	             
	                         
	                                                               
	                       
	                 
	                              
	                                                                         
	                                                                         
	               

	                                         
	                                       
	                                           
	            

	                                     

	                                                                           
	                    

	                                                                     
	                        

	                                                    
	                         
}



                                                                               
  
                                                                        

               
  
void init_SOS()
{
                                              
	                                              
	                          
	                                
	               
	                        
	                             
	               
	                     
	                          
	              
	                           
	                                
	              
	                                                    
	               
	                 
	    

	                                         
	                                                             
	                               
	                                            
	                        
	                                            
	       
	                                                                             
	                                          
	               

	               
	                           
	    
	                     
	                                
	                                        
	                          

	                                                                           
	                        
	    

	                             
	                                                                              
	                

	                          
	                                                                               
                                                    
}



                                                                               
  
                                                                      
                                                                            
                     

               
  
void report_failure_POST()
{

}
#line 1 "boot_gn.ino"
                                                                               
  
                                                                    
                                                            

                                                        

               
  
void boot_GN(byte gn)
{
  byte pin_relay, pin_heartbeat;
  String problem_temp, problem_power, problem_heartbeat;
  byte *enabled, *present;
  unsigned int *boot_time;

                                      
  switch (gn) {
    case 1:
                                           
      _GN1_running = false;

                                             
      pin_relay = PIN_RELAY_GN1;
      pin_heartbeat = PIN_HEARTBEAT_GN1;
      problem_temp = PROBLEM_GN1_TEMP;
      problem_power = PROBLEM_GN1_POWER;
      problem_heartbeat = PROBLEM_GN1_HEARTBEAT;
      enabled = &E_GN1_ENABLED;
      present = &E_PRESENT_GN1;
      boot_time = &E_BOOT_TIME_GN1;

      break;
    case 2:
                                           
      _GN2_running = false;

                                             
      pin_relay = PIN_RELAY_GN2;
      pin_heartbeat = PIN_HEARTBEAT_GN2;
      problem_temp = PROBLEM_GN2_TEMP;
      problem_power = PROBLEM_GN2_POWER;
      problem_heartbeat = PROBLEM_GN2_HEARTBEAT;
      enabled = &E_GN2_ENABLED;
      present = &E_PRESENT_GN2;
      boot_time = &E_BOOT_TIME_GN2;
      
      break;
    case 3:
                                           
      _GN3_running = false;

                                             
      pin_relay = PIN_RELAY_GN3;
      pin_heartbeat = PIN_HEARTBEAT_GN3;
      problem_temp = PROBLEM_GN3_TEMP;
      problem_power = PROBLEM_GN3_POWER;
      problem_heartbeat = PROBLEM_GN3_HEARTBEAT;
      enabled = &E_GN3_ENABLED;
      present = &E_PRESENT_GN3;
      boot_time = &E_BOOT_TIME_GN3;
      
      break;
                         
    default:
      return;
  }

                                
  digitalWrite(pin_relay, LOW);

                                 
  delay(POWER_CYCLE_DELAY);

                                                      
  if(eeprom_read_byte(enabled) && eeprom_read_byte(present))
  {
                                                                  
    if(!check_temp_GN(gn))
    {
                                                 

                                                
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

                                                                    
      if(!check_temp_GN(gn))
      {
                                            
        send_problem(problem_temp);

                            
        return;
      }
    }

                             
    digitalWrite(pin_relay, HIGH);

                                       
    delay((long)eeprom_read_word(boot_time) * 1000L);

                                                                 
    if(!check_power_GN(gn))
    {
                                                 

                                   
      power_cycle(pin_relay);

                                         
      delay((long)eeprom_read_word(boot_time) * 1000L);

                                                                   
      if(!check_power_GN(gn))
      {
                                  
        digitalWrite(pin_relay, LOW);

                                            
        send_problem(problem_power);

                          
        eeprom_update_byte(enabled, 0);

                            
        return;
      }
    }

                                                     
    if(!check_heartbeat_odroid(pin_heartbeat))
    {
                                                                  
      byte boot_attempts = 1;
      boolean _heartbeat_detected = false;

                                                                    
      while (boot_attempts < eeprom_read_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
      {
                                     
        if(!check_heartbeat_odroid(pin_heartbeat))
        {
                                       
          power_cycle(pin_relay);

                                             
          delay((long)eeprom_read_word(boot_time) * 1000L);
        }
        else
                                                   
          _heartbeat_detected = true;

                                                   
        boot_attempts++;
      }

                                     
      if(!_heartbeat_detected)
      {
                                  
        digitalWrite(pin_relay, LOW);

                                            
        send_problem(problem_heartbeat);

                            
        return;
      }
    }

                                        
    switch (gn) {
      case 1:
                                         
        _GN1_running = true;

        break;
      case 2:
                                         
        _GN2_running = true;
        
        break;
      case 3:
                                         
        _GN3_running = true;
        
        break;
                           
      default:
        return;
    }
  }
}
#line 1 "boot_primary.ino"
                                                                               
  
                                                                       
                                                                              
                                            

                                                     
                                       

                  
  
boolean boot_primary()
{
	                                       
	init_primary();

                                  
   if(eeprom_read_byte(&E_FIRST_BOOT) != 0)
                                  
      set_default_eeprom();

	                              
   if(!boot_SysMon())
                                           
      return false;

                                          
   if(!boot_NC())
                                           
      return false;

                                                                           
   delay(NC_TIME_ACQUIRE_DELAY);

	                                    
	get_time_NC();

                                                       
   get_params_core();

	                                                     
	get_params_GNs();

                          
   boot_switch();

	                                                    
	return true;
}



                                                                               
  
                                                                              

                                                     
                                                          

                   
  
boolean boot_NC()
{
                                
   _NC_running = false;

                                                                        
   Serial.println(NC_NOTIFIER_SHUTDOWN);
                                        
   delay((long)NC_SHUTDOWN_DELAY);

                                     
   digitalWrite(PIN_RELAY_NC, LOW);

                                  
   delay(POWER_CYCLE_DELAY);

                                         
   if(!eeprom_read_byte(&E_NC_ENABLED))
                          
      return false;

                                                        
   if(!check_environ_NC())
   {
                                                      

                                                
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

                                                           
      if(!check_environ_NC())
                             
         return false;
   }

                                                                  
   if(!check_temp_NC())
   {
                                                      

                                                
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

                                                           
      if(!check_temp_NC())
                             
         return false;
   }

                                     
   digitalWrite(PIN_RELAY_NC, HIGH);

                                                                

                                                               
   Serial.setTimeout((long)eeprom_read_word(&E_CONFIG_TIME_NC) * 1000L);
                                                                    
   String config_WagMan = Serial.readStringUntil(NC_TERMINATOR);
                                                        
   Serial.setTimeout(1000L);
                                                     
   if(config_WagMan != NC_NOTIFIER_CONFIG_DONE)
                          
      return false;

                                                                     
   if(!check_power_NC())
   {
                                                      

                                        
      power_cycle(PIN_RELAY_NC);

                                              
      delay((long)eeprom_read_word(&E_BOOT_TIME_NC) * 1000L);

                                                                        
      if(!check_power_NC())
      {
                                        
         digitalWrite(PIN_RELAY_NC, LOW);

                           
         eeprom_update_byte(&E_NC_ENABLED, 0);

                             
         return false;
      }
   }

                                                         
   if(!check_heartbeat_odroid(PIN_HEARTBEAT_NC))
   {
                                                                  
      byte boot_attempts = 1;
      boolean _heartbeat_detected = false;
      
                                                                    
      while(boot_attempts < eeprom_read_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS))
      {
                                      
         if(!check_heartbeat_odroid(PIN_HEARTBEAT_NC))
         {
                                              
            power_cycle(PIN_RELAY_NC);

                                                    
            delay((long)eeprom_read_word(&E_BOOT_TIME_NC) * 1000L);
         }
         else
                                                     
            _heartbeat_detected = true;

                                                    
         boot_attempts++;
      }

                                     
      if(!_heartbeat_detected)
      {
                                        
         digitalWrite(PIN_RELAY_NC, LOW);

                             
         return false;
      }
   }

                            
   _NC_running = true;

                       
   return true;
}



                                                                               
  
                                                                  
                                                             

                
  
void boot_switch()
{
                                    
   _switch_running = false;

                                 
   digitalWrite(PIN_RELAY_SWITCH, LOW);

                                  
   delay(POWER_CYCLE_DELAY);

                                                     
   if(!(eeprom_read_byte(&E_SWITCH_ENABLED)
      && eeprom_read_byte(&E_PRESENT_SWITCH)))
   {
                          
      return;
   }

                                                                      
   if(!check_temp_switch())
   {
                                             

                                                
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

                                                                         
      if(!check_temp_switch())
      {
                                             
         send_problem(PROBLEM_SWITCH_TEMP);

                             
         return;
      }
   }

                                     
   digitalWrite(PIN_RELAY_SWITCH, HIGH);

                                           
   delay((long)eeprom_read_byte(&E_BOOT_TIME_SWITCH) * 1000L);

                                                                     
   if(!check_power_switch())
   {
                                                      

                               
      power_cycle(PIN_RELAY_SWITCH);

                                     
      delay((long)eeprom_read_byte(&E_BOOT_TIME_SWITCH) * 1000L);

                                                                        
      if(!check_power_switch())
      {
                               
         digitalWrite(PIN_RELAY_SWITCH, LOW);

                                             
         send_problem(PROBLEM_SWITCH_POWER);

                               
         eeprom_update_byte(&E_SWITCH_ENABLED, 0);

                             
         return;
      }
   }

                                
   _switch_running = true;
}



                                                                               
  
                                                 

                                    
                                                         

                   
  
boolean boot_SysMon()
{
                                       
   if(!check_power_SysMon())
   {
                                         

                                                
      delay((long)BOOT_BAD_POWER_WAIT_TIME * 1000L);

                                          
      if(!check_power_SysMon())
                             
         return false;
   }

                                                     
   if(!check_environ_SysMon())
   {
                                         

                                                
      delay((long)BOOT_BAD_ENVIRON_WAIT_TIME * 1000L);

                                                        
      if(!check_environ_SysMon())
                             
         return false;
   }

                       
   return true;
}



                                                                               
  
                                                                            
                                                                           
                                                                             
           

               
  
void get_params_core()
{
                  
   Serial.println(NC_NOTIFIER_PARAMS_CORE);

                                                        
                                       
   String received_params = "";
   received_params = Serial.readStringUntil(NC_TERMINATOR);

                               
   if(received_params.length() > 0)
   {
                                                           

                        
                             
                                                                   
                                        
                                              
                                            
                                                                 
                                     
                                  
                                                      
                                  
                                            
                                   
                                             
                                              
                                                        
                                     
                                       
                                        
                               
                                                                      
                                                                      
                                                                       
                                                                       
                                                                     
                                                                     
                                               
                                               
                                                       
                                                       
                                           
                                           
                                               
                                                
                                       
        

                                                     
      String USART_baud = "";
      String USART_RX_buffer_size = "";
      String status_report_period = "";
      String max_num_SOS_boot_attempts = "";
      String max_num_subsystem_boot_attempts = "";
      String max_num_primary_boot_attempts = "";
      String device_reboot_period = "";
      String present_switch = "";
      String NC_boot_time = "";
      String NC_config_time = "";
      String switch_boot_time = "";
      String heartbeat_timeout_NC = "";
      String heartbeat_timeout_switch = "";
      String environ_timeout_SysMon = "";
      String environ_timeout_NC = "";
      String temp_processor_timeout_NC = "";
      String temp_timeout_switch = "";
      String power_timeout_SysMon = "";
      String power_timeout_NC = "";
      String power_timeout_switch = "";
      String min_temp_SysMon = "";
      String max_temp_SysMon = "";
      String min_temp_NC = "";
      String max_temp_NC = "";
      String min_temp_processor_NC = "";
      String max_temp_processor_NC = "";
      String min_temp_switch = "";
      String max_temp_switch = "";
      String min_humidity_SysMon = "";
      String max_humidity_SysMon = "";
      String min_humidity_NC = "";
      String max_humidity_NC = "";
      String max_amp_SysMon = "";
      String max_amp_NC = "";
      String max_amp_switch = "";

                                                     
      int i = 0;

                                               
      while(received_params[i] != NC_DELIMITER)
         USART_baud += received_params[i++];
                       
      i++;

      while(received_params[i] != NC_DELIMITER)
         USART_RX_buffer_size += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         status_report_period += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_num_SOS_boot_attempts += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_num_subsystem_boot_attempts += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_num_primary_boot_attempts += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         device_reboot_period += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         present_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         NC_boot_time += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         NC_config_time += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         switch_boot_time += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         environ_timeout_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         environ_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         temp_processor_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         temp_timeout_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         power_timeout_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         power_timeout_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         power_timeout_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_processor_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_processor_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_switch += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_humidity_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_humidity_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_humidity_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_humidity_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_SysMon += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_NC += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_switch += received_params[i++];

                                       
      eeprom_update_dword(&E_USART_BAUD, USART_baud.toInt());
      eeprom_update_word(&E_USART_RX_BUFFER_SIZE, (uint16_t)USART_RX_buffer_size.toInt());
      eeprom_update_byte(&E_STATUS_REPORT_PERIOD, (uint8_t)status_report_period.toInt());
      eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, (uint8_t)max_num_SOS_boot_attempts.toInt());
      eeprom_update_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS, (uint8_t)max_num_subsystem_boot_attempts.toInt());
      eeprom_update_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS, (uint8_t)max_num_primary_boot_attempts.toInt());
      eeprom_update_word(&E_DEVICE_REBOOT_PERIOD, (uint16_t)device_reboot_period.toInt());
      eeprom_update_byte(&E_PRESENT_SWITCH, (uint8_t)present_switch.toInt());
      eeprom_update_word(&E_BOOT_TIME_NC, (uint16_t)NC_boot_time.toInt());
      eeprom_update_word(&E_CONFIG_TIME_NC, (uint16_t)NC_config_time.toInt());
      eeprom_update_byte(&E_BOOT_TIME_SWITCH, (uint8_t)switch_boot_time.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, (uint8_t)heartbeat_timeout_NC.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, (uint8_t)heartbeat_timeout_switch.toInt());
      eeprom_update_byte(&E_ENVIRON_TIMEOUT_SYSMON, (uint8_t)environ_timeout_SysMon.toInt());
      eeprom_update_byte(&E_ENVIRON_TIMEOUT_NC, (uint8_t)environ_timeout_NC.toInt());
      eeprom_update_byte(&E_TEMP_PROCESSOR_TIMEOUT_NC, (uint8_t)temp_processor_timeout_NC.toInt());
      eeprom_update_byte(&E_TEMP_TIMEOUT_SWITCH, (uint8_t)temp_timeout_switch.toInt());
      eeprom_update_byte(&E_POWER_TIMEOUT_SYSMON, (uint8_t)power_timeout_SysMon.toInt());
      eeprom_update_byte(&E_POWER_TIMEOUT_NC, (uint8_t)power_timeout_NC.toInt());
      eeprom_update_byte(&E_POWER_TIMEOUT_SWITCH, (uint8_t)power_timeout_switch.toInt());
      eeprom_update_word(&E_TEMP_MIN_SYSMON, (uint16_t)min_temp_SysMon.toInt());
      eeprom_update_word(&E_TEMP_MAX_SYSMON, (uint16_t)max_temp_SysMon.toInt());
      eeprom_update_word(&E_TEMP_MIN_NC, (uint16_t)min_temp_NC.toInt());
      eeprom_update_word(&E_TEMP_MAX_NC, (uint16_t)max_temp_NC.toInt());
      eeprom_update_word(&E_TEMP_MIN_PROCESSOR_NC, (uint16_t)min_temp_processor_NC.toInt());
      eeprom_update_word(&E_TEMP_MAX_PROCESSOR_NC, (uint16_t)max_temp_processor_NC.toInt());
      eeprom_update_word(&E_TEMP_MIN_SWITCH, (uint16_t)min_temp_switch.toInt());
      eeprom_update_word(&E_TEMP_MAX_SWITCH, (uint16_t)max_temp_switch.toInt());
      eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, (uint8_t)min_humidity_SysMon.toInt());
      eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, (uint8_t)max_humidity_SysMon.toInt());
      eeprom_update_byte(&E_HUMIDITY_MIN_NC, (uint8_t)min_humidity_NC.toInt());
      eeprom_update_byte(&E_HUMIDITY_MAX_NC, (uint8_t)max_humidity_NC.toInt());
      eeprom_update_word(&E_MILLIAMP_MAX_SYSMON, (uint16_t)max_amp_SysMon.toInt());
      eeprom_update_word(&E_MILLIAMP_MAX_NC, (uint16_t)max_amp_NC.toInt());
      eeprom_update_word(&E_MILLIAMP_MAX_SWITCH, (uint16_t)max_amp_switch.toInt());
   }
}



                                                                               
  
                                                                       

               
  
void get_params_GNs()
{
                  
   Serial.println(NC_NOTIFIER_PARAMS_GN);

                                                        
                                       
   String received_params = "";
   received_params = Serial.readStringUntil(NC_TERMINATOR);

                               
   if(received_params.length() > 0)
   {
                                                           

                                           
                                           
                                           
                                           
                                           
                                           
                                         
                                         
                                         
                                           
                                           
                                           
                                     
                                     
                                     
                                                     
                                                     
                                                     
                                                     
                                                     
                                                     
                                             
                                             
                                             
        

                                                     
      String present_GN1 = "";
      String present_GN2 = "";
      String present_GN3 = "";
      String boot_time_GN1 = "";
      String boot_time_GN2 = "";
      String boot_time_GN3 = "";
      String heartbeat_timeout_GN1 = "";
      String heartbeat_timeout_GN2 = "";
      String heartbeat_timeout_GN3 = "";
      String temp_timeout_GN1 = "";
      String temp_timeout_GN2 = "";
      String temp_timeout_GN3 = "";
      String power_timeout_GN1 = "";
      String power_timeout_GN2 = "";
      String power_timeout_GN3 = "";
      String min_temp_GN1 = "";
      String max_temp_GN1 = "";
      String min_temp_GN2 = "";
      String max_temp_GN2 = "";
      String min_temp_GN3 = "";
      String max_temp_GN3 = "";
      String max_amp_GN1 = "";
      String max_amp_GN2 = "";
      String max_amp_GN3 = "";

                                                     
      int i = 0;

                                               
      while(received_params[i] != NC_DELIMITER)
         present_GN1 += received_params[i++];
                       
      i++;

      while(received_params[i] != NC_DELIMITER)
         present_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         present_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         boot_time_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         boot_time_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         boot_time_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         heartbeat_timeout_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         temp_timeout_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         temp_timeout_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         temp_timeout_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         power_timeout_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         power_timeout_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         power_timeout_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         min_temp_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_temp_GN3 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_GN1 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_GN2 += received_params[i++];
      i++;

      while(received_params[i] != NC_DELIMITER)
         max_amp_GN3 += received_params[i++];

                                       
      eeprom_update_byte(&E_PRESENT_GN1, (uint8_t)present_GN1.toInt());
      eeprom_update_byte(&E_PRESENT_GN2, (uint8_t)present_GN2.toInt());
      eeprom_update_byte(&E_PRESENT_GN3, (uint8_t)present_GN3.toInt());
      eeprom_update_word(&E_BOOT_TIME_GN1, (uint16_t)boot_time_GN1.toInt());
      eeprom_update_word(&E_BOOT_TIME_GN2, (uint16_t)boot_time_GN2.toInt());
      eeprom_update_word(&E_BOOT_TIME_GN3, (uint16_t)boot_time_GN3.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, (uint8_t)heartbeat_timeout_GN1.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, (uint8_t)heartbeat_timeout_GN2.toInt());
      eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, (uint8_t)heartbeat_timeout_GN3.toInt());
      eeprom_update_byte(&E_TEMP_TIMEOUT_GN1, (uint8_t)temp_timeout_GN1.toInt());
      eeprom_update_byte(&E_TEMP_TIMEOUT_GN2, (uint8_t)temp_timeout_GN2.toInt());
      eeprom_update_byte(&E_TEMP_TIMEOUT_GN3, (uint8_t)temp_timeout_GN3.toInt());
      eeprom_update_byte(&E_POWER_TIMEOUT_GN1, (uint8_t)power_timeout_GN1.toInt());
      eeprom_update_byte(&E_POWER_TIMEOUT_GN2, (uint8_t)power_timeout_GN2.toInt());
      eeprom_update_byte(&E_POWER_TIMEOUT_GN3, (uint8_t)power_timeout_GN3.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN1, (uint16_t)min_temp_GN1.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN1, (uint16_t)max_temp_GN1.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN2, (uint16_t)min_temp_GN2.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN2, (uint16_t)max_temp_GN2.toInt());
      eeprom_update_word(&E_TEMP_MIN_GN3, (uint16_t)min_temp_GN3.toInt());
      eeprom_update_word(&E_TEMP_MAX_GN3, (uint16_t)max_temp_GN3.toInt());
      eeprom_update_word(&E_MILLIAMP_MAX_GN1, (uint16_t)max_amp_GN1.toInt());
      eeprom_update_word(&E_MILLIAMP_MAX_GN2, (uint16_t)max_amp_GN2.toInt());
      eeprom_update_word(&E_MILLIAMP_MAX_GN3, (uint16_t)max_amp_GN3.toInt());
   }
}



                                                                               
  
                                                                        

               
  
void init_primary()
{
                       
   interrupts();

                                                            
                                     
   set_sleep_mode(SLEEP_MODE_PWR_DOWN);

                                          
   wdt_enable(WDTO_2S);

                                                    
   TCCR1A = 0;
   TCCR1B = 0;
   TCCR1C = 0;
   TCNT1 = 0;
   OCR1A = 0;
   OCR1B = 0;
   OCR1C = 0;
   ICR1 = 0;
   TIMSK1 = 0;

                                      
   TIMSK1 = _BV(TOIE1);

                                                                          
   TCCR1B = _BV(CS12);

                            
   Wire.begin();

                         
   Serial.begin(eeprom_read_dword(&E_USART_BAUD));

                                                                 
   eeprom_update_byte(&E_POST_RESULT, 0);
                                                                       
                                       
   eeprom_update_byte(&E_NUM_SOS_BOOT_ATTEMPTS, 0);
                                                                           
                               
                                                         
                                                                            
                                                           
   eeprom_update_byte(&E_TIMER_TEST_INCOMPLETE, 0);

                                      
   analogReference(DEFAULT);
                                                       
   analogRead(PIN_PHOTOCELL);
   analogRead(PIN_PHOTOCELL);
   analogRead(PIN_PHOTOCELL);
   analogRead(PIN_THERMISTOR_NC);
   analogRead(PIN_THERMISTOR_NC);
   analogRead(PIN_THERMISTOR_NC);
   analogRead(PIN_THERMISTOR_SWITCH);
   analogRead(PIN_THERMISTOR_SWITCH);
   analogRead(PIN_THERMISTOR_SWITCH);
   analogRead(PIN_THERMISTOR_GN1);
   analogRead(PIN_THERMISTOR_GN1);
   analogRead(PIN_THERMISTOR_GN1);
   analogRead(PIN_THERMISTOR_GN2);
   analogRead(PIN_THERMISTOR_GN2);
   analogRead(PIN_THERMISTOR_GN2);
   analogRead(PIN_THERMISTOR_GN3);
   analogRead(PIN_THERMISTOR_GN3);
   analogRead(PIN_THERMISTOR_GN3);

                  
   SysMon_HTU21D.begin();

                                                        
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_SYSMON);
                                                  
   Wire.write(0x04);
                                                                    
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
                                         
   Wire.endTransmission(1);

                                                    
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_NC);
                                                  
   Wire.write(0x04);
                                                                    
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
                                         
   Wire.endTransmission(1);

                                                        
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_SWITCH);
                                                  
   Wire.write(0x04);
                                                                    
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
                                         
   Wire.endTransmission(1);

                                                     
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN1);
                                                  
   Wire.write(0x04);
                                                                    
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
                                         
   Wire.endTransmission(1);

                                                     
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN2);
                                                  
   Wire.write(0x04);
                                                                    
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
                                         
   Wire.endTransmission(1);

                                                     
   Wire.beginTransmission(ADDR_CURRENT_SENSOR_GN3);
                                                  
   Wire.write(0x04);
                                                                    
   Wire.write(0x00);
   Wire.write(0x00);
   Wire.write(0x02);
                                         
   Wire.endTransmission(1);

                                                                     
   delay(POWER_CYCLE_DELAY);

                                   
   pinMode(PIN_RELAY_NC, OUTPUT);
   pinMode(PIN_RELAY_SWITCH, OUTPUT);
   pinMode(PIN_RELAY_GN1, OUTPUT);
   pinMode(PIN_RELAY_GN2, OUTPUT);
   pinMode(PIN_RELAY_GN3, OUTPUT);

                                                         
   pinMode(PIN_HEARTBEAT_NC, INPUT);
   pinMode(PIN_HEARTBEAT_SWITCH, INPUT);
   pinMode(PIN_HEARTBEAT_GN1, INPUT);
   pinMode(PIN_HEARTBEAT_GN2, INPUT);
   pinMode(PIN_HEARTBEAT_GN3, INPUT);
}



                                                                               
  
                                                                             
                                                                           
                      

                                                                             
                                                                            
                                                    

                
  
void set_default_eeprom()
{
                                                               
   eeprom_update_dword(&E_USART_BAUD, 57600);
   eeprom_update_word(&E_USART_RX_BUFFER_SIZE, 200);
   eeprom_update_byte(&E_STATUS_REPORT_PERIOD, 30);
   eeprom_update_byte(&E_MAX_NUM_SOS_BOOT_ATTEMPTS, 5);
   eeprom_update_byte(&E_MAX_NUM_SUBSYSTEM_BOOT_ATTEMPTS, 5);
   eeprom_update_byte(&E_MAX_NUM_PRIMARY_BOOT_ATTEMPTS, 5);
   eeprom_update_word(&E_DEVICE_REBOOT_PERIOD, 60);
   eeprom_update_byte(&E_PRESENT_SWITCH, 0);
   eeprom_update_word(&E_BOOT_TIME_NC, 40);
   eeprom_update_word(&E_CONFIG_TIME_NC, 1800);
   eeprom_update_byte(&E_BOOT_TIME_SWITCH, 15);
   eeprom_update_word(&E_BOOT_TIME_GN1, 10);
   eeprom_update_word(&E_BOOT_TIME_GN2, 10);
   eeprom_update_word(&E_BOOT_TIME_GN3, 10);
   eeprom_update_byte(&E_PRESENT_GN1, 0);
   eeprom_update_byte(&E_PRESENT_GN2, 0);
   eeprom_update_byte(&E_PRESENT_GN3, 0);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_HEARTBEAT_TIMEOUT_GN3, 5);
   eeprom_update_byte(&E_ENVIRON_TIMEOUT_SYSMON, 5);
   eeprom_update_byte(&E_ENVIRON_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_TEMP_PROCESSOR_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_TEMP_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_TEMP_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_TEMP_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_TEMP_TIMEOUT_GN3, 5);
   eeprom_update_byte(&E_POWER_TIMEOUT_SYSMON, 5);
   eeprom_update_byte(&E_POWER_TIMEOUT_NC, 5);
   eeprom_update_byte(&E_POWER_TIMEOUT_SWITCH, 5);
   eeprom_update_byte(&E_POWER_TIMEOUT_GN1, 5);
   eeprom_update_byte(&E_POWER_TIMEOUT_GN2, 5);
   eeprom_update_byte(&E_POWER_TIMEOUT_GN3, 5);
   eeprom_update_word(&E_TEMP_MIN_SYSMON, 0);
   eeprom_update_word(&E_TEMP_MAX_SYSMON, 100);
   eeprom_update_word(&E_TEMP_MIN_NC, 0);
   eeprom_update_word(&E_TEMP_MAX_NC, 100);
                                                                          
   eeprom_update_word(&E_TEMP_MIN_PROCESSOR_NC, 115);
   eeprom_update_word(&E_TEMP_MAX_PROCESSOR_NC, 969);
   eeprom_update_word(&E_TEMP_MIN_SWITCH, 417);
   eeprom_update_word(&E_TEMP_MAX_SWITCH, 969);
   eeprom_update_word(&E_TEMP_MIN_GN1, 417);
   eeprom_update_word(&E_TEMP_MAX_GN1, 969);
   eeprom_update_word(&E_TEMP_MIN_GN2, 417);
   eeprom_update_word(&E_TEMP_MAX_GN2, 969);
   eeprom_update_word(&E_TEMP_MIN_GN3, 417);
   eeprom_update_word(&E_TEMP_MAX_GN3, 969);
   eeprom_update_byte(&E_HUMIDITY_MIN_SYSMON, 0);
   eeprom_update_byte(&E_HUMIDITY_MAX_SYSMON, 100);
   eeprom_update_byte(&E_HUMIDITY_MIN_NC, 0);
   eeprom_update_byte(&E_HUMIDITY_MAX_NC, 100);
   eeprom_update_word(&E_MILLIAMP_MAX_SYSMON, 5000);
   eeprom_update_word(&E_MILLIAMP_MAX_NC, 2500);
   eeprom_update_word(&E_MILLIAMP_MAX_SWITCH, 1500);
   eeprom_update_word(&E_MILLIAMP_MAX_GN1, 1500);
   eeprom_update_word(&E_MILLIAMP_MAX_GN2, 1500);
   eeprom_update_word(&E_MILLIAMP_MAX_GN3, 1500);

                                                           
   eeprom_update_byte(&E_FIRST_BOOT, 0);

                                                           
   eeprom_update_byte(&E_NUM_PRIMARY_BOOT_ATTEMPTS, 0);
}

