#include<iostream>
#include"parser.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace json_obj_esp32;

std::string json_obj_esp32::parseToJsonRelay(const RelayStatus& relay_data)
{
    boost::property_tree::ptree json;

    json.put(RELAY_NUMBER, relay_data.relay_number);
    json.put(STATUS, relay_data.relay_status);

    std::stringstream myJsonEncodedData;
    boost::property_tree::write_json(myJsonEncodedData, json);

    return myJsonEncodedData.str();
}

std::string json_obj_esp32::parseToJsonEsp32(const Esp32Data& esp_data) 
{
    boost::property_tree::ptree json_output;
    boost::property_tree::ptree json_group[OUTPUT_SIZE];
    for (size_t i = 0; i < OUTPUT_SIZE; i++)
    {
        json_group[i].put(VOLTAGE, esp_data.output_data[i].v);
        json_group[i].put(CURRENT, esp_data.output_data[i].a);
        json_group[i].put(STATUS, esp_data.output_data[i].status);
        json_output.push_back(std::make_pair("", json_group[i]));
    }

    boost::property_tree::ptree json_battery;
    json_battery.put(VOLTAGE, esp_data.battery_data.v);

    boost::property_tree::ptree json_dc;
    json_dc.put(VOLTAGE, esp_data.input_data.dc_v);
    json_dc.put(CURRENT, esp_data.input_data.dc_a);

    boost::property_tree::ptree json_ac;
    json_ac.put(VOLTAGE, esp_data.input_data.ac_v);
    json_ac.put(CURRENT, esp_data.input_data.ac_a);

    boost::property_tree::ptree json_input;
    json_input.add_child(DC, json_dc);
    json_input.add_child(AC, json_ac);
    
    boost::property_tree::ptree json;
    json.add_child(INPUT, json_input);
    json.add_child(BATTERY, json_battery);
    json.add_child(OUTPUT, json_output);

    std::stringstream myJsonEncodedData;
    boost::property_tree::write_json(myJsonEncodedData, json);

    return myJsonEncodedData.str();
    
}

Esp32Data json_obj_esp32::parseFromJson(const std::string& string_data)
{
    Esp32Data esp_data;

    try
    {
        boost::property_tree::ptree json;

        std::stringstream jsonEncodedData(string_data);
        boost::property_tree::read_json(jsonEncodedData, json);

        boost::property_tree::ptree json_output = json.get_child(OUTPUT);

        size_t i = 0;

        for(const auto&  tmp_obj: json_output)
        {   
            esp_data.output_data[i].v = std::stof(tmp_obj.second.get(VOLTAGE, ""));
            esp_data.output_data[i].a = std::stof(tmp_obj.second.get(CURRENT, ""));
            esp_data.output_data[i++].status = tmp_obj.second.get<uint8_t>(STATUS);
        }

        esp_data.battery_data.v = std::stof((json.get_child(BATTERY)).get(VOLTAGE, ""));

        boost::property_tree::ptree json_input = json.get_child(INPUT);
        esp_data.input_data.dc_v = std::stof((json_input.get_child(DC)).get(VOLTAGE, ""));
        esp_data.input_data.dc_a = std::stof((json_input.get_child(DC)).get(CURRENT, ""));
        esp_data.input_data.ac_v = std::stof((json_input.get_child(AC)).get(VOLTAGE, ""));
        esp_data.input_data.ac_a = std::stof((json_input.get_child(AC)).get(CURRENT, ""));
    }
    catch (std::exception const& error)
    {
        std::cerr << error.what() << std::endl;
    }

    return esp_data;
}