#pragma once
#include<iostream>

namespace json_obj_esp32
{
    const std::string VOLTAGE = "V";
    const std::string CURRENT = "A";
    const std::string STATUS = "Status";
    const std::string AC = "AC";
    const std::string DC = "DC";
    const std::string INPUT = "Input";
    const std::string BATTERY = "Battery";
    const std::string OUTPUT = "Output";
    const std::string RELAY_NUMBER = "Relay_number";

    const size_t OUTPUT_SIZE = 4;


    struct InputData 
    {
        float dc_v;
        float dc_a;
        float ac_v;
        float ac_a;
    };

    struct BatteryData
    {
        float v;
    };

    struct OutputData
    {
        float v;
        float a;
        uint8_t status;
    };

    struct Esp32Data
    {
        InputData input_data;
        BatteryData battery_data;
        OutputData output_data[4];
    };

    struct RelayStatus
    {
        uint16_t relay_number;
        uint8_t relay_status;
    };

    std::string parseToJsonRelay(const RelayStatus& relay_data);
    std::string parseToJsonEsp32(const Esp32Data& esp_data);
    Esp32Data parseFromJson(const std::string& string_data); //json string -> struct
};
