#include <iostream>
#include <boost/math/special_functions/daubechies_scaling.hpp>
#include <boost/core/demangle.hpp>
#include <boost/hana/for_each.hpp>
#include <boost/hana/ext/std/integer_sequence.hpp>

int main()
{
    _Boost::hana::for_each(std::make_index_sequence<18>(),
    [](auto i) {
        std::cout << std::right;
        auto daub = _Boost::math::daubechies_scaling<float, i+2>();
        std::cout << "The Daubechies " << std::setw(2) <<  i + 2 << " scaling function occupies " 
                  << std::setw(12) << daub.bytes()/1000.0 << " kilobytes in relative accuracy mode in "
                  << _Boost::core::demangle(typeid(float).name()) << " precision\n";
    });

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    _Boost::hana::for_each(std::make_index_sequence<18>(),
    [](auto i) {
        std::cout << std::right;
        auto daub = _Boost::math::daubechies_scaling<float, i+2>(-2);
        std::cout << "The Daubechies " << std::setw(2) <<  i + 2 << " scaling function occupies " 
                  << std::setw(12) << daub.bytes()/1000.0 << " kilobytes in absolute accuracy mode in "
                  << _Boost::core::demangle(typeid(float).name()) << " precision\n";
    });

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    _Boost::hana::for_each(std::make_index_sequence<18>(),
    [](auto i) {
        std::cout << std::right;
        auto daub = _Boost::math::daubechies_scaling<double, i+2>();
        std::cout << "The Daubechies " << std::setw(2) <<  i + 2 << " scaling function occupies " 
                  << std::setw(12) << daub.bytes()/1000.0 << " kilobytes in relative accuracy mode in "
                  << _Boost::core::demangle(typeid(double).name()) << " precision\n";
    });

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    _Boost::hana::for_each(std::make_index_sequence<18>(),
    [](auto i) {
        std::cout << std::right;
        auto daub = _Boost::math::daubechies_scaling<double, i+2>(-2);
        std::cout << "The Daubechies " << std::setw(2) <<  i + 2 << " scaling function occupies " 
                  << std::setw(12) << daub.bytes()/1000.0 << " kilobytes in absolute accuracy mode in "
                  << _Boost::core::demangle(typeid(double).name()) << " precision\n";
    });


}
