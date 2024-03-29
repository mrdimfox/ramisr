#pragma once

#include <cstdint>
#include <iostream>

#include "config.hpp"
#include "isr_provider.hpp"

namespace examples {

class IrqHolder : IsrProvider::IrqHandler<IrqHolder, IsrProvider::Irq::SPI1>
{
 public:
    IrqHolder() :
      IsrProvider::IrqHandler<IrqHolder, IsrProvider::Irq::SPI1>(
        this,
        &IrqHolder::_spi1_irq_handler)
    {
    }

 private:
    void _spi1_irq_handler()
    {
        if constexpr (config::examples::IS_PRINT_ENABLED) {
            std::cout << "SPI1 interrupt!"
                      << "\n";
        }

        _is_spi = true;
    }

    bool _is_spi = false;
};

}  // namespace examples