#pragma once

#include <memory>

namespace lumina
{
    template <typename T>
    using Ref = std::shared_ptr<T>;

    template <typename T>
    using Scope = std::unique_ptr<T>;

    template <typename T, typename U> inline
    Ref<T> refCast(const Ref<U> u)
    {
        return std::static_pointer_cast<T>(u);
    }

    template <typename T, typename... Args> inline
    Ref<T> makeRef(Args&& ...args)
    {
        return std::make_shared<T>(args...);
    }

    template <typename T, typename... Args> inline
    Scope<T> makeScope(Args&& ...args)
    {
        return std::make_unique<T>(args...);
    }

} // namespace lumina
