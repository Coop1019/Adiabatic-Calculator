//
// Created by Cooper LeComp on 2/10/22.
//

#ifndef ADIABATIC_CALCULATOR_SPECIFIC_HEAT_CP_HPP
#define ADIABATIC_CALCULATOR_SPECIFIC_HEAT_CP_HPP

#include <cmath>

namespace cp
{
    // return in kj/k-mol
    static inline double n2(double k)
    {
        double t = k/100;
        return  39.060 -
                512.79 * pow(t, -1.5) +
                1072.7 * pow(t, -2) -
                820.40 * pow(t, -3);
    }
    static inline double o2(double k)
    {
        double t = k/100;
        return  37.432 +
                0.020102 * pow(t, 1.5) -
                178.57 * pow(t, -1.5) +
                236.88 * pow(t, -2);
    }
    static inline double co2(double k)
    {
        double t = k/100;
        return  -3.7357 +
                30.529 * pow(t, 0.5) -
                4.1034 * t +
                0.024198 * pow(t, 2);
    }
    static inline double h2o(double k)
    {
        double t = k/100;
        return  143.05 -
                183.54 * pow(t,0.25) +
                82.751 * pow(t, 0.5) -
                3.6989 * t;
    }
    static inline double h2(double k)
    {
        double t = k/100;
        return  56.505 -
                702.74 * pow(t, -0.75) +
                1165 * pow(t, -1) -
                560.7 * pow(t, -1.5);
    }
}

#endif //ADIABATIC_CALCULATOR_SPECIFIC_HEAT_CP_HPP
