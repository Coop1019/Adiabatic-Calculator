#include <iostream>
#include "specific_heat_cp.hpp"

#define T0 (298)


#define INTEGRATE_STEP_SIZE (.001)  // Step size °K
#define DELTA_H_RXN (9186)          // KJ target DeltaH


void calculate_adiabatic_flame_temp()
{
    double delta_h_run = 0;         // Running delta h total kJ
    double current_temp = T0;       // Running temperature

    double m_co2 = 12;              // moles CO2
    double m_h20 = 13;              // moles H2O
    double m_n2 = 86.95;            // moles N2
    double m_o2 = 4.625;            // moles O2

    while (delta_h_run < DELTA_H_RXN)
    {
        delta_h_run += (m_co2 * cp::co2(current_temp) / 1000 * INTEGRATE_STEP_SIZE);
        delta_h_run += (m_h20 * cp::h2o(current_temp) / 1000 * INTEGRATE_STEP_SIZE);
        delta_h_run += (m_n2 * cp::n2(current_temp) / 1000 * INTEGRATE_STEP_SIZE);
        delta_h_run += (m_o2 * cp::o2(current_temp) / 1000 * INTEGRATE_STEP_SIZE);

        current_temp += INTEGRATE_STEP_SIZE;
    }

    printf("Target CP: [%d] | Complete CP: [%.2f] | Error: [%.4f%%]\n",
           DELTA_H_RXN, delta_h_run, (delta_h_run - DELTA_H_RXN) / DELTA_H_RXN * 100);
    printf("Adiabatic Flame Temperature [%.3f]\n", current_temp);
}

int main()
{
    calculate_adiabatic_flame_temp();
    return 0;
}
