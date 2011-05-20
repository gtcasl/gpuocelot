Make sure you have the CUDA toolkit installed (I used version 3.2).
Then:

1. Open the cudaRenderer_vc90.sln with your Visual Studio
2. Compile in Release mode
3. Right-click on "cudaRenderer" in the Solution explorer, and select "Properties"
4. Click on "Configuration Properties/Debugging"
5. In the "Command Arguments", enter "..\3D-objects\chessboard.tri" and click OK
6. Hit Ctrl-F5 to run.

You should see a rotating chessboard... 

Read the upper-level README for details on navigation, or hit H (for help).

(I used the free Visual C++ 2008 Express Edition, 
 but this should work with the commercial one, too)
