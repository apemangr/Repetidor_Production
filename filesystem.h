#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "app_error.h"
#include "calendar.h"
#include "fds.h"
#include "nrf_delay.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "variables.h"

// Estructura de guardado de historiales
typedef struct
{
    uint16_t magic;
    uint16_t year;
    uint8_t  month;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  minute;
    uint8_t  second;
    uint32_t contador;
    uint16_t V1;
    uint16_t V2;
    uint16_t V3;
    uint16_t V4;
    uint16_t V5;
    uint16_t V6;
    uint16_t V7;
    uint16_t V8;
    uint8_t  temp;
    uint8_t  battery;
} store_history;

typedef struct
{
    uint16_t V1;       // Voltaje 1
    uint16_t V2;       // Voltaje 2
    uint32_t contador; // Contador de advertisings
} adc_values_t;

typedef struct
{
    uint8_t mac_emisor[6];
    uint8_t mac_repetidor[6];
    uint32_t tiempo_encendido;
    uint32_t tiempo_dormido;
    uint32_t tiempo_extendido;
    uint8_t version[3];
    datetime_t fecha_configuracion;  // Fecha y hora de configuracion
} config_repeater_t;

extern adc_values_t adc_values;
extern config_repeater_t config_repeater;

typedef enum
{
    TIEMPO_ENCENDIDO, // Tiempo de encendido
    TIEMPO_SLEEP,      // Tiempo de apagado
    TIEMPO_EXTENDED_SLEEP,
    TIEMPO_EXTENDED_ENCENDIDO
} valor_type_t;

typedef enum
{
    MAC_EMISOR,     // MAC del dispositivo emisor a buscar
    MAC_REPETIDOR   // MAC del propio repetidor
} mac_type_t;

static uint8_t mac_address_from_flash[6] = {0};

// History functions
ret_code_t save_history_record_emisor(store_history const *p_history_data, uint16_t offset);
ret_code_t save_history_record(store_history const *p_history_data);
ret_code_t read_history_record_by_id(uint16_t record_id, store_history *p_history_data);
void       print_history_record(store_history const *p_record, const char *p_title);
ret_code_t read_last_history_record(store_history *p_history_data);

ret_code_t send_all_history_ble(void);
void       history_send_next_packet(void);
bool       history_send_is_active(void);
uint32_t   history_get_progress(void);

// Date and time functions
ret_code_t write_date_to_flash(const datetime_t *p_date);
datetime_t read_date_from_flash(void);
void       write_time_to_flash(valor_type_t valor_type, uint32_t valor);
uint32_t   read_time_from_flash(valor_type_t valor_type, uint32_t default_valor);
void       load_mac_from_flash(mac_type_t mac_type, uint8_t *mac_out);
void       save_mac_to_flash(mac_type_t mac_type, uint8_t *mac_addr);

// Configuration functions
ret_code_t save_config_to_flash(config_repeater_t *p_config);
ret_code_t load_config_from_flash(config_repeater_t *p_config);
void       load_default_config(config_repeater_t *p_config);
void       init_sistema_configuracion(config_repeater_t *p_config);
ret_code_t send_config_via_ble(void);

// FDS initialization functions
void       fds_initialize(void);

#endif // FILESYSTEM_H