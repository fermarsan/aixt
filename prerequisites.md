# Python
**Aixt** project needs _Python 3.x_, which can be download from its [Home page](https://www.python.org/downloads/).

_NOTE:_ In addition, you have to add _Python_ to PATH.

## Modules
**Aixt** project uses the [_lark_](https://lark-parser.readthedocs.io/en/latest/) Python's module for inplementing the lexic and syntactic analysis, _re_ for regular expresions analysis, and _yaml_ for the configuration files. You can install all the needed modules as follows: 
```
pip install lark re pyyaml
```

# V language
**Aixt** project not only is based on _The V programming language_ but use it for formating the Aixt source code and also as cross-platform system scripting language for implementing the project's Makefiles. You can install [_V_](https://github.com/vlang/v) using [_git_](https://git-scm.com/) as follows:
```
git clone https://github.com/vlang/v
cd v
make 
v symlink
```

# Native C compilers
- **XC8**: Microchip and Atmel 8-bit microcontrollers
- **XC16**: Microchip 16-bit microcontrollers
- **ImageCraft**: Cypress PSoC1
- **tcc*, **clang** or **gcc**: x64_PC

_NOTE:_ **nbc**, the NXC compiler for LEGO Mindstorms NXT intelligent brick, is already delivered along with the **Aixt project** source code.

# Visual Studio Code (optional)
For ease of using, **Aixt** project comes with configuration [_vscode_](https://code.visualstudio.com/) for building projects directly from that editor.