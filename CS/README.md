# Registration-free WinRT in C# Desktop App sample

This sample demonstrates how to use [Registration-free WinRT](https://aka.ms/regfreewinrtblog) a new feature in Windows Builds 18309+ to reference a C++ Windows Runtime component in a non-packaged C# desktop app. It contains a C# Windows Forms app (WinFormsApp.csproj) and a WinRT Component (WinRTComponent.vcxproj).

You can learn more about Registration-free WinRT [here](https://aka.ms/regfreewinrtblog).

The C# desktop app uses:
[Microsoft.VCRTForwarders.140](https://github.com/Microsoft/vcrt-forwarders) NuGet package to manage C++ Runtime dependencies for the C++ component.

## Requirements

The sample requires Windows Build 18309+ to work

## Instructions

### WinFormsApp

A non-packaged C# WinForms app referencing a C++ WinRT Component

* The C# app has a visual Studio reference to the WinRTComponent Project. To add a VS reference to a project right click on project -> Add -> Reference -> Projects -> Select target project to reference

* The specific DLLs and classes (from the WinRT component) being referenced should be declared in the [Win32 Application manifest](https://docs.microsoft.com/en-us/windows/desktop/SbsCs/application-manifests) - WinFormsApp.exe.manifest.
(To add a new app.manifest to a desktop app right click on project -> Add -> New Item -> General -> Application Manifest File -> Name it <yourappname.exe>.manifest) 

* In order for the System to pick up the component DLLs specified in the application manifest at runtime, the DLLs must be located in the same deirectory as the app's .exe. This project is using a Post Build Event to copy over the component DLL to the app's output directory:

````
copy /Y "$(SolutionDir)WinRTComponent\bin\$(Platform)\$(Configuration)\WinRTComponent.dll"  "$(SolutionDir)$(MSBuildProjectName)\$(OutDir)WinRTComponent.dll" 

````
* To add your own Post Build Event to your C# project right click on project -> Properties -> Build Events -> Post Build Event Command line

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


