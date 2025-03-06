<h1><span style="color: red;">IMPORTANT</span></h1>
<h2>After you clone the repository in Visual Studio and open a solution change its architecture to x86 (32 bits)</h2>
<h1><b>Data Structures 2024-2025</b></h1>

<b>For using shared library in a new project add the new values:</b>
1. Project Properties -> C/C++ -> General (Additional Include Directories) : path_to_where_shared_headers_are_located;
2. Project Properties -> Linker -> General (Additional Library Directories): $(SolutionDir)$(Configuration);
3. Project Properties -> Linker -> Input (Additional Dependencies)         : $(SolutionDir)$(Configuration)\Shared.lib;
