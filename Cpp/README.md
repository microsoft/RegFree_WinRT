# Registration-free WinRT in C++ Desktop App sample

This sample demonstrates how to use [Registration-free WinRT](https://aka.ms/regfreewinrtblog) a new feature in Windows Builds 18309+ to reference a C++ Windows Runtime component in a non-packaged C++ desktop app. It contains a C++ desktop app (CppDesktopApp.vcxproj) and a WinRT Component (WinRTComponent.vcxproj).

You can learn more about Registration-free WinRT [here](https://aka.ms/regfreewinrtblog).

The C++ desktop app uses:
[C++/WinRT](https://github.com/Microsoft/xlang/blob/f1309fe42d929d612aa9b66557d9a22769067b3f/src/package/cppwinrt/nuget/readme.md) to create projection header files of the component for use in the app code
[Microsoft.VCRTForwarders.140](https://github.com/Microsoft/vcrt-forwarders) NuGet package to manage C++ Runtime dependencies for the component.

##Requirements

The sample requires Windows Build 18309+ to work

## Instructions

### CppDesktopApp

A non-packaged C# WinForms app referencing a C++ WinRT Component

* The specific DLLs and classes (from the WinRT component) being referenced should be declared in the Win32 Application manifest - CppDesktopApp.exe.manifest.
(To add a new Win32 Application Manifest to a desktop app right click on project -> Add -> New Item -> Utility -> Text File -> Name it <yourappname.exe>.manifest)
* In order for the System to pick up themcomponent DLLs specified in the application manifest at runtime, the DLLs must be located in the same deirectory as the app's .exe. This project is using a propery sheet (PropertySheet.props) to copy over the component DLL to the app's outpiut directory. 
The property sheet is also used to add a reference to the component's WinMD to enable [C++/WinRT](https://github.com/Microsoft/xlang/tree/master/src/package/cppwinrt/nuget) to generate projection headers of the component which are used in the app code.

### WinRTComponent

A simple C++ WinRT Component with a class returning a string

* The component is written using [C++/WinRT](https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt) instead of [C++/CX](https://docs.microsoft.com/en-us/cpp/cppcx/visual-c-language-reference-c-cx?view=vs-2017) therefore it requires an installed Nuget Package: [Microsoft.Windows.CppWinRT](https://www.nuget.org/packages/Microsoft.Windows.CppWinRT/).
* To manage the specific C++ Runtime Dependencies of the WinRT component, the app is using the [Microsoft.VCRTForwarders.140](https://github.com/Microsoft/vcrt-forwarders) NuGet package.

### Building and running the sample

1. Load the Project solution.
2. Retarget the solution to the SDK version on your machine – Right click -> Retarget solution
3. Build the WinRTComponent project.
4. Build the CppDesktopApp project
5. Run the app


