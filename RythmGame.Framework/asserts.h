#pragma once

#include <iostream>

#include "Log.h"

namespace RythmGame::Framework
{

    template<typename T>
    static inline void assertValueInferior( T &_value, T _min )
    {
        if( _value < _min )
        {
            logFile->Write( "Error : " + std::to_string( _value ) + " < " + std::to_string( _min ) + ", value has been set to " + std::to_string( _min ) );
            _value = _min;
        }
    }

    template<typename T>
    static inline void assertValueSuperior( T &_value, T _max )
    {
        if( _value > _max )
        {
            logFile->Write( "Error : " + std::to_string( _value ) + " < " + std::to_string( _max ) + ", value has been set to " + std::to_string( _max ) );
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