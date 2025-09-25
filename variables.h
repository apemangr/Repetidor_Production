#ifndef VARIABLES_H
#define VARIABLES_H

#define RTC_PRESCALER                         4095
#define MAGIC_PASSWORD                        0xABCD /** MAGIC */
#define APP_BLE_CONN_CFG_TAG                  1      /** NORDIC VARS */
#define APP_BLE_OBSERVER_PRIO                 3
#define UART_TX_BUF_SIZE                      256
#define UART_RX_BUF_SIZE                      256
#define ECHOBACK_BLE_UART_DATA                1

#define DEFAULT_DEVICE_ON_TIME_MS             10000
#define DEFAULT_DEVICE_SLEEP_TIME_MS          (1000 + 5000) // Agregar siempre los 5 segundos de procesamiento del emisor
#define DEFAULT_DEVICE_EXTENDED_ON_TIME_MS    20000
#define DEFAULT_DEVICE_EXTENDED_SLEEP_TIME_MS 10000

#define MAC_FILE_ID                           0x0001 /** STORAGE	 */
#define MAC_RECORD_KEY                        0x0002
#define TIME_FILE_ID                          0x0003
#define TIME_ON_RECORD_KEY                    0x0004
#define TIME_SLEEP_RECORD_KEY                 0x0005
#define TIME_EXTENDED_ON_RECORD_KEY           0x000A
#define TIME_EXTENDED_SLEEP_RECORD_KEY        0x000B
#define DATE_AND_TIME_FILE_ID                 0x0006
#define DATE_AND_TIME_RECORD_KEY              0x0007
#define HISTORY_FILE_ID                       0x0008
#define HISTORY_COUNTER_RECORD_KEY            0x0009
#define HISTORY_RECORD_KEY                    0x1000
#define HISTORY_BUFFER_SIZE                   500
#define HISTORY_RECORD_KEY_START              HISTORY_RECORD_KEY

#define MSB_16(a)                             (((a) & 0xFF00) >> 8)
#define LSB_16(a)                             ((a) & 0x00FF)

extern bool m_device_active;
extern bool m_connected_this_cycle;
extern bool m_extended_mode_on;

#endif // VARIABLES_H
