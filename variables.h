#ifndef VARIABLES_H
#define VARIABLES_H

#define RTC_PRESCALER          4095
#define APP_BLE_CONN_CFG_TAG   1 /** NORDIC VARS */
#define APP_BLE_OBSERVER_PRIO  3
#define UART_TX_BUF_SIZE       256
#define UART_RX_BUF_SIZE       256
#define ECHOBACK_BLE_UART_DATA 1

// Constantes tiempo por defecto
#define DEFAULT_DEVICE_ON_TIME_MS             10000
#define DEFAULT_DEVICE_SLEEP_TIME_MS          (600000 + 3000) // 3 segundos de offset por delay de calculos
#define DEFAULT_DEVICE_EXTENDED_ON_TIME_MS    40000
#define DEFAULT_DEVICE_EXTENDED_SLEEP_TIME_MS 10000

// FDS MACS
#define MAC_FILE_ID              0x0001
#define MAC_EMISOR_RECORD_KEY    0x0002
#define MAC_REPETIDOR_RECORD_KEY 0x0003

// FDS TIEMPOS
#define TIME_FILE_ID                   0x0004
#define TIME_ON_RECORD_KEY             0x0005
#define TIME_SLEEP_RECORD_KEY          0x0006
#define TIME_EXTENDED_ON_RECORD_KEY    0x0007
#define TIME_EXTENDED_SLEEP_RECORD_KEY 0x0008

// FDS FECHA Y HORA
#define DATE_AND_TIME_FILE_ID    0x0009
#define DATE_AND_TIME_RECORD_KEY 0x000A

// FDS CONFIGURACION
#define CONFIG_FILE_ID    0x000B
#define CONFIG_RECORD_KEY 0x000C

// FDS HISTORIALES
#define HISTORY_FILE_ID            0x000D
#define HISTORY_COUNTER_RECORD_KEY 0x000E
#define HISTORY_RECORD_KEY         0x1000
#define HISTORY_BUFFER_SIZE        500
#define HISTORY_RECORD_KEY_START   HISTORY_RECORD_KEY

// HELPERS
#define MSB_16(a) (((a) & 0xFF00) >> 8)
#define LSB_16(a) ((a) & 0x00FF)

// LOGS
#define LOG_EXEC "\n[\033[1;36m EXEC \033[0m]"
#define LOG_OK   "\n[\033[1;32m  OK  \033[0m]"
#define LOG_FAIL "\n[\033[1;31m FAIL \033[0m]"
#define LOG_WARN "\n[\033[1;35m WARN \033[0m]"
#define LOG_INFO "\n[\033[1;33m INFO \033[0m]"

extern bool m_device_active;
extern bool m_connected_this_cycle;
extern bool m_extended_mode_on;

#endif // VARIABLES_H
