# C-CPP Study

This Repository groups all my practical exercises and notes while I studying C/C++, already having programming experience, so the basic programming stuff will not be in this repo.

## How to run on your PC

You'll only need C/C++ installed, and in the C++ games section you'll need to install the [SFML Multimedia Library](https://www.sfml-dev.org/), and in the C games you'll need the [SDL2 lib](https://www.libsdl.org/download-2.0.php). To set-up your workspace follow this example below.

SDL game/.vscode/launch.json
``` json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}\\build\\game.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "your path to the mingw64 gdb.exe like: C:\\msys64\\mingw64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enably pretty printing",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "SDL2"
        }
    ]
}
```

SDL game/.vscode/tasks.json
``` json
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "shell",
			"label": "SDL2",
			"command": "your path to your gcc.exe like: C:\\msys64\\mingw64\\bin\\gcc.exe",
			"args": [
				"-g",
				"src\\*.c",
				"-o",
				"build\\game.exe",
				"-Iyour path to the sdl2 include folder like: IC:\\Users\\Gabriel\\Documents\\Out\\SDL2\\SDL2-2.0.14\\x86_64-w64-mingw32\\include",
				"-Lyour path to the sdl2 lib folder like: LC:\\Users\\Gabriel\\Documents\\Out\\SDL2\\SDL2-2.0.14\\x86_64-w64-mingw32\\lib",
				"-lmingw32",
				"-lSDL2main",
				"-lSDL2",
				"-mwindows"
			],
			"options": {
				"cwd": "${workspaceFolder}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			}
		}
	]
}
```
_**If you have some issue go to this [site](https://giovanni.codes/setup-sdl2-with-visual-studio-code-and-mingw64-on-windows/), or send to me an issue (:**_

## Where to Start

First Start With the Fundamentals: [freeCodeCamp C++ Tutorial stuff](https://github.com/Gabriel-Spinola/CPP-Study/tree/main/CodeCamp) -> [Suraj Sharma c++ Tutorials](https://github.com/Gabriel-Spinola/CPP-Study/tree/main/Suraj-Tutorials)

After that, feel free to explore the rest of the Repository

## Reference Links

Some stuff that helped to create this repository:
- [Microsoft C/C++ Documentation](https://docs.microsoft.com/en-us/cpp/?view=msvc-160)
- [W3Schools](https://www.w3schools.com/cpp/default.asp)
- [Refactoring Guru](https://refactoring.guru/)
- [Code Camp](https://www.youtube.com/channel/UC8butISFwT-Wl7EV0hUK0BQ)
- [Suraj Sharma](https://www.youtube.com/channel/UC2i39AOpDSlO1Mrn1jQ8Xkg)

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. (:

## Obs

If you have some tip I would be very grateful to receive it, especially for my English.

## License
[MIT](https://github.com/Gabriel-Spinola/CPP-Study/blob/main/LICENSE)
