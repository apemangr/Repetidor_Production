# Comandos BLE NUS del Repetidor

Este documento describe todos los comandos disponibles via BLE NUS para el dispositivo repetidor.

## Formato de comandos
Todos los comandos siguen el formato: `111XX[datos]`
- `111` = Prefijo identificador
- `XX` = Número de comando de 2 dígitos (01-14)
- `[datos]` = Datos adicionales según el comando

## Lista de comandos disponibles

### 🔧 **Comando 01: Cambiar MAC del Emisor**
- **Formato**: `11101[12 caracteres hex]`
- **Ejemplo**: `111010400000ABC3`
- **Descripción**: Guarda una nueva MAC del emisor a buscar
- **Datos**: 12 caracteres hexadecimales (6 bytes MAC)

### 📱 **Comando 02: Mostrar MAC guardada**
- **Formato**: `11102`
- **Descripción**: Muestra la MAC del emisor guardada en flash
- **Respuesta**: Log con la MAC actual

### 🔄 **Comando 03: Reiniciar dispositivo**
- **Formato**: `11103`
- **Descripción**: Reinicia el dispositivo completamente
- **Acción**: `NVIC_SystemReset()`

### ⏰ **Comando 04: Configurar tiempo activo**
- **Formato**: `11104[XXX]`
- **Ejemplo**: `11104015` (15 segundos)
- **Descripción**: Configura el tiempo que el dispositivo permanece activo
- **Datos**: 3 dígitos en segundos (máximo 666 segundos)

### 📊 **Comando 05: Leer tiempo activo**
- **Formato**: `11105`
- **Descripción**: Muestra el tiempo activo configurado
- **Respuesta**: Log con el valor en milisegundos

### 💤 **Comando 06: Configurar tiempo de sleep**
- **Formato**: `11106[XXX]`
- **Ejemplo**: `11106006` (6 segundos)
- **Descripción**: Configura el tiempo que el dispositivo permanece dormido
- **Datos**: 3 dígitos en segundos (máximo 6666 segundos)

### 😴 **Comando 07: Leer tiempo de sleep**
- **Formato**: `11107`
- **Descripción**: Muestra el tiempo de sleep configurado
- **Respuesta**: Log con el valor en milisegundos

### 📅 **Comando 08: Configurar fecha y hora**
- **Formato**: `11108[YYYYMMDDHHMMSS]`
- **Ejemplo**: `1110820240925143015` (25 Sep 2024, 14:30:15)
- **Descripción**: Configura fecha y hora del RTC
- **Datos**: 14 dígitos - Año(4) + Mes(2) + Día(2) + Hora(2) + Minuto(2) + Segundo(2)

### 🕐 **Comando 09: Leer fecha y hora**
- **Formato**: `11109`
- **Descripción**: Muestra la fecha y hora almacenada en flash
- **Respuesta**: Log con fecha en formato YYYY-MM-DD HH:MM:SS

### 📜 **Comando 11: Solicitar historial por ID**
- **Formato**: `11111[ID]`
- **Ejemplo**: `11111123` (solicitar registro #123)
- **Descripción**: Solicita un registro específico del historial
- **Datos**: ID numérico del registro

### 📚 **Comando 13: Solicitar historial completo**
- **Formato**: `11113`
- **Descripción**: Envía todos los registros de historial via BLE
- **Respuesta**: Todos los historiales guardados

### ⚙️ **Comando 14: Enviar configuración actual** ✨ **NUEVO**
- **Formato**: `11114`
- **Descripción**: Envía toda la configuración actual del dispositivo
- **Respuesta**: JSON con configuración completa + log detallado

## Ejemplo de respuesta del Comando 14

```json
{
"config":{
"mac_emisor":"C3:AB:00:00:00:04",
"mac_repetidor":"E4:72:B3:04:0C:6A",
"tiempo_activo":10000,
"tiempo_sleep":6000,
"tiempo_extendido":20000,
"version":"v1.0.0",
"fecha_config":"25/09/2024 14:30:15"
}}
```

## 🔍 **Información adicional del Comando 14**

El comando 14 envía:
- **MAC del emisor**: Dirección MAC del dispositivo a buscar
- **MAC del repetidor**: Dirección MAC propia del repetidor  
- **Tiempo activo**: Milisegundos que permanece activo en modo normal
- **Tiempo sleep**: Milisegundos que permanece dormido en modo normal
- **Tiempo extendido**: Milisegundos que permanece activo en modo extendido
- **Versión**: Versión del firmware
- **Fecha configuración**: Última vez que se guardó la configuración

## 📝 **Uso recomendado**

1. **Para configurar dispositivo nuevo**: Comandos 01, 04, 06, 08
2. **Para verificar configuración**: Comando 14
3. **Para diagnóstico**: Comandos 02, 05, 07, 09
4. **Para obtener datos**: Comandos 11, 13
5. **Para mantenimiento**: Comando 03

## ⚠️ **Notas importantes**

- Los comandos que modifican configuración la guardan automáticamente en flash con timestamp
- El comando 03 reinicia el dispositivo inmediatamente
- Los tiempos se configuran en segundos pero se almacenan en milisegundos
- Las MACs se muestran en formato big-endian (byte más significativo primero)
- El comando 14 siempre carga la configuración más actual desde flash