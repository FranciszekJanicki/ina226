#ifndef INA226_INA226_CONFIG_H
#define INA226_INA226_CONFIG_H

#include <stddef.h>
#include <stdint.h>

#define INA226_MANUFACTURER_ID 0b0101010001001001
#define INA226_BUS_VOLTAGE_SCALE 41.0F / (float32_t)(1U << 15U)
#define INA226_SHUNT_VOLTAGE_SCALE 41.0F / (float32_t)(1U << 15U)

typedef float float32_t;

typedef enum {
    INA226_ERR_OK = 0,
    INA226_ERR_FAIL = 1 << 0,
    INA226_ERR_NULL = 1 << 1,
} ina226_err_t;

typedef enum {
    INA226_SLAVE_ADDRESS_A1_GND_A0_GND = 0b1000000,
    INA226_SLAVE_ADDRESS_A1_GND_A0_VS = 0b1000001,
    INA226_SLAVE_ADDRESS_A1_GND_A0_SDA = 0b1000010,
    INA226_SLAVE_ADDRESS_A1_GND_A0_SCL = 0b1000011,
    INA226_SLAVE_ADDRESS_A1_VS_A0_GND = 0b1000100,
    INA226_SLAVE_ADDRESS_A1_VS_A0_VS = 0b1000101,
    INA226_SLAVE_ADDRESS_A1_VS_A0_SDA = 0b1000110,
    INA226_SLAVE_ADDRESS_A1_VS_A0_SCL = 0b1000111,
    INA226_SLAVE_ADDRESS_A1_SDA_A0_GND = 0b1010000,
    INA226_SLAVE_ADDRESS_A1_SDA_A0_VS = 0b1001001,
    INA226_SLAVE_ADDRESS_A1_SDA_A0_SDA = 0b1001010,
    INA226_SLAVE_ADDRESS_A1_SDA_A0_SCL = 0b1001011,
    INA226_SLAVE_ADDRESS_A1_SCL_A0_GND = 0b1001100,
    INA226_SLAVE_ADDRESS_A1_SCL_A0_VS = 0b1001101,
    INA226_SLAVE_ADDRESS_A1_SCL_A0_SDA = 0b1001110,
    INA226_SLAVE_ADDRESS_A1_SCL_A0_SCL = 0b1001111,
} ina226_slave_address_t;

typedef enum {
    INA226_REG_ADDRESS_CONFIG = 0x00,
    INA226_REG_ADDRESS_SHUNT_VOLTAGE = 0x01,
    INA226_REG_ADDRESS_BUS_VOLTAGE = 0x02,
    INA226_REG_ADDRESS_POWER = 0x03,
    INA226_REG_ADDRESS_CURRENT = 0x04,
    INA226_REG_ADDRESS_CALIBRATION = 0x05,
    INA226_REG_ADDRESS_MASK_ENABLE = 0x06,
    INA226_REG_ADDRESS_ALERT_LIMIT = 0x07,
    INA226_REG_ADDRESS_MANUFACTURER_ID = 0xFE,
    INA226_REG_ADDRESS_DIE_ID = 0xFF,
} ina226_reg_address_t;

typedef enum {
    INA226_AVERAGING_MODE_1_SAMPLE = 0b000,
    INA226_AVERAGING_MODE_4_SAMPLES = 0b001,
    INA226_AVERAGING_MODE_16_SAMPLES = 0b010,
    INA226_AVERAGING_MODE_64_SAMPLES = 0b011,
    INA226_AVERAGING_MODE_128_SAMPLES = 0b100,
    INA226_AVERAGING_MODE_256_SAMPLES = 0b101,
    INA226_AVERAGING_MODE_512_SAMPLES = 0b110,
    INA226_AVERAGING_MODE_1024_SAMPLES = 0b111,
} ina226_avg_t;

typedef enum {
    INA226_BUS_VOLTAGE_CONVERSION_TIME_140US = 0b000,
    INA226_BUS_VOLTAGE_CONVERSION_TIME_204US = 0b001,
    INA226_BUS_VOLTAGE_CONVERSION_TIME_332US = 0b010,
    INA226_BUS_VOLTAGE_CONVERSION_TIME_558US = 0b011,
    INA226_BUS_VOLTAGE_CONVERSION_TIME_1MS1 = 0b100,
    INA226_BUS_VOLTAGE_CONVERSION_TIME_2MS116 = 0b101,
    INA226_BUS_VOLTAGE_CONVERSION_TIME_4MS156 = 0b110,
    INA226_BUS_VOLTAGE_CONVERSION_TIME_8MS244 = 0b111,
} ina226_vbus_ct_t;

typedef enum {
    INA226_SHUNT_VOLTAGE_CONVERSION_TIME_140US = 0b000,
    INA226_SHUNT_VOLTAGE_CONVERSION_TIME_204US = 0b001,
    INA226_SHUNT_VOLTAGE_CONVERSION_TIME_332US = 0b010,
    INA226_SHUNT_VOLTAGE_CONVERSION_TIME_558US = 0b011,
    INA226_SHUNT_VOLTAGE_CONVERSION_TIME_1MS1 = 0b100,
    INA226_SHUNT_VOLTAGE_CONVERSION_TIME_2MS116 = 0b101,
    INA226_SHUNT_VOLTAGE_CONVERSION_TIME_4MS156 = 0b110,
    INA226_SHUNT_VOLTAGE_CONVERSION_TIME_8MS244 = 0b111,
} ina226_vsh_ct_t;

typedef enum {
    INA226_OPERATING_MODE_POWER_DOWN = 0b000,
    INA226_OPERATING_MODE_SHUNT_TRIGGERED = 0b001,
    INA226_OPERATING_MODE_BUS_TRIGGERED = 0b010,
    INA226_OPERATING_MODE_SHUNT_BUS_TRIGGERED = 0b011,
    INA226_OPERATING_MODE_SHUNT_CONTINUOUS = 0b101,
    INA226_OPERATING_MODE_BUS_CONTINUOUS = 0b110,
    INA226_OPERATING_MODE_SHUNT_BUS_CONTINUOUS = 0b111,
} ina226_mode_t;

typedef struct {
    float32_t current_scale;
    float32_t calibration;
} ina226_config_t;

typedef struct {
    void* bus_user;
    ina226_err_t (*bus_initialize)(void*);
    ina226_err_t (*bus_deinitialize)(void*);
    ina226_err_t (*bus_write_data)(void*, uint8_t, uint8_t const*, size_t);
    ina226_err_t (*bus_read_data)(void*, uint8_t, uint8_t*, size_t);
} ina226_interface_t;

inline float32_t ina226_current_range_to_scale(float32_t current_range)
{
    return current_range / (float32_t)(1U << 15U);
}

inline float32_t ina226_scale_and_shunt_resistance_to_calibration(float32_t scale,
                                                                  float32_t shunt_resistance)
{
    return 0.00512F / (scale * shunt_resistance);
}

inline float32_t ina226_current_to_power_scale(float32_t current_scale)
{
    return 25.0F * current_scale;
}

inline float32_t ina226_calibration_to_corrected_calibration(float32_t calibration,
                                                             float32_t shunt_current,
                                                             float32_t device_current)
{
    return calibration * shunt_current / device_current;
}

#endif // INA226_INA226_CONFIG_H