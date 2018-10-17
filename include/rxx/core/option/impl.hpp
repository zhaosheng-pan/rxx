#ifndef __RXX_CORE_OPTION_IMPL_HPP__
#define __RXX_CORE_OPTION_IMPL_HPP__

#include "rxx/core/option/def.hpp"
#include "rxx/core/str/def.hpp"
#include "rxx/core/result/def.hpp"

namespace rxx {

template<typename T>
template<typename E>
inline auto Option<T>::ok_or(E&& err) -> Result<T, E> {
    if (is_some()) {
        return Ok(std::move(val()));
    } else {
        return Err(std::forward<E>(err));
    }
}

template<typename T>
inline auto Option<T>::expect(const str msg) noexcept -> T {
    RXX_ASSERT(is_some(), msg);
    return std::move(val());
}

}

#include "rxx/core/option/ref/impl.hpp"

#endif /* end of include guard: __RXX_CORE_OPTION_IMPL_HPP__ */
