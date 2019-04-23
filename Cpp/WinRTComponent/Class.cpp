#include "pch.h"
#include "Class.h"
#include "Class.g.cpp"

namespace winrt::WinRTComponent::implementation
{
	hstring Class::MyProperty()
	{
		return L"Hello from an UNPACKAGED WinRT Component! :D";


	}

	void Class::MyProperty(hstring /* value */)
	{
		// throw hresult_not_implemented();
	}

	hstring Class::MyProperty2()
	{
		return L"Hello from an UNPACKAGED WinRT Component! :D";

	}

	void Class::MyProperty2(hstring /* value */)
	{
		// throw hresult_not_implemented();
	}
}
