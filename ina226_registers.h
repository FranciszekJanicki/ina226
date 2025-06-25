#ifndef INA226_INA226_REGISTERS_H
#define INA226_INA226_REGISTERS_H

#include <stdint.h>

typedef struct {
    uint8_t rst : 1;
    uint8_t avg : 3;
    uint8_t vbus_ct : 3;
    uint8_t vsh_ct : 3;
    uint8_t mode : 3;
} ina226_config_reg_t;

typedef struct {
    int16_t voltage : 16;
} ina226_shunt_voltage_reg_t;

typedef struct {
    int16_t voltage : 15;
} ina226_bus_voltage_reg_t;

typedef struct {
    int16_t power : 16;
} ina226_power_reg_t;

typedef struct {
    int16_t current : 16;
} ina226_current_reg_t;

typedef struct {
    int16_t fs : 15;
} ina226_calibration_reg_t;

typedef struct {
    uint8_t sol : 1;
    uint8_t sul : 1;
    uint8_t bol : 1;
    uint8_t bul : 1;
    uint8_t pol : 1;
    uint8_t cnvr : 1;
    uint8_t aff : 1;
    uint8_t cvrf : 1;
    uint8_t ovf : 1;
    uint8_t apol : 1;
    uint8_t len : 1;
} ina226_mask_enable_reg_t;

typedef struct {
    int16_t aul : 16;
} ina226_alert_limit_reg_t;

typedef struct {
    uint16_t mid : 16;
} ina226_manufacturer_id_reg_t;

typedef struct {
    uint16_t did : 12;
    uint8_t rid : 4;
} ina226_die_id_reg_t;

#endif // INA226_INA226_REGISTERS_H