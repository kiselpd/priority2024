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

//Esp32 json
//DATA!
// {
//     "Input": {
//         "DC": {
//             "V": "4.40314142e+14",
//             "A": "4.59135442e-41"
//         },
//         "AC": {
//             "V": "-1.89127237e-31",
//             "A": "3.0916848e-41"
//         }
//     },
//     "Battery": {
//         "V": "6.22400155e+25"
//     },
//     "Output": [
//         {
//             "V": "4.58084468e-41",
//             "A": "-1.8981449e-31",
//             "Status": "47"
//         },
//         {
//             "V": "-1.8981442e-31",
//             "A": "3.0916848e-41",
//             "Status": "160"
//         },
//         {
//             "V": "3.0916848e-41",
//             "A": "8.40779079e-45",
//             "Status": "0"
//         },
//         {
//             "V": "3.59803743e+23",
//             "A": "3.48164059e+31",
//             "Status": "48"
//         }
//     ]
// }
//###END_OF_DATA###



// RelayStatus json
// DATA!
// {
//     "Relay_number": "1",
//     "Status": "0"
// }
// ###END_OF_DATA###

