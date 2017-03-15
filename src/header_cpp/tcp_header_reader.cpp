#include "tcp_header_reader.hpp"

namespace header_cpp
{

    tcp_header_reader::tcp_header_reader(std::vector<uint32_t> data):
        m_data(data)
    {
        asssert(data.size() == 6);
        m_first_row(data[0]);
        m_second_row(data[1]);
        m_third_row(data[2]);
        m_fourth_row(data[3]);
        m_fifth_row(data[4]);
        m_sixth_row(data[5]);
    }

    uint16_t tcp_header_reader::source_port() const
    {
        return m_first_row.field<0>.read_as<uint16_t>();
    }

    uint16_t tcp_header_reader::destination_port() const
    {
        return m_first_row.field<1>.read_as<uint16_t>();
    }

    uint32_t tcp_header_reader::sequence_number() const
    {
        return m_second_row.field<0>.read_as<uint32_t>();
    }

    uint32_t tcp_header_reader::acknowledgement_number() const
    {
        return m_third_row.field<0>.read_as<uint32_t>();
    }







}
