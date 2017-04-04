#pragma once

#include <cstdint>
#include <cassert>
#include <vector>

#include <bitter/writer.hpp>

namespace header_cpp
{
namespace protocols
{
class tcp_header_writer
{
public:
    tcp_header_writer();
    ~tcp_header_writer();

    void source_port(const uint16_t value);
    void destination_port(const uint16_t value);
    void sequence_number(const uint32_t value);
    void acknowledgement_number(const uint32_t value);
    void data_offset(const uint8_t value);
    void reserved(); // Write 0;
    void urgent(const bool value);
    void acknowledgement(const bool value);
    void push(const bool value);
    void reset(const bool value);
    void synchronize(const bool value);
    void fin(const bool value);
    void window(const uint16_t value);
    void checksum(const uint16_t value);
    void urgent_pointer(const uint16_t value);
    void options(const uint32_t value);
    void padding(const uint8_t value);
    std::vector<uint32_t> data();



private:
    bitter::writer<uint32_t, 16, 16> m_first_row;
    uint32_t m_second_row;
    uint32_t m_third_row;
    bitter::writer<uint32_t, 4, 6, 1, 1, 1, 1, 1, 1, 16> m_fourth_row;
    bitter::writer<uint32_t, 16, 16> m_fifth_row;
    bitter::writer<uint32_t, 24, 8> m_sixth_row;
    std::vector<uint32_t> m_data;
};
}
}
