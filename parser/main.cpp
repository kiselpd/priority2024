#include<iostream>
#include"parser.hpp"

int main()
{
    // printf("!DATA\n{\n\
    // \"input\": {\n\
    //     \"DC\": {\n\
    //         \"V\": 1,\n\
    //         \"A\": 2\n\
    //     },\n\
    //     \"AC\": {\n\
    //         \"V\": 3,\n\
    //         \"A\": 4\n\
    //     }\n\
    // },\n\
    // \"battery\": {\n\
    //     \"V\": 5\n\
    // },\n\
    // \"output\": {\n\
    //     \"Group_1\": {\n\
    //         \"V\": 6,\n\
    //         \"A\": 7,\n\
    //         \"Status\": 8\n\
    //     },\n\
    //     \"Group_2\": {\n\
    //         \"V\": 9,\n\
    //         \"A\": 10,\n\
    //         \"Status\": 11\n\
    //     },\n\
    //     \"Group_3\": {\n\
    //         \"V\": 12,\n\
    //         \"A\": 13,\n\
    //         \"Status\": 14\n\
    //     },\n\
    //     \"Group_4\": {\n\
    //     \"V\": 15,\n\
    //     \"A\": 16,\n\
    //     \"Status\": 17\n\
    //     }\n\
    // }\n}");

    // std::string myString = "{\"id\":\"0001\",\"type\":\"donut\",\"name\":\"Cake\",\"image\":{\"url\":\"images/0001.jpg\",\"width\":200,\"height\":200},\"thumbnail\":{\"url\":\"images/thumbnails/0001.jpg\",\"width\":32,\"height\":32}}";
    // std::cout<<myString<<std::endl;

    // json_obj_esp32::Esp32Data d;

    // d.input_data.ac_a = 1.1;
    // d.input_data.ac_v = 2.2;
    // d.input_data.dc_a = 3.3;
    // d.input_data.dc_v = 4.4;

    // d.battery_data.v = 5.5;
    // d.output_data[0].a = 6.6;
    // d.output_data[0].v = 7.7;
    // d.output_data[0].status = 0;

    // d.output_data[1].a = 8.8;
    // d.output_data[1].v = 9.9;
    // d.output_data[1].status = 1;

    // d.battery_data.v = 10.1;
    // d.output_data[2].a = 11.11;
    // d.output_data[2].v = 12.12;
    // d.output_data[2].status = 0;

    // d.output_data[3].a = 13.13;
    // d.output_data[3].v = 14.14;
    // d.output_data[3].status = 1;
    // auto str = json_obj_esp32::parseToJson(d);
    // std::cout<<"!DATA\n"+str+"###END_OF_DATA###"<<std::endl;

    // json_obj_esp32::Esp32Data new_d = json_obj_esp32::parseFromJson(str);

    // std::cout<<new_d.input_data.ac_a<<" "<<new_d.input_data.ac_v<<" "<<new_d.input_data.dc_a<<" "<<new_d.input_data.dc_v<<" "<<new_d.battery_data.v<<std::endl;

    // for (size_t i = 0; i < json_obj_esp32::OUTPUT_SIZE; i++)
    // {
    //     std::cout<<new_d.output_data[i].a<<" "<<new_d.output_data[i].v<<" "<<(int)new_d.output_data[i].status<<"/"<<std::endl;
    // }

    json_obj_esp32::RelayStatus s;

    s.relay_number = 1;
    s.relay_status = 0;

    std::cout<<json_obj_esp32::parseToJsonRelay(s);
    
    return EXIT_SUCCESS;
}