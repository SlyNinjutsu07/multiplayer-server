# New things I guess

**(11.6.26)** Spoken in Wispr Flow (amazing software btw)

## `gameloop.cpp` functionality

### 30Hz Update instead of 60Hz

Updating frames through 60Hz is expensive, because your sending data back and forth with an upload speed of some
number of bytes per second. If we are looking to do many more updates per second, it can increase that many bytes per second. So broadcasting data at 30Hz rather than 60Hz is a good alternative since 30hz is still pretty smooth
and we don't have to reach an absurd number of upload and download rates for data.

### Clamp
Today I just added a clamping mechanism to the game loop.cpp file within the second while loop of the game loop function.

Essentially, the purpose of this clamp, where it says `frameTime`, is that when the server stalls due to a networking error, we don't want the server to immediately make up all of that time by updating all of the inputs that were processed and added within that amount of time. What we want to do is make sure that, even after it had stalled for a long period of time, it still continues to consistently send updates within consistent intervals. This keeps the game itself stable, and it doesn't jump around ecstatically.

### WTH IS CMAKELISTS.TXT
So basically, when compiling c++ files regularly, you typically have to list ALL the files that are being used in the program, and then you have to list things like vcpkg and then the additional uwebsocket libraries, and make sure that its being run with the right c++ version with the right compiler and blah blah blah.... It makes it a lot easier, in short, so you don't have to do any "listing".

#### What is CMakePresets?

**(11.3.26)** no idea.


### WTH IS A DLL

A DLL (".dll"), or a Dynamic-Link Library is a file of compiled code that other programs load while they run. It's like the .cpp to your .hpp 😏. In other words, it's compiled code with the definitions of all the functions you need for your .exe to load and call during execution.


