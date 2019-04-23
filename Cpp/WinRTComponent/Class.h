#pragma once

#include "Class.g.h"

namespace winrt::WinRTComponent::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

		hstring MyProperty();
		hstring MyProperty2();

		void MyProperty(hstring value);
		void MyProperty2(hstring value);
    };
}

namespace winrt::WinRTComponent::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
