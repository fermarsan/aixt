# Project's folder tree
Aixt project has the follow general folder tree:
    
```
aixt/    
    ├── aixt_build
    │   └── builder.v
    ├── aixt_cgen
    │   ├── assign.v
    │   ├── call.v
    :   :
    │   └── utils.v
    ├── aixt.v
    ├── assets
    │   ├── Aixtu-ru.jpeg
    │   ├── Aixtu-ru-wide.png
    :   :
    │   └── text-logo.svg
    ├── common_test
    │   ├── 00_one_line.v
    │   ├── 01_declaring_and_types.v
    :   :
    │   ├── 29_types.v
    ├── CONTRIBUTING.md
    ├── docs
    │   ├── Aixt language.md
    │   ├── API folder tree.md
    :   :
    │   ├── Setup file.md
    │   ├── Atmel
    │   ├── Cypress
    :   :
    │   └── WCH
    ├── LICENSE
    ├── ports
    │   ├── Atmel
    │   ├── Cypress
    :   :
    │   └── WCH
    ├── prerequisites.md
    ├── README.md
    ├── TODO.md
    └── v.mod
```

- The _source code_ is located in `aixt.v` file, and `aixt_build/`, `aixt_cgen/` folders.
- The `assets/` folder contains the resource files such images.
- The `ports/` folder contains the implementation code for each device or board (mainly C source code)
- The `docs/` folder contains the documentation for each device or board

For each device or board implementation, two folders with the same name must exist inside `ports` and `docs` folders`, for the implementation itself and the correspondent documentation:

```
aixt/    
    :
    ├── docs
    :   :
    │   ├── Emulator
    :   :
    :
    ├── ports
    :   :
    │   ├── Emulator
    :   :
    :
```

## `ports` folder
This contains the implementation in _C_ language of the Aixt API, projects and _Aixt_ examples, of each device or board. The recommended folder tree for each port is:

```
device_or_board_name/    
    ├── api
    │   ├── machine
    :   :   
    │   └── builtin.c
    ├── examples
    │   ├── example_1.v
    │   ├── example_2.v
    :   :
    │   └── example_n.v
    └── projects
        ├── project_1
        ├── project_2
        :
        └── project_n
```

The `projects` folder could contain the project folders ad files for the spefific compiler and the `examples` folder should only contain _Aixt_ (_V_) source files.

## `docs` folder
This contains the documentation for each device or board implementation. This should be contain at least a quick reference guide `quickref.md`:

```
device_or_board_name/    
    ├── quickref.md
    :
    :
    └── pin_descrition.md
```

The `projects` folder could contain the project folders and files for the specific compiler and the `examples` folder should only contain _Aixt_ (_V_) source files.