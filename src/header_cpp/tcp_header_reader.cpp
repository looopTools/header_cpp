#include "tcp_header_reader.hpp"

namespace header_cpp
{

    tcp_header_reader::tcp_header_reader(std::vector<uint32_t> data):
        m_data(data),
        m_first_row{data[0]},
        m_second_row{data[1]},
        m_third_row{data[2]},
        m_fourth_row{data[3]},
        m_fifth_row{data[4]},
        m_sixth_row{data[5]}
    {
        assert(data.size() == 6);
//        m_first_row = bitter::reader<uint32_t, 16, 16>(data[0]);
//        m_second_row(data[1]);
//        m_third_row = data[2];
//        m_fourth_row = data[3];
//        m_fifth_row(data[4]);
//        m_sixth_row(data[5]);
    }

    uint16_t tcp_header_reader::source_port() const
    {
        auto temp = m_first_row.field<0>().read_as<uint16_t>();
        return temp;
    }

    uint16_t tcp_header_reader::destination_port() const
    {
        return m_first_row.field<1>().read_as<uint16_t>();
    }

    uint32_t tcp_header_reader::sequence_number() const
    {
        return m_second_row;
    }

    uint32_t tcp_header_reader::acknowledgement_number() const
    {
        return m_third_row;
    }

    uint8_t tcp_header_reader::data_offset() const
    {
        return m_fourth_row.field<0>().read_as<uint8_t>();
    }

    uint8_t tcp_header_reader::reserved() const
    {
        unit8_t result = m_fourth_row.field<1>().read_as<uint8_t>();
        // if result is not null some thing is fucked up
        assert(0U == result);
        return result;
    }

    bool tcp_header_reader::urgent() const
    {
        return m_fourth_row.field<2>().read_as<bool>();
    }

    bool tcp_header_reader::acknowledgement() const
    {
        return m_fourth_row.field<3>().read_as<bool>();
    }

    bool tcp_header_reader::reset() const
    {
        return m_fourth_row.field<4>().read_as<bool>();
    }

    bool tcp_header_reader::synchronize() const
    {
        return m_fourth_row.field<5>().read_as<bool>();
    }

    bool tcp_header_reader::fin() const
    {
        return m_fourth_row.field<6>().read_as<bool>();
    }

    uint16_t tcp_header_reader::window() const
    {
        return m_fourth_row.field<7>().read_as<uint16_t>();
    }

    uint16_t tcp_header_reader::checksum() const
    {
        return m_fifth_row.field<0>().read_as<uint16_t>();
    }

    uint16_t tcp_header_reader::urgent_pointer() const
    {
        return m_fifth_row.field<1>().read_as<uint16_t>();
    }

    uint32_t tcp_header_reader::options() const
    {
        return m_sixth_row.field<0>().read_as<uint32_t>();
    }

    uint8_t tcp_header_reader::padding() const
    {
        return m_sixth_row.field<1>().read_as<uint8_t>();
    }
}
