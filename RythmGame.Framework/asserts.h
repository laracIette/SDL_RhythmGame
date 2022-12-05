#pragma once

#include <iostream>

namespace RythmGame::Framework
{

    template<typename T>
    static inline void assertValueInferior( T &_value, T _min )
    {
        if( _value < _min )
        {
            std::cout << "Error : " << _value << " < " << _min << ", value has been set to " << _min << std::endl;
            _value = _min;
        }
    }

    template<typename T>
    static inline void assertValueSuperior( T &_value, T _max )
    {
        if( _value > _max )
        {
            std::cout << "Error : " << _value << " > " << _max << ", value has been set to " << _max << std::endl;
            _value = _max;
        }
    }

/**
 * @brief check if (_value >= _min) && (value <= _max)
 */
    template<typename T>
    static inline void assertValueInRange( T &_value, T _min, T _max )
    {
        assertValueInferior( _value, _min );
        assertValueSuperior( _value, _max );
    }

}
