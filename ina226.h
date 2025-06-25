#ifndef INA226_INA226_H
#define INA226_INA226_H

#include "ina226_config.h"
#include "ina226_registers.h"

typedef struct {
    ina226_config_t config;
    ina226_interface_t interface;
} ina226_t;

ina226_err_t ina226_initialize(ina226_t* ina226,
                               ina226_config_t const* config,
                               ina226_interface_t const* interface);
ina226_err_t ina226_deinitialize(ina226_t* ina226);

ina226_err_t ina226_get_current_scaled(ina226_t const* ina226, float32_t* scaled);
ina226_err_t ina226_get_bus_voltage_scaled(ina226_t const* ina226, float32_t* scaled);
ina226_err_t ina226_get_shunt_voltage_scaled(ina226_t const* ina226, float32_t* scaled);
ina226_err_t ina226_get_power_scaled(ina226_t const* ina226, float32_t* scaled);

ina226_err_t ina226_get_current_raw(ina226_t const* ina226, int16_t* raw);
ina226_err_t ina226_get_bus_voltage_raw(ina226_t const* ina226, int16_t* raw);
ina226_err_t ina226_get_shunt_voltage_raw(ina226_t const* ina226, int16_t* raw);
ina226_err_t ina226_get_power_raw(ina226_t const* ina226, int16_t* raw);

ina226_err_t ina226_get_config_reg(ina226_t const* ina226, ina226_config_reg_t* reg);
ina226_err_t ina226_set_config_reg(ina226_t const* ina226, ina226_config_reg_t const* reg);

ina226_err_t ina226_get_shunt_voltage_reg(ina226_t const* ina226, ina226_shunt_voltage_reg_t* reg);

ina226_err_t ina226_get_bus_voltage_reg(ina226_t const* ina226, ina226_bus_voltage_reg_t* reg);

ina226_err_t ina226_get_power_reg(ina226_t const* ina226, ina226_power_reg_t* reg);

ina226_err_t ina226_get_current_reg(ina226_t const* ina226, ina226_current_reg_t* reg);

ina226_err_t ina226_get_calibration_reg(ina226_t const* ina226, ina226_calibration_reg_t* reg);
ina226_err_t ina226_set_calibration_reg(ina226_t const* ina226,
                                        ina226_calibration_reg_t const* reg);

ina226_err_t ina226_get_mask_enable_reg(ina226_t const* ina226, ina226_mask_enable_reg_t* reg);
ina226_err_t ina226_set_mask_enable_reg(ina226_t const* ina226,
                                        ina226_mask_enable_reg_t const* reg);

ina226_err_t ina226_get_alert_limit_reg(ina226_t const* ina226, ina226_alert_limit_reg_t* reg);
ina226_err_t ina226_set_alert_limit_reg(ina226_t const* ina226,
                                        ina226_alert_limit_reg_t const* reg);

ina226_err_t ina226_get_manufacturer_id_reg(ina226_t const* ina226,
                                            ina226_manufacturer_id_reg_t* reg);

ina226_err_t ina226_get_die_id_reg(ina226_t const* ina226, ina226_die_id_reg_t* reg);

#endif // INA226_INA226_H