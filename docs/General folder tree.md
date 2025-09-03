# Project's folder tree
Aixt project has the follow general folder tree:
    
```
aixt/    
    ├── src
    │   ├── aixt.build
    │   :   :
    │   │   └── builder.v
    │   ├── aixt.setup
    │   :   :
    │   │   └── setup.v
    │   ├── aixt.cgen
    │   │   ├── assign.v
    │   │   ├── call.v
    │   :   :
    │   │   └── utils.v
    │   └── aixt.v
    ├── assets
    │   ├── Aixtu-ru.jpeg
    │   ├── Aixtu-ru-wide.png
    :   :
    │   └── text-logo.svg
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
    ├── targets
    │   ├── Atmel
    │   ├── Cypress
    :   :
    │   └── WCH
    ├── prerequisites.md
    ├── README.md
    ├── TODO.md
    └── v.mod
```

- The _source code_ is located in the `src` folder.
- The `assets/` folder contains the resource files such images.
- The `targets/` folder contains the implementation code for each device or board (mainly Aixt's V source code)
- The `docs/` folder contains the documentation for each device or board

For each device or board implementation, two folders with the same name must exist inside `targets` and `docs` folders`, for the implementation itself and the correspondent documentation:

```
aixt/    
    :
    ├── docs
    :   :
    │   ├── Emulator
    :   :
    :
    ├── targets
    :   :
    │   ├── Emulator
    :   :
    :
```

## `targets` folder
This contains the implementation in _C_ language of the Aixt API, projects and _Aixt_ examples, of each device or board. The recommended folder tree for each port is:

```
device_or_board_name/    
    ├── api
    │   ├── pin/
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